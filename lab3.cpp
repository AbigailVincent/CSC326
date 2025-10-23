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
    // Iterate to a given position (0-based index)
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
    // Insert at position
    void insertAt(int position, int value) {
        Node* newNode = new Node(value);
        if (position <= 0 || head == nullptr) { // Insert at beginning
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
        // Find previous node of the target
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
    // Remove from position
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
    // Remove from position
    bool removeFirst() {
        if(head==nullptr) return false;
        Node *temp=head;
        head=head->next;
        delete temp;
        return true;
    }
    // Remove from position
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
int main() {
    LinkedList list;
    list.append(10);
    list.append(20);
    list.append(30);
    list.prepend(5);
    list.insertAt(2, 15);
    cout << "Linked List: ";
    list.display();
    cout << "Contains 20? " << (list.contains(20) ? "Yes" : "No") << endl;
    list.remove(20);
    cout << "After removing 20: ";
    list.display();
    return 0;
}
/*ouput:
Linked List: 5 -> 10 -> 15 -> 20 -> 30 -> NULL
Contains 20? Yes
After removing 20: 5 -> 10 -> 15 -> 30 -> NULL
*/