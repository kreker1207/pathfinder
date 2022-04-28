#include "pathf.h"

FileInfo *pf_parse(char *text){
	char **lines = mx_strsplit(text, '\n');
	int count = 0;
	for(int i = 0; lines[i] != NULL; i++)
		count++;
	int offset = 0;
	for(int i = count - 1; mx_strlen(lines[i]) == 0 && i >= 0; i--)
		offset++;
	lines[count - offset] = NULL;
	

	int line_num = mx_atoi(lines[0]);
	
	// Bridge count
	int bridge_num = 0;
	for(int i = 1; lines[i] != NULL; i++)
		bridge_num++;
	
	// FileInfo init
	FileInfo *data = malloc(sizeof(FileInfo));
	
	data->bridges = malloc(sizeof(Bridge *) * bridge_num);
	for(int i = 0; i < bridge_num; i++)
		data->bridges[i] = malloc(sizeof(Bridge));
	data->bridges_num = bridge_num;
	
	data->islands = malloc(sizeof(char*) * 0);
	data->island_num = 0;
	
	// Parsing bridges to FileInfo
	int invalid_line = -1;
	for(int i = 0; i < bridge_num; i++){
		
		// Split and check left side
		char **exp = mx_strsplit(lines[i + 1], '-');
		int exp_count = 0;
		for(char **j = exp; *j != NULL; j++)
			exp_count++;
		if(exp_count != 2){
			invalid_line = i + 2;
			break;
		}
		char *left = exp[0];
		
		// Split and check right side and length
		exp = mx_strsplit(exp[1], ',');
		exp_count = 0;
		for(char **j = exp; *j != NULL; j++)
			exp_count++;
		if(exp_count != 2){
			invalid_line = i + 2;
			break;
		}
		
		char *right = exp[0];
		char *length = exp[1];
		
		// Validation data
		if(!isonlyalpha(left) || !isonlyalpha(right) || !isonlydigit(length)){
			invalid_line = i + 2;
			break;
		}
		
		if(mx_strcmp(left, right) == 0){
			invalid_line = i + 2;
			break;
		}
		
		data->bridges[i]->left = left;
		data->bridges[i]->right = right;
		data->bridges[i]->length = mx_atoi(length);
	}
	
	// Print error for line
	if(invalid_line != -1){
		char *arr[] = {
			"error: line ",
			mx_itoa(invalid_line),
			" is not valid\n",
			NULL
		};
		mx_printerr_ae(arr);
	}
	
	// Parsing islands from bridges
	for(int i = 0; i < data->bridges_num; i++){
		// Checking left side
		bool exist = false;
		for(int j = 0; j < data->island_num; j++)
			if(mx_strcmp(data->islands[j], data->bridges[i]->left) == 0){
				exist = true;
				break;
			}
			
		// Adding left side
		if(!exist){
			data->island_num++;
			char **temp = malloc(sizeof(char *) * data->island_num);
			for(int j = 0; j < data->island_num; j++)
				if(j == data->island_num - 1)
					temp[j] = data->bridges[i]->left;
				else
					temp[j] = data->islands[j];
			data->islands = temp;
		}
		
	
		exist = false;
		for(int j = 0; j < data->island_num; j++)
			if(mx_strcmp(data->islands[j], data->bridges[i]->right) == 0){
				exist = true;
				break;
			}
			
	
		if(!exist){
			data->island_num++;
			char **temp = malloc(sizeof(char *) * data->island_num);
			for(int j = 0; j < data->island_num; j++)
				if(j == data->island_num - 1)
					temp[j] = data->bridges[i]->right;
				else
					temp[j] = data->islands[j];
			data->islands = temp;
		}
	}
	line_num++;
	
	return data;
}

