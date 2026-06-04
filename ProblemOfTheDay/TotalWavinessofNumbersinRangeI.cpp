/*
Approach:
1. For each number in the range [num1, num2]:
   - Convert the number into a string.
   - If the number has fewer than 3 digits, its waviness score is 0 because
     a peak or valley requires both a left and right neighbor.
2. Traverse all middle digits (index 1 to length-2).
3. Count a point as:
   - Peak  : digit > left digit AND digit > right digit
   - Valley: digit < left digit AND digit < right digit
4. The waviness score of a number is the total count of peaks and valleys.
5. Sum the waviness scores of all numbers in the given range and return the result.

Time Complexity:
- Let N = num2 - num1 + 1 (number of integers in the range).
- Let D = number of digits in a number.
- For each number, we scan all its digits once.
- Therefore, Time Complexity = O(N * D).

Space Complexity:
- A string representation of the current number is created.
- Therefore, Space Complexity = O(D).
*/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findWaiveScore(int num){
        string s = to_string(num);
        int l = s.length();
        if(l<3){
            return 0;
        }
        int score = 0;
        for(int i = 1; i <= l-2; i++){
            if(s[i]>s[i-1]&&s[i]>s[i+1]) score++;
            if(s[i]<s[i-1]&&s[i]<s[i+1]) score++;
        }
        return score;
    }
    int totalWaviness(int num1, int num2) {
        int score = 0;
        for(int num = num1; num <= num2; num++){
            score += findWaiveScore(num);
        }
        return score;
        
    }
};