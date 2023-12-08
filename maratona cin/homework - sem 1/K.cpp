#include <bits/stdc++.h>
using namespace std;
#define fIo ios::sync_with_stdio(false); cin.tie(NULL);

int main()
{
    fIo;
    int lenght = 1;
    int e,soma;
    priority_queue<int,vector<int>,greater<int>> fila;
    while(lenght != 0)
    {
        cin >> lenght;
        if(lenght == 0) break;
        for(int i = 0; i < lenght; i++)
        {
            cin >> e;
            fila.push(e);
        }
        soma = 0;
        while (fila.size() > 1)
        {
            e = fila.top();
            fila.pop();
            e += fila.top();
            fila.pop();
            soma+=e;
            fila.push(e);
        }
        cout << soma << "\n";
        fila.pop();
    }
}


