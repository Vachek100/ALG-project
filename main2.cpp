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

int main(){
    vector<double> A; // Polynomial represented as a vector of coefficients
    cout << "Enter the polynomial:\n";
    create(A);
    print(A);
    return 0;
}