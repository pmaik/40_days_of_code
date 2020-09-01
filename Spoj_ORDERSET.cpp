/*
    Spoj problem: ORDERSET - Order statistic set
    Find kth smallest by seg.tree .
    In this i have mapped numbers so that they will be in range of 1<= num<= 200000
    Use this link to clear the concept 
    https://www.quora.com/How-do-you-find-the-Kth-smallest-element-in-an-array-using-a-segment-tree-resulting-in-log-n-per-query-OrderSet-SPOJ
*/


/*          pmaik
    ░▒▓█►─═ Maneesh ═─◄█▓▒░


          ( •̪●)
        ███████]▄▄▄▄▄▄▄▄▃  ▃  ▃ 
    ▂▄▅█████████▅▄▃▂
   [███████████████████]
  ...◥⊙▲⊙▲⊙▲⊙▲⊙▲⊙▲⊙◤......  */
 
#include<bits/stdc++.h>
using namespace std;
#define inf() ifstream cin("in00.txt")
#define onf() ofstream cout("out00.txt")
#define ll long long int
#define pb push_back
#define pf push_front
#define mkp make_pair
#define pii pair<ll,ll>
#define fi first
#define se second
#define M 1000000007
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL);
 
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds; 
#define ordered_set  tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update>
#define ordered_set1 tree<ll, null_type, less_equal<ll>, rb_tree_tag, tree_order_statistics_node_update>
 
map<ll,ll>mp;
ll st[1000000]={0};
ll c[1000000]={0};
 
void update1(ll si, ll ss, ll se, ll idx, ll val)
{
    if(idx<ss || idx>se)
        return;
 
    if(ss==se && idx==ss)
    {
        st[si]+=val;
        return;
    }
 
    ll mid=(ss+se)/2;
    if(idx>=ss && idx<=mid)
        update1(2*si, ss, mid, idx, val);
    else
        update1(2*si+1, mid+1, se, idx, val);
 
    st[si]=st[2*si]+st[2*si+1];
}
 
ll find_kth(ll si, ll ss, ll se, ll k)
{
    if(ss==se)
    {
        return ss;
    }
 
    ll mid=(ss+se)/2;
    if(st[2*si]>=k)
    {
        return find_kth(2*si, ss, mid, k);
    }
    else //if(st[2*si]<k)
    {
        return find_kth(2*si+1, mid+1, se, k-st[2*si]);
    }
}
 
ll count_less_than_x(ll si, ll ss, ll se, ll l, ll r)
{
    if(r<ss || l>se)
        return 0;
 
    if(ss>=l && se<=r)
        return st[si];
 
    ll mid=(ss+se)/2;
    ll s1=count_less_than_x(2*si, ss, mid, l, r);
    ll s2=count_less_than_x(2*si+1, mid+1, se, l, r);
 
    return (s1+s2);
}
 
void solve(ll tc)
{
    ll q;
    cin>>q;
 
    ll x,qu[q][2];
    set<ll>v;
 
    for(ll i=0; i<q; i++)
    {
        char op;
        cin>>op;
        cin>>x;
 
        if(op=='I')
        {
            qu[i][0]=0;
            qu[i][1]=x;
            v.insert(x);
        }
        else if(op=='D')
        {
            qu[i][0]=1;
            qu[i][1]=x;
        }
        else if(op=='K')
        {
            qu[i][0]=2;
            qu[i][1]=x;
        }
        else if(op=='C')
        {
            qu[i][0]=3;
            qu[i][1]=x;
            v.insert(x);
        }
    }
 
    ll a[v.size()+10];
    ll n=0;
    for(auto it: v)
    {
        n++;
        mp[it]=n;
        a[n]=it;
        // cout<<it<<" "<<n<<endl;
    }
 
    for(ll i=0; i<q; i++)
    {
        x=mp[qu[i][1]];
        
        if(qu[i][0]==0)
        {
            if(c[x]==0)
            {
                update1(1, 1, n, x, 1);
                c[x]=1;
            }
        }
        else if(qu[i][0]==1)
        {
            if(c[x]==1)
            {
                update1(1, 1, n, x, -1);
                c[x]=0;                 
            }
        }
        else if(qu[i][0]==2)
        {
            x=qu[i][1];
            if(st[1]<x)
                cout<<"invalid"<<endl;
            else
            {
                ll res=find_kth(1, 1, n, x);
                cout<<a[res]<<"\n";
            }
        }
        else
        {
            cout<<count_less_than_x(1, 1, n, 1, x-1)<<endl;
        }
    }
}
 
int main()
{
    fastio;
 
    ll t=1;
    // cin>>t;
    for(ll tc=1; tc<=t; tc++)
    {
        solve(tc);
    }
    
    return 0;
}
