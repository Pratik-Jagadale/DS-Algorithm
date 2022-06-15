

struct bst_head
{
	struct bst_node* root_node;
	int bst_size;
};

struct bst_node{
	int data;
	struct bst_node* right;
	struct bst_node* left;
	struct bst_node* parent; 
};

struct bst_head* create bst(){
	struct bst_head* = NULL;
	bst_head = (struct bst_head*)malloc(1 * sizeof(bst_head));
	bst_head->root_node = NULL;
	bst_head->bst_size = 0;
	return bst_head;
}

insert(struct bst_head* bst, int data)
{
	if(bst_head->bst_size == 0)
	{
		stuct bst_node* node = NULL;
		node->data = data;
		node->left = NULL;
		node->right = NULL;
		node->parent = NULL;
		bst->root_node = node;
		return 0;
	}

	if(data < bst->root_node->data)
	{
		bst->root_node->left = (struct bst_node*)malloc(1 * sizeof(stuct bst_node));
		bst->root_node->left->data = data;
		bst->root_node->left->left = NULL;
		bst->root_node->left->right = NULL;

	}
	else if(data > bst->root_node->data)
	{
		bst->root_node->right = (struct bst_node*)malloc(1 * sizeof(stuct bst_node));
		bst->root_node->right->data = data;
	}


}


/*travers*/

/*in Order*/
/*
	travel(N) = if(N == NULL)
					Do nothing
				travel(N->left)
				visit(N)
				travel(N->right)
*/

void travel(stuct bst_node* p_node )
{
	if(p_node == NULL)
		return ;
	travel(p_node->left);
	printf("%d",p_node->data);
	travel(p_node->right);
}

/*Pre Order*/
/*
	travel(N) = if(N == NULL)
					Do nothing
				visit(N)
				travel(N->left)
				travel(N->right)
*/
void travel(stuct bst_node* p_node )
{
	if(p_node == NULL)
		return ;
	printf("%d",p_node->data);
	travel(p_node->left);
	travel(p_node->right);
}

/*Post Order*/
/*
	travel(N) = if(N == NULL)
					Do nothing
				travel(N->left)
				travel(N->right)
				visit(N)
*/
void travel(struct bst_node* p_node )
{
	if(p_node == NULL)
		return ;
	travel(p_node->left);
	travel(p_node->right);
	printf("%d",p_node->data);
}
