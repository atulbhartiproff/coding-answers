#include<bits/stdc++.h>
using namespace std;

void solve()
{
    int n,q;
    cin>>n>>q;
    string s; cin>>s;

    vector<int> pref(n+1,0);
    vector<int> trans(n+1,0);

    for(int i=0;i<n;i++)
    {
        pref[i+1]=pref[i];
        if(s[i]=='0') pref[i+1]++;

        if(i>0){
            trans[i+1]=trans[i];
            if(s[i]!=s[i-1]) trans[i+1]++;
        }
    }

    while(q--)
    {
        int l,r;
        cin>>l>>r;

        int m=r-l+1;
        int z=pref[r]-pref[l-1];
        int o=m-z;

        int c=trans[r]-trans[l];
        if(s[l-1]!=s[r-1]) c+=1;

        int k1=(max(z,o)+1)/2;
        // int val=2*m-c;
        int k2=(c+1)/2;
        int val=2*m-c;
        int k3=(val>0)?(val+5)/6:0;
        int k=max({k1,k2,k3,1});
        cout<<4*k-m<<endl;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}
