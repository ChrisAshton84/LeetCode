class Solution:
    def findSubstring(self, s: str, words: [str]) -> [int]:
        debug = False
​
        res = []
        
        class wordTrieNode:
            def __init__(self, c: int):
                self.c = c               # 0..25 letter represented by this node (-1 represents 'none' at head of trie)
                self.next = [None] * 26  # next possible characters in word(s) this letter is part of
                self.curWords = 0        # how many words pass through this node
                self.ends = 0            # how many times this is the last letter in a word (could be more than one!)
                self.word = ""           # remember what word ends here (avoid re-building)
                self.matches = 0         # track how many times this has been matched
​
        wordTrieHead = wordTrieNode(-1)  # head node from which all words will be encoded
        wordTrieEnds = {}                # shortcut to all nodes that end a word
​
        def strToInt(s: str) -> int:
            return ord(s) - ord('a')
​
        def enterWordInfo(head: wordTrieNode, newStr: str):
            nodePtr = head
​
            for c_str in newStr:                                                                                                                                                                                                                                          
                c = strToInt(c_str) # get value 0..25                                                                                                                                                                                                                     
                                                                                                                                                                                                                                                                          
                if nodePtr.next[c] is None:                                                                                                                                                                                                                               
                    nodePtr.next[c] = wordTrieNode(c)                                                                                                                                                                                                                     
                                                                                                                                                                                                                                                                          
                nodePtr = nodePtr.next[c]                                                                                                                                                                                                                                 
                nodePtr.curWords += 1                                                                                                                                                                                                                                     
                                                                                                                                                                                                                                                                          
            nodePtr.ends += 1              # record that this ends a word                                                                                                                                                                                                 
                                                                                                                                                                                                                                                                          
            if not newStr in wordTrieEnds: # save a pointer to every node that ends a word for quick searching                                                                                                                                                            
                nodePtr.word = newStr                                                                                                                                                                                                                                     
                wordTrieEnds[newStr] = nodePtr                                                                                                                                                                                                                            
                                                                                                                                                                                                                                                                          
        totalLen = 0                                                                                                                                                                                                                                                      
                                                                                                                                                                                                                                                                          
        for w_idx in range(len(words)):                                                                                                                                                                                                                                   
            w = words[w_idx]                                                                                                                                                                                                                                              
                                                                                                                                                                                                                                                                          
            enterWordInfo(wordTrieHead, w)                                                                                                                                                                                                                                
                                                                                                                                                                                                                                                                          
            totalLen += len(w)                                                                                                                                                                                                                                            
                                                                                                                                                                                                                                                                          
        res = []                                                                                                                                                                                                                                                          
        len_s = len(s)                                                                                                                                                                                                                                                    
        len_words = len(words)                                                                                                                                                                                                                                            
                                                                                                                                                                                                                                                                          
        def matchWordInfo(c_idx: int, trie: wordTrieNode, currentMatches: int, depth: int) -> bool: # search along s until end of word in trie is found, or non-match                                                                                                     
            if debug is True: print("      " * depth, "  Looking for match from ", s[c_idx : c_idx + 8], "...")                                                                                                                                                           
                                                                                                                                                                                                                                                                          
            for w in wordTrieEnds:                                                                                                                                                                                                                                        
                if debug is True: print("      " * depth, "    Possible word", wordTrieEnds[w].word, " remaining matches:", wordTrieEnds[w].ends - wordTrieEnds[w].matches)                                                                                               
                                                                                                                                                                                                                                                                          
            c_idx0 = c_idx                                                                                                                                                                                                                                                
                                                                                                                                                                                                                                                                          
            while c_idx < len_s:                                                                                                                                                                                                                                          
                c = strToInt(s[c_idx])                                                                                                                                                                                                                                    
                                                                                                                                                                                                                                                                          
                c_idx += 1                                                                                                                                                                                                                                                
                                                                                                                                                                                                                                                                          
                if trie.next[c] is not None:
                    if debug is True: print("      " * depth, "    found ", s[c_idx - 1])                                                                                                                                                                                 
                    trie = trie.next[c]                                                                                                                                                                                                                                   
                else:                                                                                                                                                                                                                                                     
                    if debug is True: print("      " * depth, "    match ends at: ", s[c_idx0 : c_idx])                                                                                                                                                                   
                    return False # signal no match found, and current search position                                                                                                                                                                                     
                                                                                                                                                                                                                                                                          
                if trie.ends > trie.matches: # if this ended a word, and hasn't been consumed yet
                    if debug is True: print("      " * depth, "      matched: ", trie.word, ", possible words here: ", trie.curWords, ", ending words here: ", trie.ends, ", previous matches:", currentMatches, ", remaining: ", len_words - currentMatches)             
                                                                                                                                                                                                                                                                          
                    # If this was the last match needed                                                                                                                                                                                                                   
                    if currentMatches + 1 == len_words:                                                                                                                                                                                                                   
                        res.append(c_idx - totalLen)                                                                                                                                                                                                                      
                        if debug is True: print("      " * depth, "      last match needed, c_idx=", c_idx, ", totalLen=", totalLen, ", substr: ", s[c_idx - totalLen : c_idx])                                                                                           
                        return True                                                                                                                                                                                                                                       
                                                                                                                                                                                                                                                                          
                    # First search down longer words                                                                                                                                                                                                                      
                    if trie.curWords > trie.ends:                                                                                                                                                                                                                         
                        if debug is True: print("      " * depth, "      trying to match longer word")                                                                                                                                                                    
