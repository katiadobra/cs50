/* CS50:         https://cs50.harvard.edu/x/2020/
 * Cash:         https://cs50.harvard.edu/x/2020/psets/1/cash/
 *
 * a program that first asks the user how much change is owed
 * and then prints the minimum number of coins
 * with which that change can be made.
 */

#include <cs50.h>
#include <stdio.h>
#include <math.h>

int main(void)
{
    int count = 0;
    float dollars;

    // geting a coins
    do
    {
        dollars = get_float("Change owed: ");
    } while (dollars < 0);

    // variables declaration for quarters, dimes, nickels, pennies;
    int cents = round(dollars * 100);
    int quarters = 25;
    int dimes = 10;
    int nickels = 5;
    int pennies = 1;

    // checking the number of cents until it is 0.
    do
    {
        for (int i = 0; i < cents; i++)
        {
            // at each step use the largest value coin possible
            //
            if (cents >= quarters)
            {
                cents = cents - quarters;
                count++;
            }
            else if (cents >= dimes)
            {
                cents = cents - dimes;
                count++;
            }
            else if (cents >= nickels)
            {
                cents = cents - nickels;
                count++;
            }
            else if (cents >= pennies)
            {
                cents = cents - pennies;
                count++;
            }
        }
    } while (cents != 0);

    // printing result
    printf("%i\n", count);
}
