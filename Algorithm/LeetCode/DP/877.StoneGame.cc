/* Medium
Alice and Bob play a game with piles of stones.
There are an even number of piles arranged in a row, and each pile has a positive integer number of stones piles[i].

The objective of the game is to end with the most stones.
The total number of stones across all the piles is odd, so there are no ties.

Alice and Bob take turns, with Alice starting first.
Each turn, a player takes the entire pile of stones either from the beginning or from the end of the row.
This continues until there are no more piles left, at which point the person with the most stones wins.

Assuming Alice and Bob play optimally, return true if Alice wins the game, or false if Bob wins.

Example 1:
Input: piles = [5,3,4,5]
Output: true
Explanation:
Alice starts first, and can only take the first 5 or the last 5.
Say she takes the first 5, so that the row becomes [3, 4, 5].
If Bob takes 3, then the board is [4, 5], and Alice takes 5 to win with 10 points.
If Bob takes the last 5, then the board is [3, 4], and Alice takes 4 to win with 9 points.
This demonstrated that taking the first 5 was a winning move for Alice, so we return true.

Example 2:
Input: piles = [3,7,2,3]
Output: true

Constraints:
2 <= piles.length <= 500
piles.length is even.
1 <= piles[i] <= 500
sum(piles[i]) is odd.

Relatives:
877. Stone Game
1140. Stone Game II
1406. Stone Game III
1510. Stone Game IV
1563. Stone Game V
1686. Stone Game VI
1690. Stone Game VII
1872. Stone Game VIII
2029. Stone Game IX */

#include <vector>

using namespace std;

/* Mathematical */
class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        return true;
    }
};

// DP bottom up
class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        const auto len = piles.size();
        Memo.resize(len, vector(len, -1));

        return dp(piles, 0, len-1);
    }

private:
    int dp(const vector<int>& piles, int i, int j) {
        if (i == j)
            return 0;
        if (Memo[i][j] != -1)
            return Memo[i][j];

        int ret = 0;

        if ((i + j + piles.size()) % 2 == 0) {
            ret = max(piles[i] + dp(piles, i+1, j), piles[j] + dp(piles, i, j-1));
        } else {
            ret = min(-piles[i] + dp(piles, i+1, j), -piles[j] + dp(piles, i, j-1));
        }

        Memo[i][j] = ret;

        return ret;
    }

private:
    vector<vector<int>> Memo;
};

// DP top down
class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        int N = piles.size();

        // dp[i+1][j+1] = the value of the game [piles[i], ..., piles[j]]
        int dp[N+2][N+2];
        memset(dp, 0, sizeof(dp));

        for (int size = 1; size <= N; ++size)
            for (int i = 0, j = size - 1; j < N; ++i, ++j) {
                int parity = (j + i + N) % 2;  // j - i - N; but +x = -x (mod 2)
                if (parity == 1)
                    dp[i+1][j+1] = max(piles[i] + dp[i+2][j+1], piles[j] + dp[i+1][j]);
                else
                    dp[i+1][j+1] = min(-piles[i] + dp[i+2][j+1], -piles[j] + dp[i+1][j]);
            }

        return dp[1][N] > 0;
    }
};