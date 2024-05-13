#include<bits/stdc++.h>
using namespace std;

/*Brute Force Method : Go through each and every index and if found return true else at the end return false.

Time Complexity : O(N*M)
Space Complexity : O(1)*/
bool linearSearch2D(vector<vector<int>>& arr, int key){
    for(int i=0; i<arr.size(); i++){
        for(int j=0; j<arr[0].size(); j++){
            if(arr[i][j] == key) return true;
            else if(arr[i][j] > key) return false;
        }
    }
    return false;
}

/*Better Method : Go through every row and check if the target value is between 0th index and the last index of
that row. If exists then apply binary search on that particular row, else move to the next row.

Time Complexity : O(N) + O(log m)
Space Complexity : O(1)*/
bool binary_search(vector<int>& arr, int target){
    int low = 0, high = arr.size()-1;

    while(low <= high){
        int mid = (low + high)/2;
        if(arr[mid] == target) return true;
        else if(arr[mid] > target) high = mid -1;
        else low = mid + 1;
    }
    return false;
}
bool searchMatrixBetter(vector<vector<int>>& matrix, int key){
    for(int i=0; i<matrix.size(); i++){
        int low = 0, high = matrix[0].size()-1;
        if(matrix[i][low] <= key && key <= matrix[i][high]){
            return binary_search(matrix[i],key);
        }
    }
    return false;
}

/*Optimal Method : Apply Binary Seach on 2D Matrix, Imagine the 2d matrix as an 1D array and apply BS on it.
But the catch here is you have to find the row and column through mid for which follow the below formula:
row = mid / m,
col = mid % m, dry run the formula to understand how it works. Hint : Every row starts with index m.

Time Complexity : O(log(N*M))
Space Complexity : O(1)
*/
bool binarySearch2d(vector<vector<int>>& matrix, int target){
    int n = matrix.size(), m = matrix[0].size();
    int low = 0, high = n*m-1;

    while(low <= high){
        int mid = (low + high)/2;
        int row = mid/m, col = mid%m;
        if(matrix[row][col] == target) return true;
        else if(matrix[row][col] > target) high = mid - 1;
        else low = mid + 1;
    }
    return false;
}

int main()
{
    vector<vector<int>> arr = {{1,3,5,7},{10,11,16,20},{23,30,34,60}};

    int answer = linearSearch2D(arr,16);
    cout<<"Present in the matrix or not : (Linear Search) "<<answer<<endl;

    answer = searchMatrixBetter(arr,30);
    cout<<"Present in the matrix or not : (Using Better Method) "<<answer<<endl;

    answer = binarySearch2d(arr,31);
    cout<<"Present in the matrix or not : (Using Optimal Method) "<<answer<<endl;

    
    return 0;
}