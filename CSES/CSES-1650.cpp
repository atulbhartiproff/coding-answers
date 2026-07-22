#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,q;
    cin>>n>>q;
    vector<int> arr(n);
    for(auto& i:arr) cin>>i;
    vector<int> pref(n+1);
    pref[0]=0;
    for(int i=1;i<=n;i++)
    {
        pref[i]=pref[i-1]^arr[i-1];
    }
    cout<<endl;
    for(int t=0;t<q;t++)
    {
        int l,r;
        cin>>l>>r;
        l--;
        cout<<(pref[r]^pref[l])<<endl;
    }
    return 0;

}
