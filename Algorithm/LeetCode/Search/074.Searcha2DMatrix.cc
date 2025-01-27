/* Medium
Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:
Integers in each row are sorted from left to right.
The first integer of each row is greater than the last integer of the previous row.


Example 1:
Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 3
Output: true

Example 2:
Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 13
Output: false

Constraints:
m == matrix.length
n == matrix[i].length
1 <= m, n <= 100
-10^4 <= matrix[i][j], target <= 10^4 */

#include <vector>

using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.empty()) {
            return false;
        }
        
        auto rowSize = matrix.size();
        auto colSize = matrix[0].size();
        int beg = 0;
        int end = rowSize * colSize - 1;
        
        while (beg <= end) {
            auto pivot = beg + (end - beg) / 2;
            auto mid = matrix[pivot/colSize][pivot%colSize];
            
            if (mid == target) {
                return true;
            } else if (mid < target) {
                beg = pivot + 1;
            } else {
                end = pivot - 1;
            }
        }
        
        return false;
    }
};