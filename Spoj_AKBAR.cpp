 /*
    maneesh(maik)
*/
// Recursive  BFS 

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
 
ll flag=1;
 
void BFS(queue<ll>q, ll vis[], vector<ll>G[], ll d, ll p)
{
    queue<ll>q1;
 
    if(flag==0)
        return;
        
    if(d==0)
    {
        while(q.size())
        {
            ll s=q.front();
            if(vis[s]==0)
                vis[s]=p;
            else if(vis[s]!=p)
            {
                flag=0;
                return;
            }
            q.pop();
        }
        return;
    }
    
    while(q.size())
    {
        ll s=q.front();
        for(ll i=0; i<G[s].size(); i++)
        {
            ll it=G[s][i];
            if(vis[it]==0)
            {
                vis[it]=p;
                q1.push(it);
            }
            else if(vis[it]!=p)
            {
                flag=0;
                return;
            }
        }
        q.pop();
    }
    
    d--;
    if(d>=0)
    {
        BFS(q1, vis, G, d, p);
    }
    else
    {
        return;
    }
}
 
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
 
    int t;
    cin>>t;
    while(t--)
    {
        ll n,r,m;
        cin>>n>>r>>m;
        vector<ll>G[n+2];
        ll i,x,y;
        for(i=0; i<r; i++)
        {
            cin>>x>>y;
            G[x].pb(y);
            G[y].pb(x);
        }
 
        ll vis[n+2];
        for(i=1; i<=n; i++)
        {
            vis[i]=0;
        }
 
        ll d,p,s;
        flag=1;
        queue<ll>q;
        for(i=0; i<m; i++)
        {
            cin>>x>>d;
            q.push(x); 
            if(vis[x]==0)
            {
                vis[x]=x;
            }
            else
            {
                
                flag=0;
            }
            
            if(flag==1 && d>0)
            {
                BFS(q, vis, G, d, x);
            }
        }
 
        for(i=1; i<=n; i++)
        {
            if(vis[i]==0 || flag==0)
            {
                flag=0; 
                break;
            }
        }
 
        if(flag==0)
            cout<<"No"<<endl;
        else
            cout<<"Yes"<<endl;
    }
    return 0;
} 
