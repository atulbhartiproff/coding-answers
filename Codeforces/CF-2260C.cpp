#include<bits/stdc++.h>
using namespace std;

void solve()
{
    long long x,y;
    cin>>x>>y;

    long long s=x+y;
    long long a=0;

    for(long long i=30;i>=0;i--)
    {
        if((x>>i&1)&&(s>>i&1)) a|=1LL<<i;
        else if((x>>i&1)&&!(s>>i&1))
        {
            for(long long j=i-1;j>=0;j--)
            {
                if(s>>j&1) a|=1LL<<j;
            }
            break;
        }
    }

    cout<<s<<" "<<(x-a)<<endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long t;cin>>t;
    while(t-- >0)
    {
        solve();
    }

    return 0;
}
