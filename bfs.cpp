#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, e, a, b;
    cin >> n >> e;

    vector<int> graph[n];
    vector<bool> visited(n, false);

    for (int i = 0; i < e; i++)
    {
        cin >> a >> b;
        graph[a].push_back(b);
    }

    
    int temp = 0;

    for (int i = 0; i < n; i++)
    {
        queue<int> q;

        if (!visited[i]) // if the graph has more than one component
        {
            q.push(i);
            
            while (!q.empty())
            {
                temp = q.front();
                cout << temp << endl;
                visited[temp]=true;
                q.pop();

                for (auto it : graph[temp])
                {
                    if(!visited[it]) // important
                    {
                        q.push(it);
                    }
                }
            }
        }
    }
    return 0;
}