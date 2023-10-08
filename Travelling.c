#include <stdio.h>
#include <limits.h>

#define V 4 // Number of vertices in the graph

int graph[V][V] = {
    {0, 10, 15, 20},
    {10, 0, 35, 25},
    {15, 35, 0, 30},
    {20, 25, 30, 0}
};

int visited[V];

int findNearestNeighbor(int city) {
    int nearestNeighbor = INT_MAX;
    int minDistance = INT_MAX;
    for (int i = 0; i < V; i++) {
        if (graph[city][i] != 0 && !visited[i] && graph[city][i] < minDistance) {
            minDistance = graph[city][i];
            nearestNeighbor = i;
        }
    }
    return nearestNeighbor;
}

void tsp(int start) {
    visited[start] = 1;
    printf("%d ", start);
    int nextCity = findNearestNeighbor(start);
    while (nextCity != INT_MAX) {
        printf("-> %d ", nextCity);
        visited[nextCity] = 1;
        nextCity = findNearestNeighbor(nextCity);
    }
    printf("-> %d\n", start);
}

int main() {
    // Mark all the cities as not visited
    for (int i = 0; i < V; i++) {
        visited[i] = 0;
    }

    int startingCity = 0; // Starting city for the salesman

    printf("Approximate TSP Solution:\n");
    tsp(startingCity);

    return 0;
}
