#include<bits/stdc++.h>
using namespace std;

vector<pair<int,int>> dir={{1,0},{0,1},{-1,0},{0,-1}};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int h,w; cin>>h>>w;
    vector<vector<char>> grid(h,vector<char>(w,'.'));
    int black=0;
    for(int i=0;i<h;i++)
    {
        for(int j=0;j<w;j++)
        {
            cin>>grid[i][j];
            if(grid[i][j]=='#') black++;
        }
    }

    queue<vector<int>>  q;
    vector<vector<bool>> vis(h,vector<bool>(w,false));
    q.push({0,0,1}); vis[0][0]=true;
    int path=0;
    if(grid[0][0] == '#' || grid[h-1][w-1] == '#'){
        cout << -1 << '\n';
        return 0;
    }
    while(!q.empty())
    {
        vector<int> curr=q.front();
        q.pop();

        for(auto d:dir)
        {
            int nx=curr[0]+d.first;
            int ny=curr[1]+d.second;
            if(nx<0 || ny<0 || nx>=h || ny>= w || grid[nx][ny]=='#' || vis[nx][ny]) continue;
            if(nx==h-1 && ny==w-1)
            {
                path=curr[2]+1;
                break;
            }
            q.push({nx,ny,curr[2]+1});
            vis[nx][ny]=true;
        }
        if(path>0) break;
    }
    if(path==0){
        cout << -1 << '\n';
        return 0;
    }
    cout<<(h*w)-path-black<<endl;
    return 0;
}
