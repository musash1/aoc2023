package main

import (
	"fmt"
	"log"
	"math"
	"os"
	"slices"
	"strings"
)

func main() {
    file, err := os.ReadFile("text.txt") 
    if err != nil {
        log.Fatal(err)
    }

    p1 := part1(string(file))
    p2 := part2(string(file))

    fmt.Println(p1)
    fmt.Println(p2)
}

func part1(file string) float64 {
    result := 0.0
    games := strings.Split(file, "\n") 
    for _, line := range games {
        game := strings.Split(line, ":") 
        cards := strings.Split(game[len(game)-1], "|")
        luckyNums := strings.Split(cards[0], " ") 
        winningNums := strings.Split(cards[len(cards)-1], " ") 
        matchNums := 0 

        for _, num := range winningNums {
            if slices.Contains(luckyNums, num) && num != "" {
                matchNums += 1            
            }
        }

        if matchNums == 0 {
            continue 
        }
        
        result += math.Pow(float64(2), float64(matchNums - 1))
    }
        
    return result 
}


// TODO: fix performance -> Instead of nested for loops, one for loop, create hash table and then calculate the sum with the 
// matches.
func part2(file string) int {
    games := strings.Split(file, "\n") 
    realGames := []string{}
    nums := []int{}
    matchNumbers := []int{}
    for _, line := range games {
        if line != "" {
            realGames = append(realGames, line)
        }
    }
    for line := range realGames {
        line = line
        nums = append(nums, 1) 
    } 
    for line := range realGames {
        line = line
        matchNumbers = append(matchNumbers, 0) 
    }
    for idx, line := range realGames {
        game := strings.Split(line, ":") 
        cards := strings.Split(game[len(game)-1], "|")
        luckyNums := strings.Split(cards[0], " ") 
        winningNums := strings.Split(cards[len(cards)-1], " ") 

        for _, num := range winningNums {
            if slices.Contains(luckyNums, num) && num != "" {
                matchNumbers[idx] += 1
            }
        }
        for j := range nums[idx] {
            j = j 
            for i := range matchNumbers[idx] {
                nums[idx + i + 1] += 1
            }
        }
    }

    sum := 0
    for _, x := range nums {
        sum += x
    }

    return sum 
}

