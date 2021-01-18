#include <bits/stdc++.h>
#include "../Bai4.cpp"

using namespace std;

int main() {
    BinaryTree<int, int>* tree = new BinaryTree<int, int>;
    vector<int> a = {6, 2, 9, 10, 8, 0, 4, 7, 3, 1, 20, -1, 5};

    for (auto item : a) {
        tree->insert(item, item);
    }

    cout << "Inorder traversal:\n\t";
    tree->inOrder();
//    tree->postOrder();
//    cout << '\n';
//    tree->preOrder();

    tree->remove(7);
    cout << "\n\nRemove 7 and Inorder traversal:\n\t";
    tree->inOrder();

    tree->remove(2);
    cout << "\n\nRemove 2 and Inorder traversal:\n\t";
    tree->inOrder();

    tree->remove(6);
    cout << "\n\nRemove 6 and Inorder traversal:\n\t";
    tree->inOrder();
    
    tree->remove(10);
    cout << "\n\nRemove 10 and Inorder traversal:\n\t";
    tree->inOrder();
    
    return 0;
}
/*
                       6
                     /  \
                    /    \
                   /      \
                  /        \
                 /          \
                2            9
              /  \          / \
             /    \        8   10
            0      4      /     \
           / \    / \    7      20
          -1  1  3   5   
                       
*/
