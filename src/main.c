#include "pathf.h"

t_node *new_node(int to_parent, int all_way, char *name) { 
    t_node* temp = (t_node*)malloc(sizeof(t_node)); 
    temp->to_parent = to_parent;
    temp->all_way = all_way; 
    temp->name = mx_strdup(name);
    temp->parent = NULL; 
  
    return temp; 
} 
void push_node(int to_parent, int all_way, char *name, t_node* parent) { 
    t_node* temp =  new_node(to_parent, all_way, name);
    temp->parent = parent;
    parent = temp;
}

char **first_last_name(t_node *node) {
    char **names = (char **) malloc(2 * sizeof(char*));
    for(int i = 0; i < 2; i++) {
        names[i] = NULL;
    }
    t_node *temp = node;
    names[0] = mx_strdup(node->name); 
    for(int i = 0; temp->parent != NULL; i++) {
        temp = temp->parent;
    }
    names[1] = mx_strdup(temp->name); 
    return names;
}
int main(int argc, char *argv[]) {
    if (argc != 2) {
        mx_printerr("usage: ./pathfinder [filename]\n");
        exit(0);
    }

    char *file_str = mx_file_to_str(argv[1]);
    if (file_str == NULL) {
        mx_printerr("error: file ");
        mx_printerr(argv[1]);
        mx_printerr(" does not exist\n");
        exit(0);
    }
    if(mx_strlen(file_str) == 0) {
        mx_printerr("error: file ");
        mx_printerr(argv[1]);
        mx_printerr(" is empty\n");
        exit(0);
    }

    
    char **res = pf_parse_normal(file_str);
    char **islands = list_of_islands(res);
    int islands_size = 0;
    for(int i = 0; islands[i] != NULL; i++) {
        islands_size++;
    }
FileInfo *data = pf_parse(file_str);
	if(pf_haveduplicates(data)){
		mx_printerr("error: duplicate bridges\n");
       exit(0);
    }
 
    int **matrix = adj_matrix(islands, res, islands_size);
    
    sum_check(matrix, islands_size);
    
    int i = 0;
    for(int islands_i = 0; islands_i < islands_size; islands_i++) {
        for(int islands_j = 0; islands_j < islands_size; islands_j++) {
            if(islands_i != islands_j) {                
                t_node **a = pathfinder_alg(matrix, islands, islands_i, islands_j);
                for(int j = 0; a[j] != NULL; j++) {
                    i++;
                } 
            }
        }   
    }


    t_node **res_paths = (t_node **) malloc((i + 1) * sizeof(t_node *));
    for(int j = 0; j < i; j++) {
        res_paths[j] = NULL;
    }
    
    int ii = 0;
    for(int islands_i = 0; islands_i < islands_size; islands_i++) {
        for(int islands_j = 0; islands_j < islands_size; islands_j++) {
            if(islands_i != islands_j) {
                
                t_node **a = pathfinder_alg(matrix, islands, islands_i, islands_j);
                
                for(int j = 0; a[j] != NULL; j++) {
                    res_paths[ii] = (t_node*)malloc(sizeof(t_node));
                    res_paths[ii] = a[j];
                    ii++;
                }
            }
        }   
    }
    clean_and_output(res_paths, i, islands);
}
    


