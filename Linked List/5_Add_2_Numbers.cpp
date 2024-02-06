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
2->4->6->x : Given number 1 is 642.
3->8->7->x : Given number 2 is 783.

When we will add these 2 numbers : 
  642
 +783
----------
 1425
5->2->4->1->x : Sum of the given two numbers is 1425.


Step 1 : Initialize a carry and a dummy head to store the head of the linked list.
Step 2 : Run a loop till both of the linked list becomes null and perform sum calculation on their each node.
Step 3 : Identify the number to be stored and the carry by dividing by 10 (for number > 10).
Step 4 : At last check if there is still carry left or not and if left assign it in a new node.

Why this works ? This solution works because stacks work on the basis of last in first out manner
and the last data of the stack gets stored on the top of the linked list. Also, the first data will be 
stored at the last in the stack.

Time Complexity : O()
Space Complexity : O()
*/

Node* Add2Numbers(Node*head1, Node* head2){
    Node* temp1 = head1;
    Node* temp2 = head2;
    int carry = 0;
    Node* dummyHead = new Node(-1);
    Node* current = dummyHead;

    while (temp1 != NULL || temp2 != NULL) //Running till both linked list becomes null.
    {
        int sum = carry;
        if(temp1) sum += temp1->data; //Checking if list is empty or not 
        if(temp2) sum += temp2->data; //Checking if list is empty or not 

        Node* newNode = new Node(sum%10); //Assigning the value in the node by making a number in single digit.
        carry = sum/10; //It will only store 0 or 1

        current->next = newNode; //Adding the new Node to the linked list.
        current = current->next; //Moving the current pointer

        if(temp1) temp1 = temp1->next;
        if(temp2) temp2 = temp2->next;
    }
    if (carry)
    {
        Node* newNode = new Node(carry);
        current->next = newNode;
        newNode->next = nullptr;
    }

    return dummyHead->next;
    
}

int main (){

    vector<int> arr1 = {2,4,6};
    Node* head1 = Convert_Arr2LL(arr1);

    vector<int> arr2 = {3,8,7};
    Node* head2 = Convert_Arr2LL(arr2);

    //Answer is also stored in the reverse order.
    Node* resultHead = Add2Numbers(head1,head2);
    Traverse_LL(resultHead);

    return 0;
}



