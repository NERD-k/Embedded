/*********************************************************************
 *      Author:     孔NERD <smallnerd.k@gmail.com>                  *
 *      Date:       November 4, 2018                                *
 *      Version:    test-alpha                                      *
**********************************************************************/

#include <mcs51/stc12.h>

// #define _nop_() __asm NOP __endasm

void exint0() __interrupt 0{
}

void exint1() __interrupt 2{
}

void main(void){
    IT0 = 1;    // set INT0 interrupt type
    IT1 = 1;    // set INT1 interrupt type(1:Falling only, 0:Low level)
    EX0 = 1;    // enable INT0 interrupt
    EX1 = 1;    // enable INT1 interrupt
    EA  = 1;    // open global interrupt switch

    while(1){
        // 程序
    }
}

