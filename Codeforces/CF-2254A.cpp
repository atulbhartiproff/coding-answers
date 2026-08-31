#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin>>t;
    while(t-- >0)
    {
        int a,b,c;
        cin>>a>>b>>c;
        if(a==b || b==c || a==c) cout<<0<<endl;
        else
        {
            cout<<min({abs(a-b),abs(a-c),abs(c-b)})<<endl;
        }
    }
    return 0;
}
