#include <at89c5131.h>
#include "lcd.h"
#include <stdio.h>

code unsigned char Password[]="15A8*D6#";                      
code unsigned char display_msg[]="Enter Password:"; //Display msg on 1st line of lcd
char array[8];
int i=0,row;
int correct;
unsigned char correct1;
void main()
{
    lcd_init();
    lcd_cmd(0x80);                                                  //Move cursor to first line
    msdelay(4);
    lcd_cmd(0x01);
    lcd_write_string(display_msg);
    lcd_cmd(0xc0);
    correct=1;

for(i=0;i<8;i++){

    P3= 0x0F;

    LOOP1:
    while(array[i]!= 0x0F){
    array[i]= P3;
    array[i]= array[i] & 0x0F;
    }
   
    P3=P3 & 0x0F;
    while(P3 == 0x0F){
        P3=P3 & 0x0F;
    }
   
    msdelay(20);

 

if(row==0){
    P3=0x0F;
    if(P3_3==0){
    array[i]='1';
        lcd_write_string("1");
    }
    else if(P3_2==0){
        array[i]='2';
        lcd_write_string("2");

        }
    else if(P3_1==0){
        array[i]='3';  
        lcd_write_string("3");
        }
    else if(P3_0==0){
        array[i]='A';
        lcd_write_string("A");

        }
}
else if(row==1){
    P3=0x0F;
    if(P3_3==0){
    array[i]='4';
    lcd_write_string("4");

    }
    else if(P3_2==0){
        array[i]='5';
        lcd_write_string("5");


        }
    else if(P3_1==0){
        array[i]='6';
        lcd_write_string("6");

        }
    else if(P3_0==0){
        array[i]='B';
        lcd_write_string("B");

        }
    }
else if(row==2){
    P3=0x0F;
if(P3_3==0){
    array[i]='7';
    lcd_write_string("7");
    }
    else if(P3_2==0){
        array[i]='8';
        lcd_write_string("8");
        }
    else if(P3_1==0){
        array[i]='9';
        lcd_write_string("9");

        }
    else if(P3_0==0){
        array[i]='C';
        lcd_write_string("C");

        }
    }
else if(row==3){
    P3=0x0F;
if(P3_3==0){
    array[i]='*';
  lcd_write_string("*");

    }
    else if(P3_2==0){
        array[i]='0';
        lcd_write_string("0");

        }
    else if(P3_1==0){
        array[i]='#';
        lcd_write_string("#");
        }
    else if(P3_0==0){
        array[i]='D';
        lcd_write_string("D");

        }
    }

}

 for(i=0;i<8;i++){
    if(array[i]!=Password[i]){
        correct=0;
        break;  
    }  
}

if(correct==1){
    lcd_cmd(0x80);                                                  //Move cursor to first line
    msdelay(4);
    lcd_cmd(0x01);
    lcd_write_string("Correct Password");
    lcd_cmd(0xc0);
    lcd_write_string("Access Granted");
}
else{
    lcd_cmd(0x80);                                                  //Move cursor to first line
    msdelay(4);
    lcd_cmd(0x01);
    lcd_write_string("Wrong Password");
    lcd_cmd(0xc0);
    lcd_write_string("Access Denied");
}

msdelay(5000);

}