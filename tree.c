#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left_child, *right_child;
};

struct node *createNode(int data)
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    if (newNode == NULL)
    {
        printf("Memory allocation failed");
        return NULL;
    }
    newNode->data = data;
    newNode->left_child = NULL;
    newNode->right_child = NULL;
    return newNode;
}

struct node *insert(struct node *root, int data)
{
    if (root == NULL)
        return createNode(data);

    if (data < root->data)
        root->left_child = insert(root->left_child, data);
    else if (data > root->data)
        root->right_child = insert(root->right_child, data);

    return root;
}

struct node *findMin(struct node *root)
{
    while (root && root->left_child != NULL)
        root = root->left_child;
    return root;
}

struct node *deleteNode(struct node *root, int data)
{
    if (root == NULL)
        return root;

    if (data < root->data)
        root->left_child = deleteNode(root->left_child, data);
    else if (data > root->data)
        root->right_child = deleteNode(root->right_child, data);
    else
    {
        if (root->left_child == NULL)
        {
            struct node *temp = root->right_child;
            free(root);
            return temp;
        }
        else if (root->right_child == NULL)
        {
            struct node *temp = root->left_child;
            free(root);
            return temp;
        }

        struct node *temp = findMin(root->right_child);
        root->data = temp->data;
        root->right_child = deleteNode(root->right_child, temp->data);
    }
    return root;
}

int search(struct node *root, int data)
{
    if (root == NULL)
        return 0;
    if (root->data == data)
        return 1;

    if (data < root->data)
        return search(root->left_child, data);
    return search(root->right_child, data);
}

void inorder(struct node *root)
{
    if (root != NULL)
    {
        inorder(root->left_child);
        printf("%d ", root->data);
        inorder(root->right_child);
    }
}

void preorder(struct node *root)
{
    if (root != NULL)
    {
        printf("%d ", root->data);
        preorder(root->left_child);
        preorder(root->right_child);
    }
}

void postorder(struct node *root)
{
    if (root != NULL)
    {
        postorder(root->left_child);
        postorder(root->right_child);
        printf("%d ", root->data);
    }
}

int main()
{
    struct node *root = NULL;
    int choice, data;

    while (1)
    {
        printf("\nMenu:\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Search\n");
        printf("4. Inorder Traversal\n");
        printf("5. Preorder Traversal\n");
        printf("6. Postorder Traversal\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter data to insert: ");
            scanf("%d", &data);
            root = insert(root, data);
            printf("%d inserted.\n", data);
            break;

        case 2:
            printf("Enter data to delete: ");
            scanf("%d", &data);
            root = deleteNode(root, data);
            printf("%d deleted (if it exists).\n", data);
            break;

        case 3:
            printf("Enter data to search: ");
            scanf("%d", &data);
            if (search(root, data))
                printf("%d found in the tree.\n", data);
            else
                printf("%d not found in the tree.\n", data);
            break;

        case 4:
            printf("Inorder Traversal: ");
            inorder(root);
            printf("\n");
            break;

        case 5:
            printf("Preorder Traversal: ");
            preorder(root);
            printf("\n");
            break;

        case 6:
            printf("Postorder Traversal: ");
            postorder(root);
            printf("\n");
            break;

        case 7:
            printf("Exiting program.\n");
            exit(0);

        default:
            printf("Invalid choice! Please enter a number between 1 and 7.\n");
        }
    }
    return 0;
}
