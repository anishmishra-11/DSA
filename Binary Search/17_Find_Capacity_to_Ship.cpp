#include<bits/stdc++.h>
using namespace std;

int daysReq(vector<int>& arr, int w){
    int days = 1, load = 0;
    for(int i=0; i<arr.size(); i++){
        if(arr[i] + load > w){
            days++;
            load = arr[i];
        }
        else load += arr[i];
    }
    return days;
}

pair<int,int>findMaxandSum(vector<int>& arr){
    int max = 0,sum = 0;
    for(int i=0; i<arr.size(); i++){
        sum += arr[i];
        if(arr[i] > max) max = arr[i];
    }
    return {max,sum};
}

/*Optimal Solution : Performing Binary Search

Step 1 : Initialize low to maximum of the array and high as total sum of the given array.
Step 2 : Calculate mid and check if days required is less than given day if per day weight is mid.
Step 3 : If yes, then find a less number than mid through high = mid -1.
Step 4 : Else eliminate the left half and consider the right half(i.e. low = mid+1).
Step 5 : Return the low (Remember the concept of opposite polarity)

Time Complexity : O(log(sum(weights[]) - max(weights[]) + 1) * N)
Space Complexity : O(1)
*/
int leastWeightCapacity(vector<int> &weights, int d)
{   
    pair<int,int> answer = findMaxandSum(weights);

    //Brute Force Approach : Perform Linear Search
    // for(int i=answer.first; i<=answer.second; i++){
    //     int days = daysReq(weights, i);
    //     if(days <= d) return i;
    // }

    int low = answer.first, high = answer.second;
    while(low <= high){
        int mid = (low + high)/2;
        int days = daysReq(weights, mid);
        if(days <= d) high = mid - 1; 
        else low = mid + 1;
    }
    return low;
}

int main(){
    vector<int> weights = {5,4,5,2,3,4,5,6};
    int day = 5;

    int number = leastWeightCapacity(weights,day);
    cout<<"The minimum weight per day is " << number <<endl;
    return 0;
}