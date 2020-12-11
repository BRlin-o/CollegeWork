#include<iostream>

using namespace std;

bool DEBUG = 0;
int nodeCount = 0;

typedef struct treenode{
    char data;
    struct treenode *left, *right;
} TNODE;

int max(int a, int b){
    return a>b ? a : b;
}


TNODE *newNode(char c){
    TNODE *node;
    node = (TNODE*)malloc(sizeof(TNODE));
    node->data = c;
    node->left = node->right = NULL;
    return node;
}

void setNodeLeft(TNODE* fa, TNODE *cr){
    fa->left = cr;
}

void setNodeRight(TNODE* fa, TNODE *cr){
    fa->right = cr;
}

int TreeHeight(TNODE *node, int h){
    if(node != NULL){
        if(DEBUG)cout<<"tree node: h: "<<h<<"; data: "<<node->data<<'\n';
        return max(TreeHeight(node->left, h+1), TreeHeight(node->right, h+1));
    }else{
        if(DEBUG)cout<<"tree over: h: "<<h-1<<'\n';
        return h-1;
    }
}

void TreeNodeCount_item(TNODE *node){
    if(node != NULL){
        ++nodeCount;
        TreeNodeCount_item(node->left);
        TreeNodeCount_item(node->right);
    }
}

int TreeNodeCount(TNODE *node){
    nodeCount = 0;
    TreeNodeCount_item(node);
    return nodeCount;
}

int main(){
    TNODE *tree;
    tree = newNode('a');
    setNodeLeft(tree, newNode('b'));
    setNodeRight(tree, newNode('c'));
    setNodeLeft(tree->left, newNode('d'));
    cout<<"Tree Height: "<<TreeHeight(tree, 1)<<'\n';
    cout<<"Tree Node Count: "<<TreeNodeCount(tree)<<'\n';
    return 0;
}
