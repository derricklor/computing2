//CODE TRAVERSALS
#include <stdlib.h>
struct node {
	int data;
	Node* left;
	Node* right;
};
typedef struct node Node;

int main(int argc, char* argv[])
{
	return 0;
}

void preorder(Node* root) { //	S	L	R	For constructing
	if (root != NULL) {
		printf("%d  ", root->data);
		preorder(root->left);
		preorder(root->right);
	}
}

void inorder(Node* root) { //	L	S	R
	if (root != NULL) {
		inorder(root->left);
		printf("%d  ", root->data);
		inorder(root->right);
	}
}

void postorder(Node* root) { //	L	R	S	For desconstructing
	if (root != NULL) {
		postorder(root->left);
		postorder(root->right);
		printf("%d  ", root->data);
	}
}
