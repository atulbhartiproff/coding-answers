#include<bits/stdc++.h>
using namespace std;

int poss(int n)
{
    if(n==0) return 2;
    if(n==1) return 7;
    if(n==2) return 2;
    if(n==3) return 3;
    if(n==4) return 3;
    if(n==5) return 4;
    if(n==6) return 2;
    if(n==7) return 5;
    if(n==8) return 1;
    if(n==9) return 2;
    return -1;
}

int main()
{
    int n;
    cin>>n;
    int a=n/10; a=poss(a);
    int b=n%10; b=poss(b);
    cout<<b*a;
    return 0;
}
