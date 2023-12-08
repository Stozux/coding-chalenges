#include <bits/stdc++.h>
using namespace std;

bool check(vector<int>& arr, int x,int m)
{

}

// void busca(vector<int>& arr, int x)
// {
//     int l = 1, r = 1e18+5;
//     int best = r;
//     while(l<r)
//     {
//         int m = (l+r)/2;
//         if(check(arr,x,m))
//         {
//             best = m;
//             r = m;
//         } else l = m+1;
//     }
// }



// int bs(vector<int>& arr, int x)
// {
//     int l = 0;
//     int r = arr.size();
//     while(l<r)
//     {
//         int m = (l+r)/2;
//         if(arr[m] == x) return m;
//         else if(arr[m] > x) r = m;
//         else if(arr[m] < x) l = m+1;
//     }
//     return -1;
// }




int bs(vector<int>& arr, int x)
{
    int l = 0;
    int r = arr.size();
    while (l < r)
    {
        int m = (l+r)/2;
        if(arr[m] == x) return m;
        else if(arr[m] > x) r = m;
        else if(arr[m] < x) l = m+1;
    }
    return -1;
}



int bsa(vector<int>& arr, int x)
{
    int l = 0;
    int r = arr.size();
    int best = r;
    while (l < r)
    {
        int m = (l+r)/2;
        if(check(arr,x,m))//m>=x
        {
            best = m;
            r = m;
        } else l = m+1;
    }
    return best;
}




















int main()
{
    
}
