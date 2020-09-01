/*
    Spoj problem: MKTHNUM - K-th Number
    Find kth smallest by Merge-Sort-Tree in given range (i, j) of array
 
    Here you will learn implementation of Merge_Sort_Tree.
    Happy_Coding(^_^)
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
#define inff -1000000000000000

vector<ll>st[300000];
vector<pair<ll,ll>>vec;
 
void build_tree(ll si, ll ss, ll se)
{
    if(ss==se)
    {
        st[si].push_back(vec[ss].second);
        return;
    }
 
    ll mid=(ss+se)/2;
    build_tree(2*si, ss, mid);
    build_tree(2*si+1, mid+1, se);
 
    ll i=0,j=0;
    while(i<st[2*si].size() && j<st[2*si+1].size())
    {
        if(st[2*si][i]<st[2*si+1][j])
        {
            st[si].push_back(st[2*si][i]);
            i++;
        }
        else
        {
            st[si].push_back(st[2*si+1][j]);
            j++;
        }
    }
 
    while(i<st[2*si].size())
    {
        st[si].push_back(st[2*si][i]);
        i++;
    }
    while(j<st[2*si+1].size())
    {
        st[si].push_back(st[2*si+1][j]);
        j++;
    }
}
 
ll find_kth(ll si, ll ss, ll se, ll l, ll r, ll k)
{
    if(ss==se)
        return st[si][0];
 
    ll mid=(ss+se)/2;
    ll pos1=lower_bound(st[2*si].begin(), st[2*si].end(), l)-st[2*si].begin();
    ll pos2=upper_bound(st[2*si].begin(), st[2*si].end(), r)-st[2*si].begin();
 
    ll c=pos2-pos1;
    if(c>=k)
        return find_kth(2*si, ss, mid, l, r, k);
    else
        return find_kth(2*si+1, mid+1, se, l, r, k-c);
}
 
void solve(ll tc)
{
    ll n,q;
    cin>>n>>q;
 
    ll i,j,k,a[n+5];
    vec.push_back(make_pair(inff, 0));
    for(i=1; i<=n; i++)
    {
        cin>>a[i];
        vec.push_back(make_pair(a[i], i));
    }
 
    sort(vec.begin(), vec.end());
    build_tree(1, 1, n);
        
    while(q--)
    {
        cin>>i>>j>>k;
        ll idx=find_kth(1, 1, n, i, j, k);
        cout<<a[idx]<<endl;
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
