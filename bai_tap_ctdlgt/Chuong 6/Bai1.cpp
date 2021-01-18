#include <bits/stdc++.h>

using namespace std;

template <class T>
class TreeNode {
    private:
        T elem;
        TreeNode *parent;
        list<TreeNode*> child;
        
    public:
        TreeNode* getParent(){
            return parent;
        }
        
        void setParent(TreeNode *parent){
            this->parent = parent;
        }
        
        TreeNode* getChild(int i){
            auto c = child.begin();
            for (int j=0; j<i; j++){
                c++;
                if (c == child.end()) return nullptr;
            }
            
            return *c;
        }
        
        void insertChild(T elem){
            child.push(elem);
        }
        
        list<TreeNode*> getChild(){
            return child;
        }
        
        T getElem(){
            return elem;
        }
        
        void setElem(T elem){
            this->elem = elem;
        }
};

template <class T>
class Tree {
    private:
        TreeNode<T> *root;
    
    public:
        int size(){
            int n = this->root->getChild().size();
            if (n == 0) return 1;
            
            int s = 0;
            for (int i=0; i<n; i++){
                Tree *subTree;
                subTree->root = this->root->getChild(i);
                s += subTree->size();
            }
            
            return s;
        }
        
        bool isEmpty(){
            return root->getChild().size() == 0;
        }
        
        bool isInternal(TreeNode<T>* node){
            return node->getChild().size() > 0;
        }
        
        bool isExternal(TreeNode<T>* node){
            return node->getChild().size() == 0;
        }
        
        bool isRoot(TreeNode<T>* node){
            return node == root;
        }
        
        void preOrder(TreeNode<T>* node){
            cout << node->getElem() << ' ';
            for (auto child : node->getChild()){
                preOrder(child);
            }
        }
        
        void inOrder(TreeNode<T>* node){
            int n = node->getChild().size();
            if (n > 0){
                inOrder(node->getChild(0));
            }
            
            cout << node->getElem() << ' ';
            
            if (n > 1){
                for (int i=1; i<n; i++){
                    inOrder(node->getChild(i));
                }
            }
        }
        
        void postOrder(TreeNode<T>* node){
            for (auto child : node->getChild()){
                preOrder(child);
            }
            cout << node->getElem() << ' ';
        }
        
        void insert(TreeNode<T>* parent, T elem){
            parent->insertChild(elem);
        }
        
        void remove(TreeNode<T>* node){
            for (auto child : node->getChild()){
                if (child->getChild().size()){
                    remove(child);
                }
            }
            
            node->getChild().clear;
            node->getParent()->getChild().erase(node);
        }
        
        T _root(){
            return root->getElem();
        }
};

int main(){
    Tree<int> *t;
    cout << t->size();

	return 0;
}

