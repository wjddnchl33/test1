#include <stdio.h>
#define DataType char

typedef struct Tnode { //노드 생성
    struct Tnode *left;
    DataType data;
    struct Tnode *right;
} Tnode;

typedef struct linkedBT{
    Tnode *root;
}LinkedBT;

preoder(Tnode *root) {
    if(root) {
        printf("%c ", root->data);
        preoder(root->left);
        preoder(root->right);
    }
}

inorder(Tnode *root) {
    if(root) {
        inorder(root->left);
        printf("%c ", root->data);
        inorder(root->right);
    }
}

postorder(Tnode *root) {
    if(root) {
        postorder(root->left);
        postorder(root->right);
        printf("%c ", root->data);
    }
}

int main() {
    Tnode node9 = {NULL, 'B', NULL};
    Tnode node8 = {NULL, 'A', NULL};
    Tnode node7 = {NULL, 'E', NULL};
    Tnode node6 = {NULL, 'D', NULL};
    Tnode node5 = {NULL, 'C', NULL};
    Tnode node4 = {&node8, '-', &node9};
    Tnode node3 = {&node6, '/', &node7};
    Tnode node2 = {&node4, '*', &node5};
    Tnode node1 = {&node2, '+', &node3};
    preoder(&node1); printf("<-전위 순회\n");
    inorder(&node1); printf("<-중위 순회\n");
    postorder(&node1); printf("<-후위 순회\n");


}
