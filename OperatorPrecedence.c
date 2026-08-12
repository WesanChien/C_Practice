#include <stdio.h>
int main() {
    char s[] = "0123456"; 
    char *p = s;           
    printf("%c\n",*p++);    // 印 0 往前走
    printf("%c\n",*(p++));  // 印 1 往前走 
    printf("%c\n",(*p)++);  // 印 2，取值 + 1
    printf("%c\n",*++p);    // 先往前走，再取值印出 3
    printf("%c\n",*(++p));  // 先往前走，再取值印出 4
    printf("%c\n",++*p);    // 先取值，再 + 1 再印出 5
    printf("%c\n",++(*p));  // 先取值，再 + 1 再印出 6
    printf("%s\n",s);       // 0133656
    printf("p at [%d]\n", (int)(p - s)); // p at [4]
    return 0;
}
