#include <stdio.h>
#define dataType int

typedef struct Tnode {
    struct Tnode *left;
    dataType data;
    struct Tnode *right;
} Tnode;

typedef struct LinkedBT {
    Tnode *root;
}LinkedBT;

int evaluatree_tree(Tnode *root) {
    if(!root) return 0;
    if(!root->left && !root->right) return root->data;
    else {
        int opd1 = evaluatree_tree(root->left);
        int opd2 = evaluatree_tree(root->right);
        switch (root->data) {
            case '+' : return opd1 + opd2;
            case '-' : return opd1 - opd2;
            case '*' : return opd1 * opd2;
            case '/' : return opd1 / opd2;
            case '%' : return opd1 % opd2;
        }
    }
}


int main() {
    Tnode node1 = {NULL, 10, NULL};
    Tnode node2 = {NULL, 5, NULL};
    Tnode node3 = {&node1, '-', &node2};
    Tnode node4 = {NULL, 4, NULL};
    Tnode node5 = {&node3, '*', &node4};
    Tnode node6 = {NULL, 40, NULL};
    Tnode node7 = {NULL, 8, NULL};
    Tnode node8 = {&node6, '/', &node7};
    Tnode node9 = {&node5, '+', &node8};
    LinkedBT expr;
    expr.root = &node9;
    printf("%d\n", evaluatree_tree(expr.root));
}
