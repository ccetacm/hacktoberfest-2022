#include <iostream>
#include <stack> 
#include <queue> 
#include <set>

using namespace std;

int main()
{
    int n;

    cout << "Enter Number Of Nodes :- ";
    cin >> n;

    int graph[n][n];

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            graph[i][j] = 0;
        }
    }

    int a = 1;
    while (a == 1)
    {
        cout << "Press 1 to add an edge and 2 to move forward\n\n";

        int choice = 0;

        cin >> choice;

        if (choice == 1)
        {
            int first, second;
            cout << "enter first node of the edge:- ";
            cin >> first;
            cout << "enter second node of the edge:- ";
            cin >> second;

            graph[first][second] = 1;
            graph[second][first] = 1;
            cout << endl
                 << endl;
        }
        else if (choice == 2)
        {
            a = 0;
            break;
        }
        else
        {
            cout << "Enter A Valid Number \n\n";
        }
    }

    int source;
    cout << "Enter Source Vertex :- ";
    cin >> source;

    stack<int> stack;

    set<int> explored;

    stack.push(source);

    explored.insert(source);

    queue<int> result;

    while (!stack.empty())
    {
        int top = stack.top();
        stack.pop();

        // cout << front <<endl;
        result.push(top);
        for (int i = 0; i < n; i++)
        {
            
            if (graph[top][i] == 1)
            {
                if (!explored.count(i))
                {
                    stack.push(i);
                    explored.insert(i);
                }
            }
        }
    }

    cout << "DFS Order :- ";
    while (!result.empty())
    {
        cout << result.front() << " - ";
        result.pop();
    }
}
