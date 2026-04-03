class TrieNode:
    def __init__(self):
        self.children = {}
        self.end = False

class WordDictionary:

    def __init__(self):
        self.root = TrieNode()

    def addWord(self, word: str) -> None:
        curr = self.root
        for i in word:
            if i not in curr.children:
                curr.children[i] = TrieNode()
            curr = curr.children[i]
        curr.end = True

    def search(self, word: str) -> bool:

        def dfs(string, node):
            curr = node
            for i in range(0,len(string)):
                w = string[i]
                if w == '.':
                    for child in curr.children.values():
                        if dfs(string[i+1:], child):
                            return True
                    return False

                elif w not in curr.children:
                    return False
                curr = curr.children[w]
                            
            return curr.end
        return dfs(word, self.root)
                

                
