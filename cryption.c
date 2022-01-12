/*********************************
A program that prompts the user for
input, crypts, and encrypts text
using a 26 letter key.

Author: R.J.Eizvetins
*********************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    char text [256];
    printf("Text: ");
    fgets(text, sizeof(text), stdin);
    int size = strlen(text);
    encrypt(text, size);
    printf("Crypted text: ");
    for(int i = 0; i < strlen(text)- 1; i++){
        printf("%c", text[i]);
    }
    uncrypt(text, size);
    printf("\nUnrypted text: ");
    for(int i = 0; i < strlen(text)- 1; i++){
        printf("%c", text[i]);
    }
    return 0;
}

void encrypt(char * input, int size){
    int number;
    char key [] = "NQXPOMAFTRHLZGECYJIUWSKDVB";
    char small_key [] = "nqxpomaftrhlzgecyjiuwskdvb";

    for(int i = 0; i < strlen(input)- 1; i++){

        number = input[i];
        // upercase
        if(number >= 65 && number <= 90){
            number -= 65;
            input[i] = key[number];
        }
        // lowercase
        else if(number >= 97 && number <= 122){
            number -= 97;
            input[i] = small_key[number];
        }
    }
}



void uncrypt(char * input, int size){
    int number;
    char key [] = "NQXPOMAFTRHLZGECYJIUWSKDVB";
    char small_key [] = "nqxpomaftrhlzgecyjiuwskdvb";

    for(int i = 0; i < strlen(input)- 1; i++){
        number = input[i];
        for (int j = 0; j < strlen(key); j++){
            // upercase
            if(input[i] == key[j]){
                number = j + 65;
            }
            // lowercase
            else if(input[i] == small_key[j]){
                number = j + 97;
            }
        }
        input[i] = number;
    }
}
