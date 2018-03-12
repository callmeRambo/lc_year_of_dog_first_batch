# Search for a Range
Given an array of integers sorted in ascending order, find the starting and ending position of a given target value.

Your algorithm's runtime complexity must be in the order of O(log n).

If the target is not found in the array, return [-1, -1].

For example,
Given [5, 7, 7, 8, 8, 10] and target value 8,
return [3, 4].
```c++
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        auto bounds = equal_range(nums.begin(), nums.end(), target);
        if (bounds.first == bounds.second)
            return {-1,-1};
        return {bounds.first - nums.begin(), bounds.second - nums.begin() - 1};
    }
};
```
# Analyse
## equal_range 
returns iteration type where the first and last time target appear. 
<br> which has first and second
## nums.begin()
returns the first element. 
## bounds.first - nums.begin()
result of difference towards position. 