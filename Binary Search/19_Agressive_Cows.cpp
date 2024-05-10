/* You are given an array 'arr' consisting of 'n' integers which denote the position of a stall.
You are also given an integer 'k' which denotes the number of aggressive cows.

You are given the task of assigning stalls to 'k' cows such that the minimum distance between any 
two of them is the maximum possible. Print the maximum possible minimum distance.
*/

#include<bits/stdc++.h>
using namespace std;

bool canBePlaced(vector<int>& arr, int dis, int cows){
    int placedCow = 1, lastPlaced = arr[0];
    for(int i=1; i<arr.size(); i++){
        if(arr[i] - lastPlaced >= dis){
            placedCow++;
            lastPlaced = arr[i];
        }
        if(placedCow >= cows) return true;
    }
    return false;
}

/*Brute Force Solution : Start checking for every number from 1.

Step 1 : Run a loop from 1 to max of the array.
Step 2 : Check for every i if cows can be placed for that i, if yes then continue.
Step 3 : Else break out from the loop and return the previous index where it was last possible;

Time Complexity : O(N * max(arr[]))
Space Complexity : O(1)
*/
int aggressiveCowsBrute(vector<int>& stalls, int cows){
    sort(stalls.begin(), stalls.end());
    int max = stalls[stalls.size()-1];

    for(int i=1; i<=max; i++){
        if(canBePlaced(stalls,i,cows)) continue;
        else return (i-1);
    }
    return -1;
}

/*Optimal Solution : Performing Binary Search

Step 1 : Initialize low to 1 and the high to the max element of the array.
Step 2 : Calculate mid and check if cows can be placed at mid.
Step 3 : If can be placed at mid is true then we go to the right to look for a bigger number, low = (mid+1).
Step 4 : Else eliminate the right half and consider the left half by high = mid -1.
Step 5 : Return the value of high.

Time Complexity : O(N * log(max(arr[])))
Space Complexity : O(1)
*/
int aggressiveCows(vector<int>& stalls, int cows){
    sort(stalls.begin(), stalls.end());
    int low = 1, high = stalls[stalls.size()-1];

    while(low <= high){
        int mid = (low + high)/2;
        if(canBePlaced(stalls,mid,cows)) low = mid + 1;
        else high = mid-1;
    }
    return high;
}

int main()
{
    vector<int> stalls = {0,3,4,7,10,9};
    int cows = 4;

    int number = aggressiveCowsBrute(stalls,cows);
    cout<<"The maximum of possible minimum distance is " << number <<" (found through brute force method)"<<endl;

    int answer = aggressiveCows(stalls,cows);
    cout<<"The maximum of possible minimum distance is " << answer <<" (found through optimal method)"<<endl;
       
  return 0;
}
