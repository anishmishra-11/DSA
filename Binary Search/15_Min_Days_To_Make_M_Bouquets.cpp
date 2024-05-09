#include<bits/stdc++.h>
using namespace std;

int findMin(vector<int>& arr){
	int min = INT_MAX;
	for(int i=0; i<arr.size(); i++){
		if(arr[i]<min){
			min = arr[i];
		}
	}
	return min;
}

int findMax(vector<int>& arr){
	int max = INT_MIN;
	for(int i=0; i<arr.size(); i++){
		if(arr[i] > max) max = arr[i];
	}
	return max;
}

bool possible(vector<int>& arr, int day, int k, int m){
	int count = 0, bouquets = 0;
	for(int i=0; i<arr.size(); i++){
		if(arr[i] <= day) count++;
		else{
			bouquets += (count/k);
			count = 0;
		}
	}
    //if indexes at end have adjacent bloom flowers then it will not be counted in the loop.
	bouquets += (count/k);
	return bouquets >= m;
}

/*Optimal Solution : Performing Binary Search

Step 1 : Initialize low as min of the array and high as the maximum number from the array.
Step 2 : Calculate mid and check if at mid total adjacent bloom flowers can make the bouquet.
Step 3 : If yes then mid may be the answer so search for a new minimum mid and move high = mid - 1.
Step 4 : If no, then mid cannot be the answer so search in the right half and move low = mid + 1.
Step 5 : Write the possible function to count adjacent bloom flowers.
Step 6 : If non-bloom flowers are found then check if bouquet can be formed or not till there and reset cnt = 0.

Time Complexity : O(N* log(max-min+1))
Space Complexity : O(1)
*/
int roseGarden(vector<int> arr, int k, int m)
{
	if(arr.size() < k*m) return -1; //Cases when actual flower < required flower.
	int min = findMin(arr);
	int max = findMax(arr);

	// Brute Forect Solution : Perform Linear Search 
	// for(int i=min; i<=max; i++){
	// 	if(possible(arr,i,k,m)) return i;
	// }

	int low = min, high = max;

	while(low <= high){
		int mid = (low + high)/2;
		if(possible(arr, mid, k, m)) high = mid - 1;
		else low = mid + 1;
	}

	return low;
}

int main()
{
    vector<int> flower = {1,2,1,2,7,2,2,3,1};
    //m represents the number of bouquets to be made and k represents the number of adjacent flowers required.
    int m = 2, k = 3;

    int solution = roseGarden(flower,k,m);

    cout<<"The minimum number of days required to make " << m << " bouquets is " << solution;

    return 0;
}