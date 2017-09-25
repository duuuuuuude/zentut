#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *left;
    struct node *right;
} node;

typedef int(*comparer)(int, int);
typedef void(*callback)(node*);

node* create_node(int data) {
    node* new_node = (node*)malloc(sizeof(node));
    if (new_node == NULL) {
        fprintf(stderr, "Error while creating node.\n");
        exit(1);
    }
    new_node->data = data;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

node* insert_node(node* root, comparer compare, int data) {
    if (root == NULL) 
    {
        root = create_node(data);
    } 
    else {
        int is_left  = 0;
        int r        = 0;
        node* cursor = root;
        // save the cursor's previous position
        node* prev   = NULL; 

        // traverse the tree up until the NULL
        while(cursor != NULL) 
        {
            prev = cursor;
            r = compare(data, cursor->data);
            if (r < 0) {
                is_left = 1;
                cursor = cursor->left;
            } else {
                is_left = 0;
                cursor = cursor->right;
            }
        }
        // create a node from the node that was before NULL
        if (is_left) 
            prev->left = create_node(data);
        else 
            prev->right = create_node(data);
    }
    return root;
}

node* delete_node(node* root, comparer compare, int data) {
    // if root == NULL
    if (root == NULL) {
        return NULL;
    }

    node* cursor;
    int r = compare(data, root->data);
    
    // if data < root->data
    if (r < 0) {
        root->left = delete_node(root->left, compare, data);
    }
    // if data > root->data
    else if (r > 0) {
        root->right = delete_node(root->right, compare, data);
    } 
    // if data == root->data, then we've hit base recursion base case
    else {
        // if there's no left node
        if (root->left == NULL) 
        {
            cursor = root->right;
            free(root);
            root = cursor;
        }
        // if there's no right node
        else if (root->right == NULL) 
        {
            cursor = root->left;
            free(root);
            root = cursor;
        }
        // if there are both left and right nodes
        else 
        {
            // go right
            cursor = root->right;
            // init a 'parent' node as NULL
            node* parent = NULL;
            // go left up until NULL is met
            while(cursor->left != NULL) 
            {
                    
                parent = cursor;
                cursor = cursor->left;
            }
            root->data = cursor->data;
            if (parent != NULL) 
                parent->left = delete_node(parent->left, compare, parent->left->data);
            else 
                root->right = delete_node(root->right, compare, parent->right->data);
        }
    }
    return root;
}

node* search(node* root, const int data, comparer compare) {
    if (root == NULL) {
        return NULL;
    }
    int r;
    node* cursor = root;
    while(cursor != NULL) {
        r = compare(data, cursor->data);
        if (r < 0) {
            cursor = cursor->left;
        } else if (r > 0) {
            cursor = cursor->right;
        } else {
            return cursor;
        }
    }
    return cursor;
}

void traverse(node* root, callback cb) {
    node* cursor;
    node* pre;
    if (root == NULL) {
        return;
    }

    cursor = root;

    while(cursor != NULL) {
        if (cursor->left != NULL) {
            cb(cursor);
            cursor = cursor->right;
        } else {
            pre = cursor->left;
            while(pre->right != NULL && pre->right != cursor) {
                pre = pre->right;
            }
            if (pre->right) {
                pre->right = NULL;
                cb(cursor);
                cursor = cursor->right;
            }
        }
    }
}

// recursevily remove all nodes of the tree
void dispose(node* root) {
    if (root) {
        dispose(root->left);
        dispose(root->right);
        free(root);
    }
}

// compare two nodes
int compare(int left, int right) {
    if (left > right) 
        return 1;
     else 
        return -1;
    return 0;
}

// display a node's key
void display(node* nd) {
    if (nd != NULL) {
        printf("%d ", nd->data);
    }
}

// recursevily display tree or subtree
void display_tree(node* nd) {
    if (nd == NULL) 
        return;
    printf("%d", nd->data);
    if (nd->left != NULL) {
        printf("(L:%d)", nd->left->data);
    }
    if (nd->right != NULL) {
        printf("(R:%d)", nd->right->data);
    }
    printf("\n");

    display_tree(nd->left);
    display_tree(nd->right);
}

int main() {
    node* root = NULL;
    comparer int_comp = compare;
    callback f = display;


}

