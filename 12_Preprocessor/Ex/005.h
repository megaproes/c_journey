#if !defined(SHIFT_H)
#define SHIFT_H

#define SHIFT(a, n) ((n) > 0 ? ((a) << (n)) : ((a) >> -(n)))

#endif // SHIFT_H
