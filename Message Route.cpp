#include<bits/stdc++.h>
using namespace std;
const int N=100005;
int parent[N];
vector<int>adja_list[N];
int level[N];
bool visited[N];
void bfs(int src,int dst);
void parent_traker(int  dst);
int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=0; i<=n; i++)
    {
        level[i]=-1;
        parent[i]=0;
    }
    for(int i=0; i<m; i++)
    {
        int u,v;
        cin>>u>>v;
        adja_list[u].push_back(v);
        adja_list[v].push_back(u);
    }

//    for(int i=0; i<n; i++)
//    {
//        cout<<i<<" -> ";
//        for(int j:adja_list[i])
//        {
//            cout<<j<<" ";
//        }
//        cout<<"\n";
//    }
    bfs(1,n);
    if(level[n]==-1)
    {
        cout<< "IMPOSSIBLE";
        return 0;
    }
    cout<<level[n]+1;
    cout<<endl;
    parent_traker(n);
    cout<<n;
//    for(int i=0; i<=n; i++)
//    {
//
//        cout<< parent[i];
//    }
    return 0;
}
void bfs(int src,int dst)
{
    level[src]=0;
    queue<int>q;
    q.push(src);
    while(!q.empty())
    {
        int head=q.front();
        visited[head]=true;
        q.pop();
        for(int child:adja_list[head])
        {
            if(visited[child]==false)
            {
                visited[child]=true;
                level[child] =level[head]+1;
                q.push(child);
                parent[child]=head;
            }
            if(child==dst)return;
        }
    }
}
void parent_traker(int  dst)
{
    int* src=&parent[1];
    int* dsT=&parent[dst];
    queue<int*>q;
    stack<int*>st;
    q.push(dsT);
    while(q.front()!=src)
    {
        st.push(q.front());
        int* head=q.front();
        q.pop();
        q.push(&parent[*head]);
    }
    while(!st.empty())
    {
        cout<<*st.top()<<" ";
        st.pop();
    }
}
