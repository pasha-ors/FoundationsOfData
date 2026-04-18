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

    queue->data = (int*)malloc(sizeof(int) * capacity);
    queue->capacity = capacity;
    queue->front = 0;
    queue->rear = -1;
    queue->size = 0;

    return queue;
}

void freeQueue(Queue* q) {
    free(q->data);
    free(q);
}

int isEmpty(Queue* q) {
    return q->size == 0;
}

int isFull(Queue* q) {
    return q->size == q->capacity;
}

void enqueue(Queue* q, int value) {
    if(isFull(q)){
        q->capacity *= 2;

        int *tmp = (int*)malloc(sizeof(int) * q->capacity);

        for (int i = 0; i < q->size; i++) {
            tmp[i] = q->data[(q->front + i) % (q->capacity / 2)];
        }

        free(q->data);

        q->data = tmp;

        q->front = 0;
        q->rear = q->size - 1;
    }

    q->rear = (q->rear + 1) % q->capacity;
    q->data[q->rear] = value;
    q->size++;
}

int dequeue(Queue* q) {

    if (isEmpty(q)) {
        printf("Queue underflow\n");
        return -1;
    }

    int value = q->data[q->front];

    q->front = (q->front + 1) % q->capacity;
    q->size--;

    return value;
}

int peek(Queue* q) {
    if (q->size == 0) return -1;
    return q->data[q->front];
}

