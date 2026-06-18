#include<bits/stdc++.h>
using namespace std;


int main()
{
    int N,M;
    cin>>N>>M;

    vector<int> A(N), B(N);
    vector<int> C(M), D(M);

    for (int i = 0; i < N; i++) cin >> A[i];
    for (int i = 0; i < N; i++) cin >> B[i];

    for (int i = 0; i < M; i++) cin >> C[i];
    for (int i = 0; i < M; i++) cin >> D[i];

    vector<pair<int,int>> choc,box;

    for(int i=0;i<N;i++) choc.push_back({A[i],B[i]});
    for(int i=0;i<M;i++) box.push_back({C[i],D[i]});

    sort(choc.begin(),choc.end(),greater<>());
    sort(box.begin(),box.end(),greater<>());

    int ptr=0;

    multiset<int> available;

    for(auto [l,b] :choc)
    {
        while(ptr<M && box[ptr].first>=l)
        {
            available.insert(box[ptr].second);
            ptr++;
        }

        auto it=available.lower_bound(b);

        if(it==available.end())
        {
            cout<<"No";
            return 0;
        }

        available.erase(it);
    }

    cout<<"Yes";

    return 0;
}
