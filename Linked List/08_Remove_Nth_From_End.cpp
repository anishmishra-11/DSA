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
Brute Frute Solution : Traversting two times and using length of the linked list.
Step 1 : Write the edge case when head is null.
Step 2 : First, we have to traverse once to find the length of the linked list.
Step 3 : Then by again traversing we have to go to the (Nth node-1) node to change the links before deletion.
Step 4 : Write the edge case if we have to delete the head of the linked list.
Step 5 : Return the new head or the original head of the linked list.

Time Complexity : O(2N)
Space Complexity : O(1)
*/
Node* removeKthNodeBrute(Node* head, int K)
{
    if(head == NULL) return NULL;
    Node* temp = head;
    int length = 0;
    while(temp != NULL){ // Traversing through the linked list to find the length.
        length++;
        temp = temp->next;
    }

    if (length == K) { // This is the case for deleting the head.
        Node *newHead = head->next;
        delete head;
        return newHead;
    }

    int indexFromStart = length-K-1; // This is done to stop at the previous node of the node to be deleted.
    int count = 0;
    temp = head;
    while(count != (indexFromStart)){ 
        count++;
        temp = temp->next;
    }
    Node* delNode = temp->next;
    temp->next = temp->next->next; // Updating the links in the previous node.
    delete delNode;
    return head;

}

/*
Optimal Solution : 
Step 1 : Write the edge case when head is null.
Step 2 : First, we have to initialize a fast pointer and move it K places ahead.
Step 3 : Now, declare a slow pointer and move both the pointers till fast pointer reaches the last node.
Step 4 : Write the edge case if we have to delete the head of the linked list when fast is already NULL.
Step 5 : Change the links of the slow node and return the new head or original head of the linked list.

Time Complexity : O(N)
Space Complexity : O(1)
*/
Node* removeKthNodeOptimal(Node* head, int K){
    if(head == NULL) return NULL;
    Node* fast = head;
    while(K != 0){ // Moving the fast pointer K places ahead to reach the correct node.
        fast = fast->next;
        K--;
    }
    Node* slow = head;

    // if K == Length of the linked list then fast will point to NULL which means we have to delete head.
    if (fast == NULL){ //This is to delete the head of the linked list.
        Node *newHead = head->next;
        delete head;
        return newHead;        
    }

    while(fast->next != NULL){ // Moving forward each pointer untill fast reaches the last node.
        fast = fast->next;
        slow = slow->next;
    }
    
    Node* delNode = slow->next;
    slow->next = slow->next->next; // Updating the links in the previous node.
    delete delNode;
    return head;
}

int main()
{
    vector<int> arr = {12, 1, 9, 8, 7, 1, 5};
    Node* head = Convert_Arr2LL(arr);

    head = removeKthNodeBrute(head,3);
    Traverse_LL(head);
    cout<<endl;

    head = removeKthNodeOptimal(head,6);
    Traverse_LL(head);

  return 0;
}