/*
    maneesh(maik)
*/
// D. Yet Another Monster Killing Problem

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
 
int main()
{
    fastio;
    ll tc;
    cin>>tc;
    while(tc--)
    {
        ll n;
        cin>>n;
        ll a[n+1],i,amax=0;
        for(i=0; i<n; i++)
        {
            cin>>a[i];
            amax=max(amax,a[i]);
        }
        
        ll A[n+1],s,p;
        for(i=0; i<=n; i++)
            A[i]=0;
            
        ll m,pmax=0;
        cin>>m;
        for(i=1; i<=m; i++)
        {
            cin>>p>>s;
            pmax=max(pmax,p);
            A[s]=max(A[s], p);
        }
        
        if(pmax<amax)
        {
            cout<<"-1"<<endl;
            continue;
        }
 
        for(i=n-1; i>=0; i--)
        {
            A[i]=max(A[i], A[i+1]);
        }
        
       /* for(i=1; i<=n; i++)
        cout<<A[i]<<" ";
*/
        ll j=0,maxx=0,ans=1;
        for(i=0; i<n; )
        {
            maxx=max(maxx,a[i]);
            j++;
            if(A[j]>=maxx)
            {
                i++; 
            }
            else
            {
                j=0;
                maxx=0;
                ans++;
            }
        }
 
        cout<<ans<<endl;
    }
    return 0;
}
