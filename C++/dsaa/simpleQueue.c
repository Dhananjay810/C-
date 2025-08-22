#include <stdio.h>
#include <stdlib.h>

struct queue {
    int front;
    int rear;
    int capacity;
    int *arr;
};

void createQueue(struct queue *q, int cap) {
    q->capacity = cap;
    q->front = -1;
    q->rear = -1;
    q->arr = malloc(cap * sizeof(int));
}

int isFull(struct queue *q) {
    return (q->rear == q->capacity - 1);
}

int isEmpty(struct queue *q) {
    return (q->front == -1 || q->front > q->rear);
}

void enqueue(struct queue *q, int value) {
    if (isFull(q)) {
        printf("Queue is full\n");
    } else {
        if (isEmpty(q)) {
            q->front = 0;
        }
        q->rear++;
        q->arr[q->rear] = value;
        printf("%d is enqueued\n", value);
    }
}

void dequeue(struct queue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty\n");
    } else {
        printf("%d is dequeued\n", q->arr[q->front]);
        q->front++;
    }
}

void size(struct queue *q) {
    printf("Size of the queue is %d\n", q->rear - q->front + 1);
}

void peek(struct queue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty\n");
    } else {
        printf("Front element of the queue is %d\n", q->arr[q->front]);
    }
}

void rear(struct queue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty\n");
    } else {
        printf("Rear element of the queue is %d\n", q->arr[q->rear]);
    }
}

int main() {
    struct queue *q;
    q = (struct queue *)malloc(sizeof(struct queue));
    printf("Hey, let's do some operations on the queue\n");
    printf("Enter '#' to create a queue\n");
    printf("Enter '*' to enqueue\n");
    printf("Enter '@' to dequeue\n");
    printf("Enter '$' to check if the queue is empty\n");
    printf("Enter '!' to print the size of the queue\n");
    printf("Enter '^' to print the front element of the queue\n");
    printf("Enter '(' to print the rear element of the queue\n");

    printf("Unfortunately, we have to create the queue first, so '#' is pressed automatically\n");
    int s;
    printf("Enter the size of the queue: ");
    scanf("%d", &s);
    createQueue(q, s);
    printf("Queue created successfully\n");

    char ch;
    printf("Enter any character from the menu: ");
    scanf(" %c", &ch); // Note the space before %c to consume newline characters

    while (ch != 'q') { // Let's use 'q' to quit the loop
        switch (ch) {
            case '*':
                int p;
                printf("Enter the value you want to enqueue: ");
                scanf("%d", &p);
                enqueue(q, p);
                break;
            case '@':
                dequeue(q);
                break;
            case '$':
                printf("%s\n", isEmpty(q) ? "Queue is empty" : "Queue is not empty");
                break;
            case '!':
                size(q);
                break;
            case '^':
                peek(q);
                break;
            case '(':
                rear(q);
                break;
            default:
                printf("Invalid input\n");
        }
        printf("Enter any character from the menu (or 'q' to quit): ");
        scanf(" %c", &ch);
    }

    // Free allocated memory before exiting
    free(q->arr);
    free(q);

    return 0;
}
