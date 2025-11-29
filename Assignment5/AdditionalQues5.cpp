#include <iostream>
using namespace std;

struct node {
    int coff;
    int power;
    node* next;
};

node* createNode(int coff, int power) {
    node* temp = new node;
    temp->coff = coff;
    temp->power = power;
    temp->next = NULL;
    return temp;
}

node* addPolynomial(node* pol1, node* pol2) {
    node* result = NULL;
    node* tail = NULL;

    while (pol1 != NULL || pol2 != NULL) {
        node* temp = NULL;

        if (pol1 != NULL && pol2 != NULL) {
            if (pol1->power == pol2->power) {
                int sumCoff = pol1->coff + pol2->coff;
                if (sumCoff != 0)
                    temp = createNode(sumCoff, pol1->power);
                pol1 = pol1->next;
                pol2 = pol2->next;
            } else if (pol1->power > pol2->power) {
                temp = createNode(pol1->coff, pol1->power);
                pol1 = pol1->next;
            } else {
                temp = createNode(pol2->coff, pol2->power);
                pol2 = pol2->next;
            }
        } else if (pol1 != NULL) {
            temp = createNode(pol1->coff, pol1->power);
            pol1 = pol1->next;
        } else {
            temp = createNode(pol2->coff, pol2->power);
            pol2 = pol2->next;
        }

        if (temp != NULL) {
            if (result == NULL) {
                result = temp;
                tail = temp;
            } else {
                tail->next = temp;
                tail = temp;
            }
        }
    }

    return result;
}

void display(node* head) {
    cout << "[";
    while (head != NULL) {
        cout << "[" << head->coff << ", " << head->power << "]";
        head = head->next;
        if (head != NULL)
            cout << ", ";
    }
    cout << "]" << endl;
}

int main() {
    node* a1 = createNode(5, 2);
    node* a2 = createNode(4, 1);
    node* a3 = createNode(2, 0);
    a1->next = a2;
    a2->next = a3;
    node* pol1 = a1;

    node* b1 = createNode(5, 1);
    node* b2 = createNode(5, 0);
    b1->next = b2;
    node* pol2 = b1;

    node* result = addPolynomial(pol1, pol2);

    display(result); 

    return 0;
}
