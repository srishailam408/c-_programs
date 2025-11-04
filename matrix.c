#include <stdio.h>
#include <stdlib.h>

#define MAX 100
#define INF 1000000000

// 8 directions: up, down, left, right, and diagonals
int rowDir[] = {-1, 1, 0, 0, -1, -1, 1, 1};
int colDir[] = {0, 0, -1, 1, -1, 1, -1, 1};

int main() {
    int grid[MAX][MAX];
    int dist[MAX][MAX], visited[MAX][MAX];
    int prevR[MAX][MAX], prevC[MAX][MAX];
    int rows, cols, sr, sc, dr, dc;

    printf("Enter number of rows and columns: ");
    scanf("%d %d", &rows, &cols);

    printf("Enter grid values (movement cost for each cell):\n");
    for (int i=0;i<rows;i++)
        for (int j=0;j<cols;j++)
            scanf("%d", &grid[i][j]);

    printf("Enter start row and column: ");
    scanf("%d %d", &sr, &sc);
    printf("Enter destination row and column: ");
    scanf("%d %d", &dr, &dc);

    // initialize
    for (int i=0;i<rows;i++)
        for (int j=0;j<cols;j++) {
            dist[i][j] = INF;
            visited[i][j] = 0;
            prevR[i][j] = prevC[i][j] = -1;
        }

    //dist[sr][sc] = 0;
    dist[sr][sc]=grid[sr][sc];

    for (int step = 0; step < rows*cols; ++step) {
        int min = INF, ur=-1, uc=-1;
        for (int i=0;i<rows;i++)
            for (int j=0;j<cols;j++)
                if (!visited[i][j] && dist[i][j] < min) {
                    min = dist[i][j];
                    ur=i; uc=j;
                }
        if (ur==-1) break;
        if (ur==dr && uc==dc) break;
        visited[ur][uc] = 1;

        for (int k=0;k<8;k++) {
            int vr = ur + rowDir[k];
            int vc = uc + colDir[k];
            if (vr>=0 && vr<rows && vc>=0 && vc<cols && !visited[vr][vc]) {
                int newCost = dist[ur][uc] + grid[vr][vc];
                if (newCost < dist[vr][vc]) {
                    dist[vr][vc] = newCost;
                    prevR[vr][vc] = ur;
                    prevC[vr][vc] = uc;
                }
            }
        }
    }

    if (dist[dr][dc] == INF) {
        printf("No path exists!\n");
        return 0;
    }

    // reconstruct path
    int pathR[MAX*MAX], pathC[MAX*MAX], len=0;
    for (int r=dr,c=dc; r!=-1 && c!=-1; ) {
        pathR[len]=r; pathC[len]=c; len++;
        int pr=prevR[r][c], pc=prevC[r][c];
        r=pr; c=pc;
    }

    printf("Minimum cost path = %d\nPath: ", dist[dr][dc]);
    for (int i=len-1;i>=0;i--){
        printf("(%d,%d)", pathR[i], pathC[i]);
        if (i) printf(" -> ");
    }
    printf("\n");
    return 0;
}

