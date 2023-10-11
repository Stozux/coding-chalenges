#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, h;
    cin >> n >> h;
    int altura;
    int c = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> altura;
        if(altura <= h) c++;
    }
    cout << c;
}