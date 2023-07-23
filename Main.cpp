#include "iostream"
#include "Polynomial/Polynomial.h"
using namespace std;

int main() {
    Polynomial polynomial1(3);
    Polynomial polynomial2(4);

    cin>>polynomial1;
    cin>>polynomial2;

    cout<<polynomial1;
    cout<<polynomial2;

    Polynomial sum = polynomial1 + polynomial2;
    cout<<sum;

    return 0;
}