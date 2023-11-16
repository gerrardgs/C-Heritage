// NO. 1

// DECLARE LIBRARY
#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100 // declare ukuran maks array 

typedef struct Graph{ // declare struktur Graph beranggotakan vertices array, numvertices, numneighbors
    int vertices[MAX_VERTICES];
    int numVertices;
    int numNeighbors;
}Graph;

Graph createGraph(int numVertices, int numNeighbors){ // declare fungsi creategraph beranggotakan numvertices, numneighbors
    Graph graph; // inisialisasi objek graph baru
    graph.numVertices = numVertices; // menerima argumen numvertices
    graph.numNeighbors = numNeighbors; // menerima argumen numneighbors
    for(int i = 0; i < numVertices; i++){ // perulangan untuk melihat kondisi numvertices dalam situasi tertentu dan dengan mengembalikan objek graph terinisialisasi 
        graph.vertices[i] = 0; // value vertices ditentukan dari 0
    }
    return graph;
}

void addEdge(Graph *graph, int source, int destination){ // declare fungsi addedge beranggotakan objek graph baru, source, dan destination
    graph->vertices[source]++; // menambahkan edge antara 2 vertices kedalam graph
    graph->vertices[destination]++; // menerima 3 argumen yaitu pointer ke objek graph, source, destination yang masing2 nilai vertice source dan destination ditambahkan dengan 1    
}

void checkWibuNolep(Graph *graph){ // declare fungsi checkwibunolep beranggotakan objek graph baru
    for(int i = 0; i < graph->numVertices; i++){ // perulangan dan kondisi apakah vertices dalam graph termasuk kategori wibu nolep atau tidak.
        if(graph->vertices[i] < graph->numNeighbors){ // fungsi beriterasi lewat semua vertices dalam pointer ke objek graph 
            printf("Vertex %d adalah wibu nolep\n", i); // jika jumlah tetangga vertices kurang dari numneighbors, maka akan tampil output dengan format berikut ke interface user
        }
    }
}

int main(){ // declare fungsi main
    int numVertices, numNeighbors; // beranggotakan numvertices, numneighbors
    int source, destination; // beranggotakan source, destination
    scanf("%d %d", &numVertices, &numNeighbors); // membaca dan menyimpan jumlah vertices dan neighbors yang telah diinputkan user
    Graph graph = createGraph(numVertices, numNeighbors); // declare objek graph baru dengan fungsi creategraph beranggotakan numvertices dan numneighbors
    while(1){ // perulangan untuk membaca dan menyimpan edge graph source dan destination dari inputan user 
        scanf("%d %d", &source, &destination);
        if(source == -1 && destination == -1){
            break; // perulangan berhenti apabila input -1 -1 ditemukan
        }
        addEdge(&graph, source, destination);
    }
    checkWibuNolep(&graph); // panggil fungsi checkwibunolep untuk memeriksa vertices wibunolep dalam graph
    return 0; // program selesai
}
