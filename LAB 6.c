#include <at89c5131.h>
#include "lcd.h"

code unsigned char display_msg1[]="START PROGRAM   ";//Display msg on 1st line of lcd
code unsigned char display_msg2[]="FIRST INPUT     ";	//Display msg on 1st line of lcd
code unsigned char display_msg3[]="NEXT INPUT      ";		
code unsigned char display_msg4[]="SORTING         ";	
code unsigned char display_msg5[]="COMPLETED       ";	
code unsigned char display_msg6[]="NUMBER TO BE    ";
code unsigned char display_msg7[]="SEARCHED        ";
code unsigned char display_msg8[]="THE INDEX IS    ";
code unsigned char display_msg9[]="NUMBER          ";
code unsigned char display_msg10[]="NOT FOUND       ";


unsigned char swap_nibble(unsigned char x)
{
    return ( (x & 0x0F)<<4 | (x & 0xF0)>>4 );
}


void swap(unsigned char *xp, unsigned char *yp)
	{
	int temp = *xp;
	*xp = *yp;
	*yp = temp;
	}

/*******bubble sort*******/
void bubble_sort(unsigned char a[], int n)
	{
	int i, j;
	for (i = 0; i < n-1; i++)
		for (j = 0; j < n-i-1; j++)
			if (a[j] > a[j+1])
			swap(&a[j], &a[j+1]);
	}


unsigned char a[5];
unsigned char x;
unsigned char to_be_searched;
int index;
int found=0;
int i;

void main()
{
	lcd_init();
	lcd_cmd(0x80);													//Move cursor to first line
	lcd_write_string(display_msg1);
	P1=0x00;
	msdelay(5000);
	lcd_cmd(0x80);													//Move cursor to 2nd line of LCD
	
	for(i=0 ; i<=4 ; i++)
	{
		if (i==0){
			lcd_write_string(display_msg2);
			P1=0x0F;
			msdelay(5000);	
			a[i] = P1 & (0x0F);
			x = (swap_nibble(a[i]) | 0x0F);
			lcd_cmd(0x80);													//Move cursor to first line
			lcd_write_string(display_msg3);
			P1 = x;
			msdelay(5000);}
	
	else if (i!=4){	
			a[i] = P1 & (0x0F);
			P1 = 0x0F;
			msdelay(1000);
			x = swap_nibble(a[i]) | 0x0F;
			P1 = x;
			msdelay(5000);	
			}
	else{
			a[i] = P1 & (0x0F);
			P1 = 0x0F;
			msdelay(1000);
			x = swap_nibble(a[i]) | 0x0F;
			P1 = x;
			lcd_cmd(0x80);
			lcd_write_string(display_msg4);
			lcd_cmd(0xC0);													//Move cursor to 2nd line of LCD
			msdelay(4);
			lcd_write_string(display_msg5);
			P1 = 0x00;
			msdelay(1000);}
	}
  /******************/
	/********SORTING*******/
	/******************/
	bubble_sort(a, 5);
	
		for(i = 0; i<5; i++){
				P1 = 0x00;
				msdelay(1000);
				x = swap_nibble(a[i]);
				P1 = x;
				msdelay(5000);
		}

		P1 = 0x00;
		msdelay(1000);
		lcd_cmd(0x80);
		lcd_write_string(display_msg6);
		lcd_cmd(0xC0);													//Move cursor to 2nd line of LCD
		msdelay(4);
		lcd_write_string(display_msg7);
		P1 = 0xFF;
		msdelay(5000);
		to_be_searched = P1 & 0x0F;
		msdelay(5000);
		lcd_cmd(0x01);	// LCD clear
		P1 = 0x00;
		msdelay(1000);
		
		for(i=0;i<5;i++){
			if(a[i] == to_be_searched){
				index = i+1;
				found = 1;
				index = index & 0x0F;
			 index=index<<4;
				P1 = index;
				lcd_cmd(0x80);
				lcd_write_string(display_msg8);
				break;
			}
		}
		if(found==0){ 
			lcd_cmd(0x80);
			lcd_write_string(display_msg9);
			lcd_cmd(0xC0);													//Move cursor to 2nd line of LCD
			msdelay(4);
			lcd_write_string(display_msg10);
		}


	
	while(1);
		
}