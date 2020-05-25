#include <stdio.h>
#include "is_something.h"

int main()
{
    char G[6][6];
    for (int i = 0; i < 5; ++i)
    {
        for (int j = 0; j < 5; ++j)
        {
            G[i][j] = 'a';
        }
        G[i][5] = '\0';
    }
    for (int i = 0; i < 5; ++i)
    {
        G[5][i] = ' ';
    }
    G[5][5] = '\0';

    for (int i = 0; i < 6; ++i)
    {
        printf("%d\n", isspace_string(G[i]));
    }
    return 0;
}
