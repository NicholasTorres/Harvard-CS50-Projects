#include <stdio.h>
#include <cs50.h>

long cardnum_check(void);

int main (void)
{
    long cardnum = cardnum_check();
    long cardnum_temp = cardnum;
    long cardnum_temp2 = cardnum;
    bool skip_digit = false;
    int current_digit;
    int sum_of_products = 0;
    int length_of_cardnum = 0;
    long first_two_num = cardnum;
    long first_num = cardnum;

    while (cardnum_temp > 0)
    {
        current_digit = cardnum_temp % 10;

        if(skip_digit == true)
        {
            int product = current_digit * 2;
            // sum of products is the sum of the digits of the products not the sum of the products
            // Sum is product digit 1 plus product digit 2
            sum_of_products += product / 10 + product % 10;
        }
        else
        {
            sum_of_products += current_digit;
        }

        skip_digit = !skip_digit;
        cardnum_temp /= 10;
    }

    // Ameri 15 digits starts with 34 37
    // Master 16 digits starts with 51 52 53 54 55
    // Visa 13 OR 16 digits starts with 4
    while (first_two_num >= 100)
    {
        first_two_num /= 10;
    }
    while (first_num >= 10)
    {
        first_num /= 10;
    }
    while (cardnum_temp2 > 0)
    {
        cardnum_temp2 /= 10;
        length_of_cardnum++;
    }


    if (sum_of_products % 10 == 0)
    {
        if ((first_two_num == 34 || first_two_num == 37) && length_of_cardnum == 15)
        {
            printf("AMEX\n");
        }
        else if ((first_two_num == 51 || first_two_num == 52 || first_two_num == 53 || first_two_num == 54 || first_two_num == 55) && length_of_cardnum == 16)
        {
            printf("MASTERCARD\n");
        }
        else if (first_num == 4 && (length_of_cardnum == 13 || length_of_cardnum == 16))
        {
            printf("VISA\n");
        }
        else
        {
            printf("INVALID\n");
        }
    }
    else
    {
        printf("INVALID\n");
    }
}

long cardnum_check(void)
{
    long cardnum;
    cardnum = get_long("What's your credit card number? ");
    return cardnum;
}
