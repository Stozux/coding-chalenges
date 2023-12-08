#include <bits/stdc++.h>
using namespace std;
#define fIo ios::sync_with_stdio(false); cin.tie(NULL);

int main()
{
    fIo;
    stack<char> numbers,oper;
    int cases;
    string s;
    cin >> cases;
    while (cases--)
    {

        cin >> s;
        for(auto e:s)
        {
            if(e == '/' or e == '*' or e == '+' or e == '-' or e == '^' or e == '(' )
            {
                oper.push(e);
            }else if (e == ')')
            {
                while(oper.top() != '(')
                {
                    cout << oper.top();
                    oper.pop();
                }
                oper.pop();
            } else
            {
                cout << e;
            }
        }
        cout << "\n";
    }
    


}
