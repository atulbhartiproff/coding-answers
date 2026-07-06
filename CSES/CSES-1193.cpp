#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> dir={{1,0,1},{0,1,2},{-1,0,3},{0,-1,4}};

int main()
{
    int n,m; cin>>n>>m;
    int x,y;
    vector<vector<char>> grid(n,vector<char>(m,'#'));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>grid[i][j];
            if(grid[i][j]=='A')
            {
                x=i;y=j;
            }
        }
    }
    vector<vector<char>> leg(n,vector<char>(m,'N'));
    queue<vector<int>> q;
    q.push({x,y});
    leg[x][y]='S';
    bool flag=false;
    while(!q.empty())
    {
        int i=q.front()[0];
        int j=q.front()[1];
        q.pop();

        for(auto d:dir)
        {
            int nx=i+d[0];
            int ny=j+d[1];
            if(nx<0 || ny<0 ||nx>=n ||ny>=m||grid[nx][ny]=='#' || leg[nx][ny]!='N') continue;

            if(d[2]==1) leg[nx][ny]='U';
            else if(d[2]==2) leg[nx][ny]='L';
            else if(d[2]==3) leg[nx][ny]='D';
            else if(d[2]==4) leg[nx][ny]='R';

            if(grid[nx][ny]=='B') {flag=true;x=nx;y=ny;break;}
            q.push({nx,ny});
        }
        if(flag) break;
    }

    if(!flag)
    {
        cout<<"NO"<<endl;
        return 0;
    }
    cout<<"YES"<<endl;
    string st="";
    while(grid[x][y]!='A')
    {
        if(leg[x][y]=='U')
        {
            x=x-1;
            st+="D";
        }
        else if(leg[x][y]=='D')
        {
            x=x+1;
            st+="U";
        }
        else if(leg[x][y]=='L')
        {
            y--;
            st+="R";
        }
        else if(leg[x][y]=='R')
        {
            y++;
            st+="L";
        }
    }

    reverse(st.begin(),st.end());
    cout<<st.size()<<"\n"<<st<<endl;

    return 0;

}
