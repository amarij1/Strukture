#include<stdio.h>
#include<stdlib.h>

struct _node;
typedef struct _node* position;
typedef struct _node {
	int number;
	position left;
	position right;
}Node;

position createNode(int number);
position insert(position current, position el);
void printInOrder(position current);
position find(position current, int number);
position deleteNode(position current, int number);
position findMax(position current);
position findMin(position current);

int main() {
	position root = NULL;
	position el = createNode(16);
	root = insert(root, el);
	return EXIT_SUCCESS;
}

position deleteNode(position current, int number) {
	if (NULL == current)return NULL;
	if (current->number == number) {
		if (current->left != NULL) {
			position tmp = findMax(current->left);
			current->number = tmp->number;
			current->left = deleteNode(current->right, tmp->number);
		}
		else if (current->right != NULL) {
			position tmp = findMin(current->right);
			current->number = tmp->number;
			current->right = deleteNode(current->right, tmp->number);
		}
		else {
			free(current);
			return NULL;
		}
	}
	else if (current->number > number) {
		current->left = deleteNode(current->left, number);
	}
	else{
		current->right = deleteNode(current->right, number);
	}
	return current;
}
void printInOrder(position current) {
	if (current == NULL)return;
	printInOrder(current->left);
	printf("%d", current->number);
	printInOrder(current->right);
}
position findMin(position current) {
	if (NULL == current)return NULL;
	while (current->left != NULL) current = current->left;
	return current;
}
position findMax(position current) {
	if (NULL == current)return NULL;
	while (current->right != NULL) current = current->right;
	return current;
}
position find(position current, int number) {
	if (NULL == current)return NULL;
	if (current->number == number) { 
		return current;
	} else if (current->number > number) {
		return find(current->left, number);
	}
	else
		return find(current->right, number);
}
position insert(position current, position el) {
	if (current == NULL)return el;
	if (current->number > el->number) {
		current->left = insert(current->left, el);
	} else if (current->number < el->number) {
		current->right = insert(current->right, el);
	} else {
		free(el);
	}
	return current;
}
position createNode(int number) {
	position tmp = (position)malloc(sizeof(struct _node));
	tmp->number = number;
	tmp->left = tmp->right = NULL;
	return tmp;
}