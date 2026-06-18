#include<bits/stdc++.h>
using namespace std;

void dfs(string& coll,string curr ,set<string>&st ,int n)
{
    if(curr.size()==n)
    {
        st.insert(curr);
        return;
    }

    for(int j=0;j<3;j++)
    {
        dfs(coll,curr+""+coll[j],st,n);
    }
}

int main()
{
    int n;
    cin>>n;
    set<string> st;
    string coll="abc";
    dfs(coll,"",st,n);
    for(auto it:st)
    {
        cout<<it<<endl;
    }
    return 0;
}
