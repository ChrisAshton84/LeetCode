class Solution:
    def isValid(self, s: str) -> bool:
        stack = ""
        for c in s:
            if c in ['(', '{', '[']:
                stack = stack + c
            else:
                if c == ')':
                    if len(stack) == 0 or stack[-1] != '(':
                        return False
                if c == '}':
                    if len(stack) == 0 or stack[-1] != '{':
                        return False
                if c == ']':
                    if len(stack) == 0 or stack[-1] != '[':
                        return False
                stack = stack[:-1]
                
        if len(stack) > 0:
            return False
        
        return True
