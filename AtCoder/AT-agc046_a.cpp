#include<bits/stdc++.h>
using namespace std;

int  gcd(int a ,int b)
{
    if(b==0) return a;

    return gcd(b,a%b);
}


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int X; cin>>X;
    X%=360;
    int lcm=(360/gcd(360,X))*X; //First time X and 360 face the same side
    int ans=lcm/X;

    cout<<ans;
    return 0;

}
