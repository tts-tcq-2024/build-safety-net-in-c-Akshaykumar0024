#ifndef SOUNDEX_H
#define SOUNDEX_H

#include "Soundex.h"
#include <ctype.h>
#include <string.h>

    static const char soundexTable[26] = {
        '0', // A
        '1', // B
        '2', // C
        '3', // D
        '0', // E
        '1', // F
        '2', // G
        '0', // H
        '0', // I
        '2', // J
        '2', // K
        '4', // L
        '5', // M
        '5', // N
        '0', // O
        '1', // P
        '2', // Q
        '6', // R
        '2', // S
        '3', // T
        '0', // U
        '1', // V
        '0', // W
        '2', // X
        '0', // Y
        '2'  // Z
    };

char getSoundexCode(char c) {
    c = toupper(c);
if (c >= 'A' && c <= 'Z')
   return soundexTable[c-'A'];
}
int processNameCharacters(const char *name,int sIndex,char *soundex)
{
    int len = strlen(name);
    soundex[0] = toupper(name[0]);
       for (int i = 1; i < len && sIndex < 4; i++) {
        char code = getSoundexCode(name[i]);
        if (code != '0' && code != soundex[sIndex - 1]) {
            soundex[sIndex++] = code;
        }
    }
    return sIndex;
}

void generateSoundex(const char *name, char *soundex) {
    int sIndex = 1;
    sIndex = processNameCharacters(name,soundex,sIndex);
 
    while (sIndex < 4) {
        soundex[sIndex++] = '0';
    }

    soundex[4] = '\0';
}

#endif // SOUNDEX_H
