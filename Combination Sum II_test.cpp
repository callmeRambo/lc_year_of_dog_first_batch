#include <iostream>
#include <vector>
#include <algorithm> 
using namespace std;
class Solution {
public:
    std::vector<std::vector<int> > combinationSum2(std::vector<int> &candidates, int target) {
        std::sort(candidates.begin(), candidates.end());
        std::vector<std::vector<int> > res;
        std::vector<int> combination;
        combinationSum(candidates, target, res, combination, 0);
        return res;
    }
private:
    void combinationSum(std::vector<int> &candidates, int target, std::vector<std::vector<int> > &res, std::vector<int> &combination, int begin) {
        if (!target) {
            res.push_back(combination);
            return;
        }
        for (int i = begin; i != candidates.size() && target >= candidates[i]; i++) {
            if ( i - 1 != begin - 1 && candidates[i] == candidates[i-1]){
                # i-1 != begin - 1 means it avoids the "first element" duplications. 
                continue;
            }
            cout<<candidates[i]<<endl;
            combination.push_back(candidates[i]);
            combinationSum(candidates, target - candidates[i], res, combination, i+1);
            combination.pop_back();
        }
    }
};

int main(){
    std::vector<int> test;
    test.push_back(10);
    test.push_back(1);
    test.push_back(2);
    test.push_back(7);
    test.push_back(6);
    test.push_back(1);
    test.push_back(5);

    Solution().combinationSum2(test,8);
    return 0;
}