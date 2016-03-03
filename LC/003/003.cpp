class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> alph;
        int i, n = s.size(), previ = 0, ans = 0, tot = 0;
        for (i = 0; i < n; i++)
        {
            auto got = alph.find(s[i]);
            if (got == alph.end())
            {
                ans = previ + 1;
                alph[s[i]] = i;
            } else
            {
                ans = i - got->second;
                if (ans > previ + 1)
                    ans = previ + 1;
                got->second = i;
            }
            previ = ans;
            if (ans > tot) tot = ans;
        }
        return tot;
    }
};
