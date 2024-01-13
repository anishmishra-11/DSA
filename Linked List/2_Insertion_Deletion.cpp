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

    //started from 1 because 0th index element was already included.
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

// New Concepts and Functions start from here.
/*1->2->3 Delelte 1 from here
Step 1 : Store the head in a temp node.
Step 2 : Move the head from 1 to 2 and then delete the temp.
Step 3 : Always write the edge case if head is NULL.
*/
Node * deleteHead(Node *head){
    if (head == NULL) return head;
    
    Node* temp = head;
    head = head->next;
    delete temp; //deleting the node to free up space from the heap memory

    return head;
}

/*1->2->3 Delelte 3 from here
Step 1 : Always write the edge case if head is NULL.
Step 2 : Write the case where there is only 1 node in the Linked List.
Step 3 : Stop before the last element of the Linked List.
Step 4 : Delete the next of temp which is the tail of the Linked List.
Step 5 : Assign null ptr to the temp->next. 
*/
Node* deleteTail(Node* head){
    Node*temp = head;
    if(head == NULL || head->next == NULL) return NULL;

    while (temp->next->next != NULL)
    {
        temp = temp->next;
    }
    delete temp->next;
    temp->next = nullptr;

    return head;
}

/*1->2->3 Delelte 2 from here
Step 1 : Always write the edge case if head is NULL and No element to delete.
Step 2 : Write the case for deleting the head of the Linked List.
Step 3 : Initialize a prev pointer with null, count = 0 and temp = head.
Step 4 : Check by conunt that which node is to be delted by traversing through the Linked List.
Step 5 : Change the next of prev to temp->next and then delete temp. 
*/
Node* deleteAtK(Node* head, int k){
    if(head == NULL) return head;

    //Deleting the head
    if (k == 1)
    {
        Node* temp = head;
        head = head->next;
        delete temp;
        
        return head;
    }

    Node* temp = head;
    Node* prev = nullptr;
    int count = 0;

    //Go till temp is null 
    while (temp != NULL)
    {
        count++;
        if (count == k) //Check by number if node is same which is to be deleted.   
        {
            //Establish the link between the previous node and next node before deleting the temp node.
            prev->next = temp->next;
            delete temp;
            break; //if node is deleted then no need to move forward and hence break.
        }
        prev = temp;
        temp = temp->next;
    }

    return head;    
}

/*1->2->3 Delelte 2(By Value) from here
Step 1 : Always write the edge case if head is NULL.
Step 2 : Write the case for deleting the head of the Linked List.
Step 3 : Initialize a prev pointer with null and temp = head.
Step 4 : Check by value at each node if that node is to be delted by traversing through the Linked List.
Step 5 : Change the next of prev to temp->next and then delete temp. 
*/
Node* deleteElement(Node* head, int n){
    if(head == NULL) return head;

    if (head->data == n)
    {
        Node* temp = head;
        head = head->next;
        delete temp;
        
        return head;
    }

    Node* temp = head;
    Node* prev = nullptr;

    while (temp != NULL)
    {
        if (temp->data == n)
        {
            prev->next = temp->next;
            delete temp;
            break;
        }
        prev = temp;
        temp = temp->next;
    }

    return head;    
}


/* 2 : Add 1 as the head of the Linked List.
Step 1 : Create a new node and point its next to the head.
Step 2 : Return the head of the new node.
*/
Node* insertHead(Node* head, int value){
    Node* temp = new Node(value, head);

    return temp;
}

/* 1->2->3 : Add 4 at the tail of the Linked List.
Step 1 : Always write the edge case if head is NULL.
Step 2 : Travese to the last element of the Linked List.
Step 3 : Create a new node and point its next to the nullptr.
Step 4 : Point the next of the last element of the LL to the new node. 
Step 5 : Return the head of the Linked List.
*/
Node* insertTail(Node* head, int value){
    if(head == NULL) return NULL;

    Node* temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    Node* tailNode = new Node(value);
    temp->next = tailNode;

    return head;
    
}

//Here the value of k will be between 1 to length of LL + 1.
/* 1->2->3->4 : Add 5 at the kth position of the Linked List.
Step 1 : Always write the edge case if head is NULL and check if node is to be inserted there or not.
Step 2 : Write if the node is to be added at Head of the Linked List. 
Step 3 : Initialize the count with 0 and Travese till the nullptr of the Linked List.
Step 4 : Check if the current node is one position behind the kth position.
Step 5 : Create a new node and point its next to the next element of the Linked List.
Step 6 : Establish the new connection before breaking the old connections.
Step 7 : Return the head of the Linked List.
*/
Node* insertAtPosition(Node* head, int value, int k){
    if(head == NULL){
        if(k == 1){
            Node* newNode = new Node(value);
            return newNode;
        }
        else{
            return head;
        }    
    }

    if(k == 1){
        Node* newNode = new Node(value,head);
        return newNode;
    }

    Node* temp = head;
    int count = 0;

    while (temp != NULL)
    {
        count++;
        if (count == k-1)
        {
            Node* newNode = new Node(value);
            newNode->next = temp->next;
            temp->next = newNode;
            break;
        }

        temp = temp->next;  
    }
    return head;
}

//Insert the element before value x.
/* 1->2->3->4 : Add 5 before ther given value of x in the Linked List.
Step 1 : Always write the edge case if head is NULL.
Step 2 : Write the case if the node is to be added at Head of the Linked List. 
Step 3 : Travese till the last element of the Linked List.
Step 4 : Check if the next node data is same as the given value.
Step 5 : Create a new node and point its next to the next element of the Linked List.
Step 6 : Establish the new connection before breaking the old connections.
Step 7 : Return the head of the Linked List.
*/
Node* insertBeforeValue(Node* head, int element, int value){
    if(head == NULL){
       return NULL;
    }

    if(head->data == value){
        Node* newNode = new Node(element,head);
        return newNode;
    }

    Node* temp = head;
    while (temp->next != NULL)
    {
        if (temp->next->data == value)
        {
            Node* newNode = new Node(element);
            newNode->next = temp->next;
            temp->next = newNode;
            break;
        }
        temp = temp->next;  
    }
    return head;
}


int main()
{
    vector<int> arr = {12,1,2,3,5,6,7};
    Node* head = Convert_Arr2LL(arr);

    Node* head1 = deleteHead(head);
    Traverse_LL(head1);
    cout<<endl;

    Node* head2 = deleteTail(head1);
    Traverse_LL(head2);
    cout<<endl;

    Node* head3 = deleteAtK(head2,6);
    Traverse_LL(head3);
    cout<<endl;

    Node* head4 = deleteElement(head3,11);
    Traverse_LL(head4);
    cout<<endl;

    Node* head5 = insertHead(head4,11);
    Traverse_LL(head5);
    cout<<endl;

    Node* head6 = insertTail(head5,121);
    Traverse_LL(head6);
    cout<<endl;

    Node* head7 = insertAtPosition(head6,51,5);
    Traverse_LL(head7);
    cout<<endl;

    Node* head8 = insertBeforeValue(head7,55,121);
    Traverse_LL(head8);
    cout<<endl;

    return 0;
}

