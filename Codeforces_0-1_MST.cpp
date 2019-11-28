/*
    maneesh(maik)
*/
// D. 0-1 MST 
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
 
vector<set<ll>>G(100005);
set<ll>s;
 
void DFS(ll x)
{
    s.erase(x);
    vector<ll>v;
    for(auto it:s)
    {
        if(G[x].find(it)==G[x].end())
        {
            v.pb(it);
        }
    }
    for(auto i:v)
    {
        s.erase(i);
    }
 
    for(auto i:v)
    {
        DFS(i);
    }
}
 
int main()
{
    fastio;
    
    ll n,m;
    cin>>n>>m;
    ll x,y,i;
    while(m--)
    {
        cin>>x>>y;
        G[x].insert(y);
        G[y].insert(x);
    }
 
    for(i=1; i<=n; i++)
    {
        s.insert(i);
    }
 
    ll comp=0;
    for(i=1; i<=n; i++)
    {
        if(s.find(i)!=s.end()) //if i is present in set
        {
            s.erase(s.find(i));
            comp++;
            DFS(i);
        }
    }
 
    cout<<comp-1;
    s.clear();
    return 0;
} 
