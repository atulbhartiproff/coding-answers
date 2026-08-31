#include<bits/stdc++.h>
using namespace std;

long long solve()
{
    long long n; cin>>n;
    string a; cin>>a;
    string b; cin>>b;

    // IF THE STRINGS ARE SAME JUST END
    if(a==b) return 0;
    long long acnt=0,bcnt=0;

    //ARRAYS FOR SOLUTION
    vector<long long> aodd,aeven;
    vector<long long> bodd,beven;

    //CHECK IF ITS EVEN POSSIBLE
    for(long long i=0;i<n;i+=2)
    {
        if(a[i]=='1') {acnt++;aeven.push_back(i);}
        if(b[i]=='1') {bcnt++;beven.push_back(i);}
    }
    if(acnt!=bcnt) return -1;
    acnt=0,bcnt=0;
    for(long long i=1;i<n;i+=2)
    {
        if(a[i]=='1') {acnt++;aodd.push_back(i);}
        if(b[i]=='1') {bcnt++;bodd.push_back(i);}
    }
    if(acnt!=bcnt) return -1;

    //FINDING ANSWER

    long long ans=0;
    for(long long i=0;i<aodd.size();i++)
    {
        ans+=abs(aodd[i]-bodd[i])/2;
    }
    for(long long i=0;i<aeven.size();i++)
    {
        ans+=abs(aeven[i]-beven[i])/2;
    }

    return ans;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long t;cin>>t;
    while(t-- >0)
    {
        cout<<solve()<<endl;
    }

    return 0;
}
