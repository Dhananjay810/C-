#include<stdio.h>
#include<stdlib.h>

struct cirque {
    int size;
    int front;
    int rear;
    int *a;
};

int siize(struct cirque *cq) {
    int s = cq->size - cq->front + cq->rear + 1;
    s = s % cq->size;
    return s;
}

int isEmpty(struct cirque *cq) {
    if (siize(cq) == 0) {
        return 1;
    } else if (cq->front == cq->rear && (cq->rear == 0 || cq->rear == -1)) {
        return 1;
    } else {
        return 0;
    }
}

int isFull(struct cirque *cq) {
    if (((cq->size) - (cq->front) + (cq->rear) + 1) / (cq->size) == 1 &&
        ((cq->size) - (cq->front) + (cq->rear) + 1) % (cq->size) == 0) {
        return 1;
    } else {
        return 0;
    }
}

void create(struct cirque *cq, int capi) {
    cq->size = capi;
    cq->front = -1;
    cq->rear = -1;
    cq->a = (int *)malloc(capi * sizeof(int));
}

void enqueue(struct cirque *cq, int data) {
    if (isFull(cq) == 1) {
        printf("queue is full\n");
    } else {
        if (isEmpty(cq) == 1) {
            cq->front = 0;
        }
        cq->rear = (cq->rear + 1) % cq->size;
        cq->a[cq->rear] = data;
        printf("value is entered\n");
    }
}

void dequeue(struct cirque *cq) {
    if (isEmpty(cq) == 1) {
        printf("queue is empty\n");
    } else {
        printf("%d is deleted\n", cq->a[cq->front]);
        if (cq->front == cq->rear) {
            cq->front = -1;
            cq->rear = -1;
        } else {
            cq->front = (cq->front + 1) % cq->size;
        }
    }
}

void f(struct cirque *cq) {
    if (isEmpty(cq) == 1) {
        printf("Queue is empty\n");
    } else {
        printf("%d is at front position\n", cq->a[cq->front]);
    }
}

void r(struct cirque *cq) {
    if (isEmpty(cq) == 1) {
        printf("Queue is empty\n");
    } else {
        printf("%d is at rear position\n", cq->a[cq->rear]);
    }
}

int main() {
    struct cirque *cq;
    cq = (struct cirque *)malloc(sizeof(struct cirque));
    printf("Hey, there lets do something in queue\n");
    printf("Press '#' for creating queue\n");
    printf("Press '*' for store value\n");
    printf("Press '@' for deletion\n");
    printf("Press '$' for checking is empty\n");
    printf("Press '&' for checking is full\n");
    printf("Press '!' for print size of queue\n");
    printf("Press '^' for print front element\n");
    printf("Press '(' for print rear element\n");
    printf("Unfortunately, we have to create queue first, so '#' pressed automatically\n");
    int s;
    printf("Enter size: ");
    scanf("%d", &s);
    printf("\n");
    create(cq, s);
    printf("Hence, queue is created\n");
    printf("Now, do something else\n");
    int cc = 6;
    while (cc > 0) {
        char ch;
        printf("Enter any char from above: ");
        scanf(" %c", &ch); // Notice the space before %c to consume the newline character
        switch (ch) {
            case '*':
                int n;
                printf("Enter value you want to store: ");
                scanf("%d", &n);
                enqueue(cq, n);
                printf("\n");
                break;
            case '@':
                dequeue(cq);
                printf("\n");
                break;
            case '$':
                printf("%d\n", isEmpty(cq));
                break;
            case '&':
                printf("%d\n", isFull(cq));
                break;
            case '!':
                printf("%d\n", siize(cq));
                break;
            case '^':
                f(cq);
                printf("\n");
                break;
            case '(':
                r(cq);
                printf("\n");
                break;
        }
        cc--;
    }
    free(cq->a);
    free(cq);
    return 0;
}
