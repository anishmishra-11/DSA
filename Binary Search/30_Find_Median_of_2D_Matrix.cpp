#include <bits/stdc++.h>
using namespace std;

/*
Brute Force Approach : Using a external array and sort it.

Step 1 : Go through each and every element of the matrix and store it in a array.
Step 2 : Sort the new array.
Step 3 : Since it is given that n*m will always be odd so directly find the median index.
Step 4 : Return the element from the median index.

Time Complexity : O(n*m) + O((n*m)log(n*m))
Space Complexity : O(n*m)
*/
int getMedianBrute(vector<vector<int>>& matrix){
    int n = matrix.size(), m = matrix[0].size();
    vector<int> answer;

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            answer.push_back(matrix[i][j]);
        }
    }
    sort(answer.begin(), answer.end());

    int median_index = (n*m)/2;
    return answer[median_index];
}

/*
Optimal Approach : Perform Binary Search.

Step 1 : Find the low and high of the matrix in the 0th and the (m-1)th index.
Step 2 : Write general binary search using low and high.
Step 3 : Calculate mid and find out how many elements are smaller than or equal to mid.
Step 4 : If number of elements <= median index then update low as low = mid + 1.
Step 5 : Else update high = mid - 1.
Step 6 : To find out how many smaller elements are present you can use upperBound concept.
Step 7 : For every row calculate the upper bound and sum it up.

Time Complexity : O(n*log(m))
Space Complexity : O(1)
*/
int upper_bound(vector<int>& arr, int n){
    int low = 0, high = arr.size()-1;
    int ans = arr.size();

    while(low <= high){
        int mid = (low + high)/2;
        if(arr[mid] > n){
            ans = mid;
            high = mid - 1;
        }
        else low = mid + 1;
    }
    return ans;
}
int find_smaller_elements(vector<vector<int>>& matrix, int number){
    int count = 0;
    for(int i=0; i<matrix.size(); i++){
        count += upper_bound(matrix[i],number);
    }
    return count;
}

int getMedian(vector<vector<int>> &matrix)
{
    int n = matrix.size(), m = matrix[0].size();
    int low = INT_MAX, high = INT_MIN;
    int median_index = (n*m)/2;

    for(int i=0; i<n; i++){
        low = min(low,matrix[i][0]);
        high = max(high,matrix[i][m-1]);
    }

    while(low <= high){
        int mid = (low + high)/2;

        int smaller_elements = find_smaller_elements(matrix,mid);
        if(smaller_elements <= median_index) low = mid + 1;
        else high = mid - 1;
    }
    return low;
}

int main(){
    vector<vector<int>> arr = {{2,6,9},{1,5,11},{3,7,8}};
    vector<vector<int>> arr1 = {{2},{3},{1},{4},{5}};

    int answer = getMedianBrute(arr);
    cout<<"Median of the given matrix is : "<<answer<<endl;

    answer = getMedian(arr1);
    cout<<"Median of the given matrix is : "<<answer<<endl;

    return 0;
}