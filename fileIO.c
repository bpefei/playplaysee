//
// Created by bpefei on 2020/5/26.
//

#include <string.h>
#include "fileIO.h"


FILE* open(const char* filename, unsigned int* nLines)
{
    FILE* fp;
    errno_t err;
    unsigned int cnt = 0;
    char tempC;
    err = fopen_s(&fp, filename, "r");
    if (!err)
    {
        while ((tempC = (char) fgetc(fp)) != EOF)
        {
            if (tempC == '\n')
                cnt++;
        }
        *nLines = cnt;
        rewind(fp);
    }
    return !err ? fp : null;
}


char* simplify(string str)
{
    char p[strlen(str)];
    bool flag = false;
    int j = 0;
    for (int i = 0; i < strlen(str); i++)
    {
        if (flag)
        {
            flag = false;
            continue;
        }
        if (str[i] == '-' && str[i + 1] == '>')
        {
            p[j++] = ' ';
            flag = true;
            continue;
        }
        if (str[i] == '|')
        {
            p[j++] = ' ';
            continue;
        }
        if (isspace_char(str[i]))
        {
            continue;
        }
        p[j++] = str[i];

    }
    p[j] = '\0';
    char* newstr = (char*) malloc(strlen(p));
    for (int k = 0; k < strlen(p); ++k)
    {
        newstr[k] = p[k];
    }
    newstr[strlen(p)] = '\0';
    return newstr;
}

Grammer getGrammer(const char* filename, int* nLs)
{
    char* p = (char*) malloc(100);
    unsigned int nLines;
    FILE* fp = open(filename, &nLines);
    *nLs = (int) nLines;
    char G[nLines + 1][10][10];
    // nLines+1条产生式，
    // 每条产生式最多10个单个产生式，
    // 每单个产生式最多10个字符
    for (int i = 0; i < nLines + 1; ++i)
    {
        for (int j = 0; j < 10; ++j)
        {
            for (int k = 0; k < 10; ++k)
            {
                G[i][j][k] = '\0';
            }
        }
    }
    int k = 0;
    for (int i = 0; i < nLines; ++i)
    {
        // G[i]是一行10个char*
        fgets(p, 100, fp);
        // 此时p中应该是一行产生式，如E -> aB | bA
        char* simpleString = simplify(p);
        // 按照上例，此时simpleString中是"E aB bA"
        for (int j = 0; j < 10; ++j)
        {
            // G[i][j]是一个char*
            for (int l = 0; k < strlen(simpleString); ++k, ++l)
            {
                // G[i][[j][k]是一个char
                if (simpleString[k] != ' ' && simpleString[k] != '\n')
                    G[i][j][l] = simpleString[k];
                else
                {
                    k++;
                    break;
                }

            }
        }
        k = 0;
    }
    Grammer newArray = (Grammer) malloc((nLines + 1) * sizeof(char**));
    for (int i = 0; i < nLines + 1; ++i)
    {
        newArray[i] = (char**) malloc(10 * sizeof(char*));
    }
    for (int i = 0; i < nLines + 1; ++i)
    {
        for (int j = 0; j < 10; ++j)
        {
            newArray[i][j] = (char*) malloc(10 * sizeof(char));
        }

    }
    for (int i = 0; i < nLines + 1; ++i)
    {
        for (int j = 0; j < 10; ++j)
        {
            for (int h = 0; h < 10; ++h)
            {
                newArray[i][j][h] = G[i][j][h];
            }
        }
    }
    return newArray;
}

void freeGrammer(Grammer waste, int nLs)
{
    for (int i = 0; i < nLs + 1; ++i)
    {
        for (int j = 0; j < 10; ++j)
        {
            free(waste[i][j]);
        }
        free(waste[i]);
    }
}