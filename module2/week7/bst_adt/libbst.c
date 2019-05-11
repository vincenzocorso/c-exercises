#include <stdio.h>
#include <stdlib.h>
#include "bstitem.h"
#include "bst.h"

typedef struct bst_node
{
	struct bst_node *left;
	bstitem item;
	struct bst_node *right;
} bst_node;
typedef struct bst_node *bst_node_ptr;

#include "queueitem.h"
#include "queue.h"

bst_node_ptr bst_root;

static int _is_bst_empty(bst_node_ptr bst);

static void _bst_insert(bst_node_ptr *bst, bstitem item);

static int _bst_search(bst_node_ptr bst, bstitem item);

static int _bst_distance_root(bst_node_ptr bst, bstitem item);
static int _bst_distance(bst_node_ptr bst, bstitem item1, bstitem item2);

static void _bst_delete(bst_node_ptr *bst, bstitem item);

static bst_node_ptr _bst_min(bst_node_ptr bst);
static void _bst_delete_min(bst_node_ptr *bst);

static void _bst_inorder(bst_node_ptr bst);
static void _bst_preorder(bst_node_ptr bst);
static void _bst_postorder(bst_node_ptr bst);
static void _bst_levelorder(bst_node_ptr bst);

static void _bst_print(bst_node_ptr bst, int level);

static void _bst_free(bst_node_ptr bst);

void bst_init()
{
	bst_root = NULL;
}

void bst_insert(bstitem item)
{
	_bst_insert(&bst_root, item);
}

int bst_search(bstitem item)
{
	return _bst_search(bst_root, item);
}

int bst_distance(bstitem item1, bstitem item2)
{
	return _bst_distance(bst_root, item1, item2);
}

void bst_delete(bstitem item)
{
	_bst_delete(&bst_root, item);
}

void bst_inorder()
{
	_bst_inorder(bst_root);
}

void bst_preorder()
{
	_bst_preorder(bst_root);
}

void bst_postorder()
{
	_bst_postorder(bst_root);
}

void bst_levelorder()
{
	queue_init();
	_bst_levelorder(bst_root);
	queue_free();
}

void bst_print()
{
	_bst_print(bst_root, 0);
}

void bst_free()
{
	_bst_free(bst_root);
}

static int _is_bst_empty(bst_node_ptr bst)
{
	return bst == NULL;
}

static void _bst_insert(bst_node_ptr *bst, bstitem item)
{
	if(_is_bst_empty(*bst))
	{
		*bst = malloc(sizeof(bst_node));
		if(*bst != NULL)
		{
			(*bst)->left = (*bst)->right = NULL;
			(*bst)->item = item;
		}
		else puts("ERROR: Can't create a new node.");
	}
	else
	{
		if(item < (*bst)->item)
			_bst_insert(&((*bst)->left), item);
		else if(item > (*bst)->item)
			_bst_insert(&((*bst)->right), item);
	}
}

static int _bst_distance_root(bst_node_ptr bst, bstitem item)
{
	if(item < bst->item)
		return 1 + _bst_distance_root(bst->left, item);
	else if(item > bst->item)
		return 1 + _bst_distance_root(bst->right, item);
	else return 0;
}

static int _bst_distance(bst_node_ptr bst, bstitem item1, bstitem item2)
{
	if(item1 < bst->item && item2 < bst->item)
		return _bst_distance(bst->left, item1, item2);
	else if(item1 > bst->item && item2 > bst->item)
		return _bst_distance(bst->right, item1, item2);
	else
		return _bst_distance_root(bst, item1) + _bst_distance_root(bst, item2);
}

static void _bst_delete(bst_node_ptr *bst, bstitem item)
{
	if(_is_bst_empty(*bst))
		return;
	else if(item < (*bst)->item)
		_bst_delete(&((*bst)->left), item);
	else if(item > (*bst)->item)
		_bst_delete(&((*bst)->right), item);
	else
	{
		if((*bst)->right != NULL)
		{
			bst_node_ptr min_ptr = _bst_min((*bst)->right);
			bstitem min = min_ptr->item;
			(*bst)->item = min;
			_bst_delete_min(&((*bst)->right));
		}
		else
		{
			bst_node_ptr temp = (*bst)->left;
			free(*bst);
			*bst = temp;
		}
	}
}

static bst_node_ptr _bst_min(bst_node_ptr bst)
{
	if(_is_bst_empty(bst))
		return NULL;
	else if(bst->left == NULL)
		return bst;
	else return _bst_min(bst->left);
}

static void _bst_delete_min(bst_node_ptr *bst)
{
	if((*bst)->left == NULL)
	{
		bst_node_ptr temp = (*bst)->right;
		free(*bst);
		*bst = temp;
	}
	else _bst_delete_min(&((*bst)->left));
}

static int _bst_search(bst_node_ptr bst, bstitem item)
{
	if(_is_bst_empty(bst))
		return 0;

	if(item < bst->item)
		return _bst_search(bst->left, item);
	else if(item > bst->item)
		return _bst_search(bst->right, item);
	else return 1;
}

static void _bst_inorder(bst_node_ptr bst)
{
	if(_is_bst_empty(bst))
		return;

	_bst_inorder(bst->left);
	print_bstitem(bst->item);
	printf(" ");
	_bst_inorder(bst->right);
}

static void _bst_preorder(bst_node_ptr bst)
{
	if(_is_bst_empty(bst))
		return;

	print_bstitem(bst->item);
	printf(" ");
	_bst_preorder(bst->left);
	_bst_preorder(bst->right);
}

static void _bst_postorder(bst_node_ptr bst)
{
	if(_is_bst_empty(bst))
		return;

	_bst_postorder(bst->left);
	_bst_postorder(bst->right);
	print_bstitem(bst->item);
	printf(" ");
}

static void _bst_levelorder(bst_node_ptr bst)
{
	queue_enqueue(bst);
	while(!is_queue_empty())
	{
		bst_node_ptr temp = queue_dequeue();
		print_bstitem(temp->item);
		printf(" ");
		if(!_is_bst_empty(temp->left))
			queue_enqueue(temp->left);
		if(!_is_bst_empty(temp->right))
			queue_enqueue(temp->right);
	}
	puts("");
}

static void _bst_print(bst_node_ptr bst, int level)
{
	if(_is_bst_empty(bst))
		return;

	_bst_print(bst->right, level + 1);
	printf("<%*s%5d\n", 5 * level, " ", bst->item);
	_bst_print(bst->left, level + 1);
}

static void _bst_free(bst_node_ptr bst)
{
	if(_is_bst_empty(bst))
		return;

	_bst_free(bst->left);
	_bst_free(bst->right);
	free(bst);
}
