#ifndef STD_TYPES_H_
#define STD_TYPES_H_ 

#ifndef FALSE
#define FALSE (0u)
#endif

#ifndef TRUE
#define TRUE (1U)
#endif

#define HIGH (1U)
#define LOW (0U)

#define setBit(Reg,x) Reg|=(1u<<x)
#define resetBit(Reg,x) Reg&=~(1u<<x)
#define checkBit(Reg,x) ((Reg>>x)&(1u))


typedef unsigned char		uint8;
typedef signed char			sint8;
typedef unsigned short		uint16;
typedef signed short		sint16;
typedef unsigned long		uint32;
typedef signed long			sint32;
typedef unsigned long long	uint64;
typedef signed long long	sint64;
typedef float				float32;
typedef double				float64;

#endif

