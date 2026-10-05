#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    long long n; cin>>n;
    vector<long long> ans;
    for(long long i=1;i<=n/i;i++)
    {
        if(n%i==0)
        {
            ans.push_back(i);
            if(n/i!=i)ans.push_back(n/i);
        }
    }
    sort(ans.begin(),ans.end());
    for(long long i:ans)
    {
        cout<<i<<endl;
    }

}
