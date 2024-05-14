#include<bits/stdc++.h>
using namespace std;

/* Optimal Approach : Perform Binary Search.

Step 1 : Initialize low and high as 0 and last index of the matrix respectively.
Step 2 : Write general binary search algorithm and calculate mid.
Step 3 : Find the maximum element of column mid.
Step 4 : Compare the max element to its left and right element.
Step 5 : If mid - 1 < 0 then left = -1, similarly for right mid + 1 <= n, right = -1;
Step 6 : If peak element is found then return the index of the element else eliminate
Step 7 : Eliminate one side of the matrix on the condition: (matrix[row_max_index][mid] < left) high = mid -1.

Time Complexity : (n * logm)
Space Complexity : O(1)
*/
int max_element_index(vector<vector<int>>& matrix, int col){
    int index = -1, max_value = INT_MIN;
    for(int i=0; i<matrix.size(); i++){
        if(matrix[i][col] > max_value){
            index = i;
            max_value = matrix[i][col];
        }
    }
    return index;
}

vector<int> findPeakGrid(vector<vector<int>>& matrix) {
    int n = matrix.size(), m = matrix[0].size();
    int low = 0, high = m - 1;

    while(low <= high){
        int mid = (low + high)/2;
        int row_max_index = max_element_index(matrix,mid);

        int left = mid - 1 >= 0 ? matrix[row_max_index][mid-1] : -1;
        int right = mid + 1 < n ? matrix[row_max_index][mid+1] : -1;

        if(matrix[row_max_index][mid] >left && matrix[row_max_index][mid] > right) return {row_max_index,mid};
        else if(matrix[row_max_index][mid] < left) high = mid - 1;
        else low = mid + 1;
    }
    return {-1,-1};
}

int main(){
    vector<vector<int>> arr = {{10,20,15},{21,30,14},{7,16,32}};

    vector<int> answer = findPeakGrid(arr);
    cout<<"One of the Peak Elements Index is : ";
    for(auto it : answer){
        cout<<answer[it]<<",";
    }
}