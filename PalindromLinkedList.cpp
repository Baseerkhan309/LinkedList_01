#include<iostream>
#include<vector>
using namespace std;

// Find Palindrome in a LinkedList...

class Node{
    public:
    int data;
    Node* next;

    Node(int val){
        data = val;
        next = NULL;
    }

};

class linkedList{
    Node* head;
    Node* tail;
    public:

    linkedList(){
        head = NULL;
        tail = NULL;
    }
};

bool IsPalindrome(Node* head){

    vector<int> arr;
    Node* temp = head;

    // step # 1; store Value
    while(temp){
        arr.push_back(temp->data);
        temp = temp->next;
    }

    // step # 2;  Check Palindrome 
    int i=0;
    int j = arr.size()-1;

    while(i < j){
        if(arr[i] != arr[j]){
            return false;
            
        }
        i++;
        j--;

    }
    return true;

}
int main(){
  Node* head  = new Node(1);
  Node* second  = new Node(2);
  Node* third  = new Node(2);
  Node* fourth  = new Node(1);

  head->next = second;
  second->next = third;
  third->next = fourth;

  cout << IsPalindrome(head);


    return 0;
}