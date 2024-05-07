#include<bits/stdc++.h>
using namespace std;

/*
Optimal Approach : Perform Binary Search.

Step 1 : Initialize low as 1 and high as the largest possible answer.
Step 2 : Check if pow(mid,n) is equal to m then return mid.
Step 3 : If greater than m update high = mid - 1 else update low = mid + 1.

Time Complexity : O(log N) 
Space Complexity : O(1)
*/
int NthRoot(int n, int m) {
  // Write your code here.
  int low = 1, high = m;

  while(low <= high){
    long long mid = (low + high)/2;
    long long answer = 1;
    for(int i=0; i<n; i++){
      if(answer > m) break;
      answer = answer * mid;
    }
    if(answer == m) return mid;
    else if (answer < m) low = mid + 1;
    else high = mid - 1; 
  }
  return -1;
}

int main()
{
    int number = 81, root = 3;
    int answer = NthRoot(root, number);
    cout<<root<<"th root of "<<number << " is "<<answer;

    return 0;
}