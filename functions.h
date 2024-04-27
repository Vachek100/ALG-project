#include <iostream>
#include <vector>
using namespace std;

void createPolynomial(vector<double>& A);
void createPolynomialFromSingleNumber(vector<double>& polynomial, double coeff);
void printPolynomial(const vector<double>& A);
vector<double> addPolynomials(const vector<double>& A, const vector<double>& B);
vector<double> subtractPolynomials(const vector<double>& A, const vector<double>& B);
vector<double> multiplyPolynomials(const vector<double>& A, const vector<double>& B);
vector<double> derivePolynomial(const vector<double>& A);
double evaluatePolynomial(const vector<double>& A, double x0);