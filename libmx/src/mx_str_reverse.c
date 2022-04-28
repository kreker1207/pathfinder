#include "../inc/libmx.h"

void mx_str_reverse(char *s) {
    if (!s) {
        return;
    }
	int length = mx_strlen(s) - 1;
    if (s) {
        for (int i = 0; i <= length / 2; i++) {
            mx_swap_char(&s[i], &s[length - i]);
		}
	}
}

