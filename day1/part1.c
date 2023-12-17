#include <ctype.h>
#include <stdio.h>
#include <string.h>

int part2(FILE* fptr) {
    const char *stringNums[9] = {"one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    const char *nums = "123456789\0";
    char firstValue = '0';
    char lastValue = '0';
    int calibrationValue = 0;
    char strNum[128];

    if (fptr != NULL) {
        char line [128];
        while (fgets(line, sizeof(line), fptr) != NULL) {
            int value;
            int x = 0;
            for (int i = 0; i < sizeof(line); i++) {
                if(isdigit(line[i])) {
                    for (int j = 0; j < sizeof(stringNums); j++) {
                        if (!strcmp(line, stringNums[0])) {
                            if (firstValue != '0') {
                                lastValue = nums[j];
                            } else {
                                firstValue = nums[j];
                                lastValue = nums[j];
                            }         
                        }
                    }
                    memset(strNum, 0, strlen(strNum));
                    if (firstValue != '0') {
                        lastValue = line[i];
                    } else {
                        firstValue = line[i];
                        lastValue = line[i];
                    } 
                } else {
                    strNum[x] = line[i]; 
                    x++;
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

    return calibrationValue;
}

int main() {
    FILE *fptr = fopen("test.txt", "r");
    char firstValue = '0';
    char lastValue = '0';
    int calibrationValue = 0;
    int calibrationValueP2 = part2(fptr);
/*
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
            printf("%d ", value);
            firstValue = '0';
            lastValue = '0';
            calibrationValue += value; 
            memset(&line[0], 0, sizeof(line));
        }
        fclose(fptr);
    } else {
        perror("test.txt");
    } 
*/
    printf("%d", calibrationValueP2);

    return 0;
}
