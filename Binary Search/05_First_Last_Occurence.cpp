#include <bits/stdc++.h>
using namespace std;

/*
Brute Force Approach : Perform Linear Search and update first and last indexes after every match.

Step 1 : Run a loop from start to end of the array. 
Step 2 : For every index match if the value is same as the given target value.
Step 3 : If it matches then check if first is -1 if yes then update it and then update last.
Step 4 : Return first and last as a pair.

Time Complexity : O(N) 
Space Complexity : O(1)
*/
pair<int, int> firstAndLastPosition(vector<int>& arr, int n, int k) {
    int first = -1, last = -1;
    for (int i = 0; i < n; i++) {
        if (arr[i] == k) {
            if (first == -1) first = i;
            last = i;
        }
    }
    return {first, last}; // same as make_pair(first,last);
}

// Finding the first occurence of a target in the array through plain Binary Search.
int findFirstOccurence(vector<int>& arr, int target){
    int low = 0, high = arr.size()-1;
    int first = -1;
    while(low <= high){
        int mid = low + (high - low)/2;
        if(arr[mid] == target){
            first = mid;
            high = mid - 1; //It is used to find the first occurence, by going to the left.
        }
        else if(arr[mid] < target) low = mid + 1;
        else high = mid -1;
    }
    return first;
}

int findLastOccurence(vector<int>& arr, int target){
    int low = 0, high = arr.size()-1;
    int last = -1;
    while(low <= high){
        int mid = low + (high - low)/2;
        if(arr[mid] == target){
            last = mid;
            low = mid + 1; //It is used to find the last occurence, by eliminating the left side search space.
        }
        else if(arr[mid] < target) low = mid + 1;
        else high = mid -1;
    }
    return last;
}

//Finding the first and last occurence through lowerbound and upperbound;
int lowerBound(vector<int>&arr, int n, int target){
    int low = 0, high = n - 1;
    int lb = n;
    
    while(low <= high){
        int mid = low + (high - low) / 2;
        if(arr[mid] >= target){
            lb = mid;
            high = mid - 1;
        }
        else low = mid + 1;
    }
    return lb;
}

int upperBound(vector<int>& arr, int n, int target){
    int low = 0, high = n - 1;
    int ub = n;
    
    while(low <= high){
        int mid = low + (high - low) / 2;
        if(arr[mid] > target){
            ub = mid;
            high = mid - 1;
        }
        else low = mid + 1;
    }
    return ub;
}

//Function to find the number of occurences of a element
int numberOfOccurences(vector<int>&arr, int k){
    int lb = lower_bound(arr.begin(), arr.end(), k) - arr.begin();
    int ub = upper_bound(arr.begin(), arr.end(), k) - arr.begin();

    // uppoer bound of k gives one index ahead of k therefore ub - lb gives number of occurence.
    return {ub-lb}; 
}

int main()
{
    vector<int> arr =  {2, 4, 6, 6, 8, 8, 11, 13};
    int n = 8, k = 6;
    pair<int, int> ans = firstAndLastPosition(arr, n, k);
    cout << "The first and last positions are: "<< ans.first << " " << ans.second << endl;

    int first = findFirstOccurence(arr,k);
    int last = findLastOccurence(arr,k);
    cout << "The first and last positions are: "<< first << " " << last << endl;

    int lb = lowerBound(arr,n,k);
    int ub = upperBound(arr,n,k);

    //If lb is equal to n that means that the element does not exist in the array and hence no occurence.
    //Similary for the 2nd OR condition.
    if(lb == n || arr[lb] != k) cout<<"The first and last positions are: -1 -1"<< endl;
    else cout<<"The first and last positions are: "<< lb << " " << ub-1 << endl;

    int occurence = numberOfOccurences(arr,k);
    cout<<"Number of Occurence of "<<k <<" is : "<<occurence;

    return 0;
}