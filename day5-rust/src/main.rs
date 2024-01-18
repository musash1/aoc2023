use std::{fs, ops::Range};

fn main() {
    let content = fs::read_to_string("test.txt").expect("Couldn't read File");
    println!("{:?}", part1(content));
}

fn part1(content: String) -> u16 {
    let block: Vec<&str> = content.split("\n").collect();
    let seed_line: Vec<&str> = block[0].split(":").collect();
    let seeds_arr: Vec<&str> = seed_line[1].split(" ").collect(); 
    let mut seeds: Vec<u16> = seeds_arr.iter().map(|x| x.parse::<u16>().unwrap_or(0)).collect();
    seeds.remove(0);
    let mut next_seeds: Vec<u16> = seeds.clone(); 
    let mut temp_range: Range<u16> = 1..0;
    let mut temp_second_range: Range<u16> = 1..0;
    let mut ranges: Vec<Range<u16>> = vec![];
    let mut ranges_second: Vec<Range<u16>> = vec![];
    for line in block {
        if line.is_empty() {
            let mut i = 0;
            for seed in &seeds {
                let mut j = 0;
                for range in ranges {
                    if *seed == 0 || !temp_second_range.contains(seed) {
                        i += 1;
                        continue;
                    }
                    let second_ranges_temp = match ranges_second.get(j) {
                        Some(range1) => range1,
                        None => panic!() 
                    };
                    

                    let pos = *seed - second_ranges_temp.start;
                    next_seeds[i] = range.start + pos;
                    println!("{:?}, {:?}", range.start + pos, pos);
                    j += 1;
                }
                i += 1; 
            } 
            temp_range = 1..0;
            temp_second_range = 1..0;
            seeds = next_seeds.clone();
            continue;
        }
        if contains_num(line) {
            let nums: Vec<u16> = line.split(" ").map(|x| x.parse::<u16>().unwrap_or(0)).collect();

            let line_range = nums[0]..nums[0] + nums[2] - 1;
            let line_second_range = nums[1]..nums[1] + nums[2] - 1;

            if temp_range == (1..0) && temp_second_range == (1..0) {
                temp_range = line_range;
                temp_second_range = line_second_range;
            } else {
                if line_range.start < temp_range.start && line_second_range.start < temp_second_range.start {
                    ranges.push(line_range.start..temp_range.end);
                    ranges_second.push(line_second_range.start..temp_second_range.end);
                } else if line_range.start > temp_range.start && line_second_range.start > temp_second_range.start {
                    ranges.push(temp_range.start..line_range.end);
                    ranges_second.push(temp_second_range.start..line_second_range.end);
                } else if line_range.start > temp_range.start && line_second_range.start < temp_second_range.start {
                    ranges.push(temp_range.start..line_range.end);
                    ranges_second.push(line_second_range.start..temp_second_range.end);
                } else if line_range.start < temp_range.start && line_second_range.start > temp_second_range.start {
                    ranges.push(line_range.start..temp_range.end);
                    ranges_second.push(temp_second_range.start..line_second_range.end);
                }
            } 
        } 
    }
    println!("{:?}", &seeds);
    let min = seeds.iter().min(); 
    match min {
        Some(min) => *min,
        None => 0
    } 
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
