#include<bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    cin>>s;
    int n;cin>>n;
    vector<int> pre(s.size());
    pre[0]=0;
    for(int i=1;i<s.size();i++)
    {
        pre[i]=pre[i-1]+(s[i]==s[i-1]);
    }

    for(int i=0;i<n;i++)
    {
        int l,r;
        cin>>l>>r;
        l--;r--;
        cout<<pre[r]-pre[l]<<endl;
    }

    return 0;
}
