#include <stdio.h>
// #define GET_MAX(a, b, mask) (a&mask) > (b&mask) ? (a&mask) : (b&mask)

// int main() {
//     unsigned short i = 12;
//     unsigned short j = 9;
//     printf("%d\n", GET_MAX(i++,++j, 0x7));  // 5, cuz 13 & 7 = 5
//     printf("i=%d  j=%d\n", i, j);           // i=14  j=10, cuz (a&mask) 會多做一次
//     return 0;
// }

int main(){
    unsigned short i = 12;
    unsigned short j = 9;
    #define GET_MAX(a,b) a > b ? a : b
    printf("%d\n", GET_MAX(i++,++j));  // 13
    printf("i=%d  j=%d\n", i, j);      // i=14  j=10, cuz i++ 會多做一次
    return 0;
}
