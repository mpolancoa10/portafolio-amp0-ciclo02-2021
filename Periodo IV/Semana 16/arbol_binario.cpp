// Marlon Bladimir Polanco Ayala - PA100417
#include <iostream>
#include <string>
using namespace std;
 
// Estructura de datos para almacenar un nodo de arbol binario
struct Node
{
    int data;
    Node *left, *right;
 
    Node(int data)
    {
        this->data = data;
        this->left = this->right = nullptr;
    }
};
 
struct Trunk
{
    Trunk *prev;
    string str;
 
    Trunk(Trunk *prev, string str)
    {
        this->prev = prev;
        this->str = str;
    }
};
 
// Funcion para imprimir ramas del arbol binario.
void showTrunks(Trunk *p)
{
    if (p == nullptr) {
        return;
    }
 
    showTrunks(p->prev);
    cout << p->str;
}
 
void printTree(Node* root, Trunk *prev, bool isLeft)
{
    if (root == nullptr) {
        return;
    }
 
    string prev_str = "    ";
    Trunk *trunk = new Trunk(prev, prev_str);
 
    printTree(root->right, trunk, true);
 
    if (!prev) {
        trunk->str = "----";
    }
    else if (isLeft)
    {
        trunk->str = ".----";
        prev_str = "   |";
    }
    else {
        trunk->str = "'----";
        prev->str = prev_str;
    }
 
    showTrunks(trunk);
    cout << " " << root->data << endl;
 
    if (prev) {
        prev->str = prev_str;
    }
    trunk->str = "   |";
 
    printTree(root->left, trunk, false);
}
 
int main()
{
    // Construccion de arbol
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    root->left->left->left = new Node(8);
    root->left->left->right = new Node(9);
    root->left->right->left = new Node(10);
    root->left->right->right = new Node(11);
    root->right->left->left = new Node(12);
    root->right->left->right = new Node(13);
    root->right->right->left = new Node(14);
    root->right->right->right = new Node(15);    
    root->left->left->left->left = new Node(16);
    root->left->left->left->right = new Node(17);
    root->left->left->right->left = new Node(18);
    root->left->left->right->right = new Node(19);
    root->left->right->left->left = new Node(20);
    root->left->right->left->right = new Node(21);
    root->left->right->right->left = new Node(22);
    root->left->right->right->right = new Node(23);
    root->right->left->left->left = new Node(24);
    root->right->left->left->right = new Node(25);
    root->right->left->right->left = new Node(26);
    root->right->left->right->right = new Node(27);
    root->right->right->left->left = new Node(28);
    root->right->right->left->right = new Node(29);
    root->right->right->right->left = new Node(30);
    root->right->right->right->right = new Node(31);
 
    // imprimir arbol binario
    printTree(root, nullptr, false);
 
    return 0;
}
