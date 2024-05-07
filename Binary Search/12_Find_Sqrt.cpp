//Find the square root of a given number using binary search algorithm.
#include<bits/stdc++.h>
using namespace std;

/*
Brute Force Approach : Perform Linear Search Technique.

Step 1 : Initialize answer as 0 and start a loop from 1.
Step 2 : Check if i*i is smaller than or equal to N then update answer.
Step 3 : When the square is greater than the given number break from loop.

Time Complexity : O(N) 
Space Complexity : O(1)
*/
int floorSqrtBrute(int n){
    int answer = 0;
    for(int i=1; i<=n; i++){
        if(i*i <= n){
            answer = i;
        }
        else break;
    }
    return answer;
}

/*
Optimal Approach : Perform Binary Search.

Step 1 : Initialize low as 0 and high as the largest possible answer.
Step 2 : Check if mid*mid is smaller than or equal to N and update low as mid + 1.
Step 3 : Else update high as mid - 1.

Time Complexity : O(log N) 
Space Complexity : O(1)
*/
long long floorSqrt(int n){
    int low = 0, high = n;
    long long answer;

    while(low <= high){
        long long mid = (low + high)/2;
        if(mid*mid <= n){
            answer = mid;
            low = mid + 1;
        }
        else high = mid - 1;
    }
    // Here, high can also be returned because after the end of BS it points to the correct answer.
    return answer;
}

/* Why this happens ? Because At the start low points to a probable answer and high points to not a probable
answer so after the completion of the binary search algorithm low points to first non-possible answer and 
high points to last possible answer.
*/

int main()
{
    int number = 0;
    int answer = floorSqrtBrute(number);
    cout<<"Square root of "<<number << " is "<<answer<<endl;

    long long sqrt = floorSqrt(number);
    cout<<"Square root of "<<number << " is "<<sqrt;

    return 0;
}