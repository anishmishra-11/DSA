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
Brute Frute Solution : Storing nodes of linked list and checking if they already exist in the data sturcture.
Step 1 : Iterate through the linked list and store each node in a unordered map.
Step 2 : Before storing check if the node already exists in the map or not.
Step 3 : If found, return true which means there is a loop else return false.

Time Complexity : O(N*2*(1)) 2 is the number of map operations and 1 is for time complexity of map operation. 
Space Complexity : O(N) 
*/
bool detectLoopBrute(Node* head){
    unordered_map<Node*, int> m;
    Node* temp = head;

    while (temp != NULL) {
        if (m.find(temp) != m.end()) {
            return true;
        }
        m[temp] = 1; // Insertion in the map.
        temp = temp->next;
    }

    return false; 
}

/*
Optimal Solution : Using Tortoise and Hair Algorithm
Step 1 : Initialize slow and fast pointers from head of the linked list.
Step 2 : Move slow by one step and fast by two step.
Step 3 : If they are meeting then return true that means there is a loop
Step 4 : If fast becomes null or fast's next becomes null then return false.

Time Complexity : O(N) 
Space Complexity : O(1) 

Why this works ? This algorithm works because slow moves by 1 and fast moves by 1 and there will be a point
when distance between them will becomes 0 as it is decreasing 1 by 1 in each step.
*/
bool detectLoopOptimal(Node* head){
    Node* slow = head;
    Node* fast = head;

    while(fast != NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;

        if(slow == fast) return true;
    }
    return false;
}
int main()
{
    vector<int> arr = {9,19,1,29,8};
    Node* head = Convert_Arr2LL(arr);

    head->next->next = head->next; // Making a loop for check

    bool answer = detectLoopBrute(head);
    cout<<answer<<endl;

    answer = detectLoopOptimal(head);
    cout<<answer;

             
  return 0;
}