#include<bits/stdc++.h>
#define white 1
#define gray 2
#define black 3
#define nil -1
#define inf 10000
using namespace std;

int vertex, Time=0;
int g[100][100], color[100], Prev[100], d[100], f[100],tp[100];

void graphCreate()
{
    int maxEdge,source,destin;
    cout<<"Enter number of vertex : \n";
    cin>>vertex;
    maxEdge=vertex*(vertex-1);

    cout<<"Chose two vertex from 0 to "<<vertex-1<<" and -1 -1 for terminate input "<<endl;

    for(int i=1; i<=maxEdge; i++)
    {
        cout<<"Enter edge "<<i<<": ";
        cin>>source>>destin;
        if(source==-1&&destin==-1)
        {
            break;
        }
        if(source>=vertex||destin>=vertex)
        {
            cout<<"Invalid edge\n";
            i--;
        }
        else
        {
            g[source][destin]=1;
        }
    }

}
void DFS_Visit(int u)
{
    int v;
    color[u]=gray;
    Time++;
    d[u]=Time;
    for(v=0; v<vertex; v++)
    {
        if(g[u][v]==1&&color[v]==white)
        {
            Prev[v]=u;
            DFS_Visit(v);
        }
    }

    Time++;
    f[u]=Time;
    color[u]=black;
    tp[u]=f[u];
}
void DFS()
{
    int u;
    for(u=0; u<vertex; u++)
    {
        color[u]=white;
        Prev[u]=nil;
        f[u]=inf;
        d[u]=inf;
    }
    Time=0;
    for(u=0; u<vertex; u++)
    {
        if(color[u]==white)
        {
            DFS_Visit(u);
        }
    }
}

void print_DFS()
{
    for(int i=0; i<vertex; i++)
    {
        cout<<i<<"\t"<<d[i]<<"\t\t"<<f[i]<<endl;
    }
}
int main()
{
    graphCreate();
    DFS();
    cout<<"\nResult of DFS traversal :\nVertex\tDestination\tFinish\n";
    print_DFS();

    reverse(tp,tp+vertex);
    cout<<"\nTopological Sort are : \n";
    for(int i=0; i<vertex; i++)
    {
        cout<<tp[i]<<" ";
    }

    cout<<endl;
    return 0;
}

