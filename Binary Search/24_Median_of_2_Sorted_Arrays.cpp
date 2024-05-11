#include<bits/stdc++.h>
using namespace std;

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
    vector<int> arr1 = {1,2};
    vector<int> arr2 = {3,4};

    double answer = findMedianSortedArraysBrute(arr1,arr2);
    cout<<answer<<endl;

    answer = findMedianSortedArraysBetter(arr1,arr2);
    cout<<"Answer Found through better method : "<<answer<<endl;
    
    return 0;
}