#include<iostream>
#include<vector>
using namespace std;

// Create Node
class Node{
    public:
    int data;
    Node* next;

Node(int val){
    data = val;
    next = NULL;
}

};

// Create Linkedlist
class Linkedlist{
    Node* head;
    Node* tail;

public:
    Linkedlist(){
    head = NULL;
    tail = NULL;
}
   ~Linkedlist(){
    Node* temp = head;
    while(temp){
         Node* nextNode = temp->next;
         delete temp;
         temp = nextNode; 
    }
   }

// (#1) Create Push Front Method (Node at Begining) 

void push_Front(int val){
    Node* newNode = new Node(val);
    if(head == NULL){
        head = tail = newNode;
    }else{
      newNode->next = head;
      head = newNode;
    }
}

// (#2) Create Push back Method (Node at last)

void push_Back(int val){
    Node* newnode = new Node(val);
    if(head == NULL){
        head = tail = newnode;
    }else{ 
    tail->next = newnode;
    tail = newnode;
    }
}

// (#3) Create pop Front Method (Delete Node at Begining) 

void pop_front(){
    if(head == NULL){
        cout << "Linkedlist is Empty!";
        return;
    }
    Node* temp = head;
    head = head->next;
    temp->next = NULL;
    delete temp;
}

// (#4) Create pop Back Method (Delete Node at Begining) 

void pop_Back(){
    if(head == NULL){
        cout << "List Is Empty" ;
        return;
    }
    // If there Is Only One Head 
    if(head->next == NULL){
        delete head;
        head = tail = NULL;
    return;
    }

    Node* temp = head;
    while(temp->next->next != NULL) {     // “Keep moving until the node after the next node is NULL.”
    temp = temp->next;
     }

    delete temp->next;
    temp->next = NULL;
     tail = temp;
}

// (#5) Insert a Node 
void insert(int val, int pos){
    if(pos == 0){
        push_Front(val);
        return;
    }
    Node* newnode = new Node(val);
    Node* temp = head;
    for(int i=0; i<pos-1; i++){
        if(temp == NULL){
            cout << "Position is invalid";
        return;
        }
        temp = temp->next;

    }
    // Now Node Become Pos-1 so :
    newnode->next = temp->next;// newNode is Connected with Next Node;
    temp->next = newnode;// Temp Is Connected With Newnode;
}

int helper(Node* temp , int key){
    // Base Case 
    if(temp == NULL){
        return -1;
    }

    // Head
    if(temp->data == key){
        return 0;  
    }

    // IDx
    int idx = helper(temp->next, key);
    // Tail Node  Return -1 becx of Null
    if(idx == -1){
        return -1;
    }
    return idx +1;

}

// Search Recursively 
int searchRec(int key){
  return helper(head, key);
}

// Remove Nth Node 
int size(){
    int size = 0;
    Node* temp = head;
    while(temp){
        temp = temp->next;
        size++;

    }
    return size;
}
void removeNth(int n){
    int sz = size();
    Node* prev  = head;
    for(int i=1; i<(sz-n); i++){
           prev = prev->next; // Reach To Before That Node
    }

    // TO Delete That Node
    Node* toDelete = prev->next;
    cout << "The Node That Deleted is = "<<toDelete->data << endl;
    prev->next = toDelete->next;
    delete toDelete;
}

// Print The List 
void printList(){
    Node* temp = head;
    while(temp){
        cout  << temp->data << "-->";
        temp = temp->next;
    }
        cout << "NULL\n";
}
};

int main(){
Linkedlist ll;
ll.push_Front(5);
ll.push_Front(3);
ll.push_Front(2);
ll.push_Front(1);
//ll.printList();
ll.insert(4,3);
ll.printList();
ll.removeNth(3);
ll.printList();
//cout << ll.searchRec(4);



    return 0;
}