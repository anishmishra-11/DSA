/* A monkey is given ‘n’ piles of bananas, where the 'ith' pile has ‘a[i]’ bananas. 
An integer ‘h’ is also given, which denotes the time (in hours) in which all the bananas should be eaten.
*/
#include <bits/stdc++.h>
using namespace std;

int findMax(vector<int>& arr){
	int max = INT_MIN;
	for(int i=0; i<arr.size(); i++){
		if(arr[i] > max) max = arr[i];
	}
	return max;
}

int calc_hour(vector<int>& arr, int b, int h){
    int hours = 0;
    for(int i=0; i<arr.size(); i++){
        hours += ceil((double)(arr[i]) / (double)(b));
    }
    return hours;
}

/*Brute Force Solution : Perform Linear Search starting from 1.

Step 1 : Start a for loop from 1 till the max element of the given array.
Step 2 : Check for every i, if total hour taken is less than given hour.
Step 3 : If yes then return i, else continue.
Step 4 : Write the calc_hour function, find the ceil value and convert the numbers to double.

Time Complexity : O(max(arr[]) * N)
Space Complexity : O(1)
*/
int minimumRateToEatBananasBrute(vector<int>& v, int h){
    int max = findMax(v);
    int total_hour = 0;
    for(int i=1; i<max; i++){
        total_hour = calc_hour(v,i,h);
        if(total_hour <= h) return i;
    }
    return -1;
}

/*Optimal Solution : Performing Binary Search

Step 1 : Initialize low as 1 and high as the maximum number from the array.
Step 2 : Calculate mid and check if at mid total hour taken is less than given hour.
Step 3 : If yes then mid may be the answer so search for a new minimum mid and move high = mid - 1.
Step 4 : If no, then mid cannot be the answer so search in the right half and move low = mid + 1.
Step 5 : Write the calc_hour function, find the ceil value and convert the numbers to double.

Time Complexity : O(log(max(arr[])) * N)
Space Complexity : O(1)
*/
int minimumRateToEatBananas(vector<int>& v, int h) {
    int low = 1, high = findMax(v);
    int total_hour, answer;

    while(low <= high){
        int mid = (low + high)/2;
        total_hour = calc_hour(v,mid,h);
        if(total_hour <= h) {
            answer = mid;
            high = mid - 1;
        }
        else low = mid + 1;
    }
    return answer;
}

int main()
{
    vector<int> banana = {3,6,2,8};
    int h = 7;

    int answer = minimumRateToEatBananasBrute(banana,h);
    cout<<"The minimum number of bananas to eat is " << answer <<endl;

    int solution = minimumRateToEatBananas(banana,h);
    cout<<"The minimum number of bananas to eat is " << solution <<endl;
    return 0;
}