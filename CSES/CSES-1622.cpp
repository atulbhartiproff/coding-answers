#include<bits/stdc++.h>
using namespace std;

void perm(string s,string curr,int i,vector<bool> vis,int& cnt,set<string>& st)
{
    if(s.size()==curr.size())
    {
        cnt++;
        st.insert(curr);
        return;
    }

    for(int k=0;k<s.size();k++)
    {
        // if(k==i) continue;
        if(vis[k]==true) continue;

        vis[k]=true;
        perm(s,curr+""+s[k],k,vis,cnt,st);
        vis[k]=false;
    }
    return;
}


int main()
{
    string s;
    cin>>s;
    sort(s.begin(),s.end());
    vector<bool> vis(s.size(),false);
    int cnt=0;
    set<string> st;
    perm(s,"",0,vis,cnt,st);
    cout<<st.size()<<endl;
    for(string it:st)
    {
        cout<<it<<endl;
    }
    return 0;
}
