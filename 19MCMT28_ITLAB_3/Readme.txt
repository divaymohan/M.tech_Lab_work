Assignment part 1:
Files:
    19mcmt28_IT_LAB_03.c contain the program for Quick Sort
    random.txt contains 10000 numbers in random order
    Descending.txt contains 10000 numbers in descending order
    Ascending.txt contains 10000 numbers in Ascending order
    output.txt file contains output analysis of quick sort on different Files

Commands:
    >gcc 19mcmt28_IT_LAB_03.c                                               
    >./a.out random.txt output.txt                                          
    >./a.out Descending.txt output.txt                                      
    >./a.out Ascending.txt output.txt                                       
Assignment part 2:
Files:
    19mcmt28_IT_LAB_03_2.c contains the program given in Assignment
Analysis:
The program will run in infinite loop because of this condition :  
    while ( A[i] < Pivot ) i++;
    while ( A[j] > Pivot ) j--­­;
    
    Here we are checking A[i] < pivot but in ideal case we should check for A[i] <= pivot here in first case the might never found the element less than pivot and go in infinite loop.

    :Same is the case with the condition A[j] > pivot. 
