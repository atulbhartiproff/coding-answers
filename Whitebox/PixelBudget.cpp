#include <bits/stdc++.h>
#include <vector>
using namespace std;

void brightness(vector<vector<vector<int>>>& images, int idx , int d)
{
    for(int i=0;i<images[idx].size();i++)
    {
        for(int j=0;j<images[idx][i].size();j++)
        {
            images[idx][i][j]+=d;
            images[idx][i][j]=max(0,min(255,images[idx][i][j]));
        }
    }
}
void flipv(vector<vector<vector<int>>>& images, int idx)
{
    int t=0,b=images[idx].size()-1;
    while(t<=b)
    {
        for(int i=0;i<images[idx][t].size();i++)
        {
            int temp=images[idx][t][i];
            images[idx][t][i]=images[idx][b][i];
            images[idx][b][i]=temp;
        }
        t++;
        b--;
    }
}

void fliph(vector<vector<vector<int>>>& images , int idx)
{
    int l=0,r=images[idx][0].size()-1;
    while(l<=r)
    {
        for(int i=0;i<images[idx].size();i++)
        {
            int temp=images[idx][i][l];
            images[idx][i][l]=images[idx][i][r];
            images[idx][i][r]=temp;
        }
        l++;
        r--;
    }
}


void crop(vector<vector<vector<int>>>& images,int r , int c, int h, int w, int idx)
{
    vector<vector<int>> temp(h,vector<int>(w,0));
    for(int i=0;i<h;i++)
    {
        for(int j=0;j<w;j++)
        {
            temp[i][j]=images[idx][r+i][c+j];
        }
    }
    images[idx]=temp;
}

void threshold(vector<vector<vector<int>>>& images, int idx, int thres)
{
    for(int i=0;i<images[idx].size();i++)
    {
        for(int j=0;j<images[idx][0].size();j++)
        {
            images[idx][i][j]=images[idx][i][j]>=thres?255:0;
        }
    }
}

void rotate90(vector<vector<vector<int>>>& images, int idx)
{
    int h = images[idx].size();
    int w = images[idx][0].size();

    vector<vector<int>> temp(w, vector<int>(h));

    for(int r = 0; r < h; r++)
    {
        for(int c = 0; c < w; c++)
        {
            temp[c][h - 1 - r] = images[idx][r][c];
        }
    }

    images[idx] = temp;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
	int n; cin>>n;

	vector<vector<vector<int>>> images;

	for(int i=0;i<n;i++)
	{
		int h,w;
		cin>>h>>w;
		vector<vector<int>> im(h,vector<int>(w,0));
		for(int j=0;j<h;j++)
		{
			for(int k=0;k<w;k++)
			{
				cin>>im[j][k];
			}
		}
		images.push_back(im);
	}

	int s; cin>>s;
	for(int t=0;t<s;t++)
	{
	    vector<vector<vector<int>>> imagescopy=images;
		int idx,k;
		cin>>idx>>k;
		while(k-- >0)
		{
			string q; cin>>q;
			if(q=="BRIGHTNESS")
			{
				int d; cin>>d;
				brightness(imagescopy, idx, d);
			}
			else if(q=="FLIP_H")
			{
			    fliph(imagescopy,idx);
			}
			else if(q=="FLIP_V")
			{
			    flipv(imagescopy, idx);
			}
			else if(q=="CROP")
			{
				int r,c,h,w;
				cin>>r>>c>>h>>w;
				crop(imagescopy, r, c, h, w, idx);
			}
			else if(q=="ROTATE_90")
			{
			    rotate90(imagescopy, idx);
			}
			else if(q=="THRESHOLD")
			{
				int thres; cin>>thres;
				threshold(imagescopy, idx, thres);
			}
		}
		cout<<imagescopy[idx].size()<<" "<<imagescopy[idx][0].size()<<endl;
		for(auto& row:imagescopy[idx])
		{
			for(auto& col:row)
			{
				cout<<col<<" ";
			}
			cout<<endl;
		}
	}

    return 0;
}
