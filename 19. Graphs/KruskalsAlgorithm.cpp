#include <iostream>
using namespace std;

//no of vertex in graph
#define GRAPH_SIZE 7

//macro
#define I INT_MAX

//spanning tree array for selecting edges
int tree[2][GRAPH_SIZE - 1];

//function to join two sets
void Union(int u, int v, int set[])
{
    if (set[u] < set[v])
    {
        set[u] = set[u] + set[v];
        set[v] = u;
    }
    else
    {
        set[v] = set[u] + set[v];
        set[u] = v;
    }
}

//fucntion to find element in set
int find(int u, int set[])
{
    int x = u;

    while (set[x] > 0)
    {
        x = set[x];
    }
    return x;
}

//fucntion for calculating minimum cost
void minimumCost(int **edgesArr, int edgesCount)
{
    int included[GRAPH_SIZE + 1] = {0};
    int set[GRAPH_SIZE + 1];

    for (int i = 0; i <= GRAPH_SIZE; i++)
        set[i] = -1;

    int i = 0, u, v, k, min;

    while (i < GRAPH_SIZE)
    {
        min = I;

        for (int j = 1; j <= edgesCount; j++)
        {
            if (included[j] == 0 && edgesArr[2][j] < min)
            {
                u = edgesArr[0][j];
                v = edgesArr[1][j];
                min = edgesArr[2][j];
                k = j;
            }
        }

        if (find(u, set) != find(v, set))
        {
            tree[0][i] = u;
            tree[1][i] = v;
            Union(find(u, set), find(v, set), set);
            i++;
        }
        included[k] = 1;

        if (min == I)
            break;
    }
}

//function for krushkal's algorithm
int KruskalsAlgo(int cost[][GRAPH_SIZE + 1])
{
    int EDGES = 0;
    for (int i = 1; i <= GRAPH_SIZE; i++)
    {
        for (int j = 1; j < i; j++)
        {
            if (cost[i][j] != I)
                EDGES++;
        }
    }

    int **edge = (int **)malloc(3 * sizeof(int *));
    for (int i = 0; i < 3; i++)
    {
        edge[i] = (int *)malloc((EDGES + 1) * sizeof(int));
    }

    EDGES = 1;

    for (int i = 1; i <= GRAPH_SIZE; i++)
    {
        for (int j = 1; j < i; j++)
        {
            if (cost[i][j] != I)
            {
                edge[0][EDGES] = i;
                edge[1][EDGES] = j;
                edge[2][EDGES] = cost[i][j];
                EDGES++;
            }
        }
    }

    minimumCost(edge, EDGES - 1);

    int result = 0;
    for (int i = 0; i < GRAPH_SIZE - 1; i++)
        result += cost[tree[0][i]][tree[1][i]];

    return result;
}

int main()
{
    system("cls");

    //graphs always represented in square matrices with 1 based index
    //fisrt row and column are useless so marked with zeroes
    //no edges means infinite distance so marked with INT_MAX
    int cost[][GRAPH_SIZE + 1] =
        {
            /**/ I, I, I, I, I, I, I, I,
            /**/ I, I, 7, I, I, I, 5, I, //1
            /**/ I, 7, I, 9, I, I, I, 1, //2
            /**/ I, I, 9, I, 8, I, I, I, //3
            /**/ I, I, I, 8, I, 6, I, 4, //4
            /**/ I, I, I, I, 6, I, 2, 8, //5
            /**/ I, 5, I, I, I, 2, I, I, //6
            /**/ I, I, 1, I, 4, 8, I, I, //7
            ////    1  2  3  4  5  6  7
        };

    /* Graph Structure

             (1)
           /     \
        5/         \7
       /             \
    (6)              (2)
     |              / |
     |            /1  |
     |          /     |
    2|       (7)      |9
     |      / |       |
     |  8 /   |       |
     |  /     |       |
    (5)      4|      (3)
       \      |      /
        6\    |    /8
           \  |  /
             (4)
    */

    cout << "Minimum Cost: " << KruskalsAlgo(cost) << endl;
    cout << "\nEdges between vertices: " << endl;

    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < GRAPH_SIZE - 1; j++)
            cout << tree[i][j] << " ";

        cout << endl;
    }
}