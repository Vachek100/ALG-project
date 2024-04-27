#include <iostream>
#include <vector>
#include <cmath>
#include "functions.h"

using namespace std;

int main(){
    int choice; // User's choice
    double x0;
    double value;

    vector<vector<double>> polynomials; // Store all polynomials
    vector<double> A; // First polynomial
    vector<double> B; // Second polynomial
    vector<double> C; // Resulting polynomial

    while(true){
        cout << "What do you want to do?\n";
        cout << "1. Create polynomial\n";
        cout << "2. Add polynomials together\n";
        cout << "3. Subtract polynomials\n";
        cout << "4. Multiply polynomials\n";
        cout << "5. Derive a polynomial\n";
        cout << "6. Evaluate a polynomial at a given point\n";
        cout << "7. Find the degree of a polynomial\n";
        cout << "8. Exit\n";
        cin >> choice;


        switch(choice){
            case 1:
                int subchoice;
                cout << "How do you want to create the polynomial?\n";
                cout << "1. Create a polynomial\n";
                cout << "2. Create a polynomial from a single number\n";
                cin >> subchoice;

                if(subchoice == 1) {
                    cout << "Enter the polynomial:\n";
                    createPolynomial(A);
                    printPolynomial(A);
                    cout << "\n";
                } else if(subchoice == 2) {
                    double coeff;
                    cout << "Enter the coefficient for the zero polynomial: ";
                    cin >> coeff;
                    createPolynomialFromSingleNumber(A, coeff);
                    printPolynomial(A);
                    cout << "\n";
                } else {
                    cout << "Invalid choice\n";
                }

                break;
            case 2:
                cout << "Enter the first polynomial:\n";
                createPolynomial(A);
                printPolynomial(A);
                cout << "\n";
                

                cout << "Enter the second polynomial:\n";
                createPolynomial(B);
                printPolynomial(B);
                cout << "\n";
                

                // Add the polynomials
                C = addPolynomials(A, B);

                cout << "The sum of the polynomials is:\n";
                printPolynomial(C);
                cout << "\n";
                

                break;
            case 3:
                cout << "Enter the first polynomial:\n";
                createPolynomial(A);
                printPolynomial(A);
                cout << "\n";
                

                cout << "Enter the second polynomial:\n";
                createPolynomial(B);
                printPolynomial(B);
                cout << "\n";
                

                // Subtract the polynomials
                C = subtractPolynomials(A, B);

                cout << "The difference of the polynomials is:\n";
                printPolynomial(C);
                cout << "\n";
                

                break;
            case 4:
                cout << "Enter the first polynomial:\n";
                createPolynomial(A);
                printPolynomial(A);
                cout << "\n";
                

                cout << "Enter the second polynomial:\n";
                createPolynomial(B);
                printPolynomial(B);
                cout << "\n";
                

                // Multiply the polynomials
                C = multiplyPolynomials(A, B);

                cout << "The product of the polynomials is:\n";
                printPolynomial(C);
                cout << "\n";
                

                break;
            case 5:
                cout << "Enter the polynomial to derive:\n";
                createPolynomial(A);
                printPolynomial(A);
                cout << "\n";
                

                // Derive the polynomial
                B = derivePolynomial(A);

                cout << "The derivative of the polynomial is:\n";
                printPolynomial(B);
                cout << "\n";
                

                break;
            case 6:
                cout << "Enter the polynomial to evaluate:\n";
                createPolynomial(A);
                printPolynomial(A);
                cout << "\n";
                

                cout << "Enter the point to evaluate the polynomial at:\n";
                cin >> x0;

                // Evaluate the polynomial at the given point
                value = evaluatePolynomial(A, x0);

                cout << "The value of the polynomial at " << x0 << " is " << value << ".\n\n";

                break;
            case 7:
            {
                cout << "Enter the polynomial:\n";
                createPolynomial(A);
                printPolynomial(A);
                cout << "\n";
                int degree = A.size() - 1;
                cout << "The degree of the polynomial is: " << degree << "\n";
                cout << "\n";
                break;
            }
            case 8:
                cout << "Goodbye and see you again!!!\n";
                return 0;
            default:
                cout << "Invalid choice.\n";
                break;
        }
    }
}