#include <cs50.h>
#include <stdio.h>
#include <math.h>

void check_valid(long card);
int check_sum(long card, int ndig);
double power(int base, long exp);
int add_digits(int number);

int main(void)
{
    long card = get_long("Credit card number:");
    check_valid(card);
}

void check_valid(long card)
{        
    // check if the card it 15-digit AMEX starting with 34 or 37,
    //  13 or 16-digit Visa starting with 4,
    // or 16-digit Master starting with 51, 52, 53, 54, or 55
    int ndig = log10(card) + 1;
    
    // check sum and print invalid if so
    if(ndig == 13 || ndig == 15 || ndig == 16){
        
        // check if satisfies Luhn's algorithm
        int zero = check_sum(card, ndig);
 
        if(zero != 0){
            printf("INVALID\n");
        } else {
            // get first and first2 digits of card
            int first2 = card/power(10, ndig-2);
            int first1 = card/power(10, ndig-1);

            if(first2 == 34 || first2 == 37){
                printf("AMEX\n");
            } else if(first2 > 50 && first2 < 56){
                printf("MASTERCARD\n");
            } else if(first1 == 4){
                printf("VISA\n");
            } else {
                printf("INVALID\n");
            }
        }
    } else{
        printf("INVALID\n");
    }
}

// raising to an exponent
double power(int base, long exp) {
    double i, result = 1;
    for (i = 0; i < exp; i++)
        result *= base;
    return result;
 }

// add the digits of a number together
int add_digits(int number){
    double n_digit = log10(number) + 1;
    int sum = 0;
    for(double i = n_digit; i>0; i--){
        // get the first i digits
        // pick the last of those
        long pre_digit = number/power(10,n_digit-i);
        int digit = pre_digit % 10;
        sum = sum + digit;
    }
    return sum;
}

// Luhn's algorithm
int check_sum(long card, int ndig){
 
    int every_other = 2;
    int sum = 0;
    int sum_others = 0;
    long digit;
    
    for(int i = ndig-1; i>0; i--){
        
        // get the first i digits
        // pick the last of those
        long pre_digit = card/power(10,ndig-i);
        digit = pre_digit % 10;
        
        if(every_other % 2 == 0){
            int product = 2*digit;
            sum = sum + add_digits(product);
        } else{
            sum_others = sum_others + digit;
        }
        every_other ++;
    }
    
    // add the last digit to sum_others since it was not in the loop
    sum_others = sum_others + (card % 10);
    
    // add the sum's digits
    int sum_sum = add_digits(sum);
    // add it to the sum_other
    int final_sum = sum_sum + sum_others;
    
    // get the last digit of this sum
    int last_digit = final_sum % 10;
    return last_digit;
}
