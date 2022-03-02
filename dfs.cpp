#include<bits/stdc++.h>
using namespace std;

vector <vector<int>> graph;
vector <bool> visited;

void dfs(int root)
{
    cout<<root<<endl;
    visited[root]=true;

    for(auto it : graph[root])
    {
        if(!visited[it])
            dfs(it);
    }
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
    }
    for(int i=0; i<n; i++)
    {
        if(!visited[i])
            dfs(i);
    }
    
    return 0;
}