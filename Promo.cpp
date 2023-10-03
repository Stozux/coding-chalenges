#include <iostream>
using namespace std;


int partition(long long int A[], int l, int r)
{
    int p = A[l], i = l, j = r+1;
    do
    {
        do
        {
            i++;
        } while (A[i] < p && i < r);
        do
        {
            j--;
        } while (A[j] > p);
        swap (A[i], A[j]);
    } while (i < j);
    swap (A[i], A[j]);
    swap (A[l], A[j]);
    return j;
}

void quicksort(long long int A[], int l, int r)
{
if (l < r)
    {
        int s;
        s = partition(A,l,r);
        quicksort(A,l,s-1);
        quicksort(A,s+1,r);
    }
}


void prefixsum(long long int A[], int size)
{
    for (int i = 1; i < size; i++)
    {
        A[i] += A[i-1];
    }
}


int main()
{
    int n_itens, queries;
    cin >> n_itens >> queries;
    n_itens += 1;
    long long int prices[n_itens];
    prices[0] = 0;
    for (int i = 1; i < n_itens; i++)
    {
        cin >> prices[i]; 
    }
    quicksort(prices, 0, n_itens-1);
    prefixsum(prices,n_itens);
    for (int i = 0; i < queries; i++)
    {
        int x,y;
        cin >> x >> y;
        cout << prices[n_itens-x-1+y] - prices[n_itens-x-1] << "\n";
    }
    return 0;
}




