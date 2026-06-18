#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> dir={{0,1},{1,0},{0,-1},{-1,0}};

int dfs(string& st,vector<vector<int>>& grid,int i,int j,int cnt)
{
    if(i==6 && j==0)
    {
        if(cnt==48) return 1;
        return 0;
    }
    if(cnt==48) return 0;

    bool up=(i-1>=0 && grid[i-1][j]==0);
    bool down=(i+1<grid.size() && grid[i+1][j]==0);
    bool left=(j-1>=0 && grid[i][j-1]==0);
    bool right=(j+1<grid[0].size() && grid[i][j+1]==0);

    if(!up && !down && left && right ) return 0;
    if(up && down && !left && !right ) return 0;
    // if(!up && !down && left && right && i-1>=0 && i+1<grid.size()) return 0;
    // if(up && down && !left && !right && j-1>=0 && j+1<grid[0].size()) return 0;

    grid[i][j]=1;
    int ans=0;
    int nx=i,ny=j;
    if(st[cnt]=='L') ny--;
    if(st[cnt]=='U') nx--;
    if(st[cnt]=='D') nx++;
    if(st[cnt]=='R') ny++;

    if(st[cnt]!='?')
    {
        if(nx>=0 && ny>=0 && nx<grid.size() && ny<grid[0].size() && grid[nx][ny]==0 )
            ans+=dfs(st,grid,nx,ny,cnt+1);
    }
    else {
        if(up)ans+=dfs(st,grid,i-1,j,cnt+1);
        if(down)ans+=dfs(st,grid,i+1,j,cnt+1);
        if(left)ans+=dfs(st,grid,i,j-1,cnt+1);
        if(right)ans+=dfs(st,grid,i,j+1,cnt+1);
    }

    grid[i][j]=0;
    return ans;
}


int main()
{
    string st;
    cin>>st;
    vector<vector<int>> grid(7,vector<int>(7,0));
    int total=0;
    total+=dfs(st,grid,0,0,0);
    cout<<total<<endl;
    return 0;
}
