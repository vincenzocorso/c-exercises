#include <stdio.h>
#include <string.h>
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

bst_node_ptr bst_root;

static int _is_bst_empty(bst_node_ptr bst);
static void _bst_insert(bst_node_ptr *bst, bstitem item);
static void _bst_inorder(bst_node_ptr bst);
static void _bst_preorder(bst_node_ptr bst);
static void _bst_postorder(bst_node_ptr bst);
static void _bst_free(bst_node_ptr bst);

void bst_init()
{
	bst_root = NULL;
}

void bst_insert(bstitem item)
{
	_bst_insert(&bst_root, item);
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

void bst_split(bstitem item)
{
	bstitem token = strtok(item, " ");
	while(token != NULL)
	{
		bst_insert(token);
		token = strtok(NULL, " ");
	}
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
			(*bst)->item = malloc(100 * sizeof(char));
			assign((*bst)->item, item);
		}
		else puts("ERROR: Can't create a new node.");
	}
	else
	{
		if(lt(item, (*bst)->item))//if(item < (*bst)->item)
			_bst_insert(&((*bst)->left), item);
		else if(gt(item, (*bst)->item))//else if(item > (*bst)->item)
			_bst_insert(&((*bst)->right), item);
	}
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

static void _bst_free(bst_node_ptr bst)
{
	if(_is_bst_empty(bst))
		return;

	_bst_free(bst->left);
	_bst_free(bst->right);
	free(bst);
}
