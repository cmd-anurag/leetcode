use std::cmp;
use std::collections::BTreeSet;

pub fn _minimum_cost(nums: Vec<i32>, k: i32, dist: i32) -> i64 {
    let n = nums.len();
    let k = k as usize;
    let dist = dist as usize;

    let mut k_min = BTreeSet::new();
    let mut remaining = BTreeSet::new();

    let mut sum: i64 = 0;
    let mut result = i64::MAX;

    let mut i: usize = 1;
    while i <= dist {
        k_min.insert((nums[i], i));
        sum += nums[i] as i64;

        if k_min.len() > k - 1 {
            if let Some(max) = k_min.pop_last() {
                sum -= max.0 as i64;
                remaining.insert(max);
            }
        }
        i += 1;
    }

    while i < n {
        k_min.insert((nums[i], i));
        sum += nums[i] as i64;

        if k_min.len() > k - 1 {
            if let Some(max) = k_min.pop_last() {
                sum -= max.0 as i64;
                remaining.insert(max);
            }
        }

        result = cmp::min(result, sum);

        let removed = (nums[i - dist], i - dist);

        if k_min.contains(&removed) {
            k_min.remove(&removed);
            sum -= removed.0 as i64;

            if remaining.len() > 0 {
                if let Some(temp) = remaining.pop_first() {
                    k_min.insert(temp);
                    sum += temp.0 as i64;
                }
            }
        } else {
            remaining.remove(&removed);
        }
        i += 1;
    }
    nums[0] as i64 + result
}

// translated from c++