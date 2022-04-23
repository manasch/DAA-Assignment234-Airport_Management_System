#include "header.h"
#include <stdlib.h>
#include <limits.h>

// ANY STATIC FUNCTIONS ARE UP HERE

// dfs q1 helper function
static void q1_helper(int v, int n, int *visited, const connection_t (*conn)[n])
{
    visited[v] = 1;
    for (int i = 0; i < n; i++)
    {
        if (v != i && conn[v][i].distance != INT_MAX && visited[i] == 0)
            q1_helper(i, n, visited, conn);
    }
}

// YOUR SOLUTIONS BELOW

int q1(int n, const connection_t connections[n][n])
{
    int *visited = (int *) malloc(n * sizeof(int));

    /*
        Iterating through each vertex to see if it can visit every other vertex
        Performing a DFS for each vertex will tell whether every other vertex
        can be reached or not.
    */
    for (int v = 0; v < n; v++)
    {
        // Initializing the visited array everytime
        for (int i = 0; i < n; i++)
            visited[i] = 0;
        
        q1_helper(v, n, visited, connections);
        // Checking if all the vertices have been visited
        for (int i = 0; i < n; i++)
        {
            if (visited[i] == 0)
                return 0;
        }
    }

    free(visited);
    return 1;
}

int q2(const airport_t *src, const airport_t *dest, int n, int k,
       const connection_t connections[n][n])
{
    return 0;
}

int q3(const airport_t *src, int n, const connection_t connections[n][n])
{
    return 0;
}

void q4(int n, int (*predicate_func)(const airport_t *, const airport_t *),
        airport_t airport_list[n])
{

}

pair_t q5(int n, airport_t airports[n])
{
    pair_t ans = {-1, -1};
    return ans;
}

int q6(int n, int amount, const int entry_fee[n])
{
    return 0;
}

void q7(int n, const char *pat, int contains[n], const airport_t airports[n])
{

}

int q8(int n, int trip_order[n - 1], const connection_t connections[n][n])
{
    return 0;
}

int q9(int n, pair_t edges[n - 1], const connection_t connections[n][n])
{
    return 0;
}

void q10(int n, int k, const airport_t *src,
         const connection_t connections[n][n], const int destinations[k],
         int costs[k])
{

}

// END
