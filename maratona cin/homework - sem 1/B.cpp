#include <bits/stdc++.h>
using namespace std;
#define fIo ios::sync_with_stdio(false); cin.tie(NULL);

int main()
{
    fIo;
    int cases,v;
    string op;
    stack<int> bag;
    cin >> cases;
    while(cases--)
    {
        cin >> op;
        if(op == "PUSH")
        {
            cin >> v;
            if(bag.empty()) bag.push(v);
            else
            {
                bag.push(min(bag.top(), v));
            }
        } else if(op == "POP")
        {
            if(bag.empty()) cout << "EMPTY\n";
            else
            {
                bag.pop();
            }
        } else
        {
            if(bag.empty()) cout << "EMPTY\n";
            else
            {
                cout << bag.top() << "\n";
            }
        }
    }

}