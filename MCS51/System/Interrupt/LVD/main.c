/*********************************************************************
 *      Author:     孔NERD <smallnerd.k@gmail.com>                  *
 *      Date:       November 4, 2018                                *
 *      Version:    test-alpha                                      *
**********************************************************************/

#include <mcs51/stc12.h>

#define _nop_() __asm NOP __endasm

void lvdint() __interrupt 6{
}

void main(void){
    ELVD = 1;
    EA   = 1;

    while(1){
        while(PCON & 0x20){
            PCON &= 0xDF;
            _nop_();
            _nop_();
            _nop_();
            _nop_();
        }
        _nop_();
        _nop_();
        PCON = 0x02;
        _nop_();
        _nop_();
}

