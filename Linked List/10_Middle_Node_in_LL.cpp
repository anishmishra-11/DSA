/* Given the head of a singly linked list, return the middle node of the linked list. 
If there are two middle nodes, return the second middle node.*/
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
Brute Force Solution : Traverse two times in a linked list.
Step 1 : Write the edge case when head is null or if there is a single element in the linked list.
Step 2 : First, traverse through the array and find the length of the linked list.
Step 3 : Middle node will always be (N/2 + 1)th node in the linked list for both odd and even length test cases.
Step 4 : Traverse to the node and return the node.

Time Complexity : O(N + N/2)
Space Complexity : O(1)
*/
Node* middleNodeBrute(Node* head){
    if(head == NULL || head->next == NULL) return head;
    Node* temp = head;
    int length = 0;
    while(temp != NULL){ // Finding the length of the linked list.
        length++;
        temp = temp->next;
    }
    int midNode = (length/2) + 1; // Relation between length of a linked list and its middle node.
    temp = head; // Initializing the temp with head again to start from 0.
    while(temp != NULL){
        midNode--; // First decreasing and then matching.
        if(midNode == 0) return temp;
        temp = temp->next;
    }
}

/*
Better Solution : Tortoise-Hare-Approach
Step 1 : Write the edge case when head is null or if there is a single element in the linked list.
Step 2 : Create two pointers slow and fast and initialize them to a head pointer.
Step 3 : Move slow ptr by one step & fast ptr by two steps until fast ptr is NULL or next of fast ptr is NULL.
Step 4 : Now slow ptr will be on the middle of the linked list.

Time Complexity : O(N/2)
Space Complexity : O(1)
*/
Node* middleNode(Node* head){
    if(head == NULL || head->next == NULL) return head;
    Node* fast = head;
    Node* slow = head;

    while(fast != NULL && fast->next != NULL){
        fast = fast->next->next; // Fast moves by 2.
        slow = slow->next; // Slow moves by 1.
    }
    return slow;
}

int main(){
    vector<int> arr = {12, 1, 9, 8, 7, 1};
    Node* head = Convert_Arr2LL(arr);

    Traverse_LL(head);
    Node* middle_node = middleNodeBrute(head);
    cout<<endl<<middle_node->data<<endl;

    middle_node = middleNode(head);
    cout<<middle_node->data;

    return 0;
}