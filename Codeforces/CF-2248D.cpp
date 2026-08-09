#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin>>t;
    while(t-- >0)
    {
        int n,q;
        cin>>n>>q;

        string s,t;
        cin>>s>>t;
        vector<int> pref01(n+1,0);
        vector<int> pref10(n+1,0);

        for(int i=0;i<n;i++)
        {
            pref01[i+1]=pref01[i]+(s[i]=='0' && t[i]=='1');
            pref10[i+1]=pref10[i]+(s[i]=='1' && t[i]=='0');
        }

        while(q--)
        {
            int l,r;
            cin>>l>>r;
            int len=r-l+1;
            int m01=pref01[r]-pref01[l-1];
            int m10=pref10[r]-pref10[l-1];

            if(2*m01<=len && 2*m10<=len)
            {
                cout<<"YES"<<endl;
            }
            else {
            cout<<"NO"<<endl;
            }
        }
    }
    return 0;
}
