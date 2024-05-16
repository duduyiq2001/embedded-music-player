/*
 * utility.h
 *
 * Created: 5/13/2024 7:11:03 AM
 *  Author: Administrator
 */ 

#ifndef UTILITY
#define UTILITY

// frequency of the current ck
#define XTAL_FRQ 8000000lu
#define SET_BIT(p,i) ((p) |=  (1 << (i)))
#define CLR_BIT(p,i) ((p) &= ~(1 << (i)))
#define GET_BIT(p,i) ((p) &   (1 << (i)))



void wait_avr(unsigned short msec);
void wait_micro(unsigned short microsec);
#endif


