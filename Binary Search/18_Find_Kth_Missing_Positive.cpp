#include <iostream>
#include<vector>
using namespace std;

/* Brute Force Approach : The idea is to shift k by 1 step if the current element is smaller or equal to k. 
And whenever we get a number > k, we can conclude that k is the missing number.

Step 1 : Run a for loop from 0 to size of the array.
Step 2 : If vec[i] <= k, increase the value of k by 1 else break out from the loop.
Step 3 : K is our missing number.

Time Complexity : O(N)
Space Complexity : O(1)
*/
int missingK(vector<int>& vec, int k) {
    for(int i=0; i<vec.size(); i++){
        if(vec[i] <= k) k++;
        else break;
    }
    return k;
}

/*Optimal Solution : Performing Binary Search

Step 1 : Initialize low to index 0 and the high to index n-1 i.e. the last index.
Step 2 : Calculate mid and eliminate the halves based on the number of missing numbers up to index mid.
Step 3 : If missing_numbers < k: eliminate the left half and consider the right half(i.e. low = mid+1).
Step 4 : Else eliminate the left half and consider the right half(i.e. low = mid+1).
Step 5 : Return the value of (k+high+1) i.e. the kth missing number or low + key.

Time Complexity : O(log N)
Space Complexity : O(1)
*/
int missingKOptimal(vector<int>& vec, int k){
    int low = 0, high = vec.size()-1;
    int missing_number = 0;
    while(low <= high){
        int mid = (low + high)/2;
        missing_number = vec[mid] - (mid + 1);
        if(missing_number < k) low = mid + 1;
        else high = mid -1;
    }
    return low + k;
}

int main()
{
    vector<int> nums = {2,4,5,7};
    int k = 3;

    int number = missingK(nums,k);
    cout<<"The kth missing number is " << number <<" (found through brute force method)"<<endl;

    int answer = missingKOptimal(nums,k);
    cout<<"The kth missing number is " << answer <<" (found through Binary Search)"<<endl; 
  
    return 0;
}