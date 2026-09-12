class Solution {
public:
    int n;
    vector<vector<int>> intervals;

    vector<vector<pair<long long, vector<int>>>> dp;

    pair<long long, vector<int>> solve(int i, int count) {

        if (i == n || count == 4) {
            return {0, {}};
        }

            if (dp[i][count].first != -1) {
                return dp[i][count];
            }

            auto skip = solve(i + 1, count);

            int lo = i + 1;
            int hi = n - 1;
            int next = n;

            while (lo <= hi) {

                int mid = lo + (hi - lo) / 2;

                if (intervals[mid][0] > intervals[i][1]) {
                    next = mid;
                    hi = mid - 1;
                } else {
                    lo = mid + 1;
                }
            }
            auto take = solve(next, count + 1);
            take.first += intervals[i][2];
            take.second.push_back(intervals[i][3]);

            sort(take.second.begin(), take.second.end());

            if (take.first > skip.first ||
                (take.first == skip.first && take.second < skip.second)) {

                dp[i][count] = take;
            } else {
                dp[i][count] = skip;
            }

            return dp[i][count];
        }

        vector<int> maximumWeight(vector<vector<int>> & input) {

            intervals = input;
            n = intervals.size();

            for (int i = 0; i < n; i++) {
                intervals[i].push_back(i);
            }

            sort(intervals.begin(), intervals.end(),
                 [](vector<int>& a, vector<int>& b) { return a[0] < b[0]; });

            dp.assign(n, vector<pair<long long, vector<int>>>(5, {-1, {}}));

            return solve(0, 0).second;
        }
    };