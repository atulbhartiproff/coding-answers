#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> dir={{0,1},{1,0},{0,-1},{-1,0}};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int h,w;
    cin>>h>>w;
    queue<vector<int>> q;
    vector<vector<char>> grid(h,vector<char>(w,'.'));
    for(int i=0;i<h;i++)
    {
        for(int j=0;j<w;j++)
        {
            cin>>grid[i][j];
            if(grid[i][j]=='#') q.push({i,j,0});
        }
    }

    int time=0;
    while(!q.empty())
    {
        vector<int> curr=q.front();
        time=max(time,curr[2]);
        q.pop();
        for(auto d: dir)
        {
            int nx=curr[0]+d[0];
            int ny=curr[1]+d[1];
            if(nx<0 || ny<0 || nx>=h || ny>=w || grid[nx][ny]=='#') continue;
            grid[nx][ny]='#';
            q.push({nx,ny,curr[2]+1});
        }
    }

    cout<<time<<endl;
    return 0;
}
