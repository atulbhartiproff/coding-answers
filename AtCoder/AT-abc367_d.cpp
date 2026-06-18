#include<bits/stdc++.h>
using namespace std;

int steps(vector<int>& arr,int n,int m)
{
    int ans=0;

    // for(int i=0;i<n;i++)
    // {
    //     int sum=0;
    //     for(int j=0;j<n-1;j++)
    //     {
    //         int target=(i+j)%n;
    //         sum+=arr[target];
    //         if(sum%m==0) ans++;
    //     }
    // }


    vector<vector<int>>dp(n+1,vector<int>(n+1,0));

    for(int i=1;i<n+1;i++)
    {
        for(int j=1;j<n+1;j++)
        {

        }
    }


    return ans;
}

int main()
{
    int N,M;
    cin>>N>>M;
    vector<int> arr(N);
    for(int i=0;i<N;i++)
    {
        cin>>arr[i];
    }
    cout<<steps(arr,N,M);
    return 0;
}
