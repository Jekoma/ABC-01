#ifndef __rnd__
#define __rnd__
#define N 21
#define SET "QWERTYUIOPASDFGHJKLZXCVBNMqwertyuiopasdfghjklzxcvbnm123456789,<>""'';:!(){}"
#include <stdlib.h> // для функций rand() и srand()


//------------------------------------------------------------------------------
// rnd.h - содержит генератор случайных строк длинной 20
//------------------------------------------------------------------------------

inline auto Random() {    
    char s[N];
    int i, set_len;
    set_len = strlen(SET);
    for (i = 0; i < N - 1; i++) 
    {        
        s[i] = SET[rand() % set_len];
    }        
    s[19] = '.';
    s[20] = '\0';
    return s;
}

#endif //__rnd__

