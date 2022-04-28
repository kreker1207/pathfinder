#include "pathf.h"

int mx_get_last_char_index(const char *str, char c) {
    if (str == NULL) return -2;
    for (int i = mx_strlen(str) - 1; i >= 0; i--) {
        if (str[i] == c) return i;
    }
    return -1;
}

void mx_check_str(char *str, int line_num) {
    int index = mx_get_last_char_index(str, '-');
    if(index <= 0) {
        mx_printerr("error: line ");
        mx_printerr(mx_itoa(line_num));
        mx_printerr(" is not valid\n");
        exit(0);
    }
    for(int i = 0; i < index; i++) {
        if(!mx_isalpha(*str)) {
            mx_printerr("error: line ");
            mx_printerr(mx_itoa(line_num));
            mx_printerr(" is not valid\n");
            exit(0);
        }
        str++;
    }
    str++;

    index = mx_get_last_char_index(str, ',');
    if(index <= 0) {
        mx_printerr("error: line ");
        mx_printerr(mx_itoa(line_num));
        mx_printerr(" is not valid\n");
        exit(0);
    }
    for(int i = 0; i < index; i++) {
        if(!mx_isalpha(*str)) {
            mx_printerr("error: line ");
            mx_printerr(mx_itoa(line_num));
            mx_printerr(" is not valid\n");
            exit(0);
        }
        str++;
    }
    str++;

    for(; *str != '\0'; str++) {
        if(!mx_isdigit(*str)) {
            mx_printerr("error: line ");
            mx_printerr(mx_itoa(line_num));
            mx_printerr(" is not valid\n");
            exit(0);
        }
    }
}


