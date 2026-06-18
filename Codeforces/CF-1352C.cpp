#include<bits/stdc++.h>
using namespace std;


void test()
{
    long long k,n;
    cin>>k>>n;

    // not div by 5
    // every multiple means 4 not divisible (k-1)
    // if i want 10th not divisible , i do 2nd multiple and then 2nd not divisible
    // if i want 8th not divisible , i do 2nd multiple and then 1st behind.

    int mul=n/(k-1);
    int rem=n%(k-1);

    if(rem==0)
    {
        cout<<(k*mul)-1<<endl;
        return;
    }

    cout<<(k*mul)+rem<<endl;
    return;

    return;
}


int main()
{
    long long t;
    cin>>t;
    while(t>0)
    {
        test();
        t--;
    }

    return 0;
}
