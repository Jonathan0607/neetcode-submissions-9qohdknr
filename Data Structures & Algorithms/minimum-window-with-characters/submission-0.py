class Solution:
    def minWindow(self, s: str, t: str) -> str:
        countT, window = {}, {}
        for i in t:
            countT[i] = 1 + countT.get(i, 0)
        
        have, need = 0, len(countT)
        res, resLen = "", float("infinity")
        l = 0

        for r in range(len(s)):
            letter = s[r]
            
            if letter in countT:
                window[letter] = 1 + window.get (letter, 0)
                if window[letter] == countT[letter]:
                    have += 1
            
            while have == need:
                if(r - l + 1) < resLen or len(res) < 1:
                    res = s[l:r+1]
                    resLen = r - l + 1
                if s[l] in countT:
                    window[s[l]] -= 1
                    if window[s[l]] < countT[s[l]]:
                        have -= 1
                l += 1
        return res