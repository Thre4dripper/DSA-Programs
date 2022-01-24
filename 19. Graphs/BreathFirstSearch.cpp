#include <iostream>
#include <queue>
using namespace std;

//no of vertex in graph
#define GRAPH_SIZE 8

//function for printing Breadth First Search of a Graph
void BFS(int startingNode, int graph[][GRAPH_SIZE + 1])
{
    queue<int> q;
    int visited[GRAPH_SIZE + 1] = {0};

    cout << startingNode << " ";
    visited[startingNode] = 1;
    q.push(startingNode);

    //until queue becomes empty
    while (!q.empty())
    {
        int u = q.front();
        q.pop();

        for (int v = 1; v <= GRAPH_SIZE; v++)
        {
            //if graph vertex has a connection and vertex is not visited yet
            if (graph[u][v] == 1 && visited[v] == 0)
            {
                cout << v << " ";
                visited[v] = 1;
                q.push(v);
            }
        }
    }
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

    cout << "BFS: ";
    BFS(2, graph);

    cout << "\nBFS: ";
    BFS(5, graph);

    cout << "\nBFS: ";
    BFS(8, graph);

    cout << "\nBFS: ";
    BFS(3, graph);
}