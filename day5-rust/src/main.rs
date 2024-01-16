use std::{fs, ops::Range, usize};

fn main() {
    let content = fs::read_to_string("test.txt").expect("Couldn't read File");
    println!("{:?}", part1(content));
}

fn part1(content: String) -> usize {
    let blocks: Vec<&str> = content.split("\n").collect();
    let seed_line: Vec<&str> = blocks[0].split(":").collect();
    let seeds_arr: Vec<&str> = seed_line[1].split(" ").collect(); 
    let seeds: Vec<u16> = seeds_arr.iter().map(|x| x.parse::<u16>().unwrap_or(0)).collect();
    println!("{:?}", seeds);
    let mut range: Range<usize>;
    for block in blocks {
        if contains_num(block) {
            println!("{:?}", block);
        } 
    }
    0
}

fn contains_num(str: &str) -> bool {
    if str.is_empty() { return true }; 
    for c in str.chars() {
        if c.is_numeric() {
            return true;
        }
    }
    return false;
}
