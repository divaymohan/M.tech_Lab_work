#include <stdio.h>
#include <time.h>
#include <math.h>
void big_o_n();
void big_o_n_square();
void big_o_n_cube();
void exponential();
int main()
{
    //function to calculate the value of n using O(n) time
    big_o_n();
    big_o_n_square();
    big_o_n_cube();
    exponential();

    return 0;
}
void big_o_n()
{
    clock_t start, end;
    unsigned int n = 0;
    double sec = 0;
    start = clock();
    while (sec < 1)
    {
        n++;
        end = clock();
        sec = (double)(end - start) / CLOCKS_PER_SEC;
    }
    printf("Value of n with O(n) complexity in 1 second::  %u\n", n);
}
void big_o_n_square()
{
    clock_t start, end;
    unsigned int n = 0;
    double sec = 0;
    int sts = 0;
    start = clock();
    while (sec < 1)
    {
        for (int i = 0;; i++)
        {
            n++;
            for (int j = 0; j < i; j++)
            {
                end = clock();
                sec = (double)(end - start) / CLOCKS_PER_SEC;
                if (sec >= 1)
                {
                    sts = 1;
                    break;
                }
            }
            if (sts == 1)
            {
                break;
            }
        }
    }
    printf("Value of n with O(n^2) complexity in 1 second::  %u\n", n);
}
void big_o_n_cube()
{
    clock_t start, end;
    unsigned int n = 0;
    double sec = 0;
    int sts = 0;
    start = clock();
    while (sec < 1)
    {
        for (int i = 0;; i++)
        {
            n++;
            for (int j = 0; j < i; j++)
            {
                for (int k = 0; k < i; k++)
                {
                    end = clock();
                    sec = (double)(end - start) / CLOCKS_PER_SEC;
                    if (sec >= 1)
                    {
                        sts = 1;
                        break;
                    }
                }
                if (sts == 1)
                {
                    break;
                }
            }
            if (sts == 1)
            {
                break;
            }
        }
    }
    printf("Value of n with O(n^3) complexity in 1 second::  %u\n", n);
}
void exponential()
{
    clock_t start, end;
    unsigned int n = 0;
    double sec = 0;
    int sts = 0;
    start = clock();
    while (sec < 1)
    {
        for (int i = 0;; i++)
        {
            n++;
            for (int j = 0; j < pow(2, i); j++)
            {

                end = clock();
                sec = (double)(end - start) / CLOCKS_PER_SEC;
                if (sec >= 1)
                {
                    sts = 1;
                    break;
                }
            }
            if (sts == 1)
            {
                break;
            }
        }
    }
    printf("Value of n with O(2^n) complexity in 1 second::  %u\n", n);
}
