# Count and Say
<p>
The count-and-say sequence is the sequence of integers with the first five terms as following:

1.    1
2.    11
3.    21
4.    1211
5.    111221

1 is read off as "one 1" or 11.
11 is read off as "two 1s" or 21.
21 is read off as "one 2, then one 1" or 1211.
Given an integer n, generate the nth term of the count-and-say sequence.

Note: Each term of the sequence of integers will be represented as a string.

Example 1:

Input: 1
Output: "1"
Example 2:

Input: 4
Output: "1211"
</p>

```C++
class Solution {
public:
string countAndSay(int n) {
    if (n == 0) return "";
    string res = "1";
    while (--n) {
        string cur = "";
        for (int i = 0; i < res.size(); i++) {
            int count = 1;
             while ((i + 1 < res.size()) && (res[i] == res[i + 1])){
                count++;    
                i++;
            }
            cur += to_string(count) + res[i];
        }
        res = cur;
    }
    return res;
}
};

```
# Analyse
cur += to_string(count) + res[i]; initially, it record one "1"
<br> Then it goes, override res as cur. 

1 count = 1, res = "1", cur = "11", res = "11"

2 count = 1, res = "11", cur = "211", cur = "1211", res = "1211"  
```c++
             while ((i + 1 < res.size()) && (res[i] == res[i + 1])){
                count++;    
                i++;
            }
            cur += to_string(count) + res[i];

```
This part of the code just count the number of same "word".
<br> to_string(count) + res[i]
<br> get the right word --> res[i] and quantity --> to_string(count)

