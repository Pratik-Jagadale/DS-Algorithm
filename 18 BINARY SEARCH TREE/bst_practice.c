/*
	writing first code without coding practice
	and without refer any code
	only basic functions are written 
	date: 02-10-2021
*/
#include <stdio.h>

typedef int data_t;
typedef int status_t;

struct bst* create(void);
struct bst_node* get_node(data_t new_data);
status_t insert_node(struct bst* p_bst, data_t );

void in_order_r(struct bst* p_bst);
void pre_order_r(struct bst* p_bst);
void post_order_r(struct bst* p_bst);

void in_order_travers(struct bst_node* p_bst_node);
void pre_order_travers(struct bst_node* p_bst_node);
void post_order_travers(struct bst_node* p_bst_node);

status_t destroy(struct bst** pp_bst);
void delete_nodes(struct bst_node* p_bst);

void* mcalloc(data_t size);

struct bst_node{
	int data;
	struct bst_node* left;
	struct bst_node* right;
	struct bst_node* parent;
}

struct bst{
	struct bst_node* p_root_node;
	int nr_nodes;
}

struct bst* create(void)
{
	struct bst* p_bst = NULL;
	p_bst = (struct bst*)xmalloc(1 * sizeof(struct bst));
	p_bst->p_root_node = NULL;
	return p_bst;
}

struct bst_node* get_node(data_t new_data)
{
	struct bst_node * p_bst_node = NULL;
	bst_node* p_bst_node= (struct bst_node*)xmalloc(1 * sizeof(struct bst_node));

	p_bst_node->data = new_data;
	p_bst_node->left = NULL;
	p_bst_node->right = NULL;
	p_bst_node->parent = NULL;
	return p_bst_node;
}

status_t insert_node(struct bst* p_bst, data_t new_data)
{

	if(p_bst->p_root_node == NULL)
	{
		p_bst->p_root_node = get_node(new_data);
		return 1;
	}

	struct bst_node* p_run = p_bst->p_root_node;
	while(1)
	{
		if(p_run != NULL)
		{
			if(new_data < p_run->data)
			{
				p_run  = p_run->left;
			}
			else
			{
				p_run = p_run->right;
			}	
		}
		else
		{
			p_run = get_node(new_node);
			break;
		}
	}
	return 1;
}

void in_order_r(struct bst* p_bst)
{
	puts("In Order travers");
	puts("[start]");
	in_order_travers(p_bst->p_root_node);
	puts("[END]");
}

void pre_order_r(struct bst* p_bst)
{
	puts("Pre Order travers");
	puts("[start]");
	pre_order_travers(p_bst->p_root_node);
	puts("[END]");
}

void post_order_r(struct bst* p_bst)
{
	puts("Post Order travers");
	puts("[start]");
	post_order_travers(p_bst->p_root_node);
	puts("[END]");
}

void in_order_travers(struct bst_node* p_bst_node)
{
	if(p_bst_node == NULL)
		return;
	in_order_travers(p_bst_node->letf);
	printf("[%d]",p_bst_node->data);
	in_order_travers(p_bst_node->right);
}

void pre_order_travers(struct bst_node* p_bst_node)
{
	if(p_bst_node == NULL)
		return;
	printf("[%d]",p_bst_node->data);
	pre_order_travers(p_bst_node->letf);
	pre_order_travers(p_bst_node->right);
}

void post_order_travers(struct bst_node* p_bst_node)
{
	if(p_bst_node == NULL)
		return;
	post_order_travers(p_bst_node->letf);
	post_order_travers(p_bst_node->right);
	printf("[%d]",p_bst_node->data);
}

/*
	for destroy we need to traverse the nodes in post order
	means first traverse all nodes and then in reverse order
	remove node before delete stack frame from memmory...
*/

status_t destroy(struct bst** pp_bst)
{
	if(pp_bst->p_root_node == NULL)
	{
		printf("BST is already is emty...\n");
		return 2;
	}
	delete_nodes(pp_bst->p_root_node);
	free(pp_bst);
	pp_bst = NULL;
}

void delete_nodes(struct bst_node* p_bst_node)
{
	if(p_bst_node == NULL)
		return;
	delete_nodes(p_bst_node->left);
	delete_nodes(p_bst_node->right);
	free(p_bst_node);
	p_bst_node = NULL;
}

void* xmalloc(data_t size)
{
	void* p = malloc(size);

	if(p == NULL)
	{
		printf("OUT OF MEMMORY\n");
	}
}
