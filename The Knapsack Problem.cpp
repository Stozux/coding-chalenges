#include <bits/stdc++.h>
using namespace std;

void printPo(int* A, int size)
{
    for(int i = 0; i < size; i++)
    {
        cout << A[i] << " ";
    }
    cout << "\n";
}







int main()
{
    int W,n;
    cin >> W >> n;
    int F[n+1][W+1];
    for (int i = 0; i < n+1; i++)
    {
        F[i][0] = 0;
    }
    for (int i = 0; i < W+1; i++)
    {
        F[0][i] = 0;
    }
    int w[n+1];
    w[0] = 0;
    int v[n+1];
    v[0] = 0;
    for(int i = 1; i < n+1; i++)
    {
        int peso,valor;
        cin >> peso >> valor;
        w[i] = peso;
        v[i] = valor;
    }
    // for(int i = 0; i<n+1; i++)
    // {
    //     printPo(F[i],W+1);
    // }
    // printPo(w,n);
    // printPo(v,n);
    for(int i = 0; i <= n; i++)
    {
        for(int j = 0; j <= W; j++)
        {
            if (i == 0 or j == 0)
            {
                F[i][j] = 0;
            }else if (w[i] <= j)
            {
                F[i][j] = max(F[i-1][j], v[i] + F[i-1][j-w[i]]);
            }else{
                F[i][j] = F[i-1][j];
            }
        }
    }
    int resultado = F[n][W];
    // int resultado = knapsack(n,W,w,v,F);
    cout << resultado << "\n";
    return 0;
}