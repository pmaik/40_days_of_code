 /*
    maneesh(maik)
*/
// SCC problem 
// Kosaraju algo + DFS
 
#include<iostream>
#include<algorithm>
#include<string>
#include<bitset>
#include<deque>
#include<iterator>
#include<list>
#include<map>
#include<queue>
#include<set>
#include<stack>
#include<unordered_map>
#include<unordered_set>
#include<vector>
using namespace std;
#define ll long long int
#define pb push_back
#define pf push_front
#define M 1000000007
#define fastio ios_base::sync_with_stdio(false);
#define mx 200000
 
stack<ll>s;
vector<ll>G[mx],Gt[mx];
ll A[mx]={0};
ll in[mx]={0};
    
void DFS1(ll p, ll vis[] )
{
    vis[p]=1;
 
    for(ll i=0; i<G[p].size(); i++)
    {
        ll it=G[p][i];
 
        if(vis[it]==0)
        {
            DFS1(it, vis);
        }
    }
    s.push(p);
    //cout<<p<<" ";
}
 
void DFS2(ll p, ll vis[], ll comp )
{
    vis[p]=1; A[p]=comp; //cout<<p<<" ";
    
    for(ll i=0; i<Gt[p].size(); i++)
    {
        ll it=Gt[p][i];
        if(vis[it]==0)
        {
            DFS2(it, vis, comp);
        }
    }
}
 
int main()
{
    ll n,m;
    scanf("%lld %lld",&n,&m);
 
    ll i,j,x,y;
    ll vis[n+5];
 
    for(i=1; i<=n; i++)
    {
        vis[i]=0;
        in[i]=0;
    }
 
    for(i=0; i<m; i++)
    {
        scanf("%lld %lld",&x,&y);
        G[x].pb(y);
        Gt[y].pb(x);
    }
    
/*  for(i=1; i<=n; i++)
    {
        cout<<i<<"-->  ";
        for(j=0; j<Gt[i].size(); j++)
        {
            cout<<Gt[i][j]<<" ";
        }cout<<endl;
    }*/
    
    for(i=1; i<=n; i++)
    {
        if(vis[i]==0)
        {
            DFS1(i, vis);
        }
    }
    
    for(i=1; i<=n; i++)
        vis[i]=0;
 
    ll comp=0;
    while(s.size())
    {
        ll p=s.top();
        s.pop();
        if(vis[p]==0)
        {
            comp++;
            DFS2(p, vis, comp);
            //cout<<endl;
        }
    }
    /*for(i=1; i<=n; i++)
        cout<<A[i]<<" ";
    cout<<endl;*/
 
    ll n1=comp;
    for(i=1; i<=n; i++)
    {
        for(j=0; j<Gt[i].size(); j++)
        {
            ll it=Gt[i][j];
            if(A[i]!=A[it])
            {
                in[A[it]]+=1;
            }
        }
    }
    ll cnt=0;
    for(i=1; i<=n1; i++)
    {
        if(in[i]==0)
            cnt++;
    }
 
    if(cnt>1)
    {
        cout<<printf("0");
    }
    else
    {
        cnt=0;
        for(i=1; i<=n; i++)
        {
            if(in[A[i]]==0)
                cnt++;
        }
 
        printf("%lld\n",cnt);
        
        for(i=1; i<=n; i++)
        {
            if(in[A[i]]==0)
            {
                printf("%lld ",i);
            }
        }
        printf("\n");
    }
    return 0;
}
