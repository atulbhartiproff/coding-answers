#include<bits/stdc++.h>
using namespace std;

long long divide(long long N,unordered_map<long long,long long>& mp)
{
    if(N<=1) return 0;
   if(mp.find(N)!=mp.end()) return mp[N];

   long long up=N/2;
   long long down=(N+1)/2;

   if(mp.find(up)==mp.end()) mp[up]=divide(up,mp);
   if(mp.find(down)==mp.end()) mp[down]=divide(down,mp);

   return N+mp[up]+mp[down];
}


int main()
{
    long long N;
    cin>>N;
    unordered_map<long long,long long> mp;
    mp[0]=0;mp[1]=0;mp[2]=2;
    mp[N]=divide(N,mp);
    cout<<mp[N]<<endl;
    return 0;
}
