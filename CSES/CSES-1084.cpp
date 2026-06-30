#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,m,k;
    cin>>n>>m>>k;
    vector<int> app(n);
    vector<int> house(m);
    for(int i=0;i<n;i++) cin>>app[i];
    for(int i=0;i<m;i++) cin>>house[i];

    sort(app.begin(),app.end());
    sort(house.begin(),house.end());

    int cnt=0,l=0;
    for(int i:app)
    {
        while(l<m && house[l]<i-k) l++;

        if(l==m) break;

        if(house[l]>=i-k && house[l]<=i+k)
        {
            cnt++; l++;
        }
        else {
        continue;
        }
    }

    cout<<cnt<<endl;
    return 0;
}
