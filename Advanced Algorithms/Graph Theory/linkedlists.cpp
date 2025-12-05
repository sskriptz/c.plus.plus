#include <iostream>
#include <vector>
using namespace std;

struct Node {
    int data;
    Node* next;
};

void printList(Node* head) {
    Node* current = head;
    cout << "List: ";
    while (current != nullptr) {
        cout << current->data;
        if (current->next != nullptr) {
            cout << "->";
        }
        current = current->next;
    }
    cout << endl;
}

int main () {
    Node* head = new Node;
    head->data = 10;
    
    Node* second = new Node;
    second->data = 20;
    
    Node* third = new Node;
    third->data = 30;
    

    head->next = second; 

    second->next = third; 

    third->next = nullptr; 

    printList(head);

    delete head;
    delete second;
    delete third;

    return 0;
}
