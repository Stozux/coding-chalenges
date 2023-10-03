#include <iostream>
using namespace std;


int main(){
    long long x, y, z;

    cin >> x >> y >> z;

    long long total_1, total_2;

    total_1 = x/z + (x%z != 0);
    total_2 = y/z + (y%z != 0);

    cout << total_1 * total_2 <<endl;  
    return 0;
}

