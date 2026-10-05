#include<bits/stdc++.h>
using namespace std;

int gcd(int a, int b)
{
    if(b==0) return a;
    return gcd(b,a%b);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int a,b;
    cin>>a>>b;
    long long LCM=((long long)a/gcd(max(a,b),min(a,b)))*b;
    cout<<LCM<<endl;
    return 0;
}
