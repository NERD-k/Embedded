/*********************************************************************
 *      Author:     孔NERD <smallnerd.k@gmail.com>                  *
 *      Date:       November 4, 2018                                *
 *      Version:    test-alpha                                      *
**********************************************************************/

#include <mcs51/stc12.h>

#define _nop_() __asm NOP __endasm

void t0int() __interrupt 1{
}

void t1int() __interrupt 3{
}

void main(void){
    // ET0 = 1;
    // ET1 = 1;
    EA = 1;

    while(1){
        T0 = 1;
        T1 = 1;
        while(!T0);
        _nop_();
        _nop_();
        while(!T1);
        _nop_();
        _nop_();
    }
}

