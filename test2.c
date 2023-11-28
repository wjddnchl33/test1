#include <stdio.h>

typedef struct stack{
    int top;
    int bottom;
    int data[4];
}stack;

void init_stack (stack *s) {
    s->top = s->bottom = -1;
}

void push(stack *s, int data) {
    if(s->top == 3){
        printf("메모리 오버플로");
        return 1;
    }
    s->top = (s->top+1)%4;
    s->data[s->top] = data;
}

void pop(stack *s) {
    if(s->top == s->bottom) {
        printf("메모리 언더플로");
        return 1;
    }
    printf("삭제된 값 : %d", s->data[(s->top)--]);
}

void print(stack *s) {
    printf("\n현재 스택 : ");
    for(int i = s->bottom; i != s->top;){
        i = (i+1)%4;
        printf("%d ", s->data[i]);

    }
}

int main() {

    stack s;
    int num, data;
    init_stack(&s);

    printf("1번 : 삽입    2번 :   삭제    3번 : 프로그램 종료");
    while(1) {
        printf("\n원하는 옵션을 입력해주세요 : ");
        scanf("%d", &num);

        if(num == 1) {
            printf("삽입할 값을 입력해주세요 : ");
            scanf("%d", &data);
            push(&s, data);
            print(&s);
        }
        else if(num == 2) {
            pop(&s);
            print(&s);
        }
        else if(num == 3){
            printf("프로그램을 종료합니다. ");
            break;
        }
        else
            printf("다시 입력해주세요");
    }
}
