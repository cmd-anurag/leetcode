use std::cmp;

pub fn _minimum_cost(nums: Vec<i32>) -> i32 {
    let n = nums.len();
    let mut result = i32::MAX;

    for i in 1..n - 1 {
        let mut cost = 0;
        cost += nums[0];
        cost += nums[i];

        for j in i + 1..n {
            cost += nums[j];
            result = cmp::min(result, cost);
            cost -= nums[j];
        }
    }

    result
}
