# Combination Sum

 Given a set of candidate numbers (C) (without duplicates) and a target number (T), find all unique combinations in C where the candidate numbers sums to T.

The same repeated number may be chosen from C unlimited number of times.

Note:

    All numbers (including target) will be positive integers.
    The solution set must not contain duplicate combinations.

For example, given candidate set [2, 3, 6, 7] and target 7,
A solution set is:
```
[
  [7],
  [2, 2, 3]
]
```
```C++
class Solution {
public:
    std::vector<std::vector<int> > combinationSum(std::vector<int> &candidates, int target) {
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
        for (int i = begin; i != candidates.size() && target >= candidates[i]; ++i) {
            combination.push_back(candidates[i]);
            combinationSum(candidates, target - candidates[i], res, combination, i);
            combination.pop_back();
        }
    }
};
```

# Analyse
## part1
At first, it sorted the set
<br> std::vector<std::vector<int> > res stores remaining elements in set
<br> vector<int> combination storing the combo  
## part2
if (!target) means if (!0), the end of this method, only under this circumstance, res will accpet a solution.
<br>res.push_back(combination); push combination to end of res.
<br>Otherwise, goes to iteration, which requires iterator never goes over size of candidates and target never expand candidates[i]
<br>push candidates[i] to combination and call the recursion again.Pop_back pops last elements of combination to guarantee the recursion goes well. 