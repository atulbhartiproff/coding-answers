#include<bits/stdc++.h>
using namespace std;

std::string intToBinaryCustom(int n) {
    if (n == 0) return "0";

    std::string binary = "";
    bool isNegative = n < 0;

    // Convert to unsigned to prevent overflow issues with negative bounds
    unsigned int num = isNegative ? static_cast<unsigned int>(n) : n;

    while (num > 0) {
        binary += (num % 2 == 0) ? "0" : "1";
        num /= 2;
    }

    // The bits are generated in reverse order, so we flip the string
    std::reverse(binary.begin(), binary.end());
    return binary;
}

int main()
{
    int N,M;
    cin>>N>>M;
    vector<vector<int>> switches(M,vector<int>(N,0));
    for(int i=0;i<M;i++)
    {
        int s;
        cin>>s;
        for(int j=0;j<s;j++)
        {
            int temp;
            cin>>temp;
            switches[i][temp-1]=1;
        }
    }
    vector<int> bulbs(M,-1);
    for(int i=0;i<M;i++)
    {
        int temp;
        cin>>temp;
        bulbs[i]=temp;
    }

    cout<<"-----"<<endl;

    for(int i=0;i<pow(2,N);i++)
    {
        cout<<intToBinaryCustom(i)<<endl;
    }
    return 0;
}
