#include<bits/stdc++.h>
using namespace std;

void test()
{
    int n,k;
    cin>>n>>k;
    string s;
    cin>>s;
    sort(s.begin(),s.end());
    if(s[0]!=s[k-1])
    {
        cout<<s[k-1]<<endl;
        return;
    }
    else {
        if(k==n)
        {
            cout<<s[0]<<endl;
            return;
        }
        if(s[k]==s[n-1])
        {
            int rem=n-k;
            rem=ceil((rem+k-1)/k);
            cout<<s[0]+s.substr(k,rem)<<endl;
            return;
        }
        else {
            cout<<s[0]+s.substr(k)<<endl;
            return;
        }
    }
}


int main()
{
    int t;
    cin>>t;
    while(t>0)
    {
        test();
        t--;
    }
    return 0;
}
