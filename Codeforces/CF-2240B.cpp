#include<bits/stdc++.h>
using namespace std;

using int64 = long long;

const int MOD = 998244353;

int64 pw(int64 a,int64 b){
    int64 r = 1;
    while(b){
        if(b&1) r=r*a%MOD;
        a= a*a %MOD;
        b>>= 1;
    }
    return r;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int64 n,m,r,c;
        cin>>n>>m>>r>>c;
        int64 e=(r-1)*m +(c-1)*n -(r-1)*(c-1);
        cout<<pw(2,e)<<"\n";
    }
    return 0;
}
