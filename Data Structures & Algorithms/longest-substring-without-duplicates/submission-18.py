class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        if len(s) == 0:
            return 0
        if len(s) == 1:
            return 1

        length = 1
        position = {s[0]:0}
        l = 0

        for i in range(len(s)):
            if i == 0:
                continue
            if s[i] in position.keys():
                l = position[s[i]] + 1 if l <= position[s[i]] else l
                position.pop(s[i])
                print(position.keys())
            position[s[i]] = i
            length = max(length, i-l+1)
            print(l)
            print(i)
        return length

        