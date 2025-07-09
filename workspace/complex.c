#include <stdio.h>

typedef struct {
    double real;
    double imag;
} Complex;

// Add two complex numbers
Complex add_complex(Complex a, Complex b) {
    return (Complex){a.real + b.real, a.imag + b.imag};
}

// Subtract two complex numbers
Complex sub_complex(Complex a, Complex b) {
    return (Complex){a.real - b.real, a.imag - b.imag};
}

// Multiply two complex numbers
Complex mul_complex(Complex a, Complex b) {
    return (Complex){
        a.real * b.real - a.imag * b.imag,
        a.real * b.imag + a.imag * b.real
    };
}

// Divide two complex numbers
Complex div_complex(Complex a, Complex b) {
    double denom = b.real * b.real + b.imag * b.imag;
    return (Complex){
        (a.real * b.real + a.imag * b.imag) / denom,
        (a.imag * b.real - a.real * b.imag) / denom
    };
}

// Complex conjugate
Complex conj_complex(Complex z) {
    return (Complex){z.real, -z.imag};
}

// Print complex number
void print_complex(Complex z) {
    printf("%.2f %c %.2fi\n", z.real, (z.imag < 0 ? '-' : '+'), (z.imag < 0 ? -z.imag : z.imag));
}

int main() {
    Complex z1 = {3.0, 4.0};    // 3 + 4i
    Complex z2 = {1.0, -2.0};   // 1 - 2i

    Complex sum = add_complex(z1, z2);
    Complex diff = sub_complex(z1, z2);
    Complex prod = mul_complex(z1, z2);
    Complex quot = div_complex(z1, z2);
    Complex conj1 = conj_complex(z1);
    Complex conj2 = conj_complex(z2);

    printf("z1 = ");
    print_complex(z1);

    printf("z2 = ");
    print_complex(z2);

    printf("z1 + z2 = ");
    print_complex(sum);

    printf("z1 - z2 = ");
    print_complex(diff);

    printf("z1 * z2 = ");
    print_complex(prod);

    printf("z1 / z2 = ");
    print_complex(quot);

    printf("conj(z1) = ");
    print_complex(conj1);

    printf("conj(z2) = ");
    print_complex(conj2);

    return 0;
}
