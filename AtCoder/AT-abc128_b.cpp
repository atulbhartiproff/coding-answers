#include<bits/stdc++.h>
using namespace std;

auto comp(pair<string,int>a,pair<string,int>b)
{
    if(a.first==b.first)
    {
        return a.second>b.second;
    }
     return a.first<b.first;

}

int main()
{
    int N;
    cin>>N;
    vector<pair<string,int>> r(N);
    for(int i=0;i<N;i++)
    {
        cin>>r[i].first>>r[i].second;
    }
    vector<pair<string,int>> og=r;
    sort(r.begin(),r.end(),comp);

    for(auto g:r)
    {
        for(int i=0;i<r.size();i++)
        {
            if(og[i].first==g.first && og[i].second==g.second)
            {

                cout<<i+1<<endl;
                break;
            }
        }
    }
    return 0;
}
