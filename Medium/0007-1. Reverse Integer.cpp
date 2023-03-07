/* 
Question link : https://leetcode.com/problems/reverse-integer/

Runtime : 0 ms
Beats : 100 %
Memory : 6.4 MB
Beats : 5.45 %

Time Complexity : O(k)
-> when k is length if integer(in decimal)
-> need to extract digit, push to vector, check overflow condition

Space Complexity : O(k)
-> k for digit vector
-> 4 for result, sign, digits_iter, i

Algorithm : 
1. Save sign and put absolute value in x
2. Extract digits from x and save in vector
3. Check overflow by checking if flipped number exceeds INT_MAX.
4. Convert vector to int by adding considering digit location
5. Add sign and return.
*/

#include <vector>
#include <math.h>

using namespace std;

class Solution {
public:
    int reverse(int x) {
        int result = 0;

        // remove sign
        bool sign;
        x > 0 ? sign = true : sign = false;
        x = abs(x);

        // extract digits
        vector<int> digits;
        while (x > 0){
            digits.push_back(x % 10);
            x /= 10;
        }

        // check overflow
        if (digits.size() == 10){
            if (sign){ // positive
                if (digits[0] > 2) return 0;
                else if (digits[0] == 2){
                    if (digits[1] > 1) return 0;
                    else if (digits[1] == 1){
                        if (digits[2] > 4) return 0;
                        else if (digits[2] == 4){
                            if (digits[3] > 7) return 0;
                            else if (digits[3] == 7){
                                if (digits[4] > 4) return 0;
                                else if (digits[4] == 4){
                                    if (digits[5] > 8) return 0;
                                    else if (digits[5] == 8){
                                        if (digits[6] > 3) return 0;
                                        else if (digits[6] == 3){
                                            if (digits[7] > 6) return 0;
                                            else if (digits[7] == 6){
                                                if (digits[8] > 4) return 0;
                                                else if (digits[8] == 4){
                                                    if (digits[9] > 7) return 0;                                       
                                                }                                            
                                            }                                            
                                        }
                                    }                                    
                                }
                            }
                        }
                    }
                }
            }
            else{ // negative
                if (digits[0] > 2) return 0;
                else if (digits[0] == 2){
                    if (digits[1] > 1) return 0;
                    else if (digits[1] == 1){
                        if (digits[2] > 4) return 0;
                        else if (digits[2] == 4){
                            if (digits[3] > 7) return 0;
                            else if (digits[3] == 7){
                                if (digits[4] > 4) return 0;
                                else if (digits[4] == 4){
                                    if (digits[5] > 8) return 0;
                                    else if (digits[5] == 8){
                                        if (digits[6] > 3) return 0;
                                        else if (digits[6] == 3){
                                            if (digits[7] > 6) return 0;
                                            else if (digits[7] == 6){
                                                if (digits[8] > 4) return 0;
                                                else if (digits[8] == 4){
                                                    if (digits[9] > 8) return 0;                                       
                                                }                                            
                                            }                                            
                                        }
                                    }                                    
                                }
                            }
                        }
                    }
                }
            }
        }
        vector<int>::iterator digits_iter = digits.begin();
        for (int i = digits.size() -1; i >= 0; i--){
            result += *digits_iter * pow(10, i);
            digits_iter++;
        }
        if (!sign) result *= -1;
        return result;
    }
};