#include <stdio.h>
#define MAX 20
#define INF 9999

int n;
int cost[MAX][MAX];
int dist[MAX];
int visited[MAX];

// Return the unvisited vertex with the smallest distance
int minDistance()
{
    int min = INF, index = -1;
    for (int i = 0; i < n; i++) {
        if (!visited[i] && dist[i] < min) {
            min = dist[i];
            index = i;
        }
    }
    return index;
}

void dijkstra(int source)
{
    for (int i = 0; i < n; i++) {
        dist[i] = INF;
        visited[i] = 0;
    }
    dist[source] = 0;

    for (int count = 0; count < n - 1; count++) {
        int u = minDistance();
        if (u == -1)
            break;
        visited[u] = 1;

        for (int v = 0; v < n; v++) {
            if (!visited[v] && cost[u][v] != 0 && dist[u] + cost[u][v] < dist[v])
                dist[v] = dist[u] + cost[u][v];
        }
    }
}

int main()
{
    int source;

    printf("Enter number of vertices (cities) : ");
    scanf("%d", &n);

    printf("Enter the weighted adjacency matrix (0 = no road):\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &cost[i][j]);

    printf("Enter source vertex (0 to %d) : ", n - 1);
    scanf("%d", &source);

    if (source < 0 || source >= n) {
        printf("Invalid source vertex.\n");
        return 0;
    }

    dijkstra(source);

    printf("\nShortest distance from source %d :\n", source);
    printf("Destination\tDistance\n");
    for (int i = 0; i < n; i++) {
        if (dist[i] == INF)
            printf("%d\t\tNot reachable\n", i);
        else
            printf("%d\t\t%d\n", i, dist[i]);
    }

    /* Test input (n = 5, source = 0):
       0 10 0 30 100
       10 0 50 0 0
       0 50 0 20 10
       30 0 20 0 60
       100 0 10 60 0
       Expected: 0->0, 1->10, 2->50, 3->30, 4->60                 */
    return 0;
}
