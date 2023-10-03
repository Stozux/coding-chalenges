#include <iostream>
using namespace std;


int partition(int A[], int l, int r)
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

void quicksort(int A[], int l, int r)
{
if (l < r)
    {
        int s;
        s = partition(A,l,r);
        quicksort(A,l,s-1);
        quicksort(A,s+1,r);
    }
}


int bsearch (int A[], int l, int r, int K)
{
    if (r >= l)
    {
        int m = (l+r)/2;
        if (K == A[m])
        {
            return m;
        } else if (K < A[m])
        {
            return bsearch(A,l,m-1,K);
        } else
        {
            return bsearch(A,m+1,r, K);
        } 
        
        
        
    } else
    {
        return -1;
    }
}

int main()
{
    int n, k;
    cin >> n >> k;
    int array[n];
    for (int i = 0; i < n; i++)
    {
        cin >> array[i]; 
    }
    quicksort(array, 0, n-1);
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        int ans = bsearch(array, 0, n-1,array[i]+k);
        if (ans != -1)
        {
            sum += 1;
        }
    }
    cout << sum;
    return 0;
}
