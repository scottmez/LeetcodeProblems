impl Solution {
    pub fn num_of_unplaced_fruits(fruits: Vec<i32>, baskets: Vec<i32>) -> i32 {
        let mut baskets_copy = baskets.clone();
        let mut count = fruits.len() as i32;
        for fruit in fruits {
            for basket in &mut baskets_copy {
                if *basket >= fruit {
                    count -= 1;
                    *basket = 0; // Mark this basket as used
                    break;
                }
            }
        }

        count
    }
}