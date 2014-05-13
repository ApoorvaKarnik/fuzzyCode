#include <stdio.h>
#include <stdlib.h>

void count_bits()
{
    int num = 0;
    printf("Enter a number (32bit)\n");
    scanf("\n%d",&num);
    int copy_num = num;
    int count = 0;
    for (count =0; num; count++)
    {
        num = num & (num-1);
    }
    printf("Concept: `n = n & (n-1)` till n != 0 \n\
            number of iterations is the number of 1's\n\
            Mathematically any n-1 would make sure that \n\
            there the LSB 1 is made 0 and followed by all 1's\n\
            till 0th bit. Anding with such a number pops out \n\
            the lsb 1. This process is done untill the number is 0\n");
    printf ("\nThe number of 1's in the number(%d) were %d\n",
            copy_num, count);
    printf ("---------------------------------------\n");
}

void main()
{
    /* Write a case statement to select which hack it is 
     * */
    count_bits();
    return;
}
