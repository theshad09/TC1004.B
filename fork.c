#include <stdio.h>
#include <unistd.h>
int main()
{
    while(1)
    {
    int pid= fork();
    if(pid==0)
    {
        printf("Soy el proceso hijo; pid= %d\n",pid);
    }
    else
    {
        printf("Soy el proceso padre ; pid= %d\n",pid);
    }
    }
    return 0;
}