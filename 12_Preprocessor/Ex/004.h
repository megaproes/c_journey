#if !defined(MAX3_H)
#define MAX3_H

#define MAX3(a, b, c) (a) > (b) && (a) > (c) ? a \
				: ((b) > (c)) ? b : c

#endif // MAX3_H
