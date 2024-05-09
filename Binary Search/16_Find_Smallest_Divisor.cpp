/* You are given an array of integers 'arr' and an integer 'limit'.
Your task is to find the smallest positive integer divisor, such that upon dividing all the elements 
of the given array by it, the sum of the division's result is less than or equal to the given integer's limit.
*/
#include<bits/stdc++.h>
using namespace std;

int findMax(vector<int>& arr){
	int max = INT_MIN;
	for(int i=0; i<arr.size(); i++){
		if(arr[i] > max) max = arr[i];
	}
	return max;
}

int findMin(vector<int>& arr){
	int min = INT_MAX;
	for(int i=0; i<arr.size(); i++){
		if(arr[i]<min){
			min = arr[i];
		}
	}
	return min;
}

bool possible(vector<int>& arr, int div, int limit){
	int div_sum = 0;
	for(int i=0; i<arr.size(); i++){
		div_sum += ceil((double)(arr[i])/(double)(div));
	}
	if(div_sum <= limit) return true;
	return false;
}

/*Optimal Solution : Performing Binary Search

Step 1 : Initialize low as minimum and high as the maximum number from the array.
Step 2 : Calculate mid and check if at mid, div_sum is less than or equal to the given limit value.
Step 3 : If yes then mid may be the answer so search for a new minimum mid and move high = mid - 1.
Step 4 : If no, then mid cannot be the answer so search in the right half and move low = mid + 1.
Step 5 : Write the possible function, find the div_sum value using ceil and convert the numbers to double.

Time Complexity : O(log(max) * N)
Space Complexity : O(1)
*/
int smallestDivisor(vector<int>& arr, int limit)
{
	int max = findMax(arr);
	int min = findMin(arr);

    /*Brute Force Solution : Perform linear search

    // for(int i = 1; i<=max; i++){
    // 	if(possible(arr,i,limit)) return i;
    // }
    Time Complexity : O(max * N)
    Space Complexity : O(1)
    */

	int low = min, high = max;

	while(low <= high){
		int mid = (low + high)/2;
		if(possible(arr, mid, limit)) high = mid - 1;
		else low = mid + 1;
	}
	return low;
}