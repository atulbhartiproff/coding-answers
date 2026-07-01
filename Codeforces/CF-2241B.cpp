#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;cin>>t;
    while(t-- >0)
    {
        int n; cin>>n;
        int cnt=1;
        while(n>0)
        {
            cnt*=10;
            n/=10;
        }
        cnt++;
        cout<<cnt<<endl;
    }
}
