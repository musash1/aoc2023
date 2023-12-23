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

    fmt.Println(p1)

}

func part1(file string) float64 {
    result := 0.0
    games := strings.Split(file, "\n") 
    for _, line := range games {
       
        game := strings.Split(line, ":") 
        cards := strings.Split(game[len(game)-1], "|")
        luckyNums := strings.Split(cards[0], " ") 
        winningNums := strings.Split(cards[len(cards)-1], " ") 
        matchNums := []string{}

        for _, num := range winningNums {
            if slices.Contains(luckyNums, num) && num != "" {
                matchNums = append(matchNums, num)            
            }
        }

        if len(matchNums) == 0 {
            continue 
        }
        
        result += math.Pow(float64(2), float64(len(matchNums) - 1))
    }
        

    return result 
}
