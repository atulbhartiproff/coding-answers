#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin>>t;
    while(t-- >0)
    {
        int n; cin>>n;
        vector<int> arr(n);
        for(auto& i: arr) cin>>i;
        if(n%2==1)
        {
            cout<<"NO"<<endl;
            continue;
        }
        int sum=0;
        for(int i:arr) sum+=i;
        if(sum%4==0) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
        continue;
    }
    return 0;
}
