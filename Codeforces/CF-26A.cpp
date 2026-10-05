#include<bits/stdc++.h>
using namespace std;

void solve(int n)
{
    vector<int> sieves(n+1,0);
    int cnt=0;
    for(int i=2;i<=n;i++)
    {
        if(sieves[i]==2) cnt++;

        if(sieves[i]==0){
            for(int j=i*2;j<=n;j+=i)
            {
                sieves[j]++;
            }
        }
    }

    cout<<cnt;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;cin>>t;
    solve(t);

    return 0;
}
