#include <iostream>
using namespace std;

//no of vertex in graph
#define GRAPH_SIZE 8

//macro
#define I INT_MAX

//spanning tree array for selecting edges
int tree[2][GRAPH_SIZE - 1];

//function for finding minimum cost by minimum cost spanning tree of graph
int minimumCost(int cost[][GRAPH_SIZE + 1])
{
    int near[GRAPH_SIZE + 1];
    for (int i = 0; i <= GRAPH_SIZE; i++)
        near[i] = I;

    int min = I;
    int u, v;

    //INITIAL WORK
    //fiding minimum egde in whole graph
    for (int i = 1; i <= GRAPH_SIZE; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            if (cost[i][j] < min)
            {
                min = cost[i][j];
                u = i;
                v = j;
            }
        }
    }

    //updating 'near' array based on minimum edge between two vertices
    near[u] = 0;
    near[v] = 0;
    tree[0][0] = u;
    tree[1][0] = v;

    for (int i = 1; i <= GRAPH_SIZE; i++)
    {
        if (near[i] != 0)
        {
            if (cost[i][u] > cost[i][v])
                near[i] = v;

            else
                near[i] = u;
        }
    }

    //REPEATING STEPS
    int k = 0;

    for (int i = 1; i < GRAPH_SIZE - 1; i++)
    {
        min = I;

        //finding mimimum edge connected to existing two selected vertices
        for (int j = 1; j <= GRAPH_SIZE; j++)
        {
            if (min > cost[j][near[j]])
            {
                min = cost[j][near[j]];
                k = j;
            }
        }

        //updating spanning tree array based on next minimum edge
        tree[0][i] = near[k];
        tree[1][i] = k;
        near[k] = 0;

        //updating 'near' array based on selected minimum edge
        for (int j = 1; j <= GRAPH_SIZE; j++)
        {
            if (near[j] != 0)
            {
                if (cost[j][near[j]] > cost[j][k])
                    near[j] = k;
            }
        }
    }

    //calculating final minimum cost by spanning tree array
    int result = 0;
    for (int i = 0; i < GRAPH_SIZE - 1; i++)
        result += cost[tree[0][i]][tree[1][i]];

    return result;
}

int main()
{
    system("cls");

    //graphs always represented in square matrices with 1 based index
    int cost[][GRAPH_SIZE + 1] =
        {
            /**/ I, I, I, I, I, I, I, I, I,
            /**/ I, I, 7, I, I, I, 5, I, I, //1
            /**/ I, 7, I, 9, I, I, I, 1, I, //2
            /**/ I, I, 9, I, 8, I, I, I, I, //3
            /**/ I, I, I, 8, I, 6, I, 4, I, //4
            /**/ I, I, I, I, 6, I, 2, 8, I, //5
            /**/ I, 5, I, I, I, 2, I, I, 3, //6
            /**/ I, I, 1, I, 4, 8, I, I, 5, //7
            /**/ I, I, I, I, I, I, 3, 5, I  //8
            ////    1  2  3  4  5  6  7  8
        };

    /* Graph Structure

             (1)
           /     \
        5/         \7
       /             \
    (6) ---- (8)     (2)
     |    3   |     / |
     |       5|   /1  |
     |        | /     |
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

    cout << "Minimum Cost: " << minimumCost(cost) << endl;

    cout << "Edges between vertices: " << endl;

    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < GRAPH_SIZE - 1; j++)
            cout << tree[i][j] << " ";

        cout << endl;
    }
}