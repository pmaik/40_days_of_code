/*
    maneesh(maik)
*/
// E. Enemy is weak

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

 
ll n;
vector<ll> B1(1000005, 0), B2(1000005, 0);
 
void update(vector<ll> &t, int x, ll v)
{
    while(x>0)
    {
        t[x] += v;
        x -= x&-x;
    }
}
 
ll query(vector<ll> &t, int x)
{
    ll ret = 0;
    while(x <= n)
    {
        ret += t[x];
        x += x&-x;
    }
    return ret;
}
 
ll Bsearch(ll l, ll r, ll x, ll b[])
{
	if(l==r)
		return l;
 
	ll mid=(l+r)/2;
	if(b[mid]==x)
		return mid;
	else if(b[mid]<x)
		return Bsearch(mid+1, r, x, b);
	else
		return Bsearch(l, mid, x, b);
}
 
int main()
{
    cin>>n;
    ll a[n],b[n],A[n];
    
    for(ll i=0; i<n; i++)
    {
    	cin>>a[i];
    	b[i]=a[i];
    }
 
    sort(b,b+n);
    for(ll i=0; i<n; i++)
    {
    	ll j=Bsearch(0, n-1, a[i], b);
    	A[i]=j;
    }
 
    ll ans = 0;
    for(ll i=0; i<n; i++)
    {
        ll x=A[i];
        
        update(B1, x, 1);
        
        ll q = query(B1, x+1);
        
        update(B2, x, q);
        
        ans += query(B2, x+1);
    }
    cout << ans<<endl;
    
 /*   for(int z=1; z<=6; z++)
    cout<<T1[z]<<" ";
    cout<<endl;
    for(int z=1; z<=6; z++)
    cout<<T2[z]<<" "; */
    
    /*int mm,nn;
    mm=2;
    mm=mm+(mm&(-mm));
    cout<<mm<<"  hh";*/
} 
