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

vector<ll>v;

ll ex(ll a,ll b)
{
    if(b==0)
        return 1;
    else if(b%2==0)
        return (ex((a*a),b/2));
    else
        return (a*ex((a*a),(b-1)/2));
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll i,j,t;
    ll n,a,b,c,ans,p,m,k;
    cin>>n>>k;
    for(i=0; i<k; i++)
    {
        cin>>a;
        v.pb(a);
    }
    ans=0;
    ll mask;
    for(mask=1; mask<(1<<k); mask++)
    {
        m=n;
        c=0;
        for(j=0; j<k; j++)
        {
            if((1<<j)&mask)
            {
                c++;
                m=m/v[j];
            }
        }

        if(c%2==0)
            ans-=m;
        else if(c%2==1){
            ans+=m;
        }
    }
    cout<<ans<<endl;




   return 0;
}


