class Solution:
    def countCharacters(self, words: List[str], chars: str) -> int:
        def mapWord(word):
            chMap = {}
            for ch in word:
                if chMap.get(ch) is None:
                    chMap[ch] = 1
                else:
                    chMap[ch] += 1
            return chMap

        def compareMaps(wordMap, sourceMap):
            for key in wordMap.keys():
                if wordMap.get(key) and sourceMap.get(key):
                    if wordMap[key] > sourceMap[key]:
                        return False
                else:
                    return False
            return True

        res = ""
        chMap = mapWord(chars)
        for word in words:
            wordMap = mapWord(word)
            if compareMaps(wordMap, chMap):
                res += word
        return len(res)
