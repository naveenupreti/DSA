#include <stdio.h>
#include <limits.h>
#include <float.h>

int main() {
    // char
    printf("Type: char\n");
    printf("  Size: %zu bytes\n", sizeof(char));
    printf("  Format specifier: %%c (character), %%d (numeric)\n");
    printf("  Range: %d to %d\n\n", CHAR_MIN, CHAR_MAX);

    // unsigned char
    printf("Type: unsigned char\n");
    printf("  Size: %zu bytes\n", sizeof(unsigned char));
    printf("  Format specifier: %%c (character), %%u (numeric)\n");
    printf("  Range: 0 to %u\n\n", UCHAR_MAX);

    // short
    printf("Type: short\n");
    printf("  Size: %zu bytes\n", sizeof(short));
    printf("  Format specifier: %%hd\n");
    printf("  Range: %d to %d\n\n", SHRT_MIN, SHRT_MAX);

    // unsigned short
    printf("Type: unsigned short\n");
    printf("  Size: %zu bytes\n", sizeof(unsigned short));
    printf("  Format specifier: %%hu\n");
    printf("  Range: 0 to %u\n\n", USHRT_MAX);

    // int
    printf("Type: int\n");
    printf("  Size: %zu bytes\n", sizeof(int));
    printf("  Format specifier: %%d\n");
    printf("  Range: %d to %d\n\n", INT_MIN, INT_MAX);

    // unsigned int
    printf("Type: unsigned int\n");
    printf("  Size: %zu bytes\n", sizeof(unsigned int));
    printf("  Format specifier: %%u\n");
    printf("  Range: 0 to %u\n\n", UINT_MAX);

    // long
    printf("Type: long\n");
    printf("  Size: %zu bytes\n", sizeof(long));
    printf("  Format specifier: %%ld\n");
    printf("  Range: %ld to %ld\n\n", LONG_MIN, LONG_MAX);

    // unsigned long
    printf("Type: unsigned long\n");
    printf("  Size: %zu bytes\n", sizeof(unsigned long));
    printf("  Format specifier: %%lu\n");
    printf("  Range: 0 to %lu\n\n", ULONG_MAX);

    // long long
    printf("Type: long long\n");
    printf("  Size: %zu bytes\n", sizeof(long long));
    printf("  Format specifier: %%lld\n");
    printf("  Range: %lld to %lld\n\n", LLONG_MIN, LLONG_MAX);

    // unsigned long long
    printf("Type: unsigned long long\n");
    printf("  Size: %zu bytes\n", sizeof(unsigned long long));
    printf("  Format specifier: %%llu\n");
    printf("  Range: 0 to %llu\n\n", ULLONG_MAX);

    // float
    printf("Type: float\n");
    printf("  Size: %zu bytes\n", sizeof(float));
    printf("  Format specifier: %%f\n");
    printf("  Range: %e to %e\n\n", FLT_MIN, FLT_MAX);

    // double
    printf("Type: double\n");
    printf("  Size: %zu bytes\n", sizeof(double));
    printf("  Format specifier: %%lf\n");
    printf("  Range: %e to %e\n\n", DBL_MIN, DBL_MAX);

    // long double
    printf("Type: long double\n");
    printf("  Size: %zu bytes\n", sizeof(long double));
    printf("  Format specifier: %%Lf\n");
    printf("  Range: %Le to %Le\n\n", LDBL_MIN, LDBL_MAX);

    return 0;
}
