#include <iostream>
#include <vector>
#include <cmath>

using namespace std;



void create(vector<double>& A){
    int n; //variable to store number of terms in the polynomial
    double coeff;//variable to store the coefficient

    cout << "Enter the number of terms: ";
    cin >> n;

    if(n == 1) {
        cout << "Enter the coefficient for the zero polynomial: ";
        cin >> coeff;
        A.push_back(coeff);
    } else {
        A.resize(n);

        for(int i = 0; i < n; i++){
            cout << "Enter the coefficient for term " << i << ": ";
            cin >> coeff; 
            A[i] = coeff;
        }
    }
}

void createPolynomialFromSingleNumber(vector<double>& polynomial, double coeff) {
    polynomial.clear(); // Clear the existing polynomial
    polynomial.push_back(coeff); // Add the coefficient to the polynomial
}

void print(const vector<double>& A){
    int n = A.size();

    if(n == 1) {
        cout << "P(x) = " << A[0] << "\n";
    } else {
        cout << "P(x) = ";

        for(int i = n - 1; i >= 0; i--){
            if(A[i] != 0){
                if(i != n - 1 && A[i] > 0)
                    cout << " + ";
                else if(i != n - 1 && A[i] < 0)
                    cout << " - ";
                else if(i == n - 1 && A[i] < 0)
                    cout << "-";

                if(abs(A[i]) != 1 || i == 0)
                    cout << abs(A[i]);

                if(i > 0)
                    cout << "x";

                if(i > 1)
                    cout << "^" << i;
            }
        }

        cout << "\n";
    }
}

vector<double> addPolynomials(const vector<double>& A, const vector<double>& B){
    // Determine the size of the resulting polynomial
    int size = max(A.size(), B.size());

    // Initialize the resulting polynomial with zeros
    vector<double> result(size, 0.0);

    // Add the terms of the first polynomial to the result
    for(int i = 0; i < A.size(); i++){
        result[i] += A[i];
    }

    // Add the terms of the second polynomial to the result
    for(int i = 0; i < B.size(); i++){
        result[i] += B[i];
    }

    // Return the resulting polynomial
    return result;
}

vector<double> subtractPolynomials(const vector<double>& A, const vector<double>& B){
    // Determine the size of the resulting polynomial
    int size = max(A.size(), B.size());

    // Initialize the resulting polynomial with zeros
    vector<double> result(size, 0.0);

    // Subtract the terms of the first polynomial from the result
    for(int i = 0; i < A.size(); i++){
        result[i] += A[i];
    }

    // Subtract the terms of the second polynomial from the result
    for(int i = 0; i < B.size(); i++){
        result[i] -= B[i];
    }

    // Return the resulting polynomial
    return result;
}

vector<double> multiplyPolynomials(const vector<double>& A, const vector<double>& B){
    // Determine the size of the resulting polynomial
    int size = A.size() + B.size() - 1;

    // Initialize the resulting polynomial with zeros
    vector<double> result(size, 0.0);

    // Multiply the terms of the first polynomial with the terms of the second polynomial
    for(int i = 0; i < A.size(); i++){
        for(int j = 0; j < B.size(); j++){
            result[i+j] += A[i] * B[j];
        }
    }

    // Return the resulting polynomial
    return result;
}

vector<double> derivePolynomial(const vector<double>& A){
    // Determine the size of the resulting polynomial
    int size = A.size() - 1;

    // If the polynomial is a constant, its derivative is zero
    if(size <= 0){
        return vector<double>(1, 0.0);
    }

    // Initialize the resulting polynomial with zeros
    vector<double> result(size, 0.0);

    // Derive the terms of the polynomial
    for(int i = 1; i < A.size(); i++){
        result[i-1] = A[i] * i;
    }

    // Return the resulting polynomial
    return result;
}

double evaluatePolynomial(const vector<double>& A, double x0){
    // Initialize the result with the constant term of the polynomial
    double result = A[0];

    // Evaluate the polynomial at the given point
    double x_power = x0;
    for(int i = 1; i < A.size(); i++){
        result += A[i] * x_power;
        x_power *= x0;
    }

    // Return the result
    return result;
}


int main(){
    vector<vector<double>> polynomials; // Store all polynomials
    int choice; // User's choice
    vector<double> A; // First polynomial
    vector<double> B; // Second polynomial
    vector<double> C; // Resulting polynomial
    double x0;
    double value;

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
                    create(A);
                    print(A);
                    cout << "\n";
                } else if(subchoice == 2) {
                    double coeff;
                    cout << "Enter the coefficient for the zero polynomial: ";
                    cin >> coeff;
                    createPolynomialFromSingleNumber(A, coeff);
                    print(A);
                    cout << "\n";
                } else {
                    cout << "Invalid choice\n";
                }

                break;
            case 2:
                cout << "Enter the first polynomial:\n";
                create(A);
                print(A);
                cout << "\n";
                

                cout << "Enter the second polynomial:\n";
                create(B);
                print(B);
                cout << "\n";
                

                // Add the polynomials
                C = addPolynomials(A, B);

                cout << "The sum of the polynomials is:\n";
                print(C);
                cout << "\n";
                

                break;
            case 3:
                cout << "Enter the first polynomial:\n";
                create(A);
                print(A);
                cout << "\n";
                

                cout << "Enter the second polynomial:\n";
                create(B);
                print(B);
                cout << "\n";
                

                // Subtract the polynomials
                C = subtractPolynomials(A, B);

                cout << "The difference of the polynomials is:\n";
                print(C);
                cout << "\n";
                

                break;
            case 4:
                cout << "Enter the first polynomial:\n";
                create(A);
                print(A);
                cout << "\n";
                

                cout << "Enter the second polynomial:\n";
                create(B);
                print(B);
                cout << "\n";
                

                // Multiply the polynomials
                C = multiplyPolynomials(A, B);

                cout << "The product of the polynomials is:\n";
                print(C);
                cout << "\n";
                

                break;
            case 5:
                cout << "Enter the polynomial to derive:\n";
                create(A);
                print(A);
                cout << "\n";
                

                // Derive the polynomial
                B = derivePolynomial(A);

                cout << "The derivative of the polynomial is:\n";
                print(B);
                cout << "\n";
                

                break;
            case 6:
                cout << "Enter the polynomial to evaluate:\n";
                create(A);
                print(A);
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
                create(A);
                print(A);
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