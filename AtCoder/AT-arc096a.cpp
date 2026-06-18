#include<bits/stdc++.h>
using namespace std;

int main()
{
    long long a,b,ab,x,y,total;
    cin>>a>>b>>ab>>x>>y;
    if(2*ab<a+b)
    {
        total=min(x,y)*(ab*2);
        if(x>y) total+=min((x-y)*a,(x-y)*(2*ab));
        else total+=min((y-x)*b,(y-x)*(2*ab));
    }
    else {
        total=x*a+y*b;
    }
    cout<<total;

    return 0;
}
