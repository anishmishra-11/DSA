#include<bits/stdc++.h>
using namespace std;

/* Brute Force Method : Combine in one array and then find Median.
Step 1 : Merge the given 2 arrays into a new single array using two pointers.
Step 2 : Find the median index for odd number of elements and even number of elements separately.
Step 3 : Typecast the answer properly and return the answer.

Time Complexity : O(N1 + N2) 
Space Complexity : O(N1 + N2), where N1 and N2 are the sizes of the given arrays.
*/
double findMedianSortedArraysBrute(vector<int>& nums1, vector<int>& nums2) {
    vector<int> arr;
    int i=0,j=0;
    while(i<nums1.size() && j<nums2.size()){
        if(nums1[i] < nums2[j]) arr.push_back(nums1[i++]);
        else arr.push_back(nums2[j++]);
    }
    while(i<nums1.size()){
        arr.push_back(nums1[i++]);
    }
    while (j<nums2.size()){
        arr.push_back(nums2[j++]);
    }
    int n = nums1.size() + nums2.size();
    if( n % 2 == 1) return arr[n/2];
    else return (double)((double)arr[n/2] + (double)(arr[(n/2)-1]))/2;
}

/* Better Approach : Use a counter called 'cnt' to represent the imaginary third array's index.
Step 1 : Call the required indices as ind2 = (n1+n2)/2 and ind1 = ((n1+n2)/2)-1. 
Step 2 : Also, declare the counter called ‘cnt’ and initialize it with 0.
Step 3 : Take two pointers i and j, where i and j points to the first element of both the arrays respectively.
Step 4 : Using a while loop( while(i < n1 && j < n2)), select the smallest one between the two.
Step 5 : Check if cnt is equal to the required index. If yes then return the median using formula.

Time Complexity : O(N1 + N2) 
Space Complexity : O(1)
*/
double findMedianSortedArraysBetter(vector<int>& nums1, vector<int>& nums2){
    int n1 = nums1.size(), n2 = nums2.size(), n = n1 + n2;
    int i=0, j=0;
    int index2 = n/2, index1 = index2 - 1;
    int element1, element2;
    int count = 0;

    while(i<n1 && j<n2){
        if(nums1[i] < nums2[j]){
            if(count == index1) element1 = nums1[i];
            if(count == index2) element2 = nums1[i];
            count++;
            i++;
        }
        else{
            if(count == index1) element1 = nums2[j];
            if(count == index2) element2 = nums2[j];
            count++;
            j++;
        }
    }
    while(i < n1){
        if(count == index1) element1 = nums1[i];
        if(count == index2) element2 = nums1[i];
        count++;
        i++;
    }
    while(j < n2){
        if(count == index1) element1 = nums2[j];
        if(count == index2) element2 = nums2[j];
        count++;
        j++;
    }
    if(n % 2 == 1) return element2;
    else return (double)(double(element1 + element2))/2;
}    

/* Optimal Method : Apply binary search on the basis of symmetry.
Step 1 : We have to segregate the array in two halves by picking the right number of elements from both arrays.
Step 2 : Calculate the total number of elements of combined array and how many should be in left and right halves.
Step 3 : Initialize l1, l2, r1, r2 as INT_MIN and INT_MAX respectively.
Step 4 : Compare l1 <= r2 and l2 <= r1 if true then this is the right combination else eliminate one half.
Step 5 : Check if (l1 > r2) then high = mid - 1 else (l2 > r1) low = mid + 1.

Time Complexity : O(log(min(N1,N2)))
Space Complexity : O(1)
*/
double findMedianSortedArrays(vector<int>& array1, vector<int>& array2) {
    int n1 = array1.size();
    int n2 = array2.size();
    if(n1 > n2) return findMedianSortedArrays(array2,array1);
    int n = n1 + n2;
    
    int left = (n1+n2+1)/2;
    int low = 0, high = n1;
    
    while(low <= high){
        int mid1 = (low + high)/2;
        int mid2 = left - mid1;
        
        int l1 = INT_MIN, l2 = INT_MIN;
        int r1 = INT_MAX, r2 = INT_MAX;
        
        if(mid1 - 1 >= 0) l1 = array1[mid1-1];
        if(mid2 - 1 >= 0) l2 = array2[mid2-1];
        if(mid1 < n1) r1 = array1[mid1];
        if(mid2 < n2) r2 = array2[mid2];
        
        if(l1 <= r2 && l2 <= r1){
            if(n % 2 == 1) return max(l1,l2);
            return (double)(max(l1,l2) + min(r1,r2)) / 2;
        }
        else if (l1 > r2) high = mid1 - 1;
        else low = mid1 + 1;
    }
    return 0;
}

int main()
{
    vector<int> arr1 = {2,4,6};
    vector<int> arr2 = {1,3};

    double answer = findMedianSortedArraysBrute(arr1,arr2);
    cout<<answer<<endl;

    answer = findMedianSortedArraysBetter(arr1,arr2);
    cout<<"Answer Found through better method : "<<answer<<endl;

    answer = findMedianSortedArrays(arr1,arr2);
    cout<<answer;
    
    return 0;
}