#include <bits/stdc++.h>
using namespace std;
#define fIo ios::sync_with_stdio(false); cin.tie(NULL);

int main()
{
    fIo;
    int cases,v,p;
    cin >> cases;
    string op;
    deque<int> fila;
    bool r = false;
    while (cases--)
    {  
       cin >> op;
       if(op == "reverse") r = !r;
       else
       {
        if(op == "back" or op == "front")
        {
            if(fila.empty()) cout << "No job for Ada?\n";
            else
            {
                if(r)
                {
                    if(op == "back") 
                    {
                        cout << fila.front() << "\n";
                        fila.pop_front();
                    } else if(op == "front")
                    {
                        cout << fila.back() << "\n";
                        fila.pop_back();
                    }
                } else
                {
                    if(op == "back") 
                    {
                        cout << fila.back() << "\n";
                        fila.pop_back();
                    } else if(op == "front")
                    {
                        cout << fila.front() << "\n";
                        fila.pop_front();
                    }
                }
                
            }
        } else if(op == "toFront" or op == "push_back")
        {
            cin >> v;
            if(r)
            {
                if(op == "toFront") fila.push_back(v);
                else if(op == "push_back") fila.push_front(v);
            } else
            {
                if(op =="toFront") fila.push_front(v);
                else if (op == "push_back") fila.push_back(v);
            }
        }
       }
        
    }
}