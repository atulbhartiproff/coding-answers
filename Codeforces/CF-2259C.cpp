#include<bits/stdc++.h>
using namespace std;

void solve()
{
    int n; cin>>n;
    vector<int> arr(n);
    for(auto&  i:arr) cin>>i;
    int firstone=-1,lastone=-1,firstminus=-1,lastminus=-1;
    for(int i=0;i<n;i++) if(arr[i]==1) {firstone=i;break;}
    for(int i=0;i<n;i++) if(arr[i]==-1) {firstminus=i;break;}
    for(int i=n-1;i>=0;i--) if(arr[i]==1) {lastone=i;break;}
    for(int i=n-1;i>=0;i--) if(arr[i]==-1) {lastminus=i;break;}

    if(firstone==-1)
    {
        if(firstminus!=-1 && lastminus!=-1 ) {arr[firstminus]=1;arr[lastminus]=1;}
    }
    else if(firstone==lastone)
    {
        int l=-1,r=-1;
        if(firstminus!=-1 && firstminus<firstone) l=firstone-firstminus;

        if(lastminus!=-1 && lastminus>lastone) r=lastminus-firstone;

        if(l>=r && l!=-1) arr[firstminus]=1;
        else if(r!=-1) arr[lastminus]=1;
    }
    else
    {
        int middle=lastone-firstone;
        int l=-1,r=-1;
        if(firstminus!=-1 && firstminus<firstone) l=firstone-firstminus;

        if(lastminus!=-1 && lastminus>lastone) r=lastminus-lastone;

        if(l>=middle && l>=r) arr[firstminus]=1;
        else if(r>=middle && r>=l) arr[lastminus]=1;
    }



    for(int i=0;i<n;i++) if(arr[i]==-1) arr[i]=0;
    for(auto i:arr) cout<<i<<" ";
    cout<<endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;cin>>t;
    while(t-- >0)
    {
        solve();
    }

    return 0;
}
