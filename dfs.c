#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Define a structure for the adjacency list node
typedef struct Node {
    int vertex;
    struct Node* next;
} Node;

// Define a structure for the adjacency list
typedef struct Graph {
    int numVertices;
    Node** adjLists;
    bool* visited;
} Graph;

// Function to create a new node
Node* createNode(int v) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

// Function to create a graph with 'V' vertices
Graph* createGraph(int vertices) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->numVertices = vertices;

    graph->adjLists = (Node**)malloc(vertices * sizeof(Node*));
    graph->visited = (bool*)malloc(vertices * sizeof(bool));

    for (int i = 0; i < vertices; i++) {
        graph->adjLists[i] = NULL;
        graph->visited[i] = false;
    }

    return graph;
}

// Function to add an edge to the graph
void addEdge(Graph* graph, int src, int dest) {
    // Add edge from src to dest
    Node* newNode = createNode(dest);
    newNode->next = graph->adjLists[src];
    graph->adjLists[src] = newNode;
}

// DFS algorithm
void DFS(Graph* graph, int vertex) {
    graph->visited[vertex] = true;
    printf("%d ", vertex);

    Node* temp = graph->adjLists[vertex];

    while (temp) {
        int connectedVertex = temp->vertex;

        if (!graph->visited[connectedVertex]) {
            DFS(graph, connectedVertex);
        }
        temp = temp->next;
    }
}

int main() {
    int vertices = 8;
    Graph* graph = createGraph(vertices);

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

    printf("Depth First Traversal for the graph is:\n");
    DFS(graph, 0);

    return 0;
}
