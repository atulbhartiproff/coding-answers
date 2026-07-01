#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;cin>>t;
    while(t-- >0)
    {
        int x,y;cin>>x>>y;
        if(x<y)
        {
            cout<<"NO"<<endl;
            continue;
        }
        if(x%y==0) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }

    return 0;
}
