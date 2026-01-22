#include <stdio.h>

int heap[50], size = 0;

void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

void upHeap(int i) {
    while (i > 1 && heap[i] > heap[i/2]) {
        swap(&heap[i], &heap[i/2]);
        i = i / 2;
    }
}

void insert(int val) {
    heap[++size] = val;
    upHeap(size);
}

void downHeap(int i) {
    int largest = i;
    int l = 2*i, r = 2*i + 1;

    if (l <= size && heap[l] > heap[largest])
        largest = l;
    if (r <= size && heap[r] > heap[largest])
        largest = r;

    if (largest != i) {
        swap(&heap[i], &heap[largest]);
        downHeap(largest);
    }
}
void deleteRoot() {
    heap[1] = heap[size--];
    downHeap(1);
}
void display() {
    for (int i = 1; i <= size; i++)
        printf("%d ", heap[i]);
}
int main() {
    insert(10);
    insert(30);
    insert(20);
    insert(5);

    printf("Heap: ");
    display();

    deleteRoot();
    printf("\nAfter deleting root: ");
    display();
   
    return 0;
}