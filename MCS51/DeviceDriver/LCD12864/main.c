/*********************************************************************
 *      Author:     孔NERD <smallnerd.k@gmail.com>                  *
 *      Date:       November 4, 2018                                *
 *      Version:    test-alpha                                      *
**********************************************************************/

#include <mcs51/stc12.h>

#define _nop_() __asm NOP __endasm

#define DataPort P0

#define RS P2_0
#define RW P2_1
#define EN P2_2

#define RS_CLR RS=0
#define RS_SET RS=1

#define RW_CLR RW=0
#define RW_SET RW=1

#define EN_CLR EN=0
#define EN_SET EN=1

/*************************************************
 * 微秒延时函数，大致延时时间 T=2×t+5 (us)
*************************************************/
void DelayUs2x(unsigned char t){
    while(--t);
}

/*************************************************
 * 毫秒延时函数，大致延时时间 T=1 (ms)
*************************************************/
void DelayMs(unsigned char t){
    while(t--){
        DelayUs2x(245);
        DelayUs2x(245);
    }
}

/*************************************************
 * 判忙函数
*************************************************/
/* bit LCD_Check_Busy(void){
    DataPort = 0xFF;
    RS_CLR;
    RW_SET;
    EN_CLR;
    _nop_();
    EN_SET;
    return (bit)(DataPort & 0x80);
} */

/*************************************************
 * 写入命令函数
*************************************************/
void LCD_Write_Com(unsigned char com){
    DelayMs(5);
    RS_CLR;
    RW_CLR;
    EN_SET;
    DataPort = com;
    _nop_();
    EN_CLR;
}

/*************************************************
 * 写入数据函数
*************************************************/
void LCD_Write_Data(unsigned char Data){
    DelayMs(5);
    RS_SET;
    RW_CLR;
    EN_SET;
    DataPort = Data;
    _nop_();
    EN_CLR;
}

/*************************************************
 * 清屏函数
*************************************************/
void LCD_Clear(void){
    LCD_Write_Com(0x01);
    DelayMs(5);
}

/*************************************************
 * 写入字符串函数
*************************************************/
void LCD_Write_String(unsigned char x, unsigned char y, unsigned char *s){
    if (y == 0){
        LCD_Write_Com(0x80 + x);
    }
    else{
        LCD_Write_Com(0xC0 + x);
    }
    while (*s){
        LCD_Write_Data(*s);
        s++;
    }
}

/*************************************************
 * 写入字符函数
*************************************************/
void LCD_Write_Char(unsigned char x, unsigned char y, unsigned char Data){
    if (y == 0){
        LCD_Write_Com(0x80 + x);
    }
    else{
        LCD_Write_Com(0xC0 + x);
    }
    LCD_Write_Data(Data);
}

/*************************************************
 * 初始化函数
*************************************************/
void LCD_Init(void){
    LCD_Write_Com(0x38);
    DelayMs(5);
    LCD_Write_Com(0x38);
    DelayMs(5);
    LCD_Write_Com(0x38);
    DelayMs(5);
    LCD_Write_Com(0x38);
    LCD_Write_Com(0x08);
    LCD_Write_Com(0x01);
    LCD_Write_Com(0x06);
    DelayMs(5);
    LCD_Write_Com(0x0C);
}
/*************************************************
 * 主函数
*************************************************/
void mian(void){
    LCD_Init();
    LCD_Clear();

    while(1){
        LCD_Write_Char(7, 0, 'o');
        LCD_Write_Char(8, 0, 'k');
        LCD_Write_String(1, 1, "www.google.com");
        while(1);
    }
}

