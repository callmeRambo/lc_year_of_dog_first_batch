# First Missing Positive
Given an unsorted integer array, find the first missing positive integer.

For example,
Given [1,2,0] return 3,
and [3,4,-1,1] return 2.

Your algorithm should run in O(n) time and uses constant space. 
```c++
class Solution
{
public:
    int firstMissingPositive(int A[], int n)
    {
        for(int i = 0; i < n; ++ i)
            while(A[i] > 0 && A[i] <= n && A[A[i] - 1] != A[i])
                swap(A[i], A[A[i] - 1]);
        
        for(int i = 0; i < n; ++ i)
            if(A[i] != i + 1)
                return i + 1;
        
        return n + 1;
    }
};
```
# Analyze
It actually uses BIN sort.
```c++
while(A[i] > 0 && A[i] <= n && A[A[i] - 1] != A[i])
```
there swap A[i] and A[A[i]-1] to make it sorted. While loop is of vital important.
```c++
if(A[i] != i + 1)
```
<br> there check if the number is in BIN.
