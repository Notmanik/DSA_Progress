#include<iostream>
using namespace std;

class DoublyLinkedList{
    private:
    class Node
    {
    public:
        int data;
        Node* next;
        Node* prev;
    
    Node(int val)
    {
        this -> data = val;
        this -> next = nullptr;
        this -> prev = nullptr;
    }
    };
    Node* head;
    Node* tail;
    public:
    DoublyLinkedList(){
        head = nullptr;
        tail = nullptr;
    }
    
    void insert_atbegining(int val){
        Node* newNode = new Node(val);
        if(!head) head = tail = newNode;
        else{
            newNode -> next = head;
            head -> prev = newNode;
            head = newNode;
        }
    }
    // inserting at begining
    
    void insert_at_end(int val){
        Node* newNode = new Node(val);
        if(!head) head = tail = newNode;
        else{
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }
    //inserting at end
    
    void insert_at_p(int val,int p){
        if(!head){
            cout<<"the list is empty \n";
            return;
        }
        if(p == 1){
            insert_atbegining(val);
            return;
        }
        Node* temp = head;
        for(int i = 1;i<p-1 && temp != nullptr ;i++){
            temp = temp -> next;
        }
        if(!temp){
            cout<<"Invaild index \n";
            return;
        }
        Node* newNode = new Node(val);
        newNode -> next = temp -> next;
        newNode -> prev = temp;
        if(temp -> next) temp -> next -> prev = newNode;
        temp -> next = newNode;
        if(!newNode -> next) tail = newNode;
    }


    void deletion_at_begining(){
        if(!head){
            cout<<"The DLL is already empty \n";
            return;
        }
        Node* temp = head;
        if(!head->next){
            delete head;
            delete tail;
            tail = nullptr;
            head = nullptr;
            return;
        }
        head = temp -> next;
        head -> prev = nullptr;
        delete temp;
    }

    void deletion_at_end(){
        if(!head){
            cout<<"The DLL is already empty \n";
            return;
        }
        Node* temp = tail;
        if(!head->next){ // When there's only one node
            delete head;
            delete tail;
            head = nullptr;
            tail = nullptr;
            return;
        }
        tail = temp -> prev;
        tail -> next = nullptr;
        temp -> prev = nullptr;
        delete temp;
    }

    void delete_at_p(int p) {
        if (!head) { // If list is empty
            cout << "The list is empty\n";
            return;
        }
    
        if (p <= 0) { // Invalid position
            cout << "Invalid position\n";
            return;
        }
    
        Node* temp = head;
    
        // Case 1: Delete the first node
        if (p == 1) {
            head = head->next;
            if (head) head->prev = nullptr;
            else tail = nullptr; // If list becomes empty
            delete temp;
            return;
        }
    
        // Traverse to the (p)th node
        for (int i = 1; temp != nullptr && i < p; i++) {
            temp = temp->next;
        }
    
        if (!temp) { // If position is out of bounds
            cout << "Invalid index\n";
            return;
        }
    
        // Case 2: Delete the last node
        if (!temp->next) {
            tail = temp->prev;
            tail->next = nullptr;
            delete temp;
            return;
        }
    
        // Case 3: Delete from the middle
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
        delete temp;
    }
    

    void display(){
        Node* temp = head;
        while(temp -> next != nullptr){
            cout<<temp -> data <<" -> ";
            temp = temp -> next;

        }cout<<"NULL \n";
    }

};

int main(){
    DoublyLinkedList dll;
    dll.insert_atbegining(3);
    dll.insert_atbegining(6);
    dll.insert_atbegining(98);
    dll.insert_atbegining(42);
    dll.display();
    
    return 0;
}