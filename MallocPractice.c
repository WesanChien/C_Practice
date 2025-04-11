#include<stdio.h>
#include<stdlib.h>

int main() {
    int *num = NULL;
    int length = 0;
    while (1){
        int input;
        scanf("%d", &input);
        if(input == 0) break;
        int *arr = (int *)malloc(sizeof(int) * (length + 1)); //不用malloc的話，到while的}時候，*num會被free掉
        for(int i = 0; i < length; i++) {
            arr[i] = num[i];
        }
        free(num);
        num = arr;
        // num = realloc(num, sizeof(int) * (length + 1));// realloc可取代上面
        num[length] = input;
        length++;
    }
    printf("You've entered: ");
    for(int i = 0; i < length; i++) {
        printf("%d ", num[i]);
    }
    printf("\n");
    return 0;
}
