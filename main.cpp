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
        cout << "Enter the coefficient for term " << i+1 << ": ";
        cin >> coeff; 

        cout << "Enter the exponent for term " << i+1 << ": ";
        cin >> expo;
        head = insert(head, coeff, expo);
    }
    return head;
}

void print(struct node* head){
    if(head == NULL){
        cout << "No Polynomial.\n";
    }else{
        struct node* temp = head;
        while(temp != NULL){
            cout << "(" <<temp->coefficient << "x^" << temp->exponent << ")";
            temp = temp->link;
            if(temp != NULL){
                cout << " + ";
            }else{
                cout << "\n";
            }
        }
    }
}

void polyAdd(struct node* head1, struct node* head2){
    struct node* ptr1 = head1;
    struct node* ptr2 = head2;
    struct node* head3 = NULL;
    while(ptr1 != NULL && ptr2 != NULL){
        if(ptr1->exponent == ptr2->exponent){
        head3 = insert(head3, ptr1->coefficient + ptr2->coefficient, ptr1->exponent);
        ptr1 = ptr1->link;
        ptr2 = ptr2->link;
        } else if(ptr1->exponent > ptr2->exponent){
        head3 = insert(head3, ptr1->coefficient, ptr1->exponent);
        ptr1 = ptr1->link;
        } else if(ptr1->exponent < ptr2->exponent){
            head3 = insert(head3, ptr2->coefficient, ptr2->exponent);
            ptr2 = ptr2->link;
        }
    }
    while(ptr1 != NULL){
        head3 = insert(head3, ptr1->coefficient, ptr1->exponent);
        ptr1 = ptr1->link;
    }
    while(ptr2 != NULL){
        head3 = insert(head3, ptr2->coefficient, ptr2->exponent);
        ptr2 = ptr2->link;
    }
    cout << "Added polynomial is: ";
    print(head3);
}

int main(){
    struct node* head1 = NULL; // head of the linked list
    struct node* head2 = NULL; // head of the linked list
    cout << "Enter the first polynomial:\n";
    head1 = create(head1);
    cout << "Enter the second polynomial:\n";
    head2 = create(head2);


    polyAdd(head1, head2);
    return 0;
}