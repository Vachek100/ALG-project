#include <iostream>
#include <vector>

using namespace std;

void create(vector<double>& A){
    int n; //variable to store number of terms in the polynomial
    double coeff;//variable to store the coefficient

    cout << "Enter the number of terms: ";
    cin >> n;

    A.resize(n);

    for(int i = 0; i < n; i++){
        cout << "Enter the coefficient for term " << i << ": ";
        cin >> coeff; 
        A[i] = coeff;
    }
}

void print(const vector<double>& A){
    if(A.empty()){
        cout << "No Polynomial.\n";
    }else{
        for(int i = A.size() - 1; i >= 0; --i){
            if(A[i] != 0){
                cout << A[i] << "x^" << i;
                if(i > 0){
                    cout << " + ";
                }
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

    while(true){
        cout << "What do you want to do?\n";
        cout << "1. Show polynomial/polynomials\n";
        cout << "2. Add polynomials together\n";
        cout << "3. Subtract polynomials\n";
        cout << "4. Multiply polynomials\n";
        cout << "5. Derive a polynomial\n";
        cout << "6. Evaluate a polynomial at a given point\n";
        cout << "7. Exit\n";
        cin >> choice;

        double x0;
        double value;

        switch(choice){
            case 1:
                int showChoice;
                cout << "Do you want to show:\n";
                cout << "1. One polynomial\n";
                cout << "2. Two polynomials\n";
                cout << "3. All showed polynomials\n";
                cin >> showChoice;

                switch(showChoice){
                    case 1:
                        cout << "Enter the polynomial:\n";
                        create(A);
                        print(A);
                        cout << "\n";
                        polynomials.push_back(A);
                        break;
                    case 2:
                        cout << "Enter the first polynomial:\n";
                        create(A);
                        print(A);
                        cout << "\n";
                        polynomials.push_back(A);
                        cout << "Enter the second polynomial:\n";
                        create(B);
                        print(B);
                        cout << "\n";
                        polynomials.push_back(B);
                        break;
                    case 3:
                        for(const auto& polynomial : polynomials){
                            print(polynomial);
                        }
                            cout << "\n";
                        break;
                    default:
                        cout << "Invalid choice.\n";
                        break;
                }
                break;
            case 2:
                cout << "Enter the first polynomial:\n";
                create(A);
                print(A);
                cout << "\n";
                polynomials.push_back(A);

                cout << "Enter the second polynomial:\n";
                create(B);
                print(B);
                cout << "\n";
                polynomials.push_back(B);

                // Add the polynomials
                C = addPolynomials(A, B);

                cout << "The sum of the polynomials is:\n";
                print(C);
                cout << "\n";
                polynomials.push_back(C);

                break;
            case 3:
                cout << "Enter the first polynomial:\n";
                create(A);
                print(A);
                cout << "\n";
                polynomials.push_back(A);

                cout << "Enter the second polynomial:\n";
                create(B);
                print(B);
                cout << "\n";
                polynomials.push_back(B);

                // Subtract the polynomials
                C = subtractPolynomials(A, B);

                cout << "The difference of the polynomials is:\n";
                print(C);
                cout << "\n";
                polynomials.push_back(C);

                break;
            case 4:
                cout << "Enter the first polynomial:\n";
                create(A);
                print(A);
                cout << "\n";
                polynomials.push_back(A);

                cout << "Enter the second polynomial:\n";
                create(B);
                print(B);
                cout << "\n";
                polynomials.push_back(B);

                // Multiply the polynomials
                C = multiplyPolynomials(A, B);

                cout << "The product of the polynomials is:\n";
                print(C);
                cout << "\n";
                polynomials.push_back(C);

                break;
            case 5:
                cout << "Enter the polynomial to derive:\n";
                create(A);
                print(A);
                cout << "\n";
                polynomials.push_back(A);

                // Derive the polynomial
                B = derivePolynomial(A);

                cout << "The derivative of the polynomial is:\n";
                print(B);
                cout << "\n";
                polynomials.push_back(B);

                break;
            case 6:
                cout << "Enter the polynomial to evaluate:\n";
                create(A);
                print(A);
                cout << "\n";
                polynomials.push_back(A);

                cout << "Enter the point to evaluate the polynomial at:\n";
                cin >> x0;

                // Evaluate the polynomial at the given point
                value = evaluatePolynomial(A, x0);

                cout << "The value of the polynomial at " << x0 << " is " << value << ".\n\n";

                break;
            case 7:
                cout << "Goodbye and see you again!!!\n";
                return 0;
            default:
                cout << "Invalid choice.\n";
                break;
        }
    }
}