/*
    maneesh(maik)
*/
// E. The Contest 

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
#define lb lower_bound
#define M 1000000007
#define fastio ios_base::sync_with_stdio(false)
 
int main()
{
    fastio;
    ll k1,k2,k3;
    cin>>k1>>k2>>k3;
 
    ll a1[k1],a2[k2],a3[k3],i;
    for(i=0; i<k1; i++)
        cin>>a1[i];
    for(i=0; i<k2; i++)
        cin>>a2[i];
    for(i=0; i<k3; i++)
        cin>>a3[i];
    sort(a1, a1+k1);
    sort(a2, a2+k2);
    sort(a3, a3+k3);
 
    ll n=(k1+k2+k3);
    vector<ll>arr;
    for(i=0; i<k1; i++)
        arr.pb(a1[i]);
    for(i=0; i<k2; i++)
        arr.pb(a2[i]);
    for(i=0; i<k3; i++)
        arr.pb(a3[i]);
 
    vector<ll>v(n,0);
    ll len=1;
    v[0]=arr[0];
    for(i=1; i<arr.size(); i++)
    {
        auto b=v.begin(); 
        auto e=v.begin()+len;
        auto it=lb(b,e,arr[i]);
 
        if(it==v.begin()+len)
        {
            v[len]=arr[i];
            len++;
        }
        else
        {
            *it=arr[i];
        }
    }
 
    ll ans=n-len;
    cout<<ans<<endl;
    return 0;
}
