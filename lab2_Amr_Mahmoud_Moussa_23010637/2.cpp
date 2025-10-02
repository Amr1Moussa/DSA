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
    
    int evenCount=0;
    int oddCount=0;
    for (int i=0 ; i < N ; i++)
    {   
        if (abs(arr[i])%2==0)
        {
            evenCount++;
        }
        if (abs(arr[i])%2==1)
        {
            oddCount++;
        }    
    } 
    
    cout << "[" << evenCount << "," << oddCount << "]" << endl;
    
    return 0;
}