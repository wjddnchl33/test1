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
        printf("�޸� �����÷�");
        return 1;
    }
    s->top = (s->top+1)%4;
    s->data[s->top] = data;
}

void pop(stack *s) {
    if(s->top == s->bottom) {
        printf("�޸� ����÷�");
        return 1;
    }
    printf("������ �� : %d", s->data[(s->top)--]);
}

void print(stack *s) {
    printf("\n���� ���� : ");
    for(int i = s->bottom; i != s->top;){
        i = (i+1)%4;
        printf("%d ", s->data[i]);

    }
}

int main() {

    stack s;
    int num, data;
    init_stack(&s);

    printf("1�� : ����    2�� :   ����    3�� : ���α׷� ����");
    while(1) {
        printf("\n���ϴ� �ɼ��� �Է����ּ��� : ");
        scanf("%d", &num);

        if(num == 1) {
            printf("������ ���� �Է����ּ��� : ");
            scanf("%d", &data);
            push(&s, data);
            print(&s);
        }
        else if(num == 2) {
            pop(&s);
            print(&s);
        }
        else if(num == 3){
            printf("���α׷��� �����մϴ�. ");
            break;
        }
        else
            printf("�ٽ� �Է����ּ���");
    }
}
