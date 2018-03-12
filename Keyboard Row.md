# Keyboard Row
Given a List of words, return the words that can be typed using letters of alphabet on only one row's of American keyboard like the image below.

![avatar](https://leetcode.com/static/images/problemset/keyboard.png)
```Example 1:
Input: ["Hello", "Alaska", "Dad", "Peace"]
Output: ["Alaska", "Dad"]
Note:
You may use one character in the keyboard more than once.
You may assume the input string will only contain letters of alphabet.
```

```c++
class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        vector<int> dict(26);
        vector<string> rows = {"QWERTYUIOP", "ASDFGHJKL", "ZXCVBNM"};
        for (int i = 0; i < rows.size(); i++) {
            for (auto c : rows[i]) dict[c-'A'] = 1 << i;
        }
        vector<string> res;
        for (auto w : words) {
            int r = 7;
            for (char c : w) {
                r &= dict[toupper(c)-'A'];
                if (r == 0) break;
            }
            if (r) res.push_back(w);
        }
        return res;
    }
};
```

The idea is simple. Define a mask flag for each row. In my implementation, I define the flag for Row 1 (“QWERTYUIOP”) as 1 (001), Row 2 (“ASDFGHJKL”) as 2 (010), Row 3 (“ZXCVBNM”) as 4 (100).

For each word, us 7 (111) as base, do AND operation on each character. If all chars from same row, the final result will be one of (1, 2, 4). If any character from other row, the final result will be 0