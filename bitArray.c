#include <stdio.h>

int main(){
    short arr[] = {0x1111, 0x2222, 0x3333, 0x4444, 0x5555, 0x6666};
    int a = ((int*)arr + 1)[1];             // a = 0x6666 5555, cast 成 int 是 4 bytes，往後移了兩次，再取值(Little endian)
    int b = ((int*)(arr + 2))[1];           // b = 0x6666 5555, short 走 2 bytes，int 走 4 bytes
    int d = ((int*)(arr + 1))[1];           // d = 0x5555 4444
    int c = *(int*)(arr + 3);               // c = 0x5555 4444, 轉 int 取值取 4 bytes
    int e = (arr + 1)[1];                   // e = 0x3333, 取值取 short 而已，取 2 bytes，後面可不用補 0 成 0x0000 3333
    int f = *(short*)((int*)arr + 1);       // f = 0x3333
    int g = ((short*)((int*)arr + 1))[0];   // g = 0x3333
    int h = ((short*)((int*)arr + 1))[1];   // h = 0x4444

    printf("%x\n", a);
    printf("%x\n", b);
    printf("%x\n", c);
    printf("%x\n", d);
    printf("%x\n", e);
    printf("%x\n", f);
    printf("%x\n", g);
    printf("%x\n", h);
}
