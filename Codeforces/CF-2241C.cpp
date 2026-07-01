#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin>>t;

    while(t-- >0)
    {
        int n;cin>>n;
        string s;cin>>s;
        int cnt=0; char last='x';
        for(char h:s)
        {
            if(h!=last)
            {
                last=h;
                cnt++;
            }
            if(cnt>2) break;
        }
        if(cnt==1 || cnt>2) cout<<1<<endl;
        else cout<<2<<endl;
    }
}
