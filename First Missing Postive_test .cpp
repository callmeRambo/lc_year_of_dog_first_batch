#include <iostream>
#include <vector>
#include <algorithm> 
using namespace std;
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        for (int i = 0; i < nums.size(); i++){
            while (nums[i] > 0 && nums[i] <= nums.size() && nums[nums[i] - 1] != nums[i])
                swap(nums[i], nums[nums[i]-1]);
        }
        for (int i = 0; i < nums.size(); i++){
            if (nums[i] != i+1){
                return i+1;
            }
        }
        return nums.size()+1;
    }
};

int main(){
    std::vector<int> test;
    test.push_back(3);
    test.push_back(4);
    test.push_back(-1);
    test.push_back(1);
    /*test.push_back(-1);
    test.push_back(4);
    test.push_back(2);
    test.push_back(1);
    test.push_back(9);
    test.push_back(10);*/
    cout<<Solution().firstMissingPositive(test);
    return 0;
}