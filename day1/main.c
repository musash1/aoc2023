#include <ctype.h>
#include <stdio.h>
#include <string.h>

int part1() {
    char firstValue = '0';
    char lastValue = '0';
    FILE *fptr = fopen("text.txt", "r");
    int calibrationValue = 0;
    if (fptr != NULL) {
        char line [128];
        while (fgets(line, sizeof(line), fptr) != NULL) {
            int value;
            for (int i = 0; i < sizeof(line); i++) {
                if(isdigit(line[i])) {
                    if (firstValue != '0') {
                        lastValue = line[i];
                    } else {
                        firstValue = line[i];
                        lastValue = line[i];
                    } 
                }
            }
            value = (firstValue - '0') * 10 + (lastValue - '0');
            firstValue = '0';
            lastValue = '0';
            calibrationValue += value; 
            memset(&line[0], 0, sizeof(line));
        }
    } else {
        perror("test.txt");
    } 
    fclose(fptr);

    return calibrationValue;
}

int part2() {
    const char *stringNums[9] = {"one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    FILE *fptr = fopen("text.txt", "r");
    const char *nums = "123456789\0";
    char firstValue = '0';
    char lastValue = '0';
    int calibrationValue = 0;
    char strNum[128];

    if (fptr != NULL) {
        char line[128];
        while (fgets(line, sizeof(line), fptr) != NULL) {
            int value;
            int x = 0;
            for (int i = 0; i < sizeof(line); i++) {
                strNum[x] = line[i]; 
                x++;
                if(isdigit(line[i])) {
                    memset(strNum, 0, strlen(strNum));
                    x = 0;
                   if (firstValue != '0') {
                        lastValue = line[i];
                    } else {
                        firstValue = line[i];
                        lastValue = line[i];
                    } 
                } else {
                    for (int j = 0; j < 9; j++) {
                        if (strstr(strNum, stringNums[j]) != NULL) { 
                            if (firstValue != '0') {
                                lastValue = nums[j];
                            } else {
                                firstValue = nums[j];
                                lastValue = nums[j];
                            }
                            memset(strNum, 0, strlen(strNum));
                            x = 1;
                            strNum[0] = line[i];
                            printf("%c", strNum[x]);
                        }
                    }
                }
            }
            value = (firstValue - '0') * 10 + (lastValue - '0');
            firstValue = '0';
            lastValue = '0';
            calibrationValue += value; 
            memset(strNum, 0, strlen(strNum));
            memset(&line[0], 0, sizeof(line));
            x = 0;
        }
    } else {
        perror("test.txt");
    } 
    fclose(fptr);

    return calibrationValue;
}

int main() {
    int returnValueP1 = part1();
    int returnValueP2 = part2();
    printf("Part1: %d\nPart2: %d", returnValueP1, returnValueP2);
    

    return 0;
}
