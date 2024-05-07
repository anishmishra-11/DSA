#include<bits/stdc++.h>
using namespace std;

int singleNonDuplicateBrute(vector<int>& arr){
	for(int i=0; i<arr.size(); i+=2){
        //This is done if the last element of the array appears once and to avoid index out of bound error.
		if(i == arr.size()-1) return arr[i]; 
		if(arr[i] != arr[i+1]) return arr[i];
	}
}       

//Ways to solve or How to think to apply Binary Search
//(even,odd) -> Element is on the right half.
//(odd,even) -> Element is on the left half.

/*
Optimal Approach : Perform Binary Search.

Step 1 : Write a general binary search program.
Step 2 : Check if there is only one element in the array then return itself.
Step 3 : Write edge cases for 0th and nth element is the single occurence element to avoid multiple conditions.
Step 4 : Start from low = 1 and high = 2nd last elment of the array.
Step 5 : Check if the mid element satisfies the condition.
Step 6 : If the mid's index is even then check in left or mid's index is odd then check  in right.
Step 7 : Update the low and high as per requirement.

Time Complexity : O(log N) 
Space Complexity : O(1)
*/
int singleNonDuplicate(vector<int>& arr){
    int n = arr.size();
    if(n == 1) return arr[0];
    if(arr[0] != arr[1]) return arr[0];
    if(arr[n-1] != arr[n-2]) return arr[n-1];

    int low = 1, high = n-2;
    while(low <= high){
        int mid = (low + high)/2;
        if(arr[mid] != arr[mid-1] and arr[mid] != arr[mid+1]) return arr[mid];

        if((mid % 2 == 0 and arr[mid] != arr[mid-1]) || (mid % 2 == 1 and arr[mid] != arr[mid+1]))
            low = mid + 1;
        else high = mid - 1;
    }
}

int main()
{
    vector<int> arr =  {1,1,2,2,3,3,4,5,5};
    
    int answer = singleNonDuplicateBrute(arr);
    cout<<"The element occuring only 1 time is  " << answer << endl; 

    answer = singleNonDuplicate(arr);
    cout<<"The element occuring only 1 time is  " << answer << endl; 

    return 0;
}