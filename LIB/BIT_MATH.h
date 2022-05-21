#ifndef BIT_MATH_H
#define BIT_MATH_H

#define SET_BIT(VAR,BIT)  VAR |=  ( 1<<( BIT ))
#define CLEAR_BIT(VAR,BIT)  VAR &= ~( 1<<( BIT ))
#define TOG_BIT(VAR,BIT)  VAR ^=  ( 1<<( BIT ))
#define GET_BIT(VAR,BIT)  ( ( VAR >> BIT )&1  )
#define SET_BYTE(VAR,BYTE) VAR |=(255<<(BYTE*8))

#endif
