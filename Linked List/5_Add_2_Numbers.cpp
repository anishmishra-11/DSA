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

/*
2->4->6->x : Given number 1 is 642.
3->8->7->x : Given number 2 is 783.


When we will add these 2 numbers : 
  246
 +783
----------
1425
5->2->4->1->x : Sum of the given two numbers is 1425.
*/

Node* Add2Numbers(Node*head1, Node* head2){
    Node* temp1 = head1;
    Node* temp2 = head2;
    int carry = 0;
    Node* dummyHead = new Node(-1);
    Node* current = dummyHead;

    while (temp1 != NULL || temp2 != NULL)
    {
        int sum = carry;
        if(temp1) sum += temp1->data;
        if(temp2) sum += temp2->data;

        Node* newNode = new Node(sum%10);
        carry = sum/10;

        current->next = newNode;
        current = current->next;

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

    vector<int> arr1 = {6,4,2};
    Node* head1 = Convert_Arr2LL(arr1);

    vector<int> arr2 = {3,8, 7};
    Node* head2 = Convert_Arr2LL(arr2);

    Node* resultHead = Add2Numbers(head1,head2);
    Traverse_LL(resultHead);

    return 0;
}



