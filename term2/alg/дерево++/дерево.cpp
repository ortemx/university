#include <iostream>
#include <iomanip>
#include <windows.h>
#include <ctime>
#include <queue>

using namespace std;

struct btree{
    int data;
    btree* left;
    btree* right;
};

btree *createTree(int x){
    btree *node;
    node = new btree;
    node -> data = x;
    node -> left = NULL;
    node -> right = NULL;
    return node;
}

void addbt(btree* tree, int value)
{
    btree *parent, *ptr;
    for (parent = tree; tree != NULL; ){
        parent = tree;
    if (value < tree -> data)
        tree = tree -> left;
    else
        if (value >= tree -> data)
        tree = tree -> right;
    else
        return;
    }
    ptr = createTree(value);
    if (value < parent -> data)
        parent -> left = ptr;
    else
        parent -> right = ptr;
}

void glubina(btree* node)// обход в глубину бинарного дерева
{
    if (node == NULL)
        return;
    glubina (node->left);
    glubina (node->right);
    cout<<node->data<<" \n";
}

void shirina (btree* node)// обход в ширину бинарного дерева
{
    cout<<"shirina"<<endl;
    queue <btree*> q;
    q.push (node);
    while(!q.empty())
    {
        btree* ptr = q.front();
        q.pop();
        cout<<ptr->data<<" ";
        if (ptr->left != NULL )
            q.push (ptr->left);
        if (ptr->right != NULL )
            q.push (ptr->right);
    }
    cout<<endl;
}

int chvershin(btree* node)// возвращает кол-во вершин дерева
{
    if (node == NULL)
        return 0;
    return chvershin(node->left)+chvershin(node->right)+1;
}

int main()
{
    srand(time(NULL));
    btree* head= NULL;

    int ch;
    cin>>ch;

    head=createTree(ch);

    int arr[10]={7,15,65,54,85,12,54,96,332,4};

    for (int i=0;i<10;i++)
        {
            addbt(head,arr[i]);
        }

    //addbt(head);
    cout<<"glubina"<<endl;
    glubina(head);
    shirina(head);
    cout<<"kol-vo vershin:"<<endl;
    chvershin(head);


return 0;
}
