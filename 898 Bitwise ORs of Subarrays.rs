impl Solution {
    pub fn subarray_bitwise_o_rs(arr: Vec<i32>) -> i32 {
        use std::collections::HashSet;
        let mut result_set: HashSet<i32> = HashSet::new();
        let mut prev_set: HashSet<i32> = HashSet::new();
        let mut current_set: HashSet<i32> = HashSet::new();

        let mut current_or = 0;
        for &num in &arr {
            // Prepare the current set for the new number
            current_set.clear();

            // Add the current number to the current set
            current_set.insert(num);

            // Update the current set with the new ORs
            for &prev_or in &prev_set {
                current_set.insert(prev_or | num);
            }
            // Add the current ORs to the result set
            result_set.extend(&current_set);

            // Update the previous set for the next iteration
            prev_set = current_set.clone();
        }
        result_set.len() as i32
    }
}