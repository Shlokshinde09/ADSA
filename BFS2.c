#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int queue[MAX];
int front = -1, rear = -1;
int visited[MAX];

// Function to enqueue an element
void enqueue(int vertex) {
    if (rear == MAX - 1) {
        printf("Queue is full. Cannot enqueue vertex %d\n", vertex);
        return;
    }
    if (front == -1)
        front = 0;
    queue[++rear] = vertex;
}

// Function to dequeue an element
int dequeue() {
    if (front == -1 || front > rear)
        return -1;

    int vertex = queue[front++];
    if (front > rear) {
        front = rear = -1;
    }
    return vertex;
}

// BFS traversal function
void BFS(int graph[MAX][MAX], int vertices, int start_vertex) {
    for (int i = 0; i < vertices; i++) {
        visited[i] = 0;
    }

    enqueue(start_vertex);
    visited[start_vertex] = 1;

    printf("BFS Traversal starting from vertex %d: ", start_vertex);
    while (front != -1) {
        int current_vertex = dequeue();
        printf("%d ", current_vertex);

        for (int i = 0; i < vertices; i++) {
            if (graph[current_vertex][i] == 1 && !visited[i]) {
                enqueue(i);
                visited[i] = 1;
            }
        }
    }
    printf("\n");
}

// Main function
int main() {
    int vertices, start;
    int graph[MAX][MAX];

    printf("Enter the number of vertices (max %d): ", MAX);
    scanf("%d", &vertices);

    if (vertices <= 0 || vertices > MAX) {
        printf("Invalid number of vertices. Must be between 1 and %d.\n", MAX);
        return 1;
    }

    printf("Enter the adjacency matrix (%d x %d):\n", vertices, vertices);
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            scanf("%d", &graph[i][j]);
            if (graph[i][j] != 0 && graph[i][j] != 1) {
                printf("Invalid entry at (%d, %d). Only 0 or 1 allowed.\n", i, j);
                return 1;
            }
        }
    }

    printf("Enter the starting vertex (0 to %d): ", vertices - 1);
    scanf("%d", &start);
    if (start < 0 || start >= vertices) {
        printf("Invalid starting vertex. Must be between 0 and %d.\n", vertices - 1);
        return 1;
    }

    BFS(graph, vertices, start);

    return 0;
}
