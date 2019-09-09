#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main()
{
    printf("Process Id: %d\n", getpid());
    char *args[] = {"./child", NULL};
    execvp(args[0], args);
    return 0;
}
