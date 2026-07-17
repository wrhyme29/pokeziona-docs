#ifndef GUARD_UTILITIES_H
#define GUARD_UTILITIES_H

#include <ctype.h>
#include "types_aliases.h"

#define TRUE  1
#define FALSE 0
#define min(a, b) ((a) < (b) ? (a) : (b))
#define max(a, b) ((a) >= (b) ? (a) : (b))
#define _(x)        {x}
#define ARRAY_COUNT(array) (size_t)(sizeof(array) / sizeof((array)[0]))
#define CAT(a, b) CAT_(a, b)
#define CAT_(a, b) a ## b

void capitalizeString(u8* str)
{
    u8 capNext = FALSE;
    for(int i = 1; str[i]; i++) {
        if(!capNext)
        {
            str[i] = tolower(str[i]);
        } else
        {
            capNext = FALSE;
        }
        if (isspace(str[i]) || str[i] == '-') capNext = TRUE;
    }
}

#endif // GUARD_UTILITIES_H
