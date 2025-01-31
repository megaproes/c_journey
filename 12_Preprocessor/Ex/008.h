#include "007.h" // IS_ALPHABETIC
#if !defined(IS_DIGIT_H)
#define IS_DIGIT_H

#define IS_DIGIT(a) ((a) >= '0' && (a) <= '9' ? 1 : 0)
#define IS_SPECIAL(a) ((!IS_DIGIT(a)) && (!IS_ALPHABETIC(a)))

#endif // IS_DIGIT_H
