/* You are given a sorted doubly linked list of size 'n'. Remove all the duplicate nodes present 
in the linked list.*/
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
Brute Frute Solution : Iterate over the Doubly Linked List and Change the links using a next non-duplicate node.
Step 1 : Iterate through the linked list and check if temp's data is equal to key.
Step 2 : Once the data is matching then check if temp is at head or not in case of head we need to move it by 1.
Step 3 : Store the prevNode and the nextNode and check if they are not null then perform the link changes.
Step 4 : Delete the temp and move temp to nextNode after the link changes are done.
Step 5 : If data is not matching then move temp to the next node.

Time Complexity : O(N)
Space Complexity : O(1)

Time Complexity is O(N) because outer loop is touching only the non-duplicate nodes and inner loop is touching
only the duplicate nodes hence both of these travel only upto the length of the doubly linked list.
*/
Node * removeDuplicates(Node *head){
    Node* temp = head, *nextNode = NULL;
    while (temp != NULL){
        nextNode = temp->next;
        while(nextNode != NULL && nextNode->data == temp->data){
            Node* duplicate = nextNode;
            nextNode = nextNode->next;
            delete duplicate;
        }
        temp->next = nextNode;
        if(nextNode) nextNode->back = temp;

        temp = temp->next;
    }
    return head;    
}

int main (){

    vector<int> arr = {1,1,1,4,4,6,7,7};
    Node* head = Convert_Arr2DLL(arr);

    Node* answer = removeDuplicates(head);
    Traverse_LL(answer);

    return 0;
}