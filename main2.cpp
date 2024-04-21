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
        cout << "3. Exit\n";
        cin >> choice;

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
                        polynomials.push_back(A);
                        break;
                    case 2:
                        cout << "Enter the first polynomial:\n";
                        create(A);
                        print(A);
                        polynomials.push_back(A);
                        cout << "Enter the second polynomial:\n";
                        create(B);
                        print(B);
                        polynomials.push_back(B);
                        break;
                    case 3:
                        for(const auto& polynomial : polynomials){
                            print(polynomial);
                        }
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
                polynomials.push_back(A);

                cout << "Enter the second polynomial:\n";
                create(B);
                print(B);
                polynomials.push_back(B);

                // Add the polynomials
                C = addPolynomials(A, B);

                cout << "The sum of the polynomials is:\n";
                print(C);
                polynomials.push_back(C);

                break;
            case 3:
                cout << "Goodbye and see you again!!!\n";
                return 0;
            default:
                cout << "Invalid choice.\n";
                break;
        }
    }
}