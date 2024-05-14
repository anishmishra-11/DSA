#include<bits/stdc++.h>
using namespace std;

/*Brute Force Method : Go through each and every index and if found return true else at the end return false.

Time Complexity : O(N*M)
Space Complexity : O(1)
*/
bool linearSearch2D(vector<vector<int>>& arr, int key){
    for(int i=0; i<arr.size(); i++){
        for(int j=0; j<arr[0].size(); j++){
            if(arr[i][j] == key) return true;
        }
    }
    return false;
}

/*Better Method : Go through every row and apply binary search on that particular row.

Time Complexity : O(N * log M)
Space Complexity : O(1)
*/
bool binary_search(vector<int>& arr, int target){
    int low=0, high = arr.size()-1;

    while(low <= high){
        int mid = (low + high)/2;
        if(arr[mid] == target) return true;
        else if(arr[mid] < target) low = mid + 1;
        else high = mid - 1;
    }
    return false;
}
bool searchMatrixBetter(vector<vector<int>>& matrix, int key){
    bool answer = false;
    for(int i=0; i<matrix.size(); i++){
        answer = binary_search(matrix[i],key);
        if(answer == true) return answer;
    }
    return false;
}

/*Optimal Method : Start from any one corner of the matrix and eliminate row or column on the basis of
comparison with the element.

Time Complexity : O(N+M)
Space Complexity : O(1)
*/
bool searchMatrixOptimal(vector<vector<int>>& matrix, int key){
    int row = 0, col = matrix[0].size()-1;

    while(row < matrix.size() && col >=0){
        if(matrix[row][col] == key) return true;
        else if(matrix[row][col] < key) row++;
        else col --;
    }
    return false;
}

int main()
{
    vector<vector<int>> arr = {{1,4,7,11,15},{2,5,8,12,19},{3,6,9,16,22},{10,13,14,17,24}};

    int answer = linearSearch2D(arr,23);
    cout<<"Present in the matrix or not : (Linear Search) "<<answer<<endl;

    answer = searchMatrixBetter(arr,14);
    cout<<"Present in the matrix or not : (Using Better Method) "<<answer<<endl;

    answer = searchMatrixOptimal(arr,10);
    cout<<"Present in the matrix or not : (Using Optimal Method) "<<answer<<endl;

    
    return 0;
}

