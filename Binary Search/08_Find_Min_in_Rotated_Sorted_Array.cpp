// In this problem the array contains only unique elements. 
// But a similar question can be asked for duplicate elements as well.
#include <bits/stdc++.h>
using namespace std;

/*
Optimal Approach : Perform Binary Search.

Step 1 : Write a general binary search program.
Step 2 : After calculating mid check which half is sorted.
Step 3 : Compare the sorted side lowest value to existing lowest value and update the lowest value.
Step 4 : Keep updating low and high by eliminating sorted search space and updating the lowest value.
Step 5 : We can optimize the solution if we found that the search space is sorted already.
Step 6 : Check if arr[low] <= mid and arr[mid] <= high if yes then update lowest value and break from BS.
Above condition can be trimmed down to arr[low] <= arr[high]

Time Complexity : O(log N) 
For Duplicate case, it can be nearly O(N/2)

Space Complexity : O(1)
*/
int findMin(vector<int>& arr){
   int low = 0, high = arr.size()-1;
   int answer = INT_MAX;

   while(low <= high){
        int mid = (low + high)/2;

        if(arr[low] <= arr[high]){ // This is written to optimize the algorithm.
            answer = min(arr[low], answer);
            break;
        }

        if(arr[low] <= arr[mid]){ // This is checking if the left side searh space is sorted
            answer = min(arr[low], answer); // finding the minimum value
            low = mid + 1;
        }
        else{ // This means that the right half i.e. starting from mid is sorted.
            answer = min(arr[mid], answer); // finding the minimum value
            high = mid - 1;
        }
   }
   return answer;
}

int main()
{
    vector<int> arr =  {3,4,5,1,2};
    
    int answer = findMin(arr);
    cout<<"The smallest value is " <<answer << endl;
   
    return 0;
}