#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
int main()
{
    //      printf("%d\n",getpid());
    fork();
    printf("Parent id: %d\n", getpid());
    printf("Child Process Id with Parent id: %d\n", getppid());
    printf("hello world..!!\n");
    return 0;
}
