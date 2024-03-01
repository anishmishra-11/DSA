/* You’re given a doubly-linked list and a key 'k'. Delete all the nodes having data equal to ‘k’.*/
#include <iostream>
#include <vector>
using namespace std;

class Node {
    public:
    int data;
    Node* next;
    Node* back;

    public:
    Node(int data, Node* next, Node* back){
        this->data = data;
        this->next = next;
        this->back = back;
    }

    public:
    Node(int data)
    {
      this->data = data;
      next = nullptr;
      back = nullptr;
    }
};

Node* Convert_Arr2DLL(vector<int> &arr){
    Node* head = new Node(arr[0]);
    Node* prev = head;

    for (int i = 1; i < arr.size(); i++)
    {
        Node* temp = new Node(arr[i],nullptr, prev);
        prev->next = temp;
        prev = temp;
    }
    return head;    
}  

void Traverse_LL(Node* head){

    Node* temp = head;
    while(temp != nullptr)
    {
        cout<<temp->data<< " ";
        temp = temp->next;
    }  
}

//New Concepts start from here.
/*
Brute Frute Solution : Iterate over the Doubly Linked List once and delete the node while traversal.
Step 1 : Iterate through the linked list and check if temp's data is equal to key.
Step 2 : Once the data is matching then check if temp is at head or not in case of head we need to move it by 1.
Step 3 : Store the prevNode and the nextNode and check if they are not null then perform the link changes.
Step 4 : Delete the temp and move temp to nextNode after the link changes are done.
Step 5 : If data is not matching then move temp to the next node.

Time Complexity : O(N)  
Space Complexity : O(1) 
*/
Node * sortLL(Node* head) {
    Node* temp = head;
    
}

int main (){

    vector<int> arr = {1,2,1,1,4,1,6,7,1};
    Node* head = Convert_Arr2DLL(arr);

    head = sortLL(head);
    Traverse_LL(head);

    return 0;
}