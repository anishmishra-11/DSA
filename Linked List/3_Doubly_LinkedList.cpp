/*A Doubly Linked List (DLL) is a special type of linked list in which each node contains 
a pointer to the previous node as well as the next node of the linked list.

Advantages of Doubly Linked List over the singly linked list:
1. A DLL can be traversed in both forward and backward directions. 

Applications of Doubly Linked List:
1. LRU ( Least Recently Used ) / MRU ( Most Recently Used ) Cache are constructed using Doubly Linked Lists. 
2. Used by various applications to maintain undo and redo functionalities.
3. Used by the browsers to go forward and come backward to the websites. 
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

// New Concepts and Functions start from here.
/*
Step 1 : Store the first element as the starting node and point its next to null and back to also null.
Step 2 : create a mover pointer to store the location of the first element. 
Step 3 : Iterate over the array and create a temp node whose next point to null and back to prev
Step 4 : Update the pointers through move and prev->next and prev=temp.
*/

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

/*
Step 1 : Write for edge cases first i.e if only 1 element or 0 element are present, then what should happen.
Step 2 : Store the head in a temp node, Move the head to next element.
Step 3 : Change the connections of new head and remove all the connections of temp head and then delete it.
*/
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

/*
Step 1 : Write for edge cases first i.e if only 1 element or 0 element are present, then what should happen.
Step 2 : Store the head in a temp node, Move to the last element of the linked list.
Step 3 : Update the next pointer of tail's previous node to nullptr.
Step 4 : Remove all the connections of temp node and then delete it.
*/
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

/*
Step 1 : Write for edge cases first i.e if 0 elements are present in DLL, then what should happen.
Step 2 : Initialize count and Move to the Kth element of the linked list.
Step 3 : Get the prev node and the front node of the Kth node.
Step 4 : Here we can find that there are 4 cases to delete : one element only, atHead, atTail or atIntermediate.
Step 5 : Check the if else if cases for better understanding of deletion for first 3 cases.
Step 6 : Update the connection of next in prev node and of back in front node.
Step 7 : Remove all the connections of temp node and then delete it. 
*/
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

/*
Step 1 : Get the prev node and the front node of the node.
Step 2 : If front is null then DLL has only two nodes in it, then update connections to nullptr.
Step 3 : Otherwise, update the connections in prev.next and temp.back.
Step 4 : Remove all the connections of given node or temp node and then delete it. 
*/
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

/*
Step 1 : Create a new node and at the time of creation pass next as given head and back to nullptr.
Step 2 : Update the connection in given head back as newNode.
Step 3 : Return the new updated node or head. 
*/
Node* insertBeforeHead(Node* head, int value){
    Node* newHead = new Node(value,head,nullptr);
    head->back = newHead;

    return newHead;
}

/*
Step 1 : Write for edge cases first i.e if only 1 element is present then what should happen.
Step 2 : Iterate and go till the last node of the DLL.
Step 3 : Create a new node with connection to the tail as next and back as tail's prev.
Step 4 : Update the connections of temp's back and prev's next and then return the head.
*/
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

/*
Step 1 : Write for edge cases first i.e if 1 element is present in DLL, then what should happen.
Step 2 : Initialize count and Move to the Kth element of the Doubly Linked List.
Step 3 : Get the prev node of the Kth node.
Step 4 : Create a new node with connectins to the next node as next and prev node as back.
Step 5 : Update the connections of temp's back and prev's next and then return the head.
*/
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

/*
Step 1 : Get the prev node of the given node.
Step 2 : Create a new node with connectins to the next node as next and prev node as back.
Step 3 : Update the connections of node's back and prev's next.
*/
//Given a Node, not head, Insert a given node before the given node in DLL and (Node != head)
void insertBeforeNode(Node* node, int value){
    Node* prev = node->back;
    Node* newNode = new Node(value,node,prev);

    prev->next = newNode;
    node->back = newNode;

}

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

    insertBeforeNode(head->next,100);
    Traverse_LL(head);

    return 0;
}