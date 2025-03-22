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
        cout<<endl;
    }
    void delete_at_beginning(){
        if(head == nullptr){
            cout<<"List is empty \n";
            return;
        }
        Node* temp = head;
        head = head -> next;
        delete temp;
    }
    void delete_at_end(){
        if(head == nullptr){
            cout<<"List is empty \n";
            return;
        }
        if(head -> next == nullptr){
            delete head;
            head = nullptr;
            return;
        }
        Node* temp = head;
        while(temp -> next -> next != nullptr){
            temp = temp -> next;
        }
        Node* delNode = temp -> next; // node to be deleted;
        temp -> next = nullptr;
        delete delNode;
    }
    void delete_Node_at_p(int p){
        if(head == nullptr){
            cout<<"List is empty \n";
            return;
        }
        if(p == 1){
            delete_at_beginning();
            return;
        }
        Node* temp = head;
        for(int i =1;i< p-1 && temp -> next != nullptr;i++){
            temp = temp -> next;
        }
        if(temp -> next == nullptr){
            cout<<"Invalid index \n";
            return;
        }
        Node* delNode = temp -> next; // node to be deleted;
        temp -> next = delNode -> next;
        delete delNode;
    }
};
int main(){
    LinkedList list;
    // Insert at beginning
    list.insert_at_beginning(10);
    list.insert_at_beginning(20);
    list.insert_at_beginning(30);
    cout << "After inserting at the beginning: ";
    list.display();

    // Insert at a specific position
    list.insert_at_p(25, 2);  // Insert 25 at position 2
    cout << "After inserting 25 at position 2: ";
    list.display();

    // Insert at the end
    list.insert_at_end(5);
    cout << "After inserting at the end: ";
    list.display();

    // Delete at the beginning
    list.delete_at_beginning();
    cout << "After deleting the first element: ";
    list.display();

    // Delete at the end
    list.delete_at_end();
    cout << "After deleting the last element: ";
    list.display();

    // Delete at a specific position
    list.insert_at_p(40, 2);  // Add a new element to delete it
    cout << "List before deleting at position 2: ";
    list.display();
    list.delete_Node_at_p(2); // Delete element at position 2
    cout << "After deleting element at position 2: ";
    list.display();
    return 0;
}