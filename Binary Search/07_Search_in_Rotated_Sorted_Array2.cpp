// In this problem the array may contain duplicate elements.
#include <bits/stdc++.h>
using namespace std;

/*
Brute Force Approach : Perform Linear Search and update index after every match.

Step 1 : Run a loop from start to end of the array. 
Step 2 : For every index match if the value is same as the given target value.
Step 3 : If it matches then update the index value and break out from the loop.
Step 4 : Return first and last as a pair.

Time Complexity : O(N) 
Space Complexity : O(1)
*/
bool searchRotatedSortedBrute(vector<int>& arr, int k) {
    bool index = false;
    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] == k) {
           index = i;
           break;
        }
    }
    return index; 
}

/*
Optimal Approach : Perform Binary Search.

Step 1 : Write a general binary search program.
Step 2 : After calculating mid check which half is sorted and in which part next iteration should go.
Step 3 : Check if value at low, mid and high are equal then shrink the search space by reducing low and high.
Step 4 : Check if the the number lies in that part else the number lies in the other half
Step 5 : Keep updating low and high by eliminating search space.

Time Complexity : O(log N) // For average case,
but in worst case it can be nearly O(N/2)

Space Complexity : O(1)
*/
bool searchRotatedSorted(vector<int>& arr, int key){
    int low = 0, high = arr.size()-1;
    while(low <= high){
        int mid = (low+high)/2;
        if(arr[mid] == key) return true;
        if(arr[low] == arr[mid] && arr[mid] == arr[high]){
            low = low + 1;
            high = high - 1;
            continue;
        }
        else if(arr[low] <= arr[mid]){
            if(arr[low] <= key && key <= arr[mid]) high = mid - 1;
            else low = mid + 1;
        }
        else{
            if(arr[mid] <= key && key <= arr[high]) low = mid + 1;
            else high = mid - 1;
        }
    }
    return false;
}

int main()
{
    vector<int> arr =  {5,8,9,10,1,3,4};
    int k = 3;
    
    bool answer = searchRotatedSortedBrute(arr,k);
    cout<<"The value "<< k << "is at index " <<answer << endl;
    
    bool index = searchRotatedSorted(arr,k);
    cout<< "The value "<< k << "is at index " <<index;
    return 0;
}