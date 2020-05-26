#include <stdio.h>
#include "fileIO.h"

int main()
{
    int cntLines;
    char*** grm = getGrammer("../G.txt", &cntLines);
    for (int i = 0; i < cntLines; ++i)
    {
        for (int j = 0; j < 10; ++j)
        {
            printf("%s", grm[i][j]);
            if (j < 9)
                printf(" ");
        }
        printf("\n");
    }
    freeGrammer(grm, cntLines);


}
//../是相对目录的当前目录