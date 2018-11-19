/*********************************************************************
 *      Author:     孔NERD <smallnerd.k@gmail.com>                  *
 *      Date:       November 4, 2018                                *
 *      Version:    test-alpha                                      *
**********************************************************************/

#include <mcs51/stc12.h>

// #define _nop_() __asm NOP __endasm

void PCA_isr() __interrupt 7 using 1{
}

void main(void){
    // 变量声明
    while(1){
        // 程序
    }
}

