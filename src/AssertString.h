#ifndef Assert_String_H
#define Assert_String_H

#include <assert.h>

/**
 * 封装assert宏，提供运行时级别的友好的错误信息
 */

#define ASSERT_STRING(_Expression, ...) \
	(void)((!!(_Expression)) || (printf(__VA_ARGS__), printf("\n"), 0) || (assert(_Expression), 0))

#endif /* Assert_String_H */
