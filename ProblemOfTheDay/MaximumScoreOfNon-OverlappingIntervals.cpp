#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> maximumWeight(vector<vector<int>>& intervals) {

        int n = intervals.size();

        // Store: left, right, weight, original index
        vector<tuple<int, int, int, int>> arr;

        for (int i = 0; i < n; i++) {
            arr.push_back(make_tuple(
                intervals[i][0],
                intervals[i][1],
                intervals[i][2],
                i
            ));
        }

        // Sort according to ending time
        sort(arr.begin(), arr.end(),
            [](const tuple<int, int, int, int>& a,
               const tuple<int, int, int, int>& b) {
                return get<1>(a) < get<1>(b);
            }
        );

        const long long NEG = -(1LL << 60);

        // dp[i][j] = maximum weight using first i intervals
        // while selecting exactly j intervals
        vector<vector<long long>> dp(
            n + 1,
            vector<long long>(5, NEG)
        );

        // Store selected indices
        vector<vector<vector<int>>> indices(
            n + 1,
            vector<vector<int>>(5)
        );

        // Selecting 0 intervals = weight 0
        for (int i = 0; i <= n; i++) {
            dp[i][0] = 0;
        }

        for (int i = 0; i < n; i++) {

            int l = get<0>(arr[i]);
            int r = get<1>(arr[i]);
            int weight = get<2>(arr[i]);
            int idx = get<3>(arr[i]);

            // Find first interval whose ending time >= l
            // Therefore k intervals before it have ending time < l
            int k = lower_bound(
                arr.begin(),
                arr.begin() + i,
                l,
                [](const tuple<int, int, int, int>& t, int value) {
                    return get<1>(t) < value;
                }
            ) - arr.begin();

            for (int j = 1; j <= 4; j++) {

                // Don't take current interval
                long long skip = dp[i][j];

                // Take current interval
                long long take = NEG;

                if (dp[k][j - 1] != NEG) {
                    take = dp[k][j - 1] + weight;
                }

                // Case 1: Skip is better
                if (skip > take) {

                    dp[i + 1][j] = skip;
                    indices[i + 1][j] = indices[i][j];

                }

                // Case 2: Take is better
                else if (take > skip) {

                    dp[i + 1][j] = take;

                    indices[i + 1][j] = indices[k][j - 1];

                    indices[i + 1][j].push_back(idx);

                    sort(
                        indices[i + 1][j].begin(),
                        indices[i + 1][j].end()
                    );
                }

                // Case 3: Both have same weight
                else {

                    dp[i + 1][j] = skip;

                    vector<int> takeIndices = indices[k][j - 1];

                    takeIndices.push_back(idx);

                    sort(
                        takeIndices.begin(),
                        takeIndices.end()
                    );

                    vector<int> skipIndices = indices[i][j];

                    // Choose lexicographically smaller indices
                    if (takeIndices < skipIndices) {
                        indices[i + 1][j] = takeIndices;
                    }
                    else {
                        indices[i + 1][j] = skipIndices;
                    }
                }
            }
        }

        return indices[n][4];
    }
};