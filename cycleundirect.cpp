#include<bits/stdc++.h>
using namespace std;

vector <vector<int>> graph;
vector <bool> visited;

bool detectCycle(int node, int parent) // pass two arguments node and parent
{
    visited[node]=true;
    for(auto it : graph[node])
    {
        if(!visited[it])
        {
            if(detectCycle(it,node)) // call the function recursively and return the results
                return true;
        }

        else if(it!=parent) // if the connected node is not parent but it is still visited then cycle is present
        {
            return true;
        }
    }
    return false;
}

int main()
{

    int n, e, a, b;
    cin >> n >> e;

    graph.assign(n,vector<int> ());
    visited.assign(n, false);

    for (int i = 0; i < e; i++)
    {
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    for(int i=0; i<n; i++)
    {
        if(!visited[i])
            cout<<detectCycle(i,-1);
    }
    
    return 0;
}