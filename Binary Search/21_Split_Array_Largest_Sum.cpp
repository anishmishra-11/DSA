#include<bits/stdc++.h>
using namespace std;

int largest_sum(vector<int>& arr, int sum){
    int k = 1, total_sum = 0;
    for(int i=0; i<arr.size(); i++){
        if(total_sum + arr[i] <= sum) total_sum += arr[i];
        else{
            k++;
            total_sum = arr[i];
        }
    }
    return k;
}

//This Question is exactly based on the Allocate books question. Hence the code and complexity is also same.
int splitArray(vector<int>& nums, int k) {
    int low = *max_element(nums.begin(), nums.end());
    int high = accumulate(nums.begin(), nums.end(),0);

    // for(int i=low; i<= high; i++){ //Using Linear Search 
    //     if(largest_sum(nums,i) == k) return i;
    // }
    // return -1;

    while(low <= high){
        int mid = (low + high)/2;
        if(largest_sum(nums,mid) <= k) high = mid -1;
        else low = mid + 1;
    }
    return low;
}

int main()
{
    vector<int> arr = {7,2,5,10,8};
    int k = 2;

    int split = splitArray(arr,k);
    cout<<"The minimized largest sum of the split is " << split <<endl;
    
    return 0;
}