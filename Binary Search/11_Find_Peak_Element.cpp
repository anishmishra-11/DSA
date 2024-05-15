#include<bits/stdc++.h>
using namespace std;

int findPeakElementBrute(vector<int> &arr) {

}

/*
Optimal Approach : Perform Binary Search.

Step 1 : Write a general binary search program.
Step 2 : Check if there is only one element in the array then return itself.
Step 3 : Write edge cases for 0th and nth element is the peak element to avoid multiple conditional statements.
Step 4 : Start from low = 1 and high = 2nd last elment of the array.
Step 5 : Check if the mid element is the peak element.
Step 6 : Check if the mid is on increasing graph by comparing it with left & right index element and low = mid+1.
Step 7 : If it is on decreasing graph then update high = mid - 1.

Time Complexity : O(log N) 
Space Complexity : O(1)
*/
int findPeakElement(vector<int> &arr) {
    int n = arr.size()-1;
    if(arr.size()==1) return arr[0];
    if(arr[0] > arr[1]) return arr[0];
    if(arr[n-1] > arr[n-2]) return arr[n-1];

    int low = 1, high = n-2;

    while(low <= high){
        int mid = (low + high)/2;
        if(arr[mid] > arr[mid-1] && arr[mid] > arr[mid+1]) return arr[mid];
        else if(arr[mid] > arr[mid-1] && arr[mid] < arr[mid+1]) low = mid +1;
        else high = mid -1;
    }
    return -1;
}


int main()
{
    vector<int> arr =  {1,1,2,2,3,3,4,5,5};
    
    int answer = findPeakElementBrute(arr);
    cout<<"One of the Peak Element is  " << answer << endl; 

    answer = findPeakElement(arr);
    cout<<"The element occuring only 1 time is  " << answer << endl; 

    return 0;
}