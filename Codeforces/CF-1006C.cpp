#include<bits/stdc++.h>
#include <vector>
using namespace std;

void test(vector<long long>& arr, long long n)
{
    long long l=0,r=n-1;
    long long t=0;
    vector<long long> prefl=arr;
    vector<long long> prefr=arr;

    for(long long i=1;i<n;i++) prefl[i]+=prefl[i-1];
    for(long long i=n-2;i>=0;i--) prefr[i]+=prefr[i+1];

    while(l<r)
    {
        if(prefl[l]<prefr[r]) l++;
        else if (prefr[r]<prefl[l]) r--;
        else
         {
             t=prefl[l];
             l++;r--;
         }
    }
    cout<<t<<endl;
}

int main()
{
    long long n;
    cin>>n;
    vector<long long> arr(n);
    for(long long i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    test(arr,n);
    return 0;
}
