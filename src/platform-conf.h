/*---------------------------------------------------------------------------*/
#ifndef __PLATFORM_CONF_H__
#define __PLATFORM_CONF_H__
/*---------------------------------------------------------------------------*/
#include <inttypes.h>
#include <string.h>
/*---------------------------------------------------------------------------*/
#define CC_CONF_REGISTER_ARGS          		0
#define CC_CONF_FUNCTION_POINTER_ARGS  		1
#define CC_CONF_FASTCALL					1
#define CC_CONF_VA_ARGS                		1
#define CC_CONF_NO_VA_ARGS			   		0
#define AUTOSTART_ENABLE			   		1

#ifndef CC_CONF_INLINE
	#define CC_CONF_INLINE                 	inline
#endif

#define CCIF
#define CLIF

/* These names are deprecated, use C99 names. */
typedef uint8_t u8_t;
typedef uint16_t u16_t;
typedef uint32_t u32_t;
typedef int8_t s8_t;
typedef int16_t s16_t;
typedef int32_t s32_t;

#ifndef BV
#define BV(x) 								(1<<(x))
#endif

#define CC_BYTE_ALIGNED 					__attribute__ ((packed, aligned(1)))
/*---------------------------------------------------------------------------*/
#endif /* __PLATFORM_CONF_H__ */
/*---------------------------------------------------------------------------*/
