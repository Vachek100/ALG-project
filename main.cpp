#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

struct node {
    float coefficient;//5x^3 -> coefficient = 5
    int exponent;//5x^3 -> exponent = 3
    struct node* link;
};

struct node* insert(struct node* head, int co, int ex){
    struct node* temp;
    struct node* newP = (struct node*)malloc(sizeof(struct node));
    newP->coefficient = co;
    newP->exponent = ex;
    newP->link = NULL;

    if(head == NULL || ex > head->exponent){
        newP->link = head;
        head = newP;
    }
    else{
        temp = head;
        while(temp->link != NULL && temp->link->exponent > ex){
            temp = temp->link;
        }
        newP->link = temp->link;
        temp->link = newP;
    }
    return head;
}

struct node* create(struct node* head){
    int n; //variable to store number of terms in the polynomial
    float coeff;//variable to store the coefficient
    int expo;//variable to store the exponent

    cout << "Enter the number of terms: ";
    cin >> n;

    for(int i = 0; i < n; i++){
        cout << "Enter the coefficient for term", i+1, ": ";
        cin >> coeff; 

        cout << "Enter the exponent for term", i+1, ": ";
        cin >> expo;
        head = insert(head, coeff, expo);
    }
}

void print(struct node* head){
    if(head == NULL){
        cout << "No Polynomial\n";
    }else{
        struct node* temp = head;
        while(temp != NULL){
            cout << temp->coefficient << "x^" << temp->exponent;
            temp = temp->link;
            if(temp != NULL){
                cout << " + ";
            }else{
                cout << "\n";
            }
        }
    }
}

int main(){
    struct node* head = NULL; // head of the linked list
    cout << "Enter the polynomial:\n";
    head = create(head);
    print(head);
    return 0;
}