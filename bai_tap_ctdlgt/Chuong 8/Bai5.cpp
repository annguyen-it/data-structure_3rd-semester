#include <bits/stdc++.h>
#include "./class/Dictionary.cpp"

using namespace std;

class App {
    private:
        Dictionary dictionary;
        string choice;
        bool exit;

    public:
        App(){
            do {
                Menu();
                Execute();
            } while (!exit);

        }

        void Menu(){
            cout << "\n\n=====================================";
            cout << "\n\nDICTIONARY APLLICATION";
            cout << "\n\n1. Import dictionary";
            cout << "\n2. Add new word";
            cout << "\n3. Remove word";
            cout << "\n4. Search word";
            cout << "\n5. Export dictionary";
            cout << "\n0. Exit application";

            cout << "\n\nPlease enter your choice: ";
            cin >> choice;
            cin.ignore();
        }

        void Execute(){
            if (choice.size() != 1) return Error();
            int int_choice = choice[0] - '0';
            
            switch(int_choice){
                case 1:
                    return ImportData();

                case 2:
                    return AddNewWord();

                case 3:
                    return DeleteWord();

                case 4:
                    return SearchWord();

                case 5:
                    return ExportData();

                case 0:
                    return Exit();

                default:
                    return Error();
            }
        }

        void ImportData(){
            cout << "\nEnter file name need to import: ";
            string fileName;
            cin >> fileName;

            dictionary.importFile("./src/" + fileName);
        }

        void AddNewWord(){
            string word, partOfSpeech, meaning;
            cout << "\nEnter new word need to add: ";
            getline(cin, word);
            cout << "Meaning: ";
            getline(cin, meaning);

            Word newWord(word, meaning);
            dictionary.insert(newWord);
        }

        void DeleteWord(){
            cout << "\nEnter word need to remove: ";
            string word;
            cin >> word;

            dictionary.remove(word);
        }

        void SearchWord(){
            cout << "\nEnter word need to search: ";
            string word;
            cin >> word;
            cout << '\n';
            
            dictionary.search(word);
        }

        void ExportData(){
            cout << "\nEnter file name need to export: ";
            string fileName;
            cin >> fileName;

            dictionary.exportFile("./src/" + fileName);
        }

        void Exit(){
            exit = true;
        }

        static void Error(){
            cout << "Input is invalid, please try again!";
        }
};

int main() {
    App();
    return 0;
}
