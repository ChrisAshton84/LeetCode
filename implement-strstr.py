class Solution:
    def strStr(self, haystack: str, needle: str) -> int:
        if len(needle) == 0:
            return 0
        
        if len(haystack) == 0:
            return -1
        
        haystack_len = len(haystack)
        needle_len = len(needle)
        
        idx = 0
        
        while idx < haystack_len:
            if haystack[idx] == needle[0]:
                jdx = 0
                
                matching = True
                
                while jdx < needle_len and matching:
                    if jdx + idx >= haystack_len:
                        return -1
                    
                    if haystack[idx + jdx] != needle[jdx]:
                        matching = False
                        
                    jdx += 1
                
                if matching == True:
                    return idx
            
            idx += 1
        
        return -1
                    
