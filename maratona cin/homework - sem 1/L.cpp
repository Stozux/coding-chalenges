#include <bits/stdc++.h>
using namespace std;
#define fIo ios::sync_with_stdio(false); cin.tie(NULL);

int main()
{
    fIo;
    int cases, bf, tamanhoG, tamangoB,n;
    cin >> cases;
    priority_queue<int> green_army, blue_army;
    vector<int> lutadosG,lutadosB;
    while (cases--)
    {
        cin >> bf >> tamanhoG >>tamangoB;
        for(int i = 0; i < tamanhoG;i++)
        {
            cin >> n;
            green_army.push(n);
        }
        for(int i = 0; i < tamangoB; i++)
        {
            cin >> n;
            blue_army.push(n);
        }
        while(!blue_army.empty() and !green_army.empty())
        {
            if(blue_army.empty() or green_army.empty()) break;
            lutadosB.clear();
            lutadosG.clear();
            for(int i = 0; i < bf; i++)
            {
                if(blue_army.empty() or green_army.empty()) break;
                int lg = green_army.top();
                green_army.pop();
                int lb = blue_army.top();
                blue_army.pop();
                if(lg > lb) lutadosG.push_back(lg-lb);
                else if(lb > lg) lutadosB.push_back(lb-lg);
            }
            for(auto element:lutadosB) blue_army.push(element);
            for(auto element:lutadosG) green_army.push(element);
        }
        int tb = blue_army.size();
        int tg = green_army.size();
        if(tb > tg)   
        {
            cout << "blue wins\n";
            
            for(int i = 0; i < tb; i++)
            {
                cout << blue_army.top() << "\n";
                blue_army.pop();
            }    
            if(cases > 0) cout << "\n";
            for(int i = 0;i<tg;i++) green_army.pop(); 
        } else if(tg > tb)
        {
            cout << "green wins\n";
            for(int i = 0; i < tg;i++)
            {
                cout << green_army.top() << "\n";
                green_army.pop();
            }
            if(cases > 0) cout << "\n";
            for(int i = 0;i<tb;i++) blue_army.pop(); 
        } else 
        {
            cout << "green and blue died\n";
            if(cases > 0) cout << "\n";
        }
    }

    
}
