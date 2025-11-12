/lab 3
#include <iostream>
using namespace std;

class Node{
public:
    int data;
    Node* next;
    Node(int value) { 
        data = value;
        next = nullptr;
    }
};
class LinkedList {
private:
    Node* head;
public:
    LinkedList() {
        head = nullptr;
    }
    ~LinkedList() {
        Node* current = head;
        while (current != nullptr) {
            Node* nextNode = current->next;
            delete current;
            current = nextNode;
        }
    }

    // Iterate to a given position
    Node* iterate(int position) {
        if (position < 0) return nullptr;
        Node* current = head;
        int index = 0;
        while (current != nullptr && index < position) {
            current = current->next;
            index++;
        }
        return current; // nullptr if not found
    }
 
    void insertAt(int position, int value) {
        Node* newNode = new Node(value);
        if (position <= 0 || head == nullptr) { // Insert  beginning
            newNode->next = head;
            head = newNode;
            return;
        }
        Node* prev = iterate(position - 1);
        if (prev == nullptr) { // Position too big, append at end
            append(value);
            delete newNode; // already appended, avoid memory leak
            return;
        }
        newNode->next = prev->next;
        prev->next = newNode;
    }
    // Prepend (beginning)
    void prepend(int value) {
        insertAt(0, value);
    }
    // Append (end)
    void append(int value) {
        if (head == nullptr) {
            head = new Node(value);
            return;
        }
        Node* last = iterate(size() - 1);
        last->next = new Node(value);
    }
    // Find node by value
    Node* find(int value) {
        Node* temp = head;
        while (temp != nullptr) {
            if (temp->data == value)
                return temp;
            temp = temp->next;
        }
        return nullptr;
    }
    // Contains (true/false)
    bool contains(int value) {
        return find(value) != nullptr;
    }
    // Remove by value
    bool remove(int value) {
        if (head == nullptr) return false;
        // Special case: head
        if (head->data == value) {
            Node* temp = head;
            head = head->next;
            delete temp;
            return true;
        }
        int index = 0;
        Node* current = head;
        while (current != nullptr && current->next != nullptr) {
            if (current->next->data == value) {
                Node* target = current->next;
                current->next = target->next;
                delete target;
                return true;
            }
            current = current->next;
            index++;
        }
        return false; // Not found
    }
    // Remove from pos
    bool removeAtPos(int value) {
        if(head==nullptr){
            return false;
        }
        Node *current=head;
        Node *toDelete=head;
    if(head->data==value){  //if it's head
        head=head->next;
        delete toDelete;
        return true;
    }
    while(current!=nullptr && current->next!=nullptr&&current->next->data!=value){//get right next to it to delete
    current=current->next;
    }
    if(current->next!=nullptr){
    toDelete=current->next;
    current->next = toDelete->next;
        delete toDelete;
        return true;
    }
    return false;
    }
    // Remove first
    bool removeFirst() {
        if(head==nullptr) return false;
        Node *temp=head;
        head=head->next;
        delete temp;
        return true;
    }
    // Remove from last
    bool removeLast() { 
        if(head==nullptr) return false;
        
        Node *current=head;
    while(current->next->next!=nullptr){
      current=current->next;
    }
    delete current->next;
    current->next=nullptr;
    return true;
    }
    
    // Get size
    int size() {
        int count = 0;
        Node* temp = head;
        while (temp != nullptr) {
            count++;
            temp = temp->next;
        }
        return count;
    }
    //getfirst
    int getFirst(){
        if(head==nullptr){
            return -1;
        }
        return head->data;
    }
    //getlast
    int getLast(){
        if(head==nullptr){
            return -1;
        }
        Node *temp=head;
        while(temp->next!=nullptr){
            temp=temp->next;
        }
        return temp->data;
    }
    //if isEmpty
    bool isEmpty(){
        return head==nullptr;
    }
    // Display
    void display() {
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
};
//class STACK
class Stack{
    private: //using linked list to implement stack
    LinkedList l;
    public:
    //functions using functions
    void push(int v){
        l.prepend(v); }
    bool pop(){
        return l.removeFirst();  } //returns bool value
    int top(){
        return l.getFirst(); //peek()
    }
    bool isEmpty(){
        return l.isEmpty(); //returns bool val
    }
    void display(){
        cout<<"STACK: ";
        l.display();
    }
};
class Queue{
    private:
    LinkedList queue;
    public:
    void enqueue(int m){
        queue.append(m); //adds element to end
    }
    bool dequeue(){
        return queue.removeFirst(); //removes first elememt FIFO
    }
    int begining(){
        return queue.getFirst();
    }
    bool isEmpty(){
        return queue.isEmpty();
    }
    void display(){
        cout<<"Queue: ";
        queue.display();
    }
};
int main() {
    cout<<"testing stack implementation: \n";
    Stack myStack;
    myStack.push(1);
    myStack.push(2);
    myStack.push(3);
    myStack.push(4);
    myStack.display();
    cout<<"top of stack: "<<myStack.top()<<endl;
    myStack.pop();
    myStack.display();

    cout<<"testing queue implementation: \n";
    Queue myqueue;
    myqueue.enqueue(2);
    myqueue.enqueue(4);
    myqueue.enqueue(6);
    myqueue.enqueue(8);
    myqueue.display();
    cout<<"begining of queue: "<<myqueue.begining()<<endl;
    myqueue.dequeue();
    myqueue.display();
    
    
}
/*OUTPUT:
testing stack implementation: 
STACK: 4 -> 3 -> 2 -> 1 -> NULL
top of stack: 4
STACK: 3 -> 2 -> 1 -> NULL
testing queue implementation: 
Queue: 2 -> 4 -> 6 -> 8 -> NULL
begining of queue: 2
Queue: 4 -> 6 -> 8 -> NULL
*/
/*ouput:
Linked List: 5 -> 10 -> 15 -> 20 -> 30 -> NULL
Contains 20? Yes
After removing 20: 5 -> 10 -> 15 -> 30 -> NULL
*/
