#include<bits/stdc++.h>
using namespace std;

void solve()
{
    int n; cin>>n;
    string a,b; cin>>a; cin>>b;
    if(a==b)
    {
        cout<<"YES"<<endl;
    }
    else if(n<3)
    {
        cout<<"NO"<<endl;
    }
    // else {
    //     int aone=0,bone=0;
    //     int alast=0,blast=0;
    //     for(int i=0;i<n;i++)
    //     {
    //         if(a[i]=='1') {aone++;alast=i;}
    //         if(b[i]=='1') {bone++;blast=i;}
    //     }
    //     if(aone!=bone || n<3)
    //     {
    //         cout<<"NO"<<endl;
    //     }

    //     else {
    //         if((blast-alast)%2==1) cout<<"NO"<<endl;
    //         else cout<<"YES"<<endl;
    //     }
    // }
    else {
        string odda="",oddb="",evena="",evenb="";
        for(int i=1;i<n;i+=2)
        {
            odda+=a[i]; oddb+=b[i];
        }
        for(int i=0;i<n;i+=2)
        {
            evena+=a[i];evenb+=b[i];
        }

        int aone=0,bone=0;

        for(int i=0;i<odda.size();i++)
        {
            if(odda[i]=='1') aone++;
            if(oddb[i]=='1') bone++;
        }
        if(aone!=bone)
        {
            cout << "NO" <<endl;
        }
        else
        {
            for(int i=0;i<evena.size();i++)
            {
                if(evena[i]=='1') aone++;
                if(evenb[i]=='1') bone++;
            }
            if(aone!=bone) cout<<"NO"<<endl;
            else cout<<"YES"<<endl;
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;cin>>t;
    while(t-- >0)
    {
        solve();
    }

    return 0;
}
