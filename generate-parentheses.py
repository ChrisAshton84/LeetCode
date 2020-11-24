class Solution:
    def generateParenthesis(self, n: int) -> List[str]:
        return self.genParenRecur(n, 0, "")
    
    def genParenRecur(self, n: int, o: int, curstr: str) -> List[str]:
        ret = []
        if n > 0: # If there are parenthesis left to create
            if o > 0: # If already have open parens *and* have some to create, recurse both options - before and after closing a paren
                newstrs = self.genParenRecur(n, o - 1, curstr + ")")
                
                for s in newstrs:
                #    if s not in ret:
                        ret.append(s)
            
            # Now process going deeper into parens
            newstrs = self.genParenRecur(n - 1, o + 1, curstr + "(")
            
            for s in newstrs:
                #if s not in ret:
                    ret.append(s)
        elif o > 0:
            newstrs = self.genParenRecur(n, o - 1, curstr + ")")
            
            for s in newstrs:
                #if s not in ret:
                    ret.append(s)
        else:
            ret = [curstr]
        
        return ret
