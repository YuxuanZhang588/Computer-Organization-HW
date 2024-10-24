/* Computes some simple statistics on values entered by the user.
 *
 * Time spent: 2 Hours
 *
 * Author(s): Yuxuan Zhang
*/


#include <stdio.h>
double input;
int numRead = 1;
double min;
double max;
double mean;
double variance;
double sum;
double varSum;
int count;

/* This function computes the minimum, maximum, mean, and variance
   of the numbers user entered.
*/

int main(){
    while(numRead != 0){
        count++;
        printf("Please enter a number: ");
        numRead = scanf("%lf", &input);

        if(numRead == 0){
            break;
        }

        if(count == 1){
            min = input;
            max = input;
        }

        sum += input;
        varSum += (input * input);

        if(min > input){
            min = input;
        }
        if(max < input){
            max = input;
        }
        mean = sum/count;
        variance = varSum/count - (mean*mean);
    }

    printf("Min: %.2f, Max: %.2f\n", min, max);
    printf("Mean: %.2f, Variance: %.2f\n", mean, variance);
}   
