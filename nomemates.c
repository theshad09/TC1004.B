#include <stdio.h>
#include <signal.h>
#include <unistd.h>

void handleTerm(int signal)
{
    printf("Recibi segnal %d\n",signal);
}
int main ()
{
    signal(2,handleTerm);
    while(1)
    {
        printf("Trabajando\n");
        sleep(1);
    }
    return 0;
}