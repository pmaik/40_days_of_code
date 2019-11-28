/*
    maneesh(maik)
*/
// D - Binary String Minimizing

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
	ll t;
	cin>>t;
	while(t--)
	{
		ll n,k;
		cin>>n>>k;
 
		string s;
		cin>>s;
 
		vector<ll>z;
		ll v[n+1]={0};
 
		ll i,oi=-1,strt=n,j;
		for(i=0; i<n; i++)
		{
			if(s[i]=='0')
			{
				cout<<"0";
				oi=i;
			}
			else
			{
				strt=i;
				break;
			}
		}
 
		for(i=strt+1; i<n; i++)
		{
			if(s[i]=='0')
			{
				z.pb(i);
			}
		}
 
		ll a=0,zi=-1,zi1=n-1;
		j=strt;
		for(i=0; i<z.size(); i++)
		{
			ll in=z[i]; ll d=in-j;
			//cout<<in<<" "<<j<<" "<<k<<endl;
			if(k>=d)
			{
				k=k-d; a++; j++;
				v[in]=1; zi1=in;
				if(k==0)
				{
					zi1=in;
					break;
				}
			}
			else
			{
				zi=in-k; k=0; zi1=in;
				break;
			}
		}
		//cout<<j<<" "<<strt<<" "<<zi1<<endl;
		//for(i=0; i<z.size(); i++)
		//	cout<<z[i]<<" ";
		//cout<<endl;
 
//0101111
//0011111 
		//cout<<oi<<" jjj \n";
		for(i=0; i<a; i++)
			cout<<"0";
		for(i=j; i<=zi1; i++)
		{
			if(i==zi)
				cout<<"0";
			else
				cout<<"1";
		}
 
		for(i=zi1+1; i<n; i++)
			cout<<s[i];
		cout<<endl; 
	}
}
 
/*
01011110
0101111
0011111
 
*/
