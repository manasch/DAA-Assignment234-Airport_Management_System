#include "header.h"
#include <stdlib.h>
#include <limits.h>
#include <stdio.h>

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

static int q2_helper(const int src, const int dest, int n,
                     int count, const connection_t (*conn)[n], int *visited)
{
    visited[src] = 1;
    if (src == dest)
    {
        if (count >= 0)
            return 1;
        // When you have reached the destination but took more flights than required
        return 0;
    }

    for (int v = 0; v < n; v++)
    {
        if(src != v && conn[src][v].distance != INT_MAX && visited[v] == 0 && count >= 0)
        {
            count--;
            int res = q2_helper(v, dest, n, count, conn, visited);
            if (res)
                return res;
            
            /*
                Need to unmark this as the path failed
                now it needs to check the next edge
            */
            visited[v] = 0;
            count++;
        }
    }

    // When you can't reach the destination
    return 0;
}

static void q3_helper(const int src, const int dest, const int n, const connection_t (*conn)[n], int *visited, int count, int *res)
{
    visited[src] = 1;
    if (src == dest && count != 0)
    {
        *res = 1;
        return;
    }
    if (count == 0)
        visited[dest] = 0;
    
    count++;
    
    for (int v = 0; v < n; v++)
    {
        if (src != v && conn[src][v].distance != INT_MAX && visited[v] == 0)
        {
            q3_helper(v, dest, n, conn, visited, count, res);
        }
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
            {
                free(visited);
                return 0;
            }
        }
    }

    free(visited);
    return 1;
}

int q2(const airport_t *src, const airport_t *dest, int n, int k,
       const connection_t connections[n][n])
{
    if (src->num_id == dest->num_id)
        return 0;

    // Check the destination from source directly
    if (connections[src->num_id][dest->num_id].distance != INT_MAX)
    {
        k--;
        if (k >= 0)
            return 1;
    }

    int *visited = (int *) calloc(n, sizeof(int));
    int res = 0;
    
    res = q2_helper(src->num_id, dest->num_id, n, k, connections, visited);
    free(visited);

    return res;
}

int q3(const airport_t *src, int n, const connection_t connections[n][n])
{
    /*
        A DFS (or BFS) has to performed from for each edge node
        from the src node and see if it can reach back, if it can
        terminate the DFS and return 1, otherwise return 0
    */

    int *visited = (int *) calloc(n, sizeof(int));
    int count = 0;
    int res = 0;

    q3_helper(src->num_id, src->num_id, n, connections, visited, count, &res);
    free(visited);

    return res;
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
    /*
        We are given a sorted array with, hence we can use
        binary search to find whether the amount the traveller
        has is in the list or not
    */

    // if the amount is less than the least entry fee, they can't go to any airport
    if (amount < entry_fee[0])
        return 0;
    
    // if the amount is more than the costliest fee, then can go to any airport
    if (amount > entry_fee[n - 1])
        return n;
    
    int start = 0;
    int end = n - 1;
    int mid = (start + end) / 2;
    while (start <= end)
    {
        // The amount is in the middle of the search window
        if (entry_fee[mid] == amount)
            return mid + 1;
        if (entry_fee[mid] < amount)
            start = mid + 1;
        else
            end = mid - 1;
        mid = (end + start) / 2;
    }
    
    // The amount is in the middle of one of the entry fee pairs
    if (entry_fee[mid] < amount)
        return mid + 1;
    return mid - 1;
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
