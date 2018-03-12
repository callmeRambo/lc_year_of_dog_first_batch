# Self Dividing Numbers

A self-dividing number is a number that is divisible by every digit it contains.

For example, 128 is a self-dividing number because 128 % 1 == 0, 128 % 2 == 0, and 128 % 8 == 0.

Also, a self-dividing number is not allowed to contain the digit zero.

Given a lower and upper number bound, output a list of every possible self dividing number, including the bounds if possible.
```
Example 1:
Input: 
left = 1, right = 22
Output: [1, 2, 3, 4, 5, 6, 7, 8, 9, 11, 12, 15, 22]
Note:
```
The boundaries of each input argument are 1 <= left <= right <= 10000.

```c++
class Solution {
public:
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> res;
        for (int i = left, n = 0; i <= right; i++) {
            for (n = i; n > 0; n /= 10)
                if (!(n % 10) || i % (n % 10)) break;
            if (!n) res.push_back(i);
        }
        return res;
    }
};
```
# Analyze
From left to right, select self-dividing numbers.
<br>The second iteration, n represents the dividing number

<br> if i % (n % 10) is 0, !(n % 10) must be 1. If i % (n % 10) is larger than 0, !(n % 10) must be 1, whcih represents single digit.
# if (!(n % 10) || i % (n % 10)) break; this line is the key!
