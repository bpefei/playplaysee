//
// Created by bpefei on 2020/5/24.
//

#include <string.h>
#include "is_something.h"

bool isspace_char(char c)
{
    return c == ' ';
}

bool isspace_string(const char *string)
{
    int len = (int) strlen(string);
    if (len == 0)
        return false;
    int flag = true;
    for (int i = 0; i < len; ++i)
    {
        if (!isspace_char(string[i]))
        {
            flag = false;
            break;
        }
    }
    return flag;
}

bool is_ascii_number(char c)
{
    int num = (int)c;
    return num >= 0 && num <= 9;
}

bool blank_character_is_in_set(char* set)
{
    int len = (int)strlen(set);
    bool flag = false;
    for (int i = 0; i < len; ++i)
    {
        if (set[i] == '~')
        {
            flag = true;
            break;
        }
    }
    return flag;
}