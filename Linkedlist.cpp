#include <iostream>
using namespace std;

// Linkedlist Implementation.


// Node
class Node{
    public:
    int data;
    Node* next;


Node(int val){
    data = val;
    next  = NULL;

}

~Node(){
     
    if(next != NULL){
        delete next;
        next = NULL;

    }
}

};

class Linkedlist{
     Node* head;
     Node* tail;

public:
     Linkedlist(){
        head = NULL;
        tail = NULL;

     }
     ~Linkedlist(){
       
        if(head != NULL){
            delete head;
            head = NULL;
           
        }
     }

     void push_front(int val){
        Node* newNode = new Node(val);

        if(head == NULL){
            head = tail = newNode;
        }else{
            newNode->next = head;
            head = newNode;
        }
     }

     void push_back(int val){
        Node* newNode = new Node(val);

        if(head == NULL){
            head =  tail = newNode;
        }else{
             
            tail->next = newNode;
            tail = newNode;
        }
     }

     void printList(){

        Node* temp = head;

        while(temp != NULL){
            cout << temp->data << "-->";
            temp = temp->next;
        }
        cout << "Null\n";
     }

     void insert(int val, int pos){
        Node* newndoe = new Node(val);
        Node* temp = head;
        for(int i=0; i<pos-1; i++){
            if(temp == NULL){
                cout << "Position is invalid\n";
                return;
            }
         temp = temp->next;
        }

        // temp is now at pos-1;
        newndoe->next = temp->next;   // newnode will conected with next node 
        temp->next = newndoe;        // and temp connected with newnode 
     }

     void pop_Front(){
        if(head == NULL){
            cout << "Linkedlist is Empty \n";
            return;
        }
        Node* temp = head;
        head = head->next;
        temp->next = NULL;
        delete temp;
     }

     void pop_back(){
        // Head Empty List
        if(head == NULL){
            return;
        }

        // Handle List with only one Node
        if(head->next == NULL){
            delete head;
            head = tail = NULL;
            return;
        }
        Node* temp = head;
        while(temp->next->next != NULL){
            temp = temp->next;
         
        }
        delete temp->next; // tail's prev
         temp->next = NULL;
        tail = temp;
     }

     int SearchItr(int key){
        int idx = 0;
        Node* temp = head;

        while(temp != NULL){
            if(temp->data == key){
                return idx;

            }
            temp = temp->next;
            idx++;
        }
            return -1;
     }
     // Search In Recursive

     int helper(Node* temp , int key){
        // Base Case
        if(temp == NULL){
            return -1;
        }
        // Head 
        if(temp->data == key){
            return 0;
        }
        
        // Index
        int idx = helper(temp->next, key);

        // Tail Node return -1 Becz its next is NULL
        if(idx == -1){
            return -1;
        }

        return idx + 1;

     }
     int searchRec(int key){
        return helper(head, key);
     }

     void reverse(){

        // Pointer Approach
        Node* curr = head;
        Node* prev = NULL;

        while(curr != NULL){ // ?? while(curr.next  != NULL)
            Node* next = curr->next;
            curr->next = prev; // Reverse Line 

        // Updation for next itr
            prev = curr;
            curr = next;
        }
        head = prev;
     }

     int getSize(){
        int sz = 0;
 
        Node* temp = head;

        while(temp != NULL){

        temp = temp->next;
        sz++;
        }
        return sz;

     }
     void removeNth(int n){
        int sz = getSize();
        Node* prev = head;
        for(int i=1; i<(sz-n); i++){
            prev = prev->next;
        }

        Node* ToDel = prev->next; 
        cout << "The Deleted Node Is = "<< ToDel->data << endl;
        prev->next  = prev->next->next;
     }
};

int main(){
     Linkedlist ll;
     ll.push_front(5);
     ll.push_front(4);
     ll.push_front(3);
     ll.push_front(2);
     ll.push_front(1);
     ll.printList();
     ll.removeNth(2);
     ll.printList();
    return 0;
}