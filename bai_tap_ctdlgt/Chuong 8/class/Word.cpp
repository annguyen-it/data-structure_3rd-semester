#include <bits/stdc++.h>

#ifndef __Word__cpp
#define __Word__cpp

using namespace std;

class Word {
    private:
        string word, meaning;

    public:
        Word()= default;

        Word(const string& _word, const string& _meaning){
            word = _word;
            meaning = _meaning;
        }

        string getWord() { return word; }

        friend ostream& operator<< (ostream& out, const Word& w){
            out << w.word << ": " << w.meaning << "\n";
            return out;
        }
};

#endif
