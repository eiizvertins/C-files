/******************************************************
Program that prompts the user for a credit card number
and then returns whether it is a valid American Express,
MasterCard, or Visa card number using Luhn’s Algorithm.
// Author: R.J.Eizvertins
******************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


bool luhns_algorithm(long long c, int count);
int digit_count(long long card_number);
int print_card_brand(long long card_number, int count);


int main()
{
    int result;
    long long number;
    // Prompting credit card number for user input
    printf("Enter your card number: ");
    scanf("%lld", &number);

    // Function returns digit count for credit card
    int count =  digit_count(number);

    // Function check if credit card is valid
    bool valid = luhns_algorithm(number, count);

    if (valid == true){
        // Function prints brand and returns
        result = print_card_brand(number, count);
    }
    else{
        printf("INVALID\n");
        return 1;
    }

    if (result == 0){
        printf("INVALID\n");
        return 2;
    }

    return 0;
}

/*
Luhn’s Algorithm
Determines if a credit card number is valid.
1. Multiplying every other digit by 2, starting with the
number’s second-to-last digit, and then add those products’
digits together.
2. Adding the sum to the sum of the digits that weren’t multiplied by 2.
3. If the total modulo 10 is congruent to 0 the number is valid!
*/
bool luhns_algorithm(long long c, int count){
    int num, y;
    int sum = 0;
    // Loop for every digit in ccredit card
    for(int i = 1; i < count + 1; i++){
        num = c % 10;
        // Summing digits, that weren't multiplied
        if(i % 2 == 1){
            sum += num;
        }
        // Multiplying and adding digits to sum.
        else {
            y = num*2;
            if (y > 9){
                y %= 10;
                sum += y + 1;
            }
            else{
                sum += y;
            }
        }
        c = (c - num) / 10;
    }
    // Checking if card is valid
    if (sum % 10 == 0){
        return true;
    }
    else {
        return false;
    }
}

// Returns digit count of card number
int digit_count(long long card_number){
    long long n = card_number;
    int count = 0;
    do{
        n /= 10;
        count++;
    } while (n != 0);
    return count;
}

// Checks starting digits to print brand
int print_card_brand(long long card_number, int count){
    long long i = card_number;
    while(i >= 100){
        i /= 10;
    }
        if (count == 15 || count == 16){
            // AMERICAN EXPRESS
            if (i == 34 || i == 37){
                printf("AMEX\n");
                return 1;
            }
            // MASTERCARD
            if (i >= 51 && i <= 55){
                printf("MASTERCARD\n");
                return 1;
            }
        }
        // VISA
        if (count == 13 || count == 16){
            if (i / 10 == 4){
                printf("VISA\n");
                return 1;
            }
        }
    // If returns zero cards isn't one of brands
    return 0;
}
