#include <iostream>
#include <cmath>
#include <sstream>

using namespace std;

int main(){

    string s;
    getline(cin, s);   
    
    // if empty
    if (s == "[]") {
        cout << "[]" << endl;
        return 0;
    }

    // Remove square brackets and store in an array 
    s = s.substr(1, s.size() - 2);
    int arr[100000];
    stringstream ss(s);
    string num;
    
    int N = 0;
    while (getline(ss, num, ',')) {
        arr[N++] = stoi(num);
    }
    
    int min=arr[0];
    int max=arr[0];
    for (int i=0 ; i < N ; i++)
    {   
        if (arr[i]<min)
        {
            min=arr[i];
        }
        if (arr[i]>max)
        {
            max=arr[i];
        }    
    } 
    
    cout << "[" << min << "," << max << "]" << endl;
    
    return 0;
}