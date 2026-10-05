#include <bits/stdc++.h>
using namespace std;

class Replayer{
public:
	int start_seq,max_buffer;
	set<int> buff;
	map<int,char> mapping;
	Replayer(int star,int buffer)
	{
		start_seq=star;
		max_buffer=buffer;
		buff={};
		mapping={};
	}

	void push(int n, char c)
	{
	    if(n==start_seq)
		{
		    buff.insert(n);
			mapping[n]=c;
			while(buff.count(start_seq)>0)
			{
			// cout << "DEBUG: " << start_seq << endl;
			    cout<<mapping[start_seq]<<" ";
				buff.erase(start_seq);
				start_seq++;
			}
			cout<<endl;
		}
		else
		{
		    if(buff.count(n)>0)
			{
			    cout<<"null"<<endl;
			}
			else if(buff.size()==max_buffer)
			{
			    cout<<"error"<<endl;
			}
			else
			{
			    buff.insert(n);
				mapping[n]=c;
				cout<<"null"<<endl;
			}
		}

	}



};


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string command;
    Replayer* r=nullptr;

    while(cin>>command)
    {
        if(command=="Replayer")
        {
            int s,b;
            cin>>s>>b;

            r=new Replayer(s,b);
        }
        else if(command=="push")
        {
            int seq;char load;
            cin>>seq>>load;

            r->push(seq,load);
        }
    }


    return 0;
}
