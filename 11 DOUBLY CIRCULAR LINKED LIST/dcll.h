#define pragama once


#include <stdio.h>
#include <stdlib.h>

/* Symbolic constandts */
#define TRUE 1
#define FALSE -1
#define SUCCESS 1
#define FAILURE -1
#define LIST_DATA_NOT_FOUND 2
#define LIST_EMPTY 3

/* typedefs */

typedef int data_t;
typedef int status_t;
typedef int len_t;
typedef int bool;
typedef struct node node_t;
typedef int size_t;
typedef node_t list_t;

struct node{
    data_t data;
    struct node *prev;
    struct node *next;
};

list_t* create_list(void);

status_t insert_beg(list_t* p_list, data_t new_data);
status_t insert_end(list_t* p_list, data_t new_data);
status_t insert_after(list_t* p_list, data_t new_data);
status_t insert_before(list_t* p_list, data_t new_data);

status_t get_beg(list_t* p_list, data_t *p_data);
status_t get_end(list_t* p_list, data_t* p_data);
status_t pop_beg(list_t* p_list, data_t* p_data);
status_t pop_end(list_t* p_list, data_t* p_data);

status_t remove_beg(list_t* p_list);
status_t remove_end(list_t *p_list);
status_t remove_data(list_t *p_list, data_t* r_data);

len_t get_length(list_t* p_list);
bool contains(list_t* p_list, data_t serch_data);
bool is_list_empty(loist_t* p_list);
int get_repeate_count(list_t* p_list, data_t serch_data);
void show_list(list_t* p_list, const char* msg);

list_t *concate_list(list_t* p_list1 ,list_t* p_list2 );

/* list auxillary routines */

void generic_insert(node_t *p_beg, node_t* p_mid, node_t* p_end);
void generic_delete(node_t* p_delete_node);
node_t* locate_node(lis_t* p_list, data_t, search_data);
node_t* get_list_node(data_t new_data);

/* memory allocation routines */

void* xmalloc(size_t size_in_bytes);
