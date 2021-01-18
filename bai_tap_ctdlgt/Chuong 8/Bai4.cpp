#include <bits/stdc++.h>

#ifndef __Bai4__cpp
#define __Bai4__cpp

using namespace std;

template<class Key, class T>
class Node {
    private:
        Key key;
        T elem;
        Node<Key, T> *parent, *left, *right;

    public:
        Node() {
            reset();
        }

        explicit Node(Node<Key, T>* node){
            reset();
            copy(node);
        }

        Node(Key _key, T _elem){
            reset();
            key  = _key;
            elem = _elem;
        }

        Node<Key, T> *&getParent() { return parent;}
        Node<Key, T> *&getLeft()   { return left;  }
        Node<Key, T> *&getRight()  { return right; }

        void setParent(Node *_parent) { this->parent = _parent;}
        void setLeft  (Node *_left)   { this->left   = _left;  }
        void setRight (Node *_right)  { this->right  = _right; }

        bool hasParent() { return parent != nullptr; }
        bool hasLeft()   { return left   != nullptr; }
        bool hasRight()  { return right  != nullptr; }

        T getElem()  { return elem; }
        Key getKey() { return key;  }

        void setElem(T _elem) { this->elem = _elem; }
        void setKey(Key _key) { this->key = _key; }

        bool hasNoChildren()     { return !hasLeft() && !hasRight(); }
        bool hasOnlyLeftChild()  { return  hasLeft() && !hasRight(); }
        bool hasOnlyRightChild() { return !hasLeft() &&  hasRight(); }

        void copy(Node<Key, T> *node) {
            key  = node->getKey();
            elem = node->getElem();
        }

        void createLeftChildRelation(Node<Key, T> *child) {
            setLeft(child);
            if (child != nullptr) child->setParent(this);
        }

        void createRightChildRelation(Node<Key, T> *child) {
            setRight(child);
            if (child != nullptr) child->setParent(this);
        }

        bool isLeftChildOf(Node<Key, T> *_parent) {
            return _parent->getLeft() == this;
        }

        bool isRightChildOf(Node<Key, T> *_parent) {
            return _parent->getRight() == this;
        }
        
        bool isLeftChild(){
            return isLeftChildOf(parent);
        }

        bool isRightChild(){
            return isRightChildOf(parent);
        }

        void pushLeftBranch() {
            Node<Key, T> *chosenNode = left->maxLeaf();
            auto *replaceNode = new Node<Key, T>(chosenNode);

            if (hasParent()){
                if (isLeftChild()){
                    parent->createLeftChildRelation(replaceNode);
                }
                else {
                    parent->createRightChildRelation(replaceNode);
                }
            }

            replaceNode->createRightChildRelation(right);

            if (!chosenNode->isLeftChildOf(this)){
                replaceNode->createLeftChildRelation(left);
                chosenNode->getParent()->setRight(nullptr);
            }

            delete chosenNode;
        }

        void pushRightBranch() {
            Node<Key, T> *chosenNode = right->minLeaf();
            auto *replaceNode = new Node<Key, T>(chosenNode);

            if (hasParent()){
                if (isLeftChild()){
                    parent->createLeftChildRelation(replaceNode);
                }
                else {
                    parent->createRightChildRelation(replaceNode);
                }
            }

            replaceNode->createLeftChildRelation(left);

            if (!chosenNode->isRightChildOf(this)){
                replaceNode->createRightChildRelation(right);
                chosenNode->getParent()->setLeft(nullptr);
            }

            delete chosenNode;
        }

        Node<Key, T>* maxLeaf(){
            if (hasRight()) return right->maxLeaf();
            return this;
        }

        Node<Key, T>* minLeaf(){
            if (hasLeft())  return left ->minLeaf();
            return this;
        }
        
        void reset(){
            parent = left = right = nullptr;
        }
};

template<class Key, class T>
class BinaryTree {
    private:
        Node<Key, T>* root;
        int (*comp)(Key, Key);

    public:
        BinaryTree(Node<Key, T> *root = nullptr){
            this->comp = *[](Key a, Key b){
                if (a < b) return -1;
                if (a > b) return  1;
                return 0;
            };

            this->root = root;
        }

        BinaryTree(Node<Key, T> *root, int (*comp)(Key, Key)) {
            this->root = root;
            this->comp = comp;
        }
        
        ~BinaryTree() { delete root; }
        
        int size() { return size(root); }
        
        int size(Node<Key, T> *_root) {
            if (_root == nullptr) return 0;

            Node<Key, T> *left = _root->getLeft();
            Node<Key, T> *right = _root->getRight();

            return size(left) + size(right) + 1;
        }


