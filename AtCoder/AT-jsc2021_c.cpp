#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int a,b;
    cin>>a>>b;

    int maxi=b-a;

    while(maxi>1)
    {
        int mul=(a+maxi-1)/maxi;
        if(maxi*(mul+1)>=a && maxi*(mul+1)<=b)
        {
            cout<<maxi<<endl;
            return 0;
        }
        maxi--;
    }
    cout<<1<<endl;
    return 0;
}
