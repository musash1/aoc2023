use std::fs;

fn main() {
    let input = fs::read("test.txt");
    println!("{:?}", input);
}
