#ifndef Assert_String_H
#define Assert_String_H

#include <assert.h>

/**
 * 封装assert宏，提供源代码和运行时级别的友好的错误信息
 */

#define ASSERT_STRING(_Expression, _String)	\
	(void)((!!(_Expression)) || (printf("Assertion failed: %s, function: %s, file %s, line %d\n", #_String, __FUNCSIG__, __FILE__, __LINE__), 0) || (assert(_Expression), 0))

#endif /* Assert_String_H */
