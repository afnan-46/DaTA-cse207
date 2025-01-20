#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Structure to represent a node in the adjacency list
struct Node {
    int vertex;
    struct Node* next;
};

// Structure to represent a graph
struct Graph {
    int numVertices;
    struct Node** adjLists; // Array of adjacency lists
    bool* visited;          // Array to keep track of visited nodes
};

// Queue structure for BFS
struct Queue {
    int* items;
    int front;
    int rear;
    int size;
};

// Function prototypes
struct Node* createNode(int);
struct Graph* createGraph(int);
struct Queue* createQueue(int);
void enqueue(struct Queue*, int);
int dequeue(struct Queue*);
bool isQueueEmpty(struct Queue*);
void addEdge(struct Graph*, int, int);
void BFS(struct Graph*, int);

int main() {
    struct Graph* graph = createGraph(10);

    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 0, 3);
    addEdge(graph, 1, 3);
    addEdge(graph, 2, 4);
    addEdge(graph, 3, 5);
    addEdge(graph, 3, 6);
    addEdge(graph, 4, 7);
    addEdge(graph, 4, 5);
    addEdge(graph, 5, 2);
    addEdge(graph, 6, 5);
    addEdge(graph, 7, 5);
    addEdge(graph, 7, 8);

    printf("Breadth First Traversal for the graph is:\n");
    BFS(graph, 2);

    return 0;
}

// Function to create a new node
struct Node* createNode(int v) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

// Function to create a graph with `numVertices`
struct Graph* createGraph(int numVertices) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->numVertices = numVertices;

    graph->adjLists = (struct Node**)malloc(numVertices * sizeof(struct Node*));
    graph->visited = (bool*)malloc(numVertices * sizeof(bool));

    for (int i = 0; i < numVertices; i++) {
        graph->adjLists[i] = NULL;
        graph->visited[i] = false;
    }

    return graph;
}

// Function to add an edge to the graph
void addEdge(struct Graph* graph, int src, int dest) {
    struct Node* newNode = createNode(dest);
    newNode->next = graph->adjLists[src];
    graph->adjLists[src] = newNode;
}

// Function to create a queue
struct Queue* createQueue(int size) {
    struct Queue* q = (struct Queue*)malloc(sizeof(struct Queue));
    q->items = (int*)malloc(size * sizeof(int));
    q->front = -1;
    q->rear = -1;
    q->size = size;
    return q;
}

// Function to check if the queue is empty
bool isQueueEmpty(struct Queue* q) {
    return q->front == -1;
}

// Function to enqueue an element
void enqueue(struct Queue* q, int value) {
    if (q->rear == q->size - 1) {
        return; // Queue is full
    } else {
        if (q->front == -1) {
            q->front = 0;
        }
        q->rear++;
        q->items[q->rear] = value;
    }
}

// Function to dequeue an element
int dequeue(struct Queue* q) {
    int item;
    if (isQueueEmpty(q)) {
        return -1; // Queue is empty
    } else {
        item = q->items[q->front];
        q->front++;
        if (q->front > q->rear) {
            q->front = q->rear = -1; // Reset the queue
        }
        return item;
    }
}

// Function for BFS traversal
void BFS(struct Graph* graph, int startVertex) {
    struct Queue* queue = createQueue(graph->numVertices);

    graph->visited[startVertex] = true;
    enqueue(queue, startVertex);

    while (!isQueueEmpty(queue)) {
        int currentVertex = dequeue(queue);
        printf("%d ", currentVertex);

        struct Node* temp = graph->adjLists[currentVertex];

        while (temp) {
            int adjVertex = temp->vertex;

            if (!graph->visited[adjVertex]) {
                graph->visited[adjVertex] = true;
                enqueue(queue, adjVertex);
            }
            temp = temp->next;
        }
    }

    free(queue->items);
    free(queue);
}
