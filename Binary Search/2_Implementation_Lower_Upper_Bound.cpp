#include <bits/stdc++.h>
using namespace std;

/*
Compare arr[mid] with x: With comparing arr[mid] to x, we can observe 2 different cases:
Case 1 – If arr[mid] >= x: This condition means that the index mid may be an answer. So, we will update the ‘ans’ variable with mid and search in the left half if there is any smaller index that satisfies the same condition. Here, we are eliminating the right half.
Case 2 – If arr[mid] < x: In this case, mid cannot be our answer and we need to find some bigger element. So, we will eliminate the left half and search in the right half for the answer.
*/
int lowerBound(vector<int> arr, int n, int target) {
    int low = 0, high = n-1;
    int answer = n;

    while(low <= high){
        int mid = (low+high)/2;
        if(arr[mid] >= target){
            answer = mid;
            high = mid - 1;
        }
        else low = mid + 1;
    }
    return answer;
}

int upperBound(vector<int> arr, int n , int target){
    int low = 0, high = n-1, answer = n;
    
    while(low <= high){
        int mid = (low + high)/2;

        if(arr[mid] > target){
            answer = mid;
            high = mid - 1;
        }
        else low = mid + 1;
    }
    return answer;
}

int main()
{
    vector<int> arr = {3, 5, 8, 15, 19};
    int n = 5, x = 9;
    int ind = lowerBound(arr, n, x);
    cout << "The lower bound is the index: " << ind<<endl;
    return 0;
}

