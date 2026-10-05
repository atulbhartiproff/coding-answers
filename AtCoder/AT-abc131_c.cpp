#include<bits/stdc++.h>
using namespace std;

long long gcd(long long a,long long b)
{
    if(b==0) return a;
    return gcd(b,a%b);
}


long long LCM(long long a,long long b)
{
    long long prod=a*b;
    return prod/gcd(max(a,b),min(a,b));
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    long long a,b,c,d;
    cin>>a>>b>>c>>d;
    long long csta=(a+c-1)/c;
    long long cend=b/c;
    long long dsta=(a+d-1)/d;
    long long dend=b/d;


    long long lcm=LCM(c,d);
    long long lcmsta=(a+lcm-1)/lcm;
    long long lcmend=b/lcm;

    long long cra=cend-csta+1;
    long long dra=dend-dsta+1;
    long long lra=lcmend-lcmsta+1;
    cout<<(b-a)-(cra+dra-lra)+1;
    return 0;
}
