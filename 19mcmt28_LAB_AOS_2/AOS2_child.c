#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
int main()
{
    printf("Parent id: %d\n", getpid());
    printf("i am from child process created by execv()..!!\n");
    return 0;
}
