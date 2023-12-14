#include <ctype.h>
#include <stdio.h>
#include <string.h>

int main() {
    FILE *fptr = fopen("text.txt", "r");
    char firstValue = '0';
    char lastValue = '0';
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

    printf("%d", calibrationValue);

    return 0;
}
