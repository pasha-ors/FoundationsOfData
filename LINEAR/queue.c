#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *data;     
    int front;
    int rear;
    int size;        
    int capacity;   
} Queue;

Queue* createQueue(int capacity){

    Queue* queue = (Queue*)malloc(sizeof(Queue));
    if(!queue){
        return NULL;
    }

    queue->data = (int*)malloc(sizeof(int) * capacity);

    if(!queue->data){
        free(queue);
        return NULL;
    }


    queue->capacity = capacity;
    queue->front = 0;
    queue->rear = -1;
    queue->size = 0;

    return queue;
}

void freeQueue(Queue* q) {
    if (!q) return;
    free(q->data);
    free(q);
}

int isEmpty(Queue* q) {
    return q->size == 0;
}

int isFull(Queue* q) {
    return q->size == q->capacity;
}

int resizeQueue(Queue* q) {
    int oldCapacity = q->capacity;
    int newCapacity = oldCapacity * 2;

    int* tmp = malloc(sizeof(int) * newCapacity);
    if (!tmp) {
        return 0;
    }

    for (int i = 0; i < q->size; i++) {
        tmp[i] = q->data[(q->front + i) % oldCapacity];
    }

    free(q->data);
    q->data = tmp;
    q->capacity = newCapacity;
    q->front = 0;
    q->rear = q->size - 1;

    return 1;
}

int enqueue(Queue* q, int value) {
    if(isFull(q)){
        if (!resizeQueue(q)) {
            return 0;
        }
    }

    q->rear = (q->rear + 1) % q->capacity;
    q->data[q->rear] = value;
    q->size++;

    return 1;
}

int dequeue(Queue* q, int* result) {

    if (isEmpty(q)) {
        printf("Queue underflow\n");
        return -1;
    }

    *result = q->data[q->front];

    q->front = (q->front + 1) % q->capacity;
    q->size--;

    return 1;
}

int peek(Queue* q) {
    if (q->size == 0) return -1;
    return q->data[q->front];
}

void printQueue(Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty\n");
        return;
    }

    printf("Queue: ");

    for (int i = 0; i < q->size; i++) {
        int index = (q->front + i) % q->capacity;
        printf("%d ", q->data[index]);
    }

    printf("\n");
}

int main() {
    Queue* q = createQueue(4);
    if (!q) {
        printf("Failed to create queue\n");
        return 1;
    }

    enqueue(q, 10);
    enqueue(q, 20);
    enqueue(q, 30);
    enqueue(q, 40);

    printQueue(q);

    int value;

    dequeue(q, &value);
    printf("Dequeued: %d\n", value);

    dequeue(q, &value);
    printf("Dequeued: %d\n", value);

    printQueue(q);

    enqueue(q, 50);
    enqueue(q, 60);
    enqueue(q, 70);

    printQueue(q);

    if (peek(q) != -1) {
        printf("Front element: %d\n", peek(q));
    }

    while (!isEmpty(q)) {
        dequeue(q, &value);
        printf("Dequeued: %d\n", value);
    }

    printQueue(q);

    freeQueue(q);
    return 0;
}
