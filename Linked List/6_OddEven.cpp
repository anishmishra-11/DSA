//Odd Event linked list.
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
Brute Frute Solution : By changing the values inside the nodes using array.
Step 1 : We have to use a array to store the data of the linked list.
Step 2 : First, we have to traverse through the linked list and push the even values present in the list.
Step 3 : Again, traverse through the linked list and push the odd values in the array present in the list.
Step 4 : At Last, Traverse again in the array this time replacing the values of the linked list from the array.
Step 5 : Remember to initialize the temp to head before the traversal.

Why this works ? This solution works because we are first storing the even numbers in the sequence that they are
present and then storing the odd numbers in their sequence. After all the numbers come in the array, we are just
replacing them in the linked list as per their original sequence.

Time Complexity : O(2N)
Space Complexity : O(N)
*/

//This function is used to segregate odd and even values of the linked list not the postion of the nodes.
Node* SegregateOddEvenBrute(Node* head){
    if(head == NULL || head->next == NULL) return head;
    vector<int> arr;
    Node* temp = head;

    while(temp != NULL){
        if(temp->data % 2 == 0){
            arr.push_back(temp->data);
        }
        temp = temp->next;
    }

    temp = head; //reinitialization of head to start from the start of the list again.
    while(temp != NULL){
        if(temp->data % 2 != 0){
            arr.push_back(temp->data);
        }
        temp = temp->next;
    }

    temp = head; //reinitialization of head to start from the start of the list again.
    int i = 0;
    while(temp != NULL){
        temp->data = arr[i]; //assigning the new values in the linked list.
        i++;
        temp = temp->next;        
    }
    return head;
}

/*Appraoch 2 : Better Solution - Optimized Space Complexity
Step 1 : Changing the links for odd indexed nodes.
Step 2 : Changing the links for even indexed nodes.
Step 3 : At last, connecting the last odd node link with the first even node in the linked list.
*/

Node* SegregateOddEvenIndex(Node* head){
    if(head == NULL || head->next == NULL) return head;

    Node* odd = head;
    Node* even = head->next;
    Node* evenHead = even;

    while(even != NULL && even->next != NULL){ // && is used to stop even at its last position.
        odd->next = odd->next->next;
        even->next = even->next->next;

        odd = odd->next;
        even = even->next;
    }
    odd->next = evenHead;// Connecting the last odd indexed element link with the first even node.

    return head;// The first node will be an odd node and we have not touched it so return original head.
}

int main()
{
    vector<int> arr = {6, 1, 4, 5, 7, 8, 9};
    Node* head = Convert_Arr2LL(arr);

    head = SegregateOddEvenBrute(head);
    Traverse_LL(head);
    cout<<endl;

    head = SegregateOddEvenIndex(head);
    Traverse_LL(head);

  return 0;
}