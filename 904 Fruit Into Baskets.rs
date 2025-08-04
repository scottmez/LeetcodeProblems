impl Solution {
    pub fn total_fruit(fruits: Vec<i32>) -> i32 {
        let mut lru = fruits[0];
        let mut left = 0;
        let mut right = 1;
        while right < fruits.len() && fruits[right] == lru {
            right += 1;
        }
        if right == fruits.len() {
            return right as i32;
        }
        let mut mru = fruits[right];
        let mut mru_i = right;
        let mut lru_i = left;
        let mut max = right - left;
        while right < fruits.len() {
            if fruits[right] == lru {
                lru = mru;
                lru_i = mru_i;
                mru = fruits[right];
                mru_i = right;
            }
            else if fruits[right] != mru {
                max = max.max(right - left);
                lru = mru;
                lru_i = mru_i;
                mru = fruits[right];
                mru_i = right;
                left = lru_i;
            }
            right += 1;
        }
        return max.max(right - left) as i32;
    }
}