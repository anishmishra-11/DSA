/* You’re given a sorted doubly-linked list and a key 'k'. Delete all the nodes having data equal to ‘k’.*/
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
Brute Frute Solution : Solving it using 2 loops.
Step 1 : Iterate through the linked list and check for the given sum till temp2 != NULL.
Step 2 : If a pair is found then push it in the data structure or else continue to find.
Step 3 : After completing both the loops return the data structure.

Time Complexity : O(N^2)  
Space Complexity : O(1) 
*/
vector<pair<int, int>> findPairsBrute(Node* head, int k){
    vector<pair<int, int>> answer; // Declaring the data structure.
    Node* temp1 = head, *temp2 = NULL; // Declaring 2 pointers for iteration.

    while(temp1 != NULL){ // Going once a loop
        temp2 = temp1->next; // Starts from current's next element
        while(temp2 != NULL && temp1->data + temp2->data <= k){ // If sum is greater once then no need to go .
            if(temp1->data + temp2->data == k){ // Checking for the condition.
                answer.push_back({temp1->data, temp2->data}); // Storing in the data structure.
            }
            temp2 = temp2->next; // Moving the 2nd pointer for next iteration.
        }
        temp1 = temp1->next;
        
    }
    return answer;  
}

/*
Optimal Solution : Using left and right pointers and moving them according to their sum.
Step 1 : Initialize 2 pointers left as head and right as tail of the doubly linked list.
Step 2 : Check if their sum matches to the given value of k or not.
Step 3 : If matches then store it. Move both pointers towards each other.
Step 4 : Move left rightwards and right leftwards according to their sum.
Step 5 : Once the value in right is less than the value of left then it means they have crossed.

Time Complexity : O(2N)  ~ findTail takes O(N) and findPairs take O(N) i.e. O(N + N).
Space Complexity : O(1) 
*/
Node* findTail(Node* head){ // Written to initialize right as tail of the doubly linked list.
    while(head->next != NULL){
        head = head->next;
    }
    return head;
}

vector<pair<int, int>> findPairsOptimal(Node* head, int k){
    vector<pair<int, int>> answer; 
    Node* left = head, *right = findTail(head); 
    while(left->data < right->data){
        if(left->data + right->data == k){ // If the pointers sum matches the K.
            answer.push_back({left->data, right->data});
            left = left->next;
            right = right->back;
        }
        else if(left->data + right->data > k) right = right->back; // If the sum > k then move right backwards.
        else left = left->next; // It means that the sum is less than k then move left rigtwards i.e. next. 
    }
    return answer;  
}

// To print the answer vector for each function in one go.
void print_ans(vector<pair<int,int>> result){
    for(int i=0; i<result.size(); i++){
        cout<<result[i].first<<" "<<result[i].second<<endl;
    }
}

int main (){

    vector<int> arr = {1,2,4,5,6,7,10};
    Node* head = Convert_Arr2DLL(arr);

    vector<pair<int,int>> answer = findPairsBrute(head, 11); 
    print_ans(answer);

    vector<pair<int,int>> answer2 = findPairsOptimal(head, 11);
    print_ans(answer2);    

    return 0;
}