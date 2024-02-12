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

Node* reverseList(Node *head){
    if(head == NULL || head->next == NULL) return head;
    Node* prev = NULL, *front = NULL;
    Node* temp = head;

    while(temp != NULL){
        front = temp->next;
        temp->next = prev;
        prev = temp;
        temp = front;
    }
    return prev;
}

//New Concepts start from here.
/*
Iterative Solution : Reversing the linked list and then adding 1 using carry.
Step 1 : Write the edge case when there are 0 nodes in the linked list.
Step 2 : First, Reverse the linked list and start traversal from head of the reversed linked list.
Step 3 : Add 1 to first node of the reversed linked list and update the carry as per the sum.
Step 4 : Reverse the linked list again.
Step 5 : If there is still a carry left then add a new node at the head of the linked list.

Time Complexity : O(3N)
Space Complexity : O(1)
*/
Node *addOneIterative(Node *head)
{
    if(head == NULL) return NULL;

    Node* newHead = reverseList(head); 

    Node* temp = newHead;
    int carry = 1; // Initialized carry with 1 because we have to add 1 in the linked list.
    while(temp != NULL){
        if(carry == 0) break;
        temp->data = temp->data + carry;
        if(temp->data > 9){
            carry = 1;
            temp->data = 0;
        }
        else{
            carry=0;
        }
        temp = temp->next;
    }
    newHead = reverseList(newHead);
    if(carry){
        Node* newNode = new Node(carry,newHead);
        head = newNode;
    }
    return head;
}

/*
Recursive Solution : Using Recursion and updating the values of the linked list by backtracking.
Step 1 : Write the edge case when there are 0 nodes in the linked list.
Step 2 : First, Go till the head of the linked list is null and this will be the base case and return 1.
Step 3 : Now while backtracking, add 1 to the node's data and if sum is <10 return 0 else return 1.
Step 4 : Update the node's data as per the sum.

Time Complexity : O(N)
Space Complexity : O(N)
*/
int helper(Node* head){
    if(head == NULL) return 1; // Base Case
    int carry = helper(head->next); // Using Backtracking to move backwards.
    head->data = head->data + carry;
    if(head->data < 10){
        return 0;
    }
    head->data = 0;
    return 1;
}

Node* addOneRecursive(Node* head){
    if(head == NULL) return NULL;

    int carry = helper(head); // Calling Recursion
    if(carry){ // If there is still carry left after recursion ends that means we have to add a new node.
        Node* newNode = new Node(carry,head);
        head = newNode; // Updating the head if new node is added.
    }
    return head; 
}

int main()
{
    vector<int> arr = {9,9,9,9,8};
    Node* head = Convert_Arr2LL(arr);

    head = addOneIterative(head);
    Traverse_LL(head);
    cout<<endl;

    head = addOneRecursive(head);
    Traverse_LL(head);
             
  return 0;
}