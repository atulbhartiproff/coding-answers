#include<bits/stdc++.h>
using namespace std;

int maxwin(vector<int>& arr,int N)
{
    int l=0,r=0;
    map<int,int> freq;
    int len=0;
    int maxi=0;
    while(r<N)
    {
        if(freq[arr[r]]>0)
        {
            while(freq[arr[r]]>0)
            {
                freq[arr[l]]--;
                l++;
            }
        }
        len=r-l+1;
        maxi=max(maxi,len);
        freq[arr[r]]++;
        r++;
    }
    return maxi;
}

int main()
{
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    cout<<maxwin(arr,n);
    return 0;
}
