#include <stdio.h>
#include <time.h>

int main()
    {
    clock_t begin;
    double time_spent;
    unsigned int i;

    /* Mark beginning time */
    begin = clock();
    for (i=0;1;i++)
        {
        printf("hello\n");
        /* Get CPU time since loop started */
        time_spent = (double)(clock() - begin) / CLOCKS_PER_SEC;
        if (time_spent>=5.0)
            break;
        }
    /* i could conceivably overflow */
    printf("Number of iterations completed in 5 CPU(?) seconds = %d.\n",i);
    return(0);
    }