 /*
    maneesh(maik)
*/
// Two Priority queues 

#include<bits/stdc++.h>
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
    ll tc;
    scanf("%lld", &tc);
    while(tc--)
    {
        priority_queue<ll>pq_max;
        priority_queue<ll, vector<ll>, greater<ll>>pq_min;
        ll n;
        while(true)
        {
            scanf("%lld", &n);
            if(n==0)
            {
                while(pq_min.size())
                    pq_min.pop();
                while(pq_max.size())
                    pq_max.pop();
                break;
            }
 
            if(n==-1)
            {
                printf("%lld\n",pq_max.top());
                pq_max.pop();
 
                while(pq_max.size()<pq_min.size())
                {
                    ll x=pq_min.top();
                    pq_min.pop();
                    pq_max.push(x);
                }
            }
            else
            {
                pq_min.push(n);
                if(pq_min.size()>0 && pq_max.size()>0)
                {
                    if(pq_min.top() < pq_max.top())
                    {
                        ll x=pq_min.top();
                        ll y=pq_max.top();
                        pq_min.pop();
                        pq_max.pop();
                        pq_min.push(y);
                        pq_max.push(x);
                    }
                }
 
                while(pq_max.size() < pq_min.size())
                {
                    ll x=pq_min.top();
                    pq_min.pop();
                    pq_max.push(x);
                }
            }
        }
        printf("\n");
    }
    return 0;
} 
