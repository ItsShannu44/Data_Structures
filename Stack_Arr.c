#include <stdio.h>

#define MAX 5

typedef struct {
    int arr[MAX];
    int top;
} STACK;

void push(STACK *s, int element)
{
    if (s->top == MAX - 1)
    {
        printf("\nStack Overflow! Cannot push %d", element);
        return;
    }
    s->arr[++(s->top)] = element;
    printf("\nPushed: %d", element);
}

void pop(STACK *s)
{
    if (s->top == -1)
    {
        printf("\nStack Underflow!");
        return;
    }
    printf("\nPopped: %d", s->arr[s->top]);
    s->top--;
}

void peek(STACK *s)
{
    if (s->top == -1)
    {
        printf("\nStack is Empty!");
        return;
    }
    printf("\nTop Element: %d", s->arr[s->top]);
}

void display(STACK *s)
{
    if (s->top == -1)
    {
        printf("\nStack is Empty!");
        return;
    }

    printf("\nStack Elements: ");
    for (int i = s->top; i >= 0; i--)
    {
        printf("%d ", s->arr[i]);
    }
}

int main()
{
    STACK s;
    s.top = -1;

    push(&s, 10);
    push(&s, 20);
    push(&s, 30);
    display(&s);

    pop(&s);
    display(&s);

    peek(&s);

    push(&s, 40);
    push(&s, 50);
    push(&s, 60);   
    display(&s);

    return 0;
}
