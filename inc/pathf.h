#pragma once

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <stddef.h>
#include "libmx.h"

typedef struct s_node { ////graph 
  
    int to_parent; 
    int all_way;
    char *name;
    struct s_node* parent; 
  
} t_node; 

typedef struct s_queue { 
  
    int priority; 
    t_node *node;
    struct s_queue* next; 
  
} t_queue; 

typedef struct s_bridge{
	char *left;
	char *right;
	int length;
}	Bridge;

typedef struct s_fileinfo{
	int island_num;
	int bridges_num;
	char **islands;
    Bridge **bridges;
}	FileInfo;

t_queue* newNode(t_node *node);
void pop(t_queue** head);
void push(t_queue** head, t_node *node);
int isEmpty(t_queue** head);
int peek(t_queue** head);

char *mx_file_to_str(const char *filename);
t_node **pathfinder_alg(int **arr, char **islands, int cur_x, int goal_x);
void mx_check_str(char *str, int line_num);
char **list_of_islands(char **str);
char **first_last_name(t_node *node);
void mx_printerr_ae(char **text_arr);
char **pf_parse_normal(char *str);
void push_node(int to_parent, int all_way, char *name, t_node* parent);
t_node *new_node(int to_parent, int all_way, char *name);
void sort_paths(t_node **paths, char **islands);
void clean_and_output(t_node **res, int size, char **islands);
bool mx_compare_paths(t_node *node1, t_node *node2, t_node **res_temp);
void print_node(t_node *node);
char **mx_get_names(t_node *paths);
void sum_check(int **arr, int size);
bool pf_haveduplicates(FileInfo *data);
char *mx_file_to_str(const char *file);
int mx_strlen(const char *s);
char *mx_strnew(const int size);
bool check_fline(const char *s);
int linesnum(const char *file);
FileInfo *pf_parse(char *text);
int **adj_matrix(char **islands, char **arr, int size);
