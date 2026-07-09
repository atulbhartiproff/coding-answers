#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n; cin>>n;
    vector<int> arr(n);
    for(auto& i:arr) cin>>i;

    stack <int> st;
    vector<int> ans(n,0);

    for(int i=n-1;i>=0;i--)
    {
        while(!st.empty() && arr[st.top()]>arr[i])
        {
            ans[st.top()]=i+1;
            st.pop();
        }

        st.push(i);
    }

    for(auto i:ans)
    {
        cout<<i<<" ";
    }
    cout<<endl;
    return 0;
}
