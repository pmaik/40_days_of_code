 /*
    maneesh(maik)
*/
// Bridges in undirected graph 
// Pre and Post time of DFS 
 
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
 
struct data
{
	ll u;
	ll v;
};
 
bool comp(data a, data b)
{
	if(a.u==b.u)
		return a.v<b.v;
	else
		return a.u<b.u;
}
 
ll tim;
 
void DFS(ll s, ll p, ll vis[], ll Pre[], ll Post[], ll A[], vector<ll>G[], vector<data>&edge)
{
	vis[s]=1;
	for(ll i=0; i<G[s].size(); i++)
	{
		ll it=G[s][i];
		if(vis[it]==0)
		{
			Pre[it]=tim; A[it]=tim;
			tim++;
			DFS(it, s, vis, Pre, Post, A, G, edge);
		}
	}
	Post[s]=tim; tim++;
	/*cout<<s<<" "<<p<<endl; 
	cout<<Pre[s]<<" "<<A[s]<<endl;
	cout<<Pre[p]<<" "<<A[p]<<endl;
	cout<<endl;*/
 
	ll t;
	for(ll i=0; i<G[s].size(); i++)
	{
		ll it=G[s][i];
		if(it!=p)
		{
			t=min(Pre[it], A[it]);
			A[s]=min(A[s], t);
		}
	}
 
	if(A[s]>Pre[p])
	{ 
		data z;
		z.u=min(s,p);
		z.v=max(s,p);
		edge.pb(z);
		//cout<<edge.size()<<endl;
	}
}
 
int main()
{
	fastio;
 
	ll t,tc;
	cin>>t;
	for(tc=1; tc<=t; tc++)
	{
		ll n,m;
		cin>>n>>m;
		vector<data>edge;
		data z;
		ll i,x,y;
		vector<ll>G[n+2];
		ll Pre[n+3],Post[n+3],A[n+3];
		for(i=0; i<m; i++)
		{
			cin>>x>>y;
			G[x].pb(y);
			G[y].pb(x);
		}
		ll vis[n+3];
		for(i=1; i<=n; i++)
			vis[i]=0;
 
		ll cnt=0; 
		tim=1;
		A[1]=1; Pre[1]=1;  vis[1]=1; tim++; 
		DFS(1, 1, vis, Pre, Post, A, G, edge);
		
		/*for(i=1; i<=n; i++)
			cout<<P[i]<<" ";*/
		/*for(i=1; i<=n; i++)
		{
			cout<<i<<"-->  ";
			for(ll j=0; j<G[i].size(); j++)
				cout<<G[i][j]<<" ";
			cout<<endl;
		}*/
 
		cout<<"Caso #"<<tc<<endl;
		if(edge.size()==0)
		{
			cout<<"Sin bloqueos"<<endl;
		}
		else
		{
			cout<<edge.size()<<endl;
			sort(edge.begin(), edge.end(), comp);
 
			for(i=0; i<edge.size(); i++)
			{
				cout<<edge[i].u<<" "<<edge[i].v<<endl;
			}
		}
	}
	return 0;
} 