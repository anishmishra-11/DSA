#include<bits/stdc++.h>
using namespace std;

int numberOfPainter(vector<int>& arr, int area){
    int painter = 1, total_area = 0;
    for(int i=0; i<arr.size(); i++){
        if(total_area + arr[i] <= area) total_area += arr[i];
        else{
            painter++;
            total_area = arr[i];
        }
    }
    return painter;
}

//This Question is exactly based on the Allocate books question. Hence the code and complexity is also same.
int findLargestMinDistance(vector<int> &boards, int k)
{
    int low = *max_element(boards.begin(), boards.end());
    int high = accumulate(boards.begin(), boards.end(),0);

    // for(int i=low; i<=high; i++){ // this is not working 
    //     if(numberOfPainter(boards, i) == k) return i;
    // }

    while(low <= high){
        int mid = (low + high)/2;
        if(numberOfPainter(boards,mid) <= k) high = mid -1;
        else low = mid + 1;
    }
    return low;
}

int main()
{
    vector<int> arr = {8,6,10,3,2,7,10};
    int k = 7;

    int area = findLargestMinDistance(arr,k);
    cout<<"The minimized time to paint the wall is " << area <<endl;
    
    return 0;
}

