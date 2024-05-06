#include <iostream>
#include <vector>
using namespace std;

/*
Recursive Implementation : Takes 4 parameters i.e. the array, the low pointer, the high pointer and the target. 

Approach : In each recursive call, we will change the value of low and high pointers to trim down the search 
space. Except for this, the rest of the steps will be the same.

Base case: The base case of the recursion will be low > high. If (low > high), the search space becomes invalid 
which means the target is not present in the array.

Step 1 : Divide the search space into 2 halves using mid pointer.
Step 2 : Compare the middle element with the target and trim down the search space
Step 3 : If arr[mid] == target, target is found, return the index of the target and the recursion will end.
Step 4 : If target > arr[mid], target is located on the right half of the array, update low as mid+1.
Step 5 : If target < arr[mid], target is located on the left half of the array. update high as mid-1.
*/

int recursiveImplementation(vector<int>& nums, int low, int high, int k){
    if(low >= high) return -1;

    int mid = (low+high)/2;
    if(nums[mid] == k) return mid;
    else if(nums[mid] < k) recursiveImplementation(nums,mid+1, high, k);
    else recursiveImplementation(nums,low,mid-1,k);
}

int binarySearchRecursion(vector<int>& nums, int target){
    int n = nums.size();
    int low = 0, high = n-1;

    int answer = recursiveImplementation(nums,low,high,target);
    return answer;
}

/*
Iterative Implementation : Run a loop till low <= high and keep updating them in each iteration. 

Step 1 : Initially, the pointers low and high will be 0 and n-1(where n = size of the given array) respectively.
Step 2 : Run a loop will run until either we fount the target or any of the pointers crosses the other.
Step 3 : Inside the loop, find the mid of the array and match it with the target value.
Step 4 : If target is found then return the index else update the low and high pointers as per the conditions.
Step 5 : Return -1 at the end which shows that no matching element is found.

Time Complexity : O(log N) // Here base is 2 nothing else.
*/
int binarySearch(vector<int>& nums, int target) {
    int n = nums.size(); //size of the array
    int low = 0, high = n - 1;

    while (low <= high) {
        int mid = (low + high) / 2;
        if (nums[mid] == target) return mid;
        else if (nums[mid] < target) low = mid + 1;
        else high = mid - 1;
    }
    return -1;
}

/*
OverFlow Case : When low and high becomes equal to INT_MAX then mid will not be able to store it because
2 * INT_MAX will not be a integer value. Therefore for such cases we can write mid as :
mid = low + (high-low)/2;

which is equivalent to mid = (2 * low + high - low)/2
and, from here we can say : mid = (low + high)/2
*/
int main()
{
    vector<int> a = {3, 4, 6, 7, 9, 12, 16, 17};
    int target = 12;
    int ind = binarySearch(a, target);
    if (ind == -1) cout << "The target is not present." << endl;
    else cout << "The target is at index: "<< ind << endl;

    int index = binarySearchRecursion(a,target);
    if (index == -1) cout << "The target is not present." << endl;
    else cout << "The target is at index: "<< index << endl;

    return 0;
}
