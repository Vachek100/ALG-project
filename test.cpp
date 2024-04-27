#include <iostream>
#include <vector>
#include <cmath>
#include "functions.cpp"

using namespace std;


int main(){
    // Define the polynomials
    const vector<double> A = {4, 5, -1, 7, 0, 3};
    const vector<double> B = {-7, 1, -1, 9, 2, 6};

    // Print the polynomials
    cout << "Polynomial A:\n";
    printPolynomial(A);
    cout << "\n";

    cout << "Polynomial B:\n";
    printPolynomial(B);
    cout << "\n";

    // Add the polynomials
    vector<double> C = addPolynomials(A, B);
    cout << "The sum of the polynomials is:\n";
    printPolynomial(C);
    cout << "\n";

    // Subtract the polynomials
    C = subtractPolynomials(A, B);
    cout << "The difference of the polynomials is:\n";
    printPolynomial(C);
    cout << "\n";

    // Multiply the polynomials
    C = multiplyPolynomials(A, B);
    cout << "The product of the polynomials is:\n";
    printPolynomial(C);
    cout << "\n";

    // Derive the polynomials
    vector<double> D = derivePolynomial(A);
    cout << "The derivative of the polynomial A is:\n";
    printPolynomial(D);
    cout << "\n";

    D = derivePolynomial(B);
    cout << "The derivative of the polynomial B is:\n";
    printPolynomial(D);
    cout << "\n";

    // Evaluate the polynomials at a given point
    double x0 = 5.0;
    double value = evaluatePolynomial(A, x0);
    cout << "The value of the polynomial A at " << x0 << " is " << value << ".\n\n";

    value = evaluatePolynomial(B, x0);
    cout << "The value of the polynomial B at " << x0 << " is " << value << ".\n\n";

    // Find the degree of the polynomials
    int degree = A.size() - 1;
    cout << "The degree of the polynomial A is: " << degree << "\n";
    degree = B.size() - 1;
    cout << "The degree of the polynomial B is: " << degree << "\n";

    return 0;
}