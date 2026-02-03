pub fn _is_trionic(nums: Vec<i32>) -> bool {
        let n = nums.len();

        let mut a = false; // increasing
        let mut b = false; // decreasing
        let mut c = false; // increasing
        
        let mut i: usize = 0;

        while i < n-1 {
            if nums[i] >= nums[i+1] {
                break;
            }
            i += 1;
            a = true;
        }
        while i < n-1 {
            if nums[i] <= nums[i+1] {
                break;
            }
            i += 1;
            b = true;
        }
        while i < n-1 {
            if nums[i] >= nums[i+1] {
                break;
            }
            i += 1;
            c = true;
        }

        i == n-1 && a && b && c
    }