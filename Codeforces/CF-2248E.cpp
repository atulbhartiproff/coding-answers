#include <algorithm>
#include<bits/stdc++.h>
#include <iterator>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long t; cin>>t;
    while(t-- >0)
    {
        long long n,m,d;
        cin>>n>>m>>d;

        vector<long long> p(m);
        vector<long long> r(m);
        vector<long long> pref(m,0);
        long long rewa=0;
        for(long long i=0;i<m;i++)
        {
            cin>>p[i]>>r[i];
            rewa+=r[i];
            pref[i]=rewa;
        }

        auto V=[&](long long x)->long long{
            if(x==0) return 0;
            long long score=x*d;
            long long cycl=x/n;
            long long rem=x%n;

            score+=cycl*rewa;
            if(rem>0 && m>0)
            {
                auto it=upper_bound(p.begin(),p.end(),rem);
                if(it!=p.begin())
                {
                    int idx=distance(p.begin(),it)-1;
                    score+=pref[idx];
                }
            }
            return score;
        };

        bool flag=false;
        for(long long i=0;i<m;i++)
        {
            for(long long j=i;j<m;j++)
            {
                if(V(p[i])+V(p[j])>V(p[i]+p[j]+1))
                {
                    flag=true;
                    break;
                }
            }
            if(flag) break;
        }

        if(flag) cout<<"YES"<<"\n";
        else cout<<"NO"<<"\n";

        continue;
    }
    return 0;
}
