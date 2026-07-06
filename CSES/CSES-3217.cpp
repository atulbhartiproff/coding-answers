#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> dir={{2,1},{2,-1},{1,2},{1,-2},{-2,1},{-2,-1},{-1,2},{-1,-2}};

int main()
{
    int n; cin>>n;
    vector<vector<int>> grid(n,vector<int>(n,-1));
    grid[0][0]=0;
    queue<vector<int>> q;
    q.push({0,0,0});
    while(!q.empty())
    {
        vector<int> curr=q.front();
        q.pop();
        for(auto i:dir)
        {
            int nx=curr[0]+i[0];
            int ny=curr[1]+i[1];
            if(nx<0 || ny<0 || nx>=n || ny>=n) continue;
            if(grid[nx][ny]!=-1) continue;
            grid[nx][ny]=curr[2]+1;
            q.push({nx,ny,grid[nx][ny]});
        }
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout<<grid[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
