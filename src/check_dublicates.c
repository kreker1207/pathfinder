#include "pathf.h"

bool pf_haveduplicates(FileInfo *data){
	for(int i = 0; i < data->bridges_num - 1; i++)
		if(
			mx_strcmp(data->bridges[i]->left, data->bridges[i + 1]->left) == 0
			&&
			mx_strcmp(data->bridges[i]->right, data->bridges[i + 1]->right) == 0
			)
			return true;
	return false;
}

