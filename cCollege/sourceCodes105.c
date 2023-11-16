#include <stdio.h>
#include <stdlib.h>

typedef struct Graph
{
    int numVertices;
    int **adjmatrix;
} Graph;

Graph *createGraph()
{
    Graph *graph = malloc(sizeof(Graph));
    graph->numVertices = 0;
    graph->adjmatrix = NULL;
    return graph;
}

void addVertex(Graph *graph)
{
    int newVertices = graph->numVertices + 1;
    graph->adjmatrix = realloc(graph->adjmatrix, newVertices * sizeof(int *));
    graph->adjmatrix[newVertices - 1] = malloc(newVertices * sizeof(int));
    for (int i = 0; i < newVertices; i++)
    {
        graph->adjmatrix[i] = realloc(graph->adjmatrix[i], newVertices * sizeof(int));
        graph->adjmatrix[i][newVertices - 1] = 0;
        graph->adjmatrix[newVertices - 1][i] = 0;
    }
    graph->numVertices++;
}

void addEdge(Graph *graph, int source, int destination)
{
    if (source >= 0 && source < graph->numVertices && destination >= 0 && destination < graph->numVertices)
    {
        graph->adjmatrix[source][destination] = 1;
        graph->adjmatrix[destination][source] = 1;
        }
        else
        {
            printf("Invalid Vertex.");
        }
    }
    
void printGraph (Graph *graph)
{
    for (int i = 0; i < graph->numVertices; i++)
    {
        for (int j = 0; j < graph->numVertices; j++)
        {
            printf("%d ", graph->adjmatrix[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

int main()
{
    Graph *graph = createGraph();
    printGraph(graph);
    int pilihan;
    do
    {
        printGraph(graph);
        printf("Menu\n1.Buat Vertex Baru\n2.Buat Edge\nMasukkan pilihan : ");
        scanf("%d", &pilihan);
        if (pilihan == 1)
        {
            addVertex(graph);
        }
        else if (pilihan == 2)
        {
            int source, destination;
            scanf("%d %d", &source, &destination);
            addEdge(graph, source, destination);
        }
        system("cls");
    }
    while (pilihan != 0);
}
