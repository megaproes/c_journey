#include "006.h"
#if !defined(ALPHABETIC)
#define ALPHABETIC

#define IS_LOWERCASE(a) (((a) >= 'a' && (a) <= 'z') ? 1 : 0)
#define IS_ALPHABETIC(a) ((IS_LOWERCASE(a) || IS_UPPER_CASE(a)) ? 1 : 0)

#endif // ALPHABETIC
