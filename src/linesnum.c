#include "pathf.h"
int linesnum(const char *file) {
    int count = 0;;
    for(int i = 0; file[i] != '\0'; i++){
        if(file[i] == '\n'){
            count++;
        }
        if(file[i+1] == '\0' && file[i] !='\n'){
            count++;
        }
    }
    return count;
}


