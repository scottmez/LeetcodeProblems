impl Solution {
    pub fn generate(num_rows: i32) -> Vec<Vec<i32>> {
        let mut triangle = vec![vec![1]];
        for i in 1..num_rows as usize {  //last number exclusive // i is usize type
            let mut row = vec![1; i+1];
            for j in 1..i { //last number exclusive
                row[j] = triangle[i - 1][j - 1] + triangle[i - 1][j];
            }
            triangle.push(row);
        }
        triangle
    }
}