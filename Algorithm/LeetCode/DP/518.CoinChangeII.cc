/* Medium
You are given coins of different denominations and a total amount of money.
Write a function to compute the number of combinations that make up that amount.
You may assume that you have infinite number of each kind of coin.

Example 1:
Input: amount = 5, coins = [1, 2, 5]
Output: 4
Explanation: there are four ways to make up the amount:
5=5
5=2+2+1
5=2+1+1+1
5=1+1+1+1+1

Example 2:
Input: amount = 3, coins = [2]
Output: 0
Explanation: the amount of 3 cannot be made up just with coins of 2.

Example 3:
Input: amount = 10, coins = [10]
Output: 1

Note:
You can assume that
0 <= amount <= 5000
1 <= coin <= 5000
the number of coins is less than 500
the answer is guaranteed to fit into signed 32-bit integer

Relatives:
322. Coin Chagne
518. Coin Change 2
983. Minimum Cost For Tickets */

#include <vector>

using namespace std;

// DP: bottom up
class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<int> dp(amount+1, 0);
        dp[0] = 1;

        for (const auto& coin : coins) {
            for (int curAmount = coin; curAmount <= amount; ++curAmount) {
                dp[curAmount] += dp[curAmount-coin];
            }
        }

        return dp[amount];
    }
};

class Solution {
public:
    int change(int amount, vector<int>& coins) {
        const auto len = coins.size();
        vector<vector<int>> dp(len + 1, vector(amount + 1, 0));

        for (auto i = 0; i <= len; ++i) {
            dp[i][0] = 1;
        }

        for (auto i = 1; i <= len; ++i) {
            for (auto j = 1; j <= amount; ++j) {
                if (j >= coins[i-1]) {
                    dp[i][j] = dp[i-1][j] + dp[i][j-coins[i-1]];
                } else {
                    dp[i][j] = dp[i-1][j];
                }
            }
        }

        return dp[len][amount];
    }
};

class Solution {
public:
    int change(int amount, vector<int>& coins) {
        const auto len = coins.size();
        vector<vector<int>> dp(amount + 1, vector(len + 1, 0));

        for (auto i = 0; i <= len; ++i) {
            dp[0][i] = 1;
        }

        for (auto i = 1; i <= amount; ++i) {
            for (auto j = 1; j <= len; ++j) {
                if (i >= coins[j-1]) {
                    dp[i][j] = dp[i][j-1] + dp[i-coins[j-1]][j];
                } else {
                    dp[i][j] = dp[i][j-1];
                }
            }
        }

        return dp[amount][len];
    }
};