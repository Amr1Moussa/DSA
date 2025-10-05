#include <iostream>
using namespace std;
# define ll long long

int main() {
    int n;
    cin >> n;

    ll arr[n][n];

    for (int i = 0; i < n; i++){
        // first and last elements in each row are 1
        arr[i][0] = 1; 
        arr[i][i] = 1;

        for (int j=1; j<i; j++){
            arr[i][j] = arr[i-1][j-1] + arr[i-1][j]; // each element is sum of two elements above it
        }
    }


    for (int i=0; i < n; i++){
        for (int j=0; j <= i; j++){
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
