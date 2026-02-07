#include <stdio.h>
#define MAX 5

typedef struct {
    int arr[MAX];
    int front, rear;
} DEQUE;

void init(DEQUE *dq) {
    dq->front = -1;
    dq->rear = -1;
}

/* Insert at front */
void insertFront(DEQUE *dq, int x) {
    if ((dq->front == 0 && dq->rear == MAX-1) || (dq->front == dq->rear + 1)) {
        printf("\nDeque Overflow");
        return;
    }

    if (dq->front == -1) {
        dq->front = dq->rear = 0;
    } else if (dq->front == 0) {
        dq->front = MAX - 1;
    } else {
        dq->front--;
    }

    dq->arr[dq->front] = x;
    printf("\nInserted %d at front", x);
}

/* Insert at rear */
void insertRear(DEQUE *dq, int x) {
    if ((dq->front == 0 && dq->rear == MAX-1) || (dq->front == dq->rear + 1)) {
        printf("\nDeque Overflow");
        return;
    }

    if (dq->front == -1) {
        dq->front = dq->rear = 0;
    } else if (dq->rear == MAX - 1) {
        dq->rear = 0;
    } else {
        dq->rear++;
    }

    dq->arr[dq->rear] = x;
    printf("\nInserted %d at rear", x);
}

/* Delete from front */
void deleteFront(DEQUE *dq) {
    if (dq->front == -1) {
        printf("\nDeque Underflow");
        return;
    }

    printf("\nDeleted %d from front", dq->arr[dq->front]);

    if (dq->front == dq->rear) {
        dq->front = dq->rear = -1;
    } else if (dq->front == MAX - 1) {
        dq->front = 0;
    } else {
        dq->front++;
    }
}

/* Delete from rear */
void deleteRear(DEQUE *dq) {
    if (dq->front == -1) {
        printf("\nDeque Underflow");
        return;
    }

    printf("\nDeleted %d from rear", dq->arr[dq->rear]);

    if (dq->front == dq->rear) {
        dq->front = dq->rear = -1;
    } else if (dq->rear == 0) {
        dq->rear = MAX - 1;
    } else {
        dq->rear--;
    }
}

/* Display deque */
void display(DEQUE *dq) {
    if (dq->front == -1) {
        printf("\nDeque is Empty");
        return;
    }

    printf("\nDeque Elements: ");
    int i = dq->front;
    while (1) {
        printf("%d ", dq->arr[i]);
        if (i == dq->rear)
            break;
        i = (i + 1) % MAX;
    }
}

/* Main */
int main() {
    DEQUE dq;
    init(&dq);

    insertRear(&dq, 10);
    insertRear(&dq, 20);
    insertFront(&dq, 5);
    display(&dq);

    deleteFront(&dq);
    deleteRear(&dq);
    display(&dq);

    return 0;
}
