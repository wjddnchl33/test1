#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
}Node;

typedef struct Queue{
    Node*front;
    Node*rear;
}Queue;

void init_Queue(Queue *Q){
    Q->front = Q->rear = NULL;
}

void enqueue(Queue *Q, int data){
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    if(Q->front == NULL) {
        Q->front = Q->rear = newNode;
    }
    else {
        Q->rear->next = newNode;
        Q->rear = newNode;
    }

}

void dequeue(Queue *Q) {
    Node*remove;
    if(Q->front == NULL) {
        printf("ERROR!");
        return;
    }
    remove = Q->front;
    Q->front = remove->next;
    free(remove);
}


void print(Queue *Q) {
    for(Node *p = Q->front; p; p = p->next) {
        printf("%d  ", p->data);
    }
}

int main() {
    Queue Q;
    init_Queue(&Q);
    int num,data;


    printf("1번 : 삽입   2번 : 삭제  3번  : 프로그램 종료");
    while(1) {
        printf("\n원하는 옵션을 입력하세요 : ");
        scanf("%d", &num);
        if(num == 1) {
            printf("삽입할 값을 입력하세요 : ");
            scanf("%d", &data);
            enqueue(&Q, data);
            print(&Q);
        }
        else if(num == 2) {
            dequeue(&Q);
            print(&Q);
        }
        else if(num == 3){
            break;
        }
        else
            printf("다시 입력해주세요");
    }

}
