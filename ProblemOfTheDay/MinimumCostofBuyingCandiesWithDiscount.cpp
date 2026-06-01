/*
Approach:
1. Sort the cost array in descending order so that the most expensive candies come first.
2. According to the offer, for every 3 candies purchased, the cheapest one among those 3 is free.
3. After sorting in decreasing order, every third candy (indices 2, 5, 8, ...) becomes the free candy.
4. Traverse the sorted array and add the cost of all candies except every third candy.
5. Return the total cost.

Example:
cost = [6,5,7,9,2,2]

After sorting:
[9,7,6,5,2,2]

Free candies -> 6 and 2
Total cost = 9 + 7 + 5 + 2 = 23

Time Complexity: O(n log n)
- Sorting the array takes O(n log n).
- Traversing the array takes O(n).

Space Complexity: O(1)
- No extra space is used apart from the sorting operation.
*/
#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    int minimumCost(vector<int>& cost) {
        int n = cost.size();
        sort(begin(cost),end(cost),greater<int>());
        int total = 0;
        for(int i = 0; i < n; i++){
        if(i%3!=2){
            total+=cost[i];
        }
        }
        return total;
    }
};