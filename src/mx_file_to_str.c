#include "pathf.h"

char *mx_file_to_str(const char *filename) {
   int fl = open(filename, O_RDONLY);
    if (fl == -1) {
        close(fl);
        return NULL;
    }
    int size =0;
    char buf;
    for(int sz = read(fl,&buf,1);sz > 0; sz = read(fl, &buf, 1)) {
        size++;
    }
    close(fl);
int fd = open(filename, O_RDONLY);
    char *newstr = mx_strnew(size);
    read(fd, newstr, size);
    close(fd);
    return newstr;
}

