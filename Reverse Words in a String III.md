# Reverse Words in a String III

Given a string, you need to reverse the order of characters in each word within a sentence while still preserving whitespace and initial word order.
```
Example 1:
Input: "Let's take LeetCode contest"
Output: "s'teL ekat edoCteeL tsetnoc"
```
Note: In the string, each word is separated by single space and there will not be any extra space in the string.

```c++
class Solution {
public:
    string reverseWords(string s) {
        for (int i = 0; i < s.size(); i++){
            if (s[i]==' ') return s;
            int j = i;
            for (; j < s.length() && s[j] != ' '; j++) { }
            reverse(s.begin() + i, s.begin() + j);
            i = j;
        }
        return s;
    }
};
```

By using reverse, s.begin() + 1 means move to second element of s