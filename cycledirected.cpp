#include<bits/stdc++.h>
using namespace std;

vector <vector<int>> graph;
vector <bool> visited;
vector<bool> dfsvisited;

// make two vectors visited and dfsvisited and all the elements in it should be false
// whenever we call the function make visited and dfsvisited as true
// if there is no cycle present make dfsvisited as false and return false

bool detectCycle(int node)
{
    visited[node] = true;
    dfsvisited[node] = true;
    for(auto it : graph[node])
    {
        if(!visited[it])
        {
            if(detectCycle(it))
                return true;
        }
        else if(dfsvisited[it])
            return true;
    }
    dfsvisited[node] = false;
    return false;
}

int main()
{

    int n, e, a, b;
    cin >> n >> e;

    graph.assign(n,vector<int> ());
    visited.assign(n, false);
    dfsvisited.assign(n,false);
    for (int i = 0; i < e; i++)
    {
        cin >> a >> b;
        graph[a].push_back(b);
    }
    for(int i=0; i<n; i++)
    {
        if(!visited[i])
            cout<<detectCycle(i);
    }
    
    return 0;
}