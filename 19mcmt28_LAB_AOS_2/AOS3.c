//https://www.tecmint.com/ps-command-examples-for-linux-process-monitoring/
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main()
{
    char *command = "ps -eo pid,ppid,cmd,%mem,%cpu --sort=-%mem > out.txt";
    system(command);
    return 0;
}
