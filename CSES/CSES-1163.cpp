#include <bits/stdc++.h>
#include <ios>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int x, n;
    cin >> x >> n;

    set<int> pos;
    multiset<int> len;

    pos.insert(0);
    pos.insert(x);
    len.insert(x);

    for (int i = 0; i < n; i++) {
        int p;
        cin>>p;

        auto r=pos.upper_bound(p);
        auto l=prev(r);

        len.erase(len.find(*r - *l));

        int newl=p- *l;
        int newr=*r-p;
        len.insert(newl);
        len.insert(newr);

        pos.insert(p);

        cout<<*len.rbegin()<<" ";
    }
}
