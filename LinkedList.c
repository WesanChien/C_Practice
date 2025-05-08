#include<stdio.h>
#include<stdlib.h>

struct Node {
    int data;
    struct Node* next; // Node* next in C++. Or using typedef struct Node{...}Node; in C
};
struct Node* HEAD = NULL;

void insertBegin(int data){
    struct Node* tmp = (struct Node*)malloc(sizeof(struct Node));
    tmp->data = data;
    tmp->next = HEAD;
    HEAD = tmp;
}

void deleteBegin(){
    struct Node* tmp = HEAD;
    HEAD = HEAD->next;
    free(tmp);
}

void insertNth(int data, int n){
    struct Node* tmp1 = (struct Node*)malloc(sizeof(struct Node));
    tmp1->data = data;
    if(n == 1){
        tmp1->next = HEAD;
        HEAD = tmp1;
    }
    else{
        struct Node* tmp2 = HEAD;
        for(int i = 0; i < n - 2; i++){
            tmp2 = tmp2->next;
        }
        tmp1->next = tmp2->next;
        tmp2->next = tmp1;
    }
}

void deleteNth(int n){
    struct Node* tmp1 = HEAD;
    if(n == 1){
        deleteBegin();
    }
    else{
        for(int i = 0; i < n - 2; i++){
            tmp1 = tmp1->next; 
        }
        struct Node* tmp2 = tmp1->next;
        tmp1->next = tmp2->next;
        free(tmp2);
    }
}

void reverse(){
    struct Node *prev, *curr, *nxt;
    prev = NULL;
    curr = HEAD;
    while(curr != NULL){
        nxt = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nxt;
    }
    HEAD = prev;
}

void printList(struct Node* n){
    while(n != NULL){
        printf("%d ", n -> data);
        n = n -> next;
    }
    printf("\n");
}

int main() {
    // int x, k;
    // printf("How many nodes you want?");
    // scanf("%d", &x);
    // for(int i = 0; i < x; i++){
    //     printf("The node value is: ");
    //     scanf("%d", &k);
    //     insertBegin(k);
    // }
    insertNth(2, 1); // List: 2
    insertNth(3, 2); // List: 2, 3
    insertNth(4, 1); // List: 4, 2, 3
    insertNth(5, 2); // List: 4, 5, 2, 3
    // deleteNth(2);
    printList(HEAD);
    reverse();
    printList(HEAD);
    return 0;
}
