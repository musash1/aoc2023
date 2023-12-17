#include <ctype.h>
#include <stdio.h>
#include <string.h>

int main() {
    const char *stringNums[9] = {"one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    FILE *fptr = fopen("test.txt", "r");
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
                        }
                    }
                }
            }
            value = (firstValue - '0') * 10 + (lastValue - '0');
            firstValue = '0';
            lastValue = '0';
            calibrationValue += value; 
            printf("%d ", value);
            memset(strNum, 0, strlen(strNum));
            memset(&line[0], 0, sizeof(line));
        }
    } else {
        perror("test.txt");
    } 
    printf("%d", calibrationValue);

    return calibrationValue;
}
