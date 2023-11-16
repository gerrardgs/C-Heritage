#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int destination;
    struct Node *next;
} Node;

typedef struct Graph
{
    int numVertices;
    Node** adjList;
} Graph;

Graph* createGraph(int numVertices)
{
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->numVertices = numVertices;
    graph->adjList = (Node**)malloc(numVertices * sizeof(Node*));
    for (int i = 0; i < numVertices; i++)
    {
        graph->adjList[i] = NULL;
    }
    return graph;
}

Node* createNode(int dest)
{
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->destination = dest;
    newNode->next = NULL;
    return newNode;
}

void addEdge(Graph* graph, int source, int destination)
{
    Node *newNode = createNode(destination);
    newNode->next = graph->adjList[source];
    graph->adjList[source] = newNode;
    newNode = createNode(source);
    newNode->next = graph->adjList[destination];
    graph->adjList[destination] = newNode;
}

void printGraph(Graph* graph)
{
    for (int i = 0; i < graph->numVertices; i++)
    {
        Node *temp = graph->adjList[i];
        printf("List yang bersebelahan dengan %d:\n", i);
        while(temp)
        {
            printf("%d -> ", temp->destination);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}

void destroyGraph(Graph* graph)
{
    if (graph)
    {
        if (graph->adjList)
        {
            for (int i = 0; i < graph->numVertices; ++i)
            {
                Node* temp = graph->adjList[i];
                while(temp)
                {
                    Node* prev = temp;
                    temp = temp->next;
                    free(prev);
                }
            }
            free(graph->adjList);
        }
        free(graph);
    }
}

int main()
{
    Graph* graph = createGraph(5);
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 4);
    addEdge(graph, 1, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 1, 4);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 4);
    printGraph(graph);
    destroyGraph(graph);
    return 0;
}
