#include "pathf.h"
void mx_printerr_ae(char **text_arr){
	for(char **line = (char**)text_arr; *line != NULL; line++)
		mx_printerr(*line);
	exit(0);
}
