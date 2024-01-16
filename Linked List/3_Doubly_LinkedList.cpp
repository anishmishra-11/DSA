/*A Doubly Linked List (DLL) is a special type of linked list in which each node contains 
a pointer to the previous node as well as the next node of the linked list.

Advantages of Doubly Linked List over the singly linked list:
1. A DLL can be traversed in both forward and backward directions. 

Applications of Doubly Linked List:
1. LRU ( Least Recently Used ) / MRU ( Most Recently Used ) Cache are constructed using Doubly Linked Lists. 
2. Used by various applications to maintain undo and redo functionalities. 
*/
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

void Traverse_LL(Node* head){

    Node* temp = head;
    while(temp != nullptr)
    {
        cout<<temp->data<< " ";
        temp = temp->next;
    }  
}

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

Node* deleteHead(Node* head){
    if(head == NULL || head->next == NULL){
        return NULL;
    }

    Node* prev = head;
    head = head->next;
    head->back = nullptr;
    prev->next = nullptr;

    delete prev;

    return head;
}

Node* deleteTail(Node* head){
    if(head == NULL || head->next == NULL) return NULL;

    Node* tail = head;
    while (tail->next != NULL)
    {
        tail = tail->next;
    }
    tail->back->next = nullptr;
    tail->back = nullptr;

    delete tail;

    return head;
}

Node* deleteKthElement(Node* head, int k){
    if(head == NULL) return NULL;
    //This code helps to go to the Kth node of the Doubly Linked List.
    int count = 0;
    Node* temp = head;
    while(temp->next != NULL){
        count++;
        if(count == k) break;
        temp = temp->next;
    }

    //After reaching to Kth node, We can find pointers for prev and next elements 
    Node* prev = temp->back;
    Node* front = temp->next;

    //This is the edge case if DLL consists of a single element.
    if(prev == NULL && front == NULL){
        delete temp;
        return NULL;
    }
    else if (prev == NULL){ //This is the edge case where we have to delete the 1st element of the DLL.
        head = deleteHead(temp);
        return head;
    }
    else if(front == NULL){ //This is the edge case where we have to delete the Nth or Last element of the DLL.
        head = deleteTail(head);
        return head;
    }
    else { //This is the case for standing at any intermediate node of the DLL.
        prev->next = temp->next;
        front->back = prev;
        temp->next = nullptr;
        temp->back = nullptr;
    }

    return head;
}

//Given a Node, not head, Delete a given node from DLL and (Node != head)
void deleteNode(Node* temp){
    Node* prev = temp->back;
    Node* front = temp->next;

    if(front == NULL){
        prev->next = nullptr;
        temp->back = nullptr;
        delete temp;
        return;
    }

    prev->next = front;
    front->back = prev;
    temp->next = temp->back = nullptr;

    delete(temp);    
}

Node* insertBeforeHead(Node* head, int value){
    Node* newHead = new Node(value,head,nullptr);
    head->back = newHead;

    return newHead;
}

Node* insertBeforeTail(Node* head, int value){
    if(head->next == NULL){
        return insertBeforeHead(head, value);
    }
    Node* temp = head;
    while(temp->next != NULL){
        temp = temp->next;
    }

    Node* prev = temp->back;
    Node* newNode = new Node(value, temp, prev);
    temp->back = newNode;
    prev->next = newNode;

    return head;
}


Node* insertBeforeKthElement(Node* head, int k, int value){
    if(k==1){
        head = insertBeforeHead(head, value);
        return head;
    }

    Node* temp = head;
    int count = 0;

    while(temp->next != NULL){
        count++;
        if(count == k) break;
        temp = temp->next;

    }
    Node* prev = temp->back;
    Node* newNode = new Node(value, temp, prev);
    prev->next = newNode;
    temp->back = newNode;

    return head;
}

//Given a Node, not head, Insert a given node before the given node in DLL and (Node != head)

int main (){

    vector<int> arr = {1,2,3,4,5,6,7,8};
    Node* head = Convert_Arr2DLL(arr);

    Traverse_LL(head);
    cout<<endl;

    head = deleteHead(head);
    Traverse_LL(head);
    cout<<endl;

    head = deleteTail(head);
    Traverse_LL(head);
    cout<<endl;

    head = deleteKthElement(head,7);
    Traverse_LL(head);
    cout<<endl;

    deleteNode(head->next);
    Traverse_LL(head);
    cout<<endl;

    head = insertBeforeHead(head,11);
    Traverse_LL(head);
    cout<<endl;

    head = insertBeforeTail(head,121);
    Traverse_LL(head);
    cout<<endl;

    head = insertBeforeKthElement(head,6,151);
    Traverse_LL(head);
    cout<<endl;

    return 0;
}