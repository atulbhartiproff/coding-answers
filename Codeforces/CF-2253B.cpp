#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin>>t;

    while(t-- >0)
    {

        // cout<<"For testcase "<<12-t<<endl;
        int n; cin>>n;
        vector<int> arr(n);
        for(auto& i:arr) cin>>i;
        int cnt=n;
        vector<pair<int,int>> blocks;
        for(int i=1;i<n;i++)
        {
            if(arr[i]==arr[i-1]) cnt--;
        }
        int curr=1,col=arr[0];
        for(int i=1;i<n;i++)
        {
            if(arr[i]==col) curr++;
            else
            {
                blocks.push_back({curr,col});
                curr=1,col=arr[i];
            }
        }
        blocks.push_back({curr,col});
        int inc1=false,inc2=false;
        int sz=blocks.size();
        for(int i=0;i<(int)sz-1;i++)
        {
            if(blocks[i].first>=2 && blocks[i+1].first>=2)
            {
                inc2=true;
                break;
            }
        }
        if(inc2==false)
        {
            for(int i=0;i<(int)sz-2;i++)
            {
                if(blocks[i].first<2) continue;

                if(blocks[i].second!=blocks[i+2].second)
                {
                    inc1=true;
                    break;
                }
            }
            for(int i=2;i<sz;i++)
            {
                if(blocks[i].first<2) continue;

                if(blocks[i].second!=blocks[i-2].second)
                {
                    inc1=true;
                    break;
                }
            }
            if(sz>=2 && blocks[1].first>=2 && blocks[0].first==1) inc1=true;
            if(sz>=2 && blocks[(int)sz-2].first>=2 && blocks[(int)sz-1].first==1) inc1=true;
        }
        // cout<<"Blocks: "<<blocks.size()<<endl;
        if(inc2) cnt+=2;
        else if(inc1) cnt++;
        cout<<cnt<<endl;

    }
    return 0;
}
