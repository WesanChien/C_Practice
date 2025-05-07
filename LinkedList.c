#include<stdio.h>
#include<stdlib.h>

struct Node {
    int data;
    struct Node* next; // Node* next in C++. Or using typedef struct Node{...}Node; in C
};
struct Node* HEAD = NULL;

void insertBegin(int x){
    struct Node* tmp = (struct Node*)malloc(sizeof(struct Node));
    tmp->data = x;
    tmp->next = HEAD;
    HEAD = tmp;
}

void printList(struct Node* n){
    while(n != NULL){
        printf("%d ", n -> data);
        n = n -> next;
    }
}

int main() {
    int x, k;
    printf("How many nodes you want?");
    scanf("%d", &x);
    for(int i = 0; i < x; i++){
        printf("The node value is: ");
        scanf("%d", &k);
        insertBegin(k);
    }
    printList(HEAD);
    return 0;
}
