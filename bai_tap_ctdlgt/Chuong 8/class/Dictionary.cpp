#include <bits/stdc++.h>
#include "../Bai4.cpp"
#include "Word.cpp"

#ifndef __Dictionary__cpp
#define __Dictionary__cpp

using namespace std;

class Dictionary {
    private:
        BinaryTree<string, Word>* tree;

    public:
        Dictionary(){
            tree = new BinaryTree<string, Word>;
        }

        void importFile(const string& fileName){
            ifstream fi(fileName, ios::in);

            if (fi.is_open()){
                string word, partOfSpeech, meaning;
                while (getline(fi, word, '\n')){
                    getline(fi, meaning, '\n');

                    Word* newWord = new Word (word, meaning);

                    tree->insert(word, *newWord);
                }
            }
            else {
                cout << "Read file error!\n";
            }
        }

        void insert(Word word){
            tree->insert(word.getWord(), word);
        }

        void remove(const string& word){
            tree->remove(word);
        }

        void search(const string& word){
            Node<string, Word>* node = tree->search(word);
            if (node == nullptr){
                cout << '\n' << '"' << word << '"' << " is not found!";
            }
            else {
                cout << node->getElem();
            }
        }

        void exportFile(const string& fileName){
            ofstream of(fileName);

            if (of.is_open()){
                int n = tree->size();
                of << "\t\tDICTIONARY\n";
                of << "(" << n << " word is available)\n\n\n ";
                tree->inOrder(of);
            }
            else {
                cout << "Write file error!\n";
            }
        }
};

#endif
