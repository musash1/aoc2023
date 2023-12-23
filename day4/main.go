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

func part2(file string) int {
    result := 0
    games := strings.Split(file, "\n") 
    realGames := []string{}
    nums := []int{}
    for _, line := range games {
        if line != "" {
            realGames = append(realGames, line)
        }
    }
    for line := range realGames {
        line = line
        nums = append(nums, 1) 
    } 
    for idx, line := range realGames {
        j := 0
        for j < nums[idx] {
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
            
            i := 0 
            if (matchNums > 0) {
                for i < matchNums {
                    nums[idx + i + 1] += 1
                    i++
                }
            }
            j++
        }
    }

    for _, val := range nums {
        result += val
    }

    return result 
}
