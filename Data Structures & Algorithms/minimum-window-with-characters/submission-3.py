from collections import Counter

class Solution:
    def minWindow(self, s: str, t: str) -> str:

        need = Counter(t)
        missing = len(t) 
        l = 0
        res = "" 

        for r in range(len(s)):
            ch = s[r]
            if need[ch] > 0:
                missing -= 1
            
            need[ch] -= 1

            while missing == 0:
                if r-l+1 < len(res) or len(res) == 0:
                    res = s[l:r+1]

                need[s[l]] += 1

                if need[s[l]] > 0:
                    missing += 1

                l += 1
        return res