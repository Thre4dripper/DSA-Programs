#include <iostream>
using namespace std;

//no of vertex in graph
#define GRAPH_SIZE 8

//function for printing Depth First Search of a Graph
void Print(int startingNode, int graph[][GRAPH_SIZE + 1], int visited[GRAPH_SIZE + 1])
{
    if (visited[startingNode] == 0)
    {
        cout << startingNode << " ";
        visited[startingNode] = 1;

        for (int v = 1; v <= GRAPH_SIZE; v++)
        {
            if (graph[startingNode][v] == 1)
                Print(v, graph, visited);
        }
    }
}

//function for initialising fresh visited array for DFS
void DFS(int startingNode, int graph[][GRAPH_SIZE + 1])
{
    int visited[GRAPH_SIZE + 1] = {0};
    for (int i = 0; i <= GRAPH_SIZE; i++)
        visited[i] = 0;

    Print(startingNode, graph, visited);
}

int main()
{
    system("cls");

    //graphs always represented in square matrices with 1 based index
    int graph[][GRAPH_SIZE + 1] =
        {
            /**/ 0, 0, 0, 0, 0, 0, 0, 0, 0,
            /**/ 0, 0, 1, 1, 1, 0, 0, 0, 0, //1
            /**/ 0, 1, 0, 0, 1, 1, 1, 0, 0, //2
            /**/ 0, 1, 0, 0, 1, 0, 0, 0, 0, //3
            /**/ 0, 1, 1, 1, 0, 1, 0, 0, 0, //4
            /**/ 0, 0, 1, 0, 1, 0, 1, 1, 1, //5
            /**/ 0, 0, 1, 0, 0, 1, 0, 0, 1, //6
            /**/ 0, 0, 0, 0, 0, 1, 0, 0, 1, //7
            /**/ 0, 0, 0, 0, 0, 1, 1, 1, 0  //8
            ////    1  2  3  4  5  6  7  8
        };

    /* Graph Structure
       1 ----- 2 ----- 6
       | \     | \   /  \
       |  \    |  \ /    \
       |   \   |   5 --- 8
       |    \  |  / \   /
       |     \ | /   \ /
       3 ----- 4      7
    */

    cout << "DFS: ";
    DFS(2, graph);

    cout << "\nDFS: ";
    DFS(5, graph);

    cout << "\nDFS: ";
    DFS(8, graph);

    cout << "\nDFS: ";
    DFS(3, graph);
}