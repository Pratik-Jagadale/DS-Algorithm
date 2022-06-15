#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "bst.h"

bst_t *create_bst(void)
{
	bst_t p_bst = NULL;
	p_bst = (bst_t*)malloc(sizeof(bst_t));
	p_bst->p_root_node = NULL;
	p_bst->nr_size = 0;
	return p_bst;
}

ret_t insert_bst(bst_t* p_bst, data_t new_data)
{

}

bool search_bst(bst_t* p_bst, data_t search_data)
{
	if(search_bst_node(p_bst->p_root_node, search_data) != NULL)
		return true;
	return false;
}

void inorder_r(bst_t *p_bst)
{
	__inorder_r(p_bst->p_root_node);
}

void preorder_r(bst_t *p_bst)
{
	__preorder_r(p_bst->p_root_node);
}

void postorder_r(bst_r* p_bst)
{
	__postorder_r(p_bst->p_root_node);
}

void inorder_nrc(bst_t* p_bst)
{
	
}

void preorder_nrc(bst_t *p_bst)
{

}

void postorder_nrc(bst_t *p_bst)
{

}

ret_t maximum_bst(bst_t *p_bst, data_t *p_max_data)
{

}

ret_t minimum_bst(bst_t* p_bst,data_t *p_min_data)
{

}

ret_t inorder_successor(bst_t *p_bst,data_t e_data, data_t *p_suc_data)
{

}

ret_t inorder_predecessor(bst_t *p_bst, data_t e_data, data_t *p_pred_data)
{

}

/*ret_t remove_bst(bst_t *p_bst, data_t r_data)
{
	bst_node_t p_bst_r_node = NULL;
	p_bst_r_node = search_bst_node(p_bst->p_root_node, r_data); 
	if(p_bst_r_node == NULL)
		return (BST_DATA_NOT_FOUND);

	transplant_bst(p_bst, )
}*/

ret_t destroy_bst(bst **p_bst)
{

}

ret_t remove_bst_extended(bst_t *p_bst, data_t r_data)
{

}

/* BST auxillary (Helper routines)*/
bst_node_t *search_bst_node(bst_node_t *p_bst_node, data_t search_data)
{

	bst_node_t p_run = NULL;
	p_run = p_bst_node;

	while(1)
	{
		if(p_run->data == search_data)
			return p_run;
		else if(p_bst_node->data < search_data)
			p_run = p_run->left;
		else if(p_run > search_data)
			p_run = p_run->right;
		else
		{
			if(p_run == NULL){
				p_run = NULL;
				return NULL;
			}
		}
	}
}

bst_node_t *get_bst_node(data_t new_data)
{
	bst_node_t* p_bst_node = NULL;
	p_bst_node = (bst_node_t*)malloc(sizeof(bst_node_t));
	p_bst_node->data = new_data;
	p_bst_node->parent = NULL;
	p_bst_node->left = NULL;
	p_bst_node->right = NULL;

	return p_bst_node;
}

bst_node_t *inorder_successor_node(bst_node_t *p_bst_node)
{

}

bst_node_t *inorder_predecessor_node(bst_node_t *p_bst_node)
{

}

void __inorder_r(bst_node_t *p_bst_node)
{
	if(p_bst_node == NULL)
	{
		return;
	}
	__inorder_r(p_bst_node->left);
	printf(" - %d - ", p_bst_node->data);
	__inorder_r(p_bst_node->right);
}

void __preorder_r(bst_node_t *p_root_node)
{
	if(p_bst_node == NULL)
	{
		return;
	}
	
	printf(" - %d - ", p_bst_node->data);
	__inorder_r(p_bst_node->left);
	__inorder_r(p_bst_node->right);
}

void __postorder_r(bst_node_t *p_root_node)
{
	if(p_bst_node == NULL)
	{
		return;
	}
	
	__inorder_r(p_bst_node->left);
	__inorder_r(p_bst_node->right);
	printf(" - %d - ", p_bst_node->data);
}

void __destroy_bst_r(bst_node_t *_root_node)
{

}

void transplant_bst(bst_t *p_bst, bst_node_t *u, bst_node_t *v) /* helper routine for exchange nodes */
{

}

/* BST auxillary - stack auxillary*/
stack_t *create_bstptr_stack()
{

}

ret_t push_bstptr(stack_t *p_stack, bst_node_t *p_bst_node)
{

}

ret_t top_bstptr(stack_t *p_stack, bst_node_t **pp_bst_node)
{

}

ret_t pop_bstptr(stack_t *p_stack, bst_node_t **pp_bst_node)
{

}

ret_t set_bstptr_top_color(stack_t *p_stack, color_t new_color)
{

}

ret_t get_bstptr_top_color(stack_t *p_stack, color_t *p_top_color)
{

}

bool is_bstptr_stack_empty(stack_t *p_stack)
{

}

ret_t destroy_bstptr_stack(stack_t **pp_stack)
{

}

/* Bst auxillary  -List Interfaces */
lis_t *create_bstptr_list(void)
{

}

ret_t insert_bstptr_end(list_t *p_list, bst_node_t *p_bst_node)
{

}

ret_t examine_bstptr_end(list_t *p_list, bst_node_t **pp_bst_node)
{

}

ret_t examine_and_delete_bstptr_end(list_t *p_list, bst_node_t **pp_bst_node)
{

}

bool is_bstptr_list_empty(list_t *p_list)
{

}

ret_t destroy_bstptr_list(list_t **pp_list)
{

}

/* BST auxillary -List Intefaces auxillary */
void gerneric_bstptr_insert(bstptr_node_t *p_beg, bstptr_node_t *p_mid, bstptr_node_t *p_end)
{

}

void generic_bstptr_delete(bstptr_node_t *p_bstptr_node)
{

}

bstptr_node_t *search_bstptr_node(list_t *p_list, bst_node_t *p_bst_node)
{

}

bstptr_noe_t *get_bstptr_node(bst_node_t *p_bst_node)
{

}

/* General auxillary routines */
void *xmalloc(size_t nr_size){

	void* p = NULL;
	p = malloc(nr_size);
	if(p == NULL)
	{
		printf("OUT OF MEMMORY...\n");
		return NULL;
	}
	return p;
}

