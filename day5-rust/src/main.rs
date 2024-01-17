use std::{fs, ops::Range, usize};

fn main() {
    let content = fs::read_to_string("test.txt").expect("Couldn't read File");
    println!("{:?}", part1(content));
}

fn part1(content: String) -> usize {
    let block: Vec<&str> = content.split("\n").collect();
    let seed_line: Vec<&str> = block[0].split(":").collect();
    let seeds_arr: Vec<&str> = seed_line[1].split(" ").collect(); 
    let mut seeds: Vec<u16> = seeds_arr.iter().map(|x| x.parse::<u16>().unwrap_or(0)).collect();
    println!("{:?}", seeds);
    let mut temp_range: Range<u16> = 1..0;
    let mut temp_second_range: Range<u16> = 1..0;
    let mut range: Range<usize>;
    for line in block {
        if line.is_empty() {
            temp_range = 1..0;
            temp_second_range = 1..0;
            continue;
        }
        if contains_num(line) {
            let nums: Vec<u16> = line.split(" ").map(|x| x.parse::<u16>().unwrap_or(0)).collect();
            let range_start = nums[0];
            let range_value = nums[1];
            let range_length = nums[2];

            if temp_range == (1..0) && temp_second_range == (1..0) {
                temp_range = range_start..range_start + range_length - 1;
                temp_second_range = range_value..range_value + range_length - 1;
            } 

        } 
    }
    0
}

fn contains_num(str: &str) -> bool {
    if str.contains("seeds") { return false; }
    for c in str.chars() {
        if c.is_numeric() {
            return true;
        }
    }
    return false;
}
