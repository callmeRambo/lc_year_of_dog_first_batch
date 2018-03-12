# Combination Sum II

 Given a collection of candidate numbers (C) and a target number (T), find all unique combinations in C where the candidate numbers sums to T.

Each number in C may only be used once in the combination.

Note:

    All numbers (including target) will be positive integers.
    The solution set must not contain duplicate combinations.

For example, given candidate set [10, 1, 2, 7, 6, 1, 5] and target 8,
A solution set is:
```
[
  [1, 7],
  [1, 2, 5],
  [2, 6],
  [1, 1, 6]
]
```
```C++
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
                continue;
            }
            combination.push_back(candidates[i]);
            combinationSum(candidates, target - candidates[i], res, combination, i+1);
            combination.pop_back();
        }
    }
};
```

#Analyse
```c++
            if ( i - 1 != begin - 1 && candidates[i] == candidates[i-1]){
                continue;
            }
```
Filtering the duplicated parts with i-1 != begin - 1 which avoids the "first element" duplications. 
