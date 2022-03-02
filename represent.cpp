#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,e,a,b;
    cin>>n>>e;
    
    // n is used to make n sized vectors
    // e is the number of edges

    vector<int>graph[n];
    for(int i=0; i<e; i++)
    {
        cin>>a>>b;
        graph[a].push_back(b); //for directed graph
        // graph[b].push_back(a);// for undirected graph
    }

    for(int i=0; i<n; i++)
    {
        for(auto it : graph[i])
            cout<<i<<"->"<<it<<endl;
    }
    return 0;
}