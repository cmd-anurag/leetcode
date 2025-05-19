#include <vector>
#include <string>
using std::vector;
using std::string;

/**
 * @class Solution
 * @brief Determines the type of a triangle based on side lengths.
 *
 * This class provides a method to classify a triangle as "equilateral", "isosceles", 
 * "scalene", or "none" based on the lengths of its sides using the triangle inequality theorem.
 *
 * @see https://leetcode.com/problems/type-of-triangle/description/ Type of Triangle
 */
class Solution {
public:
    /**
     * @brief Determines the type of triangle from given side lengths.
     *
     * Given a vector of three integers representing the side lengths of a triangle,
     * this function first checks if the sides can form a valid triangle. If not, it returns "none".
     * Otherwise, it returns:
     * - "equilateral" if all three sides are equal,
     * - "isosceles" if any two sides are equal,
     * - "scalene" if all sides are different.
     *
     * @param nums A vector of exactly three integers representing triangle side lengths.
     * @return A string: "equilateral", "isosceles", "scalene", or "none".
     *
     * @see https://leetcode.com/problems/type-of-triangle/description/ Type of Triangle
     */
    string triangleType(vector<int>& nums) {
        int a = nums[0];
        int b = nums[1];
        int c = nums[2];

        if (a + b <= c || a + c <= b || b + c <= a) {
            return "none";
        }

        if (a == b && b == c) {
            return "equilateral";
        }
        else if (a == b || b == c || c == a) {
            return "isosceles";
        }
        else {
            return "scalene";
        }
    }
};