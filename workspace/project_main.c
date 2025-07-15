#include "complex.h"

int main(void) {
    Complex z1 = complex_make(3.0,  4.0);
    Complex z2 = complex_make(1.0, -2.0);

    Complex sum  = complex_add(z1, z2);
    Complex prod = complex_mul(z1, z2);

    printf("z1 + z2 = ");
    complex_print(sum);

    printf("z1 * z2 = ");
    complex_print(prod);

    return 0;
}
