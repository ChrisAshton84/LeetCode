char * longestCommonPrefix(char ** strs, int strsSize){
    if (strsSize == 0) {
        char * ret;
        
        asprintf(&ret, "");
        
        return ret;
    } else if (strsSize == 1) {
        char * ret;
        
        asprintf(&ret, "%s", strs[0]);
        
        return ret;
    }
​
    int match = 1; // Whether it's possible there's still a match
    int pos = -1;  // Position of last matched char
    char matchChar;// Which character from str 0 to look for
​
    // Iterate over each string - compare character by character
    // Once a non-matching case is found, or end of any string,
    // previous character was end of longest common string
​
    while (match && (matchChar = strs[0][pos + 1])!= '\0') {
        for (int str = 1; str < strsSize; str++) {
            char curChar = strs[str][pos + 1];
            
            if (curChar != matchChar) {
                match = 0;
                break;
            }
        }
        
        if (match)
            pos++;
    }
    
    char * ret;
    
    asprintf(&ret, "%.*s", pos + 1, strs[0]);
​
    return ret;
}
