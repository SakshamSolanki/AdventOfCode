#include <stdio.h>
#include <stdlib.h>

int compareString(char* str, char cpmStr[]){
    for(int i = 0; cpmStr[i] != '\0'; i++){
        if(*(str + i) != cpmStr[i]) return -1;
    }
    return 0;
}

int getCalibrationValues(char str[]){
    int firstDigit = -1;
    int lastDigit = -1;

    char *numbers[] = {"one" , "two" , "three" , "four" , "five" , "six" , "seven" , "eight" , "nine"};

    for(int i = 0; str[i] != '\0'; i++){
        
        if(str[i] >= '1' && str[i] <= '9'){
            if(firstDigit == -1) {
                firstDigit = (int)str[i] - 48;
                lastDigit = (int)str[i] - 48;
            }else{
                lastDigit = (int)str[i] - 48;
            }
        }

        for(int j = 0; j < 9; j++){
            if(!compareString(&str[i] , numbers[j])){
                if(firstDigit == -1) {
                    firstDigit = j + 1;
                    lastDigit = j + 1;
                }else{
                    lastDigit = j + 1;
                }
            }
        }

    }
    return firstDigit * 10 + lastDigit;
}

int getCalibrationSum(char inputFile[]){

    FILE *fh;
    int sum = 0;

    fh = fopen(inputFile, "r");
    char buffer[255];

    if(fh != NULL){
        while(fgets(buffer, 255 , fh) != NULL){
            sum += getCalibrationValues(buffer);
        }
    }else{
        printf("Error opening file\n");
        return -1;
    }

    return sum;
}

int main(){

    printf("%d\n" , getCalibrationSum("input.txt"));
    return 0;
}