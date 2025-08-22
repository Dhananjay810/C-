#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SIZE 100

// Queue structure for BFS
struct Queue {
    int items[MAX_SIZE];
    int front;
    int rear;
};

// Function to create a queue
struct Queue* createQueue() {
    struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
    queue->front = -1;
    queue->rear = -1;
    return queue;
}

// Function to check if the queue is empty
bool isEmpty(struct Queue* queue) {
    return (queue->rear == -1);
}

// Function to add an item to the queue
void enqueue(struct Queue* queue, int value) {
    if (queue->rear == MAX_SIZE - 1)
        printf("Queue is full\n");
    else {
        if (queue->front == -1)
            queue->front = 0;
        queue->rear++;
        queue->items[queue->rear] = value;
    }
}

// Function to remove an item from the queue
int dequeue(struct Queue* queue) {
    int item;
    if (isEmpty(queue)) {
        printf("Queue is empty\n");
        item = -1;
    } else {
        item = queue->items[queue->front];
        queue->front++;
        if (queue->front > queue->rear) {
            queue->front = queue->rear = -1;
        }
    }
    return item;
}

// Function to perform Breadth-First Search
void BFS(int adjMatrix[][MAX_SIZE], int startVertex, int n) {
    struct Queue* queue = createQueue();
    bool visited[n];
    for (int i = 0; i < n; i++)
        visited[i] = false;

    visited[startVertex] = true;
    enqueue(queue, startVertex);

    printf("Breadth First Search starting from vertex %d: ", startVertex);

    while (!isEmpty(queue)) {
        int currentVertex = dequeue(queue);
        printf("%d ", currentVertex);
        
        for (int i = 0; i < n; i++) {
            if (adjMatrix[currentVertex][i] == 1 && !visited[i]) {
                visited[i] = true;
                enqueue(queue, i);
            }
        }
    }
    printf("\n");
}

// Driver program to test above functions
int main() {
    int n = 6; // Number of vertices
    int adjMatrix[MAX_SIZE][MAX_SIZE] = {
        {0, 0, 1, 1, 0, 0},
        {1, 0, 0, 1, 1, 0},
        {1, 1, 0, 0, 1, 1},
        {0, 1, 0, 0, 1, 0},
        {0, 1, 1, 0, 0, 0},
        {0, 0, 1, 0, 0, 0}
    };

    int startVertex = 0; // Starting vertex for BFS

    BFS(adjMatrix, startVertex, n);

    return 0;
}
