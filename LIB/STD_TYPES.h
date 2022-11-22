/**********************************************************/
/*           Author  : Asmaa Mohsen                       */
/*           Layer   : APP                                */
/*           Version : 1.00                               */
/**********************************************************/

#ifndef STD_TYPES_H
#define STD_TYPES_H


#define NULL 0


//1Byte data types
typedef unsigned char u8;
typedef signed char s8;

//2Byte data types
typedef unsigned short int u16;
typedef signed short int s16;

//4Byte data types
typedef unsigned long int u32;
typedef signed long int s32;

//floating data types
typedef float f32;
typedef double f64;
typedef long double f128;

//error statement
#define OK               0
#define NOK              1
#define NULL_POINTER     2
#define OUT_OF_RANGE     3
#define BUSY_STATE       4
#define WRONG_ID         5
#define WRONG_CHANNEL    6
#define WRONG_FREQ       7


#endif 
