/* Medium
Given a circular integer array nums (i.e., the next element of nums[nums.length - 1] is nums[0]),
return the next greater number for every element in nums.

The next greater number of a number x is the first greater number to its traversing-order next in the array,
which means you could search circularly to find its next greater number.
If it doesn't exist, return -1 for this number.



Example 1:
Input: nums = [1,2,1]
Output: [2,-1,2]
Explanation: The first 1's next greater number is 2;
The number 2 can't find next greater number.
The second 1's next greater number needs to search circularly, which is also 2.

Example 2:
Input: nums = [1,2,3,4,3]
Output: [2,3,4,-1,4]


Constraints:
1 <= nums.length <= 10^4
-109 <= nums[i] <= 10^9

Relatives:
316. Remove Duplicate Letters
496. Next Greater Element I
503. Next Greater Element II
556. Next Greater Element III
739. Daily Temperatures */

#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        const auto size = nums.size();
        stack<int> stk;
        vector<int> result(size);

        for (int i = 2 * size - 1; i >= 0; --i) {
            const auto idx = i % size;

            while (!stk.empty() && stk.top() <= nums[idx]) {
                stk.pop();
            }
            result[idx] = stk.empty() ? -1 : stk.top();
            stk.emplace(nums[idx]);
        }

        return result;
    }
};