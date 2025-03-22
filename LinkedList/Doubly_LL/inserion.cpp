#include<iostream>
using namespace std;

class DLinkedList{
    private:
    class Node
    {
    private:
        int data;
        Node* next;
        Node* prev;
    
    Node(int val)
    {
        this -> data = val;
        this -> next = nullptr;
        this -> prev = nullptr;
    }
    Node* head;
    };
    public:

    
    
};

int main(){

    return 0;
}