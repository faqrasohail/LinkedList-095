#include <iostream>
using namespace std;

// Node structure
struct Node {
    int data;
    Node* next;
};

// Linked list class
class LinkedList {
private:
    Node* head;

public:
    LinkedList() {
        head = nullptr;
    }

    // Function to insert at the beginning
    void insertAtBeginning(int value) {
        Node* newNode = new Node();
        newNode->data = value;
        newNode->next = head;
        head = newNode;
    }

    // Function to delete from the beginning
    void deleteFromBeginning() {
        if (head == nullptr) {
            cout << "List is empty, nothing to delete." << endl;
            return;
        }
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    // Function to insert at nth position
    void insertAtN(int position, int value) {
        Node* newNode = new Node();
        newNode->data = value;

        if (position == 1) {
            newNode->next = head;
            head = newNode;
            return;
        }

        Node* temp = head;
        for (int i = 0; i < position - 2; i++) {
            temp = temp->next;
        }

        newNode->next = temp->next;
        temp->next = newNode;
    }

    // Function to delete from the end
    void deleteFromEnd() {
        if (head == nullptr) {
            cout << "List is empty, nothing to delete." << endl;
            return;
        }

        if (head->next == nullptr) {
            delete head;
            head = nullptr;
            return;
        }

        Node* temp = head;
        while (temp->next->next != nullptr) {
            temp = temp->next;
        }
        delete temp->next;
        temp->next = nullptr;
    }

    // Function to delete from nth position
    void deleteAtN(int position) {
        if (head == nullptr) {
            cout << "List is empty, nothing to delete." << endl;
            return;
        }

        Node* temp = head;
        if (position == 1) {
            head = head->next;
            delete temp;
            return;
        }

        for (int i = 0; i < position - 2; i++) {
            temp = temp->next;
        }

        Node* nodeToDelete = temp->next;
        temp->next = temp->next->next;
        delete nodeToDelete;
    }

    // Function to search for a value
    bool search(int value) {
        Node* temp = head;
        while (temp != nullptr) {
            if (temp->data == value) {
                return true;
            }
            temp = temp->next;
        }
        return false;
    }

    // Function to update value at nth position
    void updateAtN(int position, int value) {
        Node* temp = head;
        for (int i = 0; i < position - 1; i++) {
            if (temp == nullptr) {
                cout << "Position exceeds the length of the list." << endl;
                return;
            }
            temp = temp->next;
        }
        temp->data = value;
    }

    // Function to display the linked list
    void display() {
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    LinkedList list;
    list.insertAtBeginning(5);
    list.insertAtBeginning(3);
    list.insertAtBeginning(1);
    list.display(); // Output: 1 3 5

    list.deleteFromBeginning();
    list.display(); // Output: 3 5

    list.insertAtN(2, 7);
    list.display(); // Output: 3 7 5

    list.deleteFromEnd();
    list.display(); // Output: 3 7

    list.deleteAtN(2);
    list.display(); // Output: 3

    cout << "Is 7 present in the list? " << (list.search(7) ? "Yes" : "No") << endl; // Output: No

    list.updateAtN(1, 9);
    list.display(); // Output: 9

    return 0;
}