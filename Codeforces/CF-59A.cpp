#include<bits/stdc++.h>
using namespace std;

int main()
{
    string st;
    cin>>st;
    int small=0,big=0;
    for(char ch:st)
    {
        if(isupper(ch))big++;
        else small++;
    }

    string ans="";
    for(char ch:st)
    {
        if(small>=big) ans+=tolower(ch);
        else ans+=toupper(ch);
    }
    cout<<ans;
    return 0;
}
