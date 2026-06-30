#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,x;
    cin>>n>>x;
    vector<int> child(n);
    for(int i=0;i<n;i++) cin>>child[i];

    sort(child.begin(),child.end());

    int l=0,r=child.size()-1;
    int cnt=0;
    while(l<=r)
    {
        int rem=x;
        if(child[r]<=rem) {rem-=child[r];r--;}
        if(child[l]<=rem) {rem-=child[l];l++;}
        // cout<<rem<<endl;
        if(rem!=x)cnt++;
        else break;
    }
    cout<<cnt<<endl;
    return 0;
}
