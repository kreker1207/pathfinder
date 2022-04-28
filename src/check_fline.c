#include "pathf.h"

bool check_fline(const char *s) {
bool fline = true;
for(int i = 0; s[i] != '\n'; i++) {
    if(s[i]>='0' && s[i]<='9') {
        fline = true;
    }
    else {
        return false;
    }
}
return true;
}





