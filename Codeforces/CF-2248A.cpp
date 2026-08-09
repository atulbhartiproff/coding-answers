#include<bits/stdc++.h>
using namespace std;

string Bob(string x)
{
    int i=0;
    for(i=0;i<x.size();i++)
    {
        if(x[i]=='1') break;
    }
    if(i==x.size()) return x;

    string ns=x.substr(0,i)+x.substr(i+1);
    return ns;
}

string Alice(string x, int idx)
{
    string ns=x;
    ns.erase(idx,1);
    return ns;
}


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin>>t;
    while(t-- >0)
    {
        string st;
        cin>>st;
        vector<int> z;
        for(int i=0;i<st.size();i++)
        {
            if(st[i]=='0')
            {
                z.push_back(i);
            }
        }

        string res1=Bob(Alice(st,z[0]));

        if(z.size()>=2)
        {
            string res2=Bob(Alice(st,z[1]));
            cout<<max(res1,res2)<<endl;
        }
        else {
            cout<<res1<<endl;
        }
    }
}
