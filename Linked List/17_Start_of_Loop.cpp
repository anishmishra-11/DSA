#include <iostream>
#include <vector>
#include <unordered_map>
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
Brute Frute Solution : Storing nodes of linked list in a map and then matching if already seen.
Step 1 : Iterate through the linked list and store each node in a unordered map.
Step 2 : Before storing check if the node already exists in the map or not.
Step 3 : If found, return the node itself, which is the start of the loop else return NULL.

Time Complexity : O(N*2*(1)) 2 is the number of map operations and 1 is for time complexity of map operation. 
Space Complexity : O(N) 
*/
Node* StartOfLoopBrute(Node* head){
    unordered_map<Node*, int> m;
    Node* temp = head;

    while (temp != NULL) {
        if (m.find(temp) != m.end()) {
            return temp;
        }
        m[temp] = 1;
        temp = temp->next;
    }

    return NULL;  
}

/*
Optimal Solution : Using Tortoise and Hare Algorithm and reinitialization of slow to head.
Step 1 : Initialize slow and fast pointers from head of the linked list.
Step 2 : Move slow by one step and fast by two step.
Step 3 : If they are meeting then there is a loop and hence find start of it else return NULL.
Step 4 : Now, move slow to head and move both the pointers, slow and fast by 1 step each.
Step 5 : The node at they meet again is the starting point of the loop.

Time Complexity : O(N) 
Space Complexity : O(1) 

Why this works ? This algorithm works because after detecting a loop the distance from the node where it is 
detected and the distance of start of loop from its head is at the same distance i.e. d. You can check it 
by taking some examples.
*/
Node* StartOfLoopOptimal(Node* head){
    Node* slow = head;
    Node* fast = head;

    while(fast != NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;

        if(slow == fast){ // Here we are finding the starting of loop.
            slow = head;
            while(slow != fast){
                slow = slow->next;
                fast = fast->next;
            }
            return fast;
        }
    }
    return NULL;
}

int main()
{
    vector<int> arr = {9,19,1,29,8,11,7};
    Node* head = Convert_Arr2LL(arr);

    head->next->next->next->next = head->next->next; // Making a loop for check

    Node* answer = StartOfLoopBrute(head);
    cout<<answer->data<<endl;

    answer = StartOfLoopOptimal(head);
    cout<<answer->data<<endl;
             
  return 0;
}