        bool isEmpty()                  { return root == nullptr; }
        bool isRoot(Node<Key, T> *node) { return node == root; }
        
        bool isInternal(Node<Key, T> *node) { return node->hasLeft() || node->hasRight(); }
        bool isExternal(Node<Key, T> *node) { return node->hasNoChildren(); }

        void preOrder (ostream& out = cout) { preOrder (root, out); }
        void inOrder  (ostream& out = cout) { inOrder  (root, out); }
        void postOrder(ostream& out = cout) { postOrder(root, out); }

        void preOrder(Node<Key, T> *curr, ostream& out = cout) {
            if(isEmpty()) return;

            Node<int, T> *left = curr->getLeft(), *right = curr->getRight();

            out << curr->getElem() << ' ';
            if (left != nullptr) preOrder(left, out);
            if (right != nullptr) preOrder(right, out);
        }
        
        void inOrder(Node<Key, T> *curr, ostream& out = cout) {
            if(isEmpty()) return;

            Node<Key, T> *left = curr->getLeft(), *right = curr->getRight();

            if (left != nullptr) inOrder(left, out);
            out << curr->getElem() << ' ';
            if (right != nullptr) inOrder(right, out);
        }

        void postOrder(Node<Key, T> *curr, ostream& out = cout) {
            if(isEmpty()) return;

            Node<int, T> *left = curr->getLeft(), *right = curr->getRight();

            if (left != nullptr) postOrder(left, out);
            if (right != nullptr) postOrder(right, out);
            out << curr->getElem() << ' ';
        }
        
        Node<Key, T>* search(Key key){
            return search(key, root);
        }

        Node<Key, T>* search(Key key, Node<Key, T> *node) {
            if (node == nullptr) return node;
            
            if (comp(key, node->getKey()) == -1) return search(key, node-> getLeft());
            if (comp(key, node->getKey()) ==  1) return search(key, node->getRight());
            
            return node;
        }

        void insert(Key key, T elem) {
            auto *newNode = new Node<Key, T>(key, elem);
            insert(root, newNode);
        }

        void insert(Node<Key, T> *&_root, Node<Key, T> *newNode) {
            if (_root == nullptr) {
                _root = newNode;
            }
            else if (comp(newNode->getKey(), _root->getKey()) == -1){
                if (_root->hasLeft()) 
                    insert(_root->getLeft(), newNode);
                else 
                    _root->createLeftChildRelation(newNode);
            }
            else if (comp(newNode->getKey(), _root->getKey()) == 1) {
                if (_root->hasRight()) 
                    insert(_root->getRight(), newNode);
                else
                    _root->createRightChildRelation(newNode);
            }
        }

        void remove(Key key) {
            Node<Key, T> *node = search(key, root);
            remove(node);
        }

        void remove(Node<Key, T> *node) {
            if (node == nullptr) return;

            Node<Key, T> *parent, *left, *right;
            parent = node->getParent();
            left   = node->getLeft();
            right  = node->getRight();

            if (isRoot(node)){
                removeRoot();
                return;
            }
            
            if (isExternal(node)) {
                if (node->isLeftChildOf(parent))
                    parent->setLeft(nullptr);
                else 
                    parent->setRight(nullptr);
                    
                delete node;
            }
            else if (node->hasOnlyLeftChild()) {
                if (node->isLeftChildOf(parent)) 
                    parent->createLeftChildRelation(left);
                else
                    parent->createRightChildRelation(left);
                
                delete node;
            }
            else if (node->hasOnlyRightChild()) {
                if (node->isLeftChildOf(parent)) 
                    parent->createLeftChildRelation(right);
                else 
                    parent->createRightChildRelation(right);
                    
                delete node;
            }
            else {
                int leftSize = size(left);
                int rightSize = size(right);
                
                if (leftSize > rightSize) {
                    node->pushLeftBranch();
                    delete node;
                }
                else {
                    node->pushRightBranch();
                    delete node;
                }
            }
        }
        
        void removeRoot(){
            Node<Key, T> *left, *right;
            left  = root->getLeft();
            right = root->getRight();

            int leftSize = size(left);
            int rightSize = size(right);

            if (leftSize == 0 && rightSize == 0){
                delete root;
                root = nullptr;
            }
            else if (leftSize > rightSize){
                root->pushLeftBranch();
                delete root;
                root = left->getParent();
            }
            else {
                root->pushRightBranch();
                delete root;
                root = right->getParent();
            }
        }
        
        
        T rootElem(){
            return root->getElem();
        }
};

#endif
