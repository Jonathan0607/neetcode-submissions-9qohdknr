class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        anagrams = defaultdict(list)
        for word in strs:
            anagrams[tuple(sorted(list((word))))].append(word) 
        return (list(anagrams.values()))