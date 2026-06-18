#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> dir={{1,1},{-1,1},{-1,-1},{1,-1},{0,1},{1,0},{0,-1},{-1,0}};

bool isSafe(vector<vector<char>>& grid, int x, int y)
{

    for(auto d:dir)
    {
        int nx=x+d[0];int ny=y+d[1];
        while(nx>=0 && ny>=0 && nx<grid.size() && ny<grid[0].size())
        {
            if(grid[nx][ny]=='Q') return false;
            nx+=d[0];ny+=d[1];
        }
    }

    return true;
}


void Queens(vector<vector<char>>& grid, int r,int& cnt)
{
    if(r==grid.size())
    {
        cnt++;
        return;
    }

    for(int i=0;i<8;i++)
    {
        if(grid[r][i]=='.')
        {
            if(isSafe(grid,r,i))
            {
                grid[r][i]='Q';
                Queens(grid,r+1,cnt);
                grid[r][i]='.';
            }
        }
    }
}


int main()
{
    vector<vector<char>> grid(8,vector<char>(8,'.'));
    for(int i=0;i<8;i++)
    {
        for(int j=0;j<8;j++)
        {
            cin>>grid[i][j];
        }
    }
    int cnt=0;
    Queens(grid,0,cnt);
    cout<<cnt<<endl;
    return 0;
}
