#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <sstream>
#include <algorithm>
using namespace std;

int main(){
    
    string s;
    getline(cin, s);   
    
    // Remove square brackets and store in an array 
    s = s.substr(1, s.size() - 2);
    int arr[100000];
    stringstream ss(s);
    string num;
    
    int N = 0;
    while (getline(ss, num, ',')) {
        arr[N++] = stoi(num);
    }
    
    int median=0;
    sort(arr, arr + N);
    if (N % 2 == 1) {
        median = arr[N / 2];
    } else {
        median = (arr[N/2 - 1] + arr[N/2]) / 2;
    }

    cout << median << endl;
    
    return 0;
}