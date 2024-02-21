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
Brute Frute Solution : Storing nodes of linked list with a timer.
Step 1 : Iterate through the linked list and store each node in a unordered map.
Step 2 : Before storing check if the node already exists in the map or not. Increase the timer after storing.
Step 3 : If found, return the length using formula ((timer + 1) - Timer) at the current node else return false.

Time Complexity : O(N*2*(1)) 2 is the number of map operations and 1 is for time complexity of map operation. 
Space Complexity : O(N) 
*/
int LengthOfLoopBrute(Node* head){
    unordered_map<Node*, int> m;
    Node* temp = head;
    int timer = 0;

    while (temp != NULL) {
        if (m.find(temp) != m.end()) {
            return timer - m[temp] + 1;
        }
        timer++;
        m[temp] = timer; 
        temp = temp->next;
    }

    return 0; 
}

/*
Optimal Solution : Using Tortoise and Hare Algorithm
Step 1 : Use slow and fast pointers to find a loop in the linked list.
Step 2 : After detection of the loop then move 1 complete round to the same node using one pointer.
Step 3 : Increment count for each node and whene again the pointers meet return the count.
Step 4 : If no loop is found then return 0.

Time Complexity : O(N)
Space Complexity : O(1) 
*/
int LengthOfLoopOptimal(Node* head){
    Node* slow = head;
    Node* fast = head;

    while(fast != NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;

        if(slow == fast){ // Finding the length of the loop.
            fast = fast->next; // Moving 1 step every time.
            int count = 1; //Starting from the next node and count as 1.
            while(fast != slow){
                count++;
                fast = fast->next;
            }
            return count;
        }
    }
    return 0;
}

int main()
{
    vector<int> arr = {9,19,1,29,8,12,19,7};
    Node* head = Convert_Arr2LL(arr);

    head->next->next->next->next->next = head; // Making a loop for check 

    int answer = LengthOfLoopBrute(head);
    cout<<answer<<endl;

    answer = LengthOfLoopOptimal(head);
    cout<<answer;
        
  return 0;
}