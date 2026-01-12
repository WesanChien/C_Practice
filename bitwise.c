#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>

uint32_t q1(uint32_t x){ // (a) 把第 5 個 bit 設為 1 (b) 把第 7 個 bit 清為 0 (c) 檢查第 3 個 bit 是否為 1
    x |= (0x1 << 5);
    x &= ~(0x1 << 7);
    if(x &(0x1 << 3)) printf("The third bit is 1.\n");
    else printf("The third bit is not 1.\n");

    return x;
}

uint32_t q2(uint32_t x){ // (a)寫一行 code，讓 bit 2 與 bit 3 同時 toggle，一起反轉
    uint32_t toggle = (0x1 << 2) | (0x1 << 3); // 0000 1100
    x ^= toggle;

    return x;
}

void q3(uint32_t x){ // (a) 取出 bit 0 (b) 取出 bit 7
    int bit0 = x & 1;
    int bit7 = (x >> 7) & 1;
    printf("bit0 is %d, bit7 is %d\n", bit0, bit7);
}

// uint32_t extract_bits(uint32_t y, int pos, int len){
    
// }

int main() {
    uint32_t x = 0x85; // 1000 0101
    x = q1(x);
    printf("%u\n", x);

    x = q2(x);
    printf("%u\n", x);

    q3(x);

    uint32_t y = 0b11010110;
    extract_bits(y, 2, 3); //101
    printf("%d\n", y);

    return 0;
}
