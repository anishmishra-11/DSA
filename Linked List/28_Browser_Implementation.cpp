#include <iostream>
#include <vector>
#include<string>
using namespace std;
/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */

class Node {
    public:
    string val;
    Node* next;
    Node* prev;

    public:
    Node(string data, Node * next, Node* prev){
        this->val = data;
        this->next = next;
        this->prev = prev;
    }

    public:
    Node(string data)
    {
      this->val = data;
      next = nullptr;
      prev = nullptr;
    }
};

class BrowserHistory {
public:
    Node* current;
    BrowserHistory(string homepage) {
        current = new Node(homepage);
    }
    
    void visit(string url) {
        Node* newNode = new Node(url);
        current->next = newNode;
        newNode->prev = current;
        current = newNode;
    }
    
    string back(int steps) {
        while(steps){
            steps--;
            if(current->prev) current = current->prev;
            else break;
        }
        return current->val;
    }
    
    string forward(int steps) {
        while(steps){
            if(current->next) current = current->next;
            else break;
            steps--;
        }
        return current->val;
    }
};

int main() {
    vector<string> operations = {"BrowserHistory","visit","visit","visit","back","back","forward","visit","forward","back","back"};
    vector<vector<string>> parameters = {{"leetcode.com"},{"google.com"},{"facebook.com"},{"youtube.com"},{ "1" },{ "1" },{ "1" },{"linkedin.com"},{ "2" },{ "2" },{ "7" }};
    vector<string> output;

    BrowserHistory* browser = nullptr;

    for (size_t i = 0; i < operations.size(); ++i) {
        if (operations[i] == "BrowserHistory") {
            browser = new BrowserHistory(parameters[i][0]);
            output.push_back("null");
        } else if (operations[i] == "visit") {
            browser->visit(parameters[i][0]);
            output.push_back("null");
        } else if (operations[i] == "back") {
            string result = browser->back(stoi(parameters[i][0]));
            output.push_back(result);
        } else if (operations[i] == "forward") {
            string result = browser->forward(stoi(parameters[i][0]));
            output.push_back(result);
        }
    }

    // Output the result
    cout << "Output: [";
    for (const string& val : output) {
        cout << "\"" << val << "\", ";
    }
    cout << "]" << endl;

    return 0;
}