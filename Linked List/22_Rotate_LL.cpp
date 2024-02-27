/* You are given a linked list having ‘n’ nodes and an integer ‘k’.
You have to rotate the linked list to the right by ‘k’ positions .*/
#include <iostream>
#include <vector>
using namespace std;

class Node {
    public:
    int data;
    Node * next;

    public:
    Node(int data, Node * next){
        this->data = data;
        this->next = next;
    }

    public:
    Node(int data)
    {
      this->data = data;
      next = nullptr;
    }
};

Node* Convert_Arr2LL(vector<int> & arr){
    Node* head = new Node(arr[0]);
    Node* mover = head;

    for (int i = 1; i < arr.size(); i++)
    {
        Node* temp = new Node(arr[i]);
        mover->next = temp;
        mover = temp;
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
Optimal Solution : Finding the (length - k)th node and then changing the links
Step 1 : Find the length and tail of the linked list.
Step 2 : If k is equal to the length of the linked list then the rotated list will be same as original list.
Step 3 : Since K can be anything then before proceeding further modulo it by length to make it less than length.
Step 4 : Now connect the tail's next to head and find the (length - k)th node through a function.
Step 5 : Update the head as newTail's next and make newTail's next point to NULL.

Time Complexity : O(N) +  O(length of list – (length of list % k))
Reason: O(N) for calculating the length of the list. O(N – (length of list % k)) for breaking link.
Space Complexity : O(1) 
*/
Node* find_New_Tail(Node* head, int n){
    n--; // Decreasing first to mark the head as first node.
    while(n){
        head = head->next;
        n--;
    }
    return head;
}

Node* rotate_LL(Node* head, int k){
    if(head == NULL || k == 0) return head;
    Node* tail = head;
    int length = 1;
    while(tail->next != NULL){ // Finding the tail node of the linked list.
        tail = tail->next;
        length++;
    }
    if(k == length) return head; // If k == length then rotated linked list == original linked list.
    k = k % length; // Making the value of k lesser than the length of the linked list.
    tail->next = head; // Connecting the link of tail node from null to the head of the linked list.

    // We have passed length - k, because we want the 3rd node if length is 5 and k is 2 i.e. except last 2 nodes.
    Node* newTail = find_New_Tail(head, length - k); // Finding the new Tail of the rotated linked list.

    head = newTail->next; // Updating the new head of the rotated linked list.
    newTail->next = NULL; // Pointing the new tail of the rotated linked list to NULL.

    return head;
}

int main (){

    vector<int> arr = {1,2,3,4,5};
    Node* head = Convert_Arr2LL(arr);

    head = rotate_LL(head,2);
    Traverse_LL(head);



    return 0;
}