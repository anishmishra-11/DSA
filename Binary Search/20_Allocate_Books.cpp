/*Given an array ‘arr’ of integer numbers, ‘arr[i]’ represents the number of pages in the ‘i-th’ book.
There are ‘m’ number of students, and the task is to allocate all the books to the students.

Allocate books in such a way that:
1. Each student gets at least one book.
2. Each book should be allocated to only one student.
3. Book allocation should be in a contiguous manner.

You have to allocate the book to ‘m’ students such that the maximum number of pages assigned to a student 
is minimum. If the allocation of books is not possible, return -1.
*/
#include<bits/stdc++.h>
using namespace std;

int numberOfStudents(vector<int>& arr, int pages){
    int student = 1, totalPages = 0;
    for(int i=0; i<arr.size(); i++){
        if(totalPages + arr[i] <= pages) totalPages += arr[i];
        else{
            student++;
            totalPages = arr[i];
        }
    }
    return student;
}

/*Brute Force Solution : Start checking from maximum given page till the total sum of the given array.

Step 1 : Run a loop from max till the total sum of the array.
Step 2 : Check for every i if totalrequired students is equal to given student then return i.
Step 3 : Else continue in the loop and return -1 if loop ends;

Time Complexity : O(N * sum-max+1)
Space Complexity : O(1)
*/
int findPagesBrute(vector<int>& pages, int students){
    int low = *max_element(pages.begin(), pages.end());
    int high = accumulate(pages.begin(), pages.end(),0);
    
    for(int i=low; i<=high; i++){
        if(numberOfStudents(pages,i) == students) return i;
    }
    return -1;
}

/*Optimal Solution : Performing Binary Search

Step 1 : Initialize low to max element of the array and the high to the sum of the array.
Step 2 : Calculate mid and number of students possible at mid.
Step 3 : If calculated students is greater than given student then low = (mid+1).
Step 4 : Else eliminate the right half and consider the left half by high = mid -1.
Step 5 : Return the value of low.(Using the concept of Opposite Polarity)

Time Complexity : O(N * log(sum-max+1))
Space Complexity : O(1)
*/
int findPages(vector<int>& pages, int students){
    if(pages.size() < students) return -1;

    int low = *max_element(pages.begin(), pages.end());
    int high = accumulate(pages.begin(), pages.end(),0);

    while(low <= high){
        int mid = (low + high)/2;
        int toalStudent = numberOfStudents(pages,mid);
        if(toalStudent <= students) high = mid -1;
        else low = mid + 1;
    }
    return low;
}

int main()
{
    vector<int> pages = {12,34,67,90};
    int students = 2;

    int bruteMethod = findPagesBrute(pages,students);
    cout<<"The maximum number of pages assigned to a student while it minimum is " << bruteMethod <<endl;

    int answer = findPages(pages,students);
    cout<<"The maximum number of pages assigned to a student while it minimum is " << answer <<endl;
    
    return 0;
}