class Solution:
    def letterCombinations(self, digits: str) -> List[str]:
        letterMap = {                         2: ['a', 'b', 'c'], 3: ['d', 'e', 'f'],
                     4: ['g', 'h', 'i'],      5: ['j', 'k', 'l'], 6: ['m', 'n', 'o'],
                     7: ['p', 'q', 'r', 's'], 8: ['t', 'u', 'v'], 9: ['w', 'x', 'y', 'z']}
        
        ret = []
        
        for curNum in digits:
            num = int(curNum)
            if len(ret) == 0:
                ret = letterMap[num].copy()
            else:
                existing = len(ret)
                for idx in range(existing):
                    for newChar in letterMap[num]:
                        ret.append(ret[idx] + newChar)
                ret = ret[existing:]
            
        return ret
