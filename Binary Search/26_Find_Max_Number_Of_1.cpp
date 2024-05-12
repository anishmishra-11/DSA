/* You are given a 2D matrix 'ARR' (containing either ‘0’ or ‘1’) of size 'N' x 'M', where 
each row is in sorted order. Find the 0-based index of the first row with the maximum number of 1's.

Note :
1. If two rows have the same number of 1’s, return the row with a lower index.
2. If no row exists where at-least one '1' is present, return -1.
*/

#include<bits/stdc++.h>
using namespace std;

int rowWithMax1sBrute(vector<vector<int>> &matrix, int n, int m)
{
    int index = -1, max = 0;

    for(int i=0; i<n; i++){
        int sum = 0; 
        for(int j=0; j<m; j++){
            sum += matrix[i][j];
        }
        if(sum > max){
            index = i;
            max = sum;
        }
    }
    return index;
}

int rowWithMax1s(vector<vector<int>> &matrix, int n, int m)
{
    int index = -1, max = 0;

    for(int i=0; i<n; i++){
        int lb = lower_bound(matrix[i].begin(), matrix[i].end(),1) - matrix[i].begin();
        int ones = n - lb;

        if(ones > max){
            index = i;
            max = ones;
        }
    }
    return index;
}

int main()
{
    vector<vector<int>> arr = {{0,0,0},{0,0,1},{1,1,1}};

    int answer = rowWithMax1sBrute(arr,3,3);
    cout<<"Row Index with Maximum 1s (found through brute force method) "<<answer<<endl;

    answer = rowWithMax1s(arr,3,3);
    cout<<"Row Index with Maximum 1s (found through optimal method) "<<answer<<endl;
    
    return 0;
}