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
    
    string ispalindrome = "YES";
    for (int i=0 ; i < N/2 ; i++)
    {   
        if (arr[i]!=arr[N-i-1])
        {
            ispalindrome="NO";
            break;
        }
    }

    cout << ispalindrome << endl;

    return 0;
}