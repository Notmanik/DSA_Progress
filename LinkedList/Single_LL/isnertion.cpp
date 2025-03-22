#include<iostream>
using namespace std;

class LinkedList{
    private:
    class Node{
        public:
        int data;
        Node* next;
    
        Node(int val){
            this->data = val;
            this->next = nullptr;
        }
    };
    Node* head;
    public: 
    LinkedList(){
        head = nullptr;
    }
    void insert_at_beginning(int val) {
        Node* newNode = new Node(val);
        newNode->next = head;
        head = newNode;
    }
    void insert_at_end(int val) {
        Node* newNode = new Node(val);

        if (head == nullptr) {
            head = newNode;
            return;
        }

        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
    void insert_at_p(int val, int p) {
        // Edge case: Invalid position
        if (p <= 0) {
            cout << "Invalid Position\n";
            return;
        }
    
        // Special case: Insert at beginning
        if (p == 1) {
            insert_at_beginning(val);
            return;
        }
    
        // Traverse to the (p-1)-th node
        Node* temp = head;
        for (int i = 1; i < p - 1 && temp != nullptr; i++) {
            temp = temp->next;
        }
    
        // If temp is null, the position is out of bounds
        if (temp == nullptr) {
            cout << "Invalid Position\n";
            return;
        }
    
        // Insert the new node at the p-th position
        Node* newNode = new Node(val);
        newNode->next = temp->next;
        temp->next = newNode;
    }
    void display(){
        Node* temp = head;
        while(temp != nullptr){
            cout<<temp -> data <<" -> ";
            temp = temp->next;
        }cout<<"NULL \n";
    }
};
int main(){
    LinkedList list;
    list.insert_at_beginning(10);
    list.insert_at_p(20, 2); // Inserts at position 2
    list.insert_at_p(5, 1);  // Inserts at position 1
    list.insert_at_p(15, 3); // Inserts at position 3

    list.display();
    return 0;
}