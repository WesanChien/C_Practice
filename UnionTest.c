#include <stdio.h>

struct A {
    unsigned short a1; // 2 bytes
    unsigned short a2;
    unsigned short a3;
};

union B {
    unsigned long long b1; // 8 bytes
    struct A b2;
};

int main() {
    // 假設是 Little Endian, Lower address 放 lsb
    union B uu;
    printf("%zu\n", sizeof(uu));  // 8 bytes due to long long

    uu.b1 = 0xffffffffffffffff; // msb -> lsb
    uu.b2.a1 = 0x1234;
    uu.b2.a2 = 0x5678;
    uu.b2.a3 = 0xabcd;
    printf("%llx\n", uu.b1);   // ff ff ab cd 56 78 12 34
    *(&(uu.b2.a3) + 1) = 0xeeee;
    printf("%llx\n", uu.b1);   // ee ee ab cd 56 78 12 34
    return 0;
}
