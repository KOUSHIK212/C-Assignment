#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct Stack {
    int d;
    struct Stack *next;
};


struct Stack *CreateStack () {
    return NULL;
}

int isEmptyStack(struct Stack *up) {
    return (up == NULL);
}

void Push(struct Stack **up, int d) {
    struct Stack *newNode = (struct Stack*) malloc(sizeof(struct Stack));
    if(!newNode)
        return;
    newNode->d = d;
    newNode->next = *up;
    *up = newNode;
}

int Pop(struct Stack **up) {
    struct Stack *t;
    int d;

    if(isEmptyStack(*up)) {
        printf("Empty Stack.\n");
        return INT_MIN;
    }

    t = *up;
    d = (*up)->d;
    *up = (*up)->next;
    free(t);
    return d;
}

struct Queue {
    struct Stack *S1;
    struct Stack *S2;
};

struct Queue *CreateQueue() {

    struct  Queue  *newNode = (struct Queue *) malloc(sizeof(struct  Queue ));

    return newNode;
}

void EnQueue(struct Queue *Q, int d) {
    Push(&Q->S1, d);
}

int DeQueue(struct Queue *Q) {
    if(!isEmptyStack(Q->S2)) {
        return Pop(&Q->S2);
    }
    else {
        while(!isEmptyStack(Q->S1)) {
            Push(&Q->S2, Pop(&Q->S1));
        }
        return Pop(&Q->S2);
    }
}

int main() {
    struct Queue *Q = CreateQueue();
    Q->S1 = Q->S2 = NULL;
    EnQueue(Q, 3);
    EnQueue(Q, 4);
    EnQueue(Q, 7);

    printf("%d ", DeQueue(Q));
    printf("%d ", DeQueue(Q));
    printf("%d ", DeQueue(Q));

    return 0;
}
