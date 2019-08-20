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

#ifndef BV
#define BV(x) 								(1<<(x))
#endif

#define CC_BYTE_ALIGNED 					__attribute__ ((packed, aligned(1)))
/*---------------------------------------------------------------------------*/
#endif /* __PLATFORM_CONF_H__ */
/*---------------------------------------------------------------------------*/
