/**
 * @param {string} s
 * @return {number}
 */
var romanToInt = function(s) {
    var i;
    var ret = 0;
    
    for (i = 0; i < s.length; i++) {
        var c = s.charAt(i);
        switch (c) {
            case 'M':
                ret += 1000;
                break;
            case 'D':
                ret += 500;
                break;
            case 'C':
                if (i + 1 < s.length) {
                    var c2 = s.charAt(i + 1);
                    
                    switch (c2) {
                        case 'M':
                            ret += 900;
                            i++;
                            break;
                        case 'D':
                            ret += 400;
                            i++;
                            break;
                        default:
                            ret += 100;
                            break;
                    }
                } else
                    ret += 100;
                break;
            case 'L':
                ret += 50;
                break;
            case 'X':
                if (i + 1 < s.length) {
                    var c2 = s.charAt(i + 1);
                    
                    switch (c2) {
                        case 'C':
                            ret += 90;
                            i++;
                            break;
                        case 'L':
                            ret += 40;
                            i++;
                            break;
                        default:
                            ret += 10;
                            break;
                    }
                } else
                    ret += 10;
                break;
            case 'V':
                ret += 5;
                break;
            case 'I':
                if (i + 1 < s.length) {
                    var c2 = s.charAt(i + 1);
                    
                    switch (c2) {
                        case 'X':
                            ret += 9;
                            i++;
                            break;
                        case 'V':
                            ret += 4;
                            i++;
                            break;
                        default:
                            ret += 1;
                            break;
                    }
                } else
                    ret += 1;
                break;
        }
    }
    
    return ret;
};
