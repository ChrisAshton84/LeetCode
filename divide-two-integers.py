class Solution:
    def divide(self, dividend: int, divisor: int) -> int:
        quotient = 0
        
        dividend_pos = True
        if dividend < 0:
            dividend_pos = False
            dividend = -dividend
            
        divisor_pos = True
        if divisor < 0:
            divisor_pos = False
            divisor = -divisor
            
        if divisor > dividend:
            return 0
                    
        result_pos = True
        if dividend_pos != divisor_pos:
            result_pos = False
​
        if divisor == dividend:
            if result_pos:
                return 1
            else:
                return -1
​
        #print("dividend: ", dividend, ",divisor: ", divisor, ", result_pos: ", result_pos)
​
        for i in range(32):
            comp_i = 31 - i
            
            mul_divisor = divisor << comp_i
            
            if mul_divisor <= 2**31:
                #print("Trying mul_divisor: ", mul_divisor, ", remainder: ", dividend)
                if dividend >= mul_divisor:
                    #print("  yes, comp_i: ", comp_i, ", add_val: ", (1 << comp_i), ", quotient: ", quotient + (1 << comp_i))
                    dividend -= mul_divisor
                    quotient += (1 << comp_i)
        
        if result_pos == False:
            quotient = -quotient
​
        if quotient > (2**31 - 1):
            quotient = 2**31 - 1
​
        return quotient
