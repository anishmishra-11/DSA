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
Brute Frute Solution : By counting the occurences of 0,1,2 in the linked list.
Step 1 : We have to use three variables for storing the number of occurences of each number.
Step 2 : Traverse through the linked list and update the count of each number present there.
Step 3 : Bring back the temp to head of the linked list.
Step 4 : Run a loop and replace the values of the linked list with the correct number of occurences.

Time Complexity : O(2N)
Space Complexity : O(1)
*/
Node* Sort_012Brute(Node* head){
    if(head == NULL || head->next == NULL) return head;

    Node* temp = head;
    int count_0 = 0, count_1 = 0, count_2 = 0;

    while(temp != NULL){
        if(temp->data == 0) count_0++;        
        else if(temp->data == 1) count_1++;
        else count_2++;
        temp = temp->next;
    }
    temp = head; // Reinitialization of head
    for(int i=1; i<=count_0; i++){ //Placing number of 0 in the linked list.
        temp->data = 0;
        temp = temp->next;
    }

    for(int i=1; i<=count_1; i++){ //Placing number of 1 in the linked list.
        temp->data = 1;
        temp = temp->next;
    }

    for(int i=1; i<=count_2; i++){ //Placing number of 2 in the linked list.
        temp->data = 2;
        temp = temp->next;
    }

    return head;
}

/*Appraoch 2 : Better Solution - By Changing the links - Optimized Space Complexity
Step 1 : First, handle the edge cases related to head.
Step 2 : Initialize 3 dummy head nodes called N_dummyHeades for each 0, 1 and 2.
Step 3 : Traverse through the linked list using temp and make 3 separate linked lists using temp & dummyHeads.
Step 4 : Connect the links in a correct order of the 3 small linked list for handling multiple cases.

Time Complexity : O(N)
Space Complexity : O(1)
*/
Node* Sort_012Optimal(Node* head){
    if(head == NULL || head->next == NULL) return head;

    Node* zeroDummyHead = new Node(-1), *oneDummyHead = new Node(-1), *twoDummyHead = new Node(-1);
    Node *zero = zeroDummyHead, *one = oneDummyHead, *two = twoDummyHead;

    Node* temp = head;
    while (temp != NULL)
    {
        if(temp->data == 0) {
            zero->next = temp;
            zero = zero->next; // It also can be written as temp.
        }
        else if(temp->data == 1) {
            one->next = temp;
            one = one->next;
        }
        else {
            two->next = temp;
            two = two->next;
        }    
        temp = temp->next;
    }

    // Attaching the links of the 3 different linked list considering multiple cases.
    zero->next = oneDummyHead->next ? oneDummyHead->next : twoDummyHead->next; // Used to point the new head
    one->next = twoDummyHead->next; 
    two->next = NULL; // Last node should anyways point to null 

    Node* newHead = zeroDummyHead->next; // Storing the new head.
    delete zeroDummyHead, oneDummyHead, twoDummyHead; // Freeing up the space used by dummy nodes.

    return newHead;   
}

int main(){
    vector<int> arr = {2, 1, 0, 0, 2, 1, 0};
    Node* head = Convert_Arr2LL(arr);

    head = Sort_012Brute(head);
    Traverse_LL(head);
    cout<<endl;

    vector<int> arr1 = {1, 1, 0, 2, 2, 1, 2,2,1,0};
    Node* head1 = Convert_Arr2LL(arr1);

    head1 = Sort_012Optimal(head1);
    Traverse_LL(head1);
    return 0;
}