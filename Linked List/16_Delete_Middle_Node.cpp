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
Brute Force Solution : Find the length of the linked list and then go the (middle-1)th node.
Step 1 : Write the edge case when there are 0 node or 1 node in the linked list.
Step 2 : First, find the lenth of the linked list.
Step 3 : Find the middle index of the lists i.e. integer division of N by 2.
Step 4 : Start traversal again from head and go to the middle's previous node.
Step 5 : Change the links and delete the middle node.

Time Complexity : O(N + N/2)
Space Complexity : O(1)
*/
Node* deleteMiddleBrute(Node* head){
    if(head == NULL || head->next == NULL) return NULL;
    int count=0;
    Node* temp = head;
    while(temp != NULL){ // Finding the length of the linked list.
        count++;
        temp = temp->next;
    }

    int middle = count/2; // Index of the middle's previous node.
    temp = head;

    while(middle){ // Going to the middle's previous node.
        middle--;
        if(middle == 0){
            Node* mid = temp->next; // Storing the node to delete it later.
            temp->next = temp->next->next;
            delete mid; // Freeing up the space
        }
        temp = temp->next;
    }
    return head;
}

/*
Optimal Solution : Use Tortoise and Hare Algorithm and go to the (middle-1)th node.
Step 1 : Write the edge case when there are 0 or 1 node in the linked list.
Step 2 : Initialize prev, slow and fast pointers.
Step 3 : Move fast by 2step, slow & prev pointers by 1 step.
Step 4 : Change the links using prev & slow pointers and delete the middle node.

Time Complexity : O(N/2)
Space Complexity : O(1)
*/
Node* deleteMiddleOptimal(Node* head){
    if(head == NULL || head->next == NULL) return NULL;
    Node* fast = head, *slow = head, *prev = NULL;

    while(fast != NULL && fast->next != NULL){
        prev = slow;
        fast = fast->next->next;
        slow = slow->next;
    }
    prev->next = slow->next;
    return head;
}

int main()
{
    vector<int> arr = {9,19,1,29,8,10};
    Node* head = Convert_Arr2LL(arr);

    head = deleteMiddleBrute(head);
    Traverse_LL(head);
    cout<<endl;

    head = deleteMiddleOptimal(head);
    Traverse_LL(head);
             
  return 0;
}