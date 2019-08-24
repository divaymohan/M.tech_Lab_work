There are two program files:
1.generate_Numbers.c [to generate random numbers in a file]
    *Command to run this file:

        >gcc generate_Numbers.c 
        >./a.out #numbers filename.txt 

        #number::How many numbers you want to generate ;
        filename.txt in which file these no you want to write
2.bubble_Insertion_comparison.c
    *Command to run this file:
        
        >gcc bubble_Insertion_comparison.
        >./a.out input.txt output.txt

        input.txt contains the numbers
        output.txt is output file in which running time of insertion and bubble will store
all commands:
>gcc generate_Numbers.c
>./a.out 1000 random_1000.txt
>./a.out 2000 random_2000.txt
>./a.out 3000 random_3000.txt
>./a.out 4000 random_4000.txt
>./a.out 5000 random_5000.txt
>./a.out 6000 random_6000.txt
>./a.out 7000 random_7000.txt
>./a.out 8000 random_8000.txt
>./a.out 9000 random_9000.txt
>./a.out 10000 random_10000.txt
>sort random_1000.txt > asc_1000.txt
>sort random_2000.txt > asc_2000.txt
>sort random_3000.txt > asc_3000.txt
>sort random_4000.txt > asc_4000.txt
>sort random_5000.txt > asc_5000.txt
>sort random_6000.txt > asc_6000.txt
>sort random_7000.txt > asc_7000.txt
>sort random_8000.txt > asc_8000.txt
>sort random_9000.txt > asc_9000.txt
>sort random_10000.txt > asc_10000.txt
>sort -r random_1000.txt > dsc_1000.txt
>sort -r random_2000.txt > dsc_2000.txt
>sort -r random_3000.txt > dsc_3000.txt
>sort -r random_4000.txt > dsc_4000.txt
>sort -r random_5000.txt > dsc_5000.txt
>sort -r random_6000.txt > dsc_6000.txt
>sort -r random_7000.txt > dsc_7000.txt
>sort -r random_8000.txt > dsc_8000.txt
>sort -r random_9000.txt > dsc_9000.txt
>sort -r random_10000.txt > dsc_10000.txt
>gcc bubble_Insertion_comparison.c
>./a.out random_1000.txt output_in.txt
>./a.out random_2000.txt output_in.txt
>./a.out random_3000.txt output_in.txt
>./a.out random_4000.txt output_in.txt
>./a.out random_5000.txt output_in.txt
>./a.out random_6000.txt output_in.txt
>./a.out random_7000.txt output_in.txt
>./a.out random_8000.txt output_in.txt
>./a.out random_9000.txt output_in.txt
>./a.out random_10000.txt output_in.txt
>./a.out asc_1000.txt output_Asc.txt
>./a.out asc_2000.txt output_Asc.txt
>./a.out asc_3000.txt output_Asc.txt
>./a.out asc_4000.txt output_Asc.txt
>./a.out asc_5000.txt output_Asc.txt
>./a.out asc_6000.txt output_Asc.txt
>./a.out asc_7000.txt output_Asc.txt
>./a.out asc_8000.txt output_Asc.txt
>./a.out asc_9000.txt output_Asc.txt
>./a.out asc_10000.txt output_Asc.txt
>./a.out dsc_1000.txt output_Dsc.txt
>./a.out dsc_2000.txt output_Dsc.txt
>./a.out dsc_3000.txt output_Dsc.txt
>./a.out dsc_4000.txt output_Dsc.txt
>./a.out dsc_5000.txt output_Dsc.txt
>./a.out dsc_6000.txt output_Dsc.txt
>./a.out dsc_7000.txt output_Dsc.txt
>./a.out dsc_8000.txt output_Dsc.txt
>./a.out dsc_9000.txt output_Dsc.txt
>./a.out dsc_10000.txt output_Dsc.txt

after these commands just run the compareComplexities.ibynb file on jupyter notebook to see full analysis

files:
    output_Asc.txt : contains time taken by bubble sort and insertion sort with the size of input on Ascending order data.
    output_Dsc.txt : contains time taken by bubble sort and insertion sort with the size of input on Descending order data.
    output_in.txt : contains time taken by bubble sort and insertion sort with the size of input on random order data.

OR just see the compareComplexities.pdf file to see whole analysis.
