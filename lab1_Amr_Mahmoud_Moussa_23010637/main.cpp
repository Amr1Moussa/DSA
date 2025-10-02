#include <iostream>
using namespace std;

class ICalculator {
public:
    int multiply(int x, int y){
        return (x*y);
    }

    int bitwiseAnd(int x, int y){
        return (x&y);
    }
};

int main() {
    ICalculator calc;
    int x, y;

    cout << "Enter first number: ";
    cin >> x;
    cout << "Enter second number: ";
    cin >> y;

    cout << "Multiplication: " << calc.multiply(x, y) << endl;
    cout << "Bitwise AND: " << calc.bitwiseAnd(x, y);

    return 0;
}

// note: in Cpp no need to split interface from implementation