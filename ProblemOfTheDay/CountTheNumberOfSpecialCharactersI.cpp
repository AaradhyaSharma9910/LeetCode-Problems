#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numberOfSpecialChars(string word) {
        bitset<26> upper,lower;
        for(char c:word){
            if(islower(c)){
                lower.set(c-'a');

            }
            else{
                upper.set(c-'A');
            }
        }
        lower = lower&upper;
        return lower.count();
    }
};
/*

Time Complexity: O(n)

- We traverse the string once using the loop.
- set() operation in bitset takes O(1).
- AND operation between two bitsets is O(1) because size is fixed (26).
- count() is also O(1).

Overall Time Complexity = O(n)

where n = length of the string.



Space Complexity: O(1)

- We only use two bitsets of fixed size 26.
- Space does not depend on input size.

Overall Space Complexity = O(1)



Theory / Logic:

A character is called special if:
- its lowercase version exists
- and its uppercase version also exists

Example:
'a' and 'A' both present -> special
'b' only present -> not special

Approach:
1. Store all lowercase letters in one bitset.
2. Store all uppercase letters in another bitset.
3. Perform bitwise AND operation.
4. Common set bits represent special characters.
5. count() returns total number of special characters.

*/