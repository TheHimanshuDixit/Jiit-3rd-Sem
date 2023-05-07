#include <bits/stdc++.h>
using namespace std;

class BST
{
    int data;
    BST *left, *right;

public:
    BST() : data(0), left(NULL), right(NULL)
    {
    }
    BST(int value)
    {
        data = value;
        left = right = NULL;
    }
    BST *Insert(BST *root, int value)
    {
        if (!root)
        {
            return new BST(value);
        }
        if (value >= root->data)
        {
            root->right = Insert(root->right, value);
        }
        else if (value < root->data)
        {
            root->left = Insert(root->left, value);
        }
        return root;
    }
    void inorder(BST *root)
    {
        if (root == NULL)
            return;
        else
        {
            inorder(root->left);
            cout << root->data << " ";
            inorder(root->right);
        }
    }
    BST *minValueNode(BST *node)
    {
        BST *current = node;
        while (current && current->left != NULL)
            current = current->left;

        return current;
    }
    BST *remove(BST *root, int key)
    {
        if (root == NULL)
        {
            return NULL;
        }
        else if (key < root->data)
        {
            root->left = remove(root->left, key);
        }
        else if (key > root->data)
        {
            root->right = remove(root->right, key);
        }
        else
        {
            if (root->left == NULL and root->right == NULL)
            {
                delete root;
                root = NULL;
            }
            else if (root->left == NULL)
            {
                BST *temp = root;
                root = root->right;
                delete temp;
            }
            else if (root->right == NULL)
            {
                BST *temp = root;
                root = root->left;
                delete temp;
            }
            else
            {
                BST *temp = minValueNode(root->right);
                root->data = temp->data;
                root->right = remove(root->right, temp->data);
            }
        }
        return root;
    }
};
struct node
{
    int data;
    node *left;
    node *right;
};
struct node *insertion(int n, int a[], int size)
{
    node *temp = new node;
    temp = NULL;
    if (n > 31)
    {
        return temp;
    }
    else if (!a[n])
    {
        return temp;
    }
    else if (a[n])
    {
        temp = new node;
        temp->data = a[n];
        temp->left = insertion(2 * n + 1, a, size);
        temp->right = insertion(2 * n + 2, a, size);
    }
}
void postorder(node *root)
{
    if (root == NULL)
        return;
    else
    {
        postorder(root->left);
        postorder(root->right);
        cout << root->data << " ";
    }
}
void preorder(node *root)
{
    if (root == NULL)
        return;
    else
    {
        cout << root->data << " ";
        preorder(root->left);
        preorder(root->right);
    }
}
void inorder(node *root)
{
    if (root == NULL)
        return;
    else
    {
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }
}
void levelorder(node *root)
{
    if (root == NULL)
        return;
    queue<node *> q;
    q.push(root);
    while (q.empty() == false)
    {
        node *node = q.front();
        cout << node->data << " ";
        q.pop();
        if (node->left != NULL)
            q.push(node->left);
        if (node->right != NULL)
            q.push(node->right);
    }
}

vector<int> longestPath(node *root)
{
    if (root == NULL)
    {
        vector<int> temp = {};
        return temp;
    }
    vector<int> rightvect = longestPath(root->right);
    vector<int> leftvect = longestPath(root->left);
    if (leftvect.size() > rightvect.size())
        leftvect.push_back(root->data);
    else
        rightvect.push_back(root->data);
    return (accumulate(leftvect.begin(), leftvect.end(), 0) > accumulate(rightvect.begin(), rightvect.end(), 0)
                ? leftvect
                : rightvect);
}

struct node *newNode(char F)
{
    node *N = new node;
    N->left = NULL;
    N->right = NULL;
    N->data = F;
    return N;
}
node *insertnode(char c, queue<node *> &q, struct node *root)
{
    node *Node = newNode(c);
    if (root == NULL)
    {
        root = Node;
    }
    else if (q.front()->left == NULL)
        q.front()->left = Node;
    else
    {
        q.front()->right = Node;
        q.pop();
    }
    q.push(Node);
    return root;
}

node *createtree()
{
    node *root = NULL;
    char arr[9] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I'};
    queue<node *> q;
    for (int i = 0; i < 9; i++)
        root = insertnode(arr[i], q, root);
    return root;
}

void spiralorder(node *root)
{
    stack<struct node *> s1;
    stack<struct node *> s2;
    s1.push(root);
    while (!s1.empty() || !s2.empty())
    {
        while (!s1.empty())
        {
            node *temp1 = s1.top();
            cout << temp1->data << " ";
            s1.pop();
            if (temp1->right)
                s2.push(temp1->right);
            if (temp1->left)
                s2.push(temp1->left);
        }
        while (!s2.empty())
        {
            node *temp2 = s2.top();
            cout << temp2->data << " ";
            s2.pop();
            if (temp2->left)
                s1.push(temp2->left);
            if (temp2->right)
                s1.push(temp2->right);
        }
    }
}

int main()
{
    // Solution 1
    int a[] = {1, 2, 3, 4, 5, 6, 7, 0, 8, 9, 0, 0, 0, 10, 11, 12, 13, 12, 13, 0, 14, 0, 0, 0, 0, 0, 0, 15, 0, 16, 17};
    node *root;
    root = insertion(0, a,31);
    preorder(root);
    cout << endl;
    inorder(root);
    cout << endl;
    postorder(root);
    cout << endl;
    levelorder(root);

    // Solution 2
    vector<int> ans = longestPath(root);
    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << " ";
    cout << endl;
    cout << "\nSum = "
         << accumulate(ans.begin(), ans.end(), 0);

    // Solution 3
    node *root3;
    root3 = createtree();
    cout << "LEVEL ORDER" << endl;
    levelorder(root3);
    cout << endl;
    cout << "SPIRAL ORDER" << endl;
    spiralorder(root3);

    // Solution 4
    int b[] = {10, 20, 30, 40, 50, 40, 35, 25, 20, 40, 18, 19, 22, 27, 30, 27};
    BST bst, *root4 = NULL;
    root4 = bst.Insert(root4, b[0]);
    BST *curr = root4;
    for (int i = 1; i < 16; i++)
    {
        bst.Insert(root4, b[i]);
    }
    bst.inorder(curr);
    int k;
    cin >> k;
    bst.remove(curr, k);
    bst.inorder(curr);
    return 0;
}
