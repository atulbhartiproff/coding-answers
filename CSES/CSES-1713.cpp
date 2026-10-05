#include <algorithm>
#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin>>n;
    vector<int> arr(n);
    for(auto& i:arr) cin>>i;
    int maxi=*max_element(arr.begin(),arr.end());

    vector<int> nums(maxi+1,1);
    for(int i=2;i<=maxi;i++)
    {
        for(int j=i;j<=maxi;j+=i)
        {
            nums[j]++;
        }
    }

    for(auto& i:arr)
    {
        cout<<nums[i]<<endl;
    }
    return 0;
}
