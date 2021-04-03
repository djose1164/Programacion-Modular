#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    for (int i = 0; i <= 100; i++)
    {
        fflush(stdout);
        if (i % 25 == 0)
            printf("Hackeando a la NASA %d%% completado.\r", i);
        else
            continue;
        sleep(1);
    }

    printf("La NASA fue hackeada satisfactoriamente.\n");

    return 0;
}
