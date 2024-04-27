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