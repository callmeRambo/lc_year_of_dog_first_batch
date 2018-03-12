# Number Complement

Given a positive integer, output its complement number. The complement strategy is to flip the bits of its binary representation.

Note:
The given integer is guaranteed to fit within the range of a 32-bit signed integer.
You could assume no leading zero bit in the integer’s binary representation.
```
Example 1:
Input: 5
Output: 2
Explanation: The binary representation of 5 is 101 (no leading zero bits), and its complement is 010. So you need to output 2.

Example 2:
Input: 1
Output: 0
Explanation: The binary representation of 1 is 1 (no leading zero bits), and its complement is 0. So you need to output 0.
```
```c++
class Solution {
public:
    int findComplement(int num) {
        unsigned mask = ~0;
        while (num & mask) mask <<= 1;
        return ~mask & ~num;
    }
};
```

#Analyse 
if directly use ~num, it would appear -6( 10010), this question becomes eradicate the first 1.

Therefore, a mask is used and initialized as 11;
by left moving the 11 -- 110 -- 1100...finally 10010 and 1100000 is 0. quit recursion.
Then ~mask is 0011111, ~num is 010, the and action makes 10, the answer.
