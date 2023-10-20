#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp>
#include <functional> // for less
#include <iostream>
#include<bits/stdc++.h>
#define endl '\n'
#define ll  long long int
#define pb push_back


using namespace __gnu_pbds;
using namespace std;

typedef tree<long long int, null_type, less_equal<long long int>, rb_tree_tag,
        tree_order_statistics_node_update>
        ordered_multiset;
ordered_multiset s;
//ordered_multiset :: iterator it;

const ll N=1e6+3;
 bool sive[N];
ll hp[N+10];
vector<ll>pf[N];
ll a[N];
ll b[N];
vector<ll>v;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll i,j;
    for(i=0; i<N; i++)
    {
        sive[i]=true;
    }
    sive[0]=false;
    sive[1]=false;
    for(i=2; i<=N; i++)
    {
        if(sive[i])
        {
            hp[i]=i;
            for(j=i; j<=N; j+=i)
            {
                sive[j]=false;
                hp[j]=i;
            }
        }
    }

    ll p,num;
    for(i=2; i<1000000; i++)
    {
        num=i;
        while(num>1)
        {
            p=hp[num];
            while(num%p==0)
            {
                num/=p;

            }
          pf[i].pb(p);
        }
    }

ll n,c,mask,num1;
   cin>>n;
   for(i=0; i<n; i++)
   {
       cin>>c;
       v.pb(c);
   }
   for(i=0; i<n; i++)
   {
       for(mask=1; mask<(1<<(pf[v[i]].size())); mask++)
       {
           c=0;
           num1=1;
           for(j=0; j<pf[v[i]].size(); j++)
           {
               if(mask&(1<<j))
               {
                   c++;
                   num1=num1*pf[v[i]][j];
               }
           }
           a[num1]++;
           b[num1]=c;
       }
   }
  ll ans=0;
  for(i=0; i<N; i++)
  {
      c=(a[i]*(a[i]-1))/2;
      if(b[i]%2==0)
        ans-=c;
      else
        ans+=c;
  }
  ll sum=(n*(n-1))/2;
  cout<<sum-ans;

   return 0;
}



