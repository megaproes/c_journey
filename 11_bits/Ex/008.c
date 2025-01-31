#include <limits.h>
#include <limits.h>
/* Function to set a bit pattern in a given unsigned integer */
void bitpat_set(unsigned *x, unsigned value, unsigned start_pos, unsigned size)
{
    if (size == 0 || start_pos >= sizeof(unsigned) * 8)
    {
        // If size is 0 or start_pos is out of bounds, do nothing
        return;
    }

    unsigned n_bits = sizeof(unsigned) * 8; // Number of bits in unsigned

    // Clamp size if it extends beyond the end of the bitfield
    if (start_pos + size > n_bits)
    {
        size = n_bits - start_pos;
    }

    // Create a mask for the bits we want to replace
    unsigned mask;
    if (size == n_bits)
    {
        mask = ~0u;
    }
    else
    {
        mask = ((1u << size) - 1) << (n_bits - start_pos - size);
    }

    // Align the value to the correct position, truncating any extra bits
    value = (value & ((1u << size) - 1)) << (n_bits - start_pos - size);

    // Clear the bits in the original number and set the new value
    *x = (*x & ~mask) | value;
}
