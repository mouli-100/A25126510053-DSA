#include <stdio.h>
#define MAX 20
int adj[MAX][MAX];
int visited[MAX];
int n;
void bfs(int start)
{
    int queue[MAX], front = 0, rear = 0;
    visited[start] = 1;
    queue[rear++] = start;
    printf("Visit order (BFS) : ");
    while (front < rear) {
        int v = queue[front++];
        printf("%d ", v);
        for (int i = 0; i < n; i++) {
            if (adj[v][i] == 1 && !visited[i]) {
                visited[i] = 1;
                queue[rear++] = i;
            }
        }
    }
    printf("\n");
}
int main()
{
    int start;
    printf("Enter number of locations (vertices) : ");
    scanf("%d", &n);
    printf("Enter the adjacency matrix (%d x %d):\n", n, n);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &adj[i][j]);
    printf("Enter starting vertex (0 to %d) : ", n - 1);
    scanf("%d", &start);
    if (start < 0 || start >= n) {
        printf("Invalid starting vertex.\n");
        return 0;
    }
    for (int i = 0; i < n; i++)
        visited[i] = 0;
    bfs(start);
    int unreachable = 0;
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            if (!unreachable)
                printf("Not reachable from %d : ", start);
            printf("%d ", i);
            unreachable = 1;
        }
    }
    if (unreachable)
        printf("\nThe graph is partially connected.\n");
    else
        printf("All vertices were visited. The graph is connected.\n");                       
    return 0;
}
