/********************************************************************************
 *		DICT
 *		author(s): Jonathan Ho
 *		citations:
 *
 *		goal: Create a linked list data structure with structs
 *
 *
 *
 ********************************************************************************/


#include <iostream> 
#include <string>
#include <fstream>
#include <cctype>
#include "LinkedList.h"
#include "testll.h"


#define DEFAULT_DICT "dictionary1.txt"
#define DEFAULT_OUTPUT_FILE "dict-updated.txt"

using namespace std;

enum Actions {
    QUIT, COUNT, PRINT_TO_SCREEN, ADD_WORD, LINEAR_SEARCH, DELETE_WORD, BINARY_SEARCH,
    INSERT_IN_ORDER, SWAP, BUBBLE_SORT, SELECTION_SORT, MERGE_DICTS,
    MERGE_SORT, LOAD_NEW_DICT, WRITE_DICT_TO_FILE, UNIT_TEST
};

int max_menu_option = UNIT_TEST;
int max_dict_option = 12;


void printMenuOptions();
int getMenuChoice();
void incompleteFunction();
void loadDict(LinkedList* currList, const string fileName);
void loadDict(LinkedList* currList, const int dictNum);
int pickDict(const int currDict, const int userMode);
void writeToDict(const LinkedList* currList);
string cleanWord(const string& input);
Node* findWord(LinkedList* myList, string userWord);
void linearSearch(LinkedList* myList);
void addWord(LinkedList* myList);
void deleteWord(LinkedList* myList);
void insertWord(LinkedList* myList);
void mergeDictionaries(LinkedList* myList, const int currDict);


int main() {
    int currOption = getMenuChoice();
    LinkedList* myList = new LinkedList;
    int currDict = 1;
    loadDict(myList, DEFAULT_DICT);

    while (currOption != QUIT) {

        switch (currOption) {

        case COUNT:
            cout << "There are " << (*myList).size() << " words in dictionary #" << currDict << "." << endl;

            currOption = getMenuChoice();
            break;

        case PRINT_TO_SCREEN:
            (*myList).printWords();

            currOption = getMenuChoice();
            break;

        case ADD_WORD:
            addWord(myList);

            currOption = getMenuChoice();
            break;

        case LINEAR_SEARCH:
            linearSearch(myList);

            currOption = getMenuChoice();
            break;

        case DELETE_WORD:
            deleteWord(myList);

            currOption = getMenuChoice();
            break;

        case INSERT_IN_ORDER:
            insertWord(myList);

            currOption = getMenuChoice();
            break;


        case MERGE_DICTS:
            mergeDictionaries(myList, currDict);
            currDict = max_dict_option + 1;

            currOption = getMenuChoice();
            break;


        case LOAD_NEW_DICT:
            currDict = pickDict(currDict, 0);
            loadDict(myList, currDict);

            currOption = getMenuChoice();
            break;

        case WRITE_DICT_TO_FILE:
            writeToDict(myList);

            currOption = getMenuChoice();
            break;

        case UNIT_TEST:
            promptUnitTest();

            currOption = getMenuChoice();
            break;

        default:
            incompleteFunction();

            currOption = getMenuChoice();
            break;

        }

    }

    return 0;
}


void printMenuOptions() {
    cout << "--------------------------------------------" << endl;
    cout << "Options menu: " << endl;
    cout << "(" << COUNT << ") Count - get number of words in dictionary list" << endl;
    cout << "(" << PRINT_TO_SCREEN << ") Print words to screen" << endl;
    cout << "(" << ADD_WORD << ") Add a word (to end of dictionary list)" << endl;
    cout << "(" << LINEAR_SEARCH << ") Find a word (Linear Search)" << endl;
    cout << "(" << DELETE_WORD << ") Find word, delete if found " << endl;
    cout << "(" << BINARY_SEARCH << ") Find a word - Binary Search (assumes words are sorted alphabetically)" << endl;
    cout << "(" << INSERT_IN_ORDER << ") Find word, insert if not found (assumes words are sorted alphabetically)" << endl;
    cout << "(" << SWAP << ") Swap two words" << endl;
    cout << "(" << BUBBLE_SORT << ") Sort words (Bubble Sort)" << endl;
    cout << "(" << SELECTION_SORT << ") Sort words (Selection Sort)" << endl;
    cout << "(" << MERGE_DICTS << ") Merge two dictionaries (assumes words are sorted alphabetically)" << endl;
    cout << "(" << MERGE_SORT << ") Sort words (Merge Sort)" << endl;
    cout << "(" << LOAD_NEW_DICT << ") Load a dictionary (closes current dictionary)" << endl;
    cout << "(" << WRITE_DICT_TO_FILE << ") Write current dictionary to file" << endl;
    cout << "(" << UNIT_TEST << ") Unit test of data structure" << endl;
    cout << "Enter a number from 1 to " << max_menu_option << ", or 0 to exit:     " << endl;
}

int getMenuChoice() {
    int currOption;
    printMenuOptions();
    bool validOption = false;

    while (validOption == false) {

        cin >> currOption;
        if (currOption < 0 || currOption > max_menu_option) {
            cout << "Error! Input must be a number between 1 and " << max_menu_option << ", or 0 to exit." << endl;
            printMenuOptions();
        }

        else {

            if (currOption == 0) {
                cout << "Thank you! Bye!" << endl;
                exit(0);
            }

            validOption = true;
            break;
        }

    }

    return currOption;
}

void incompleteFunction() {
    cout << "Coming soon!" << endl;
}

void loadDict(LinkedList* currList, const string fileName) {
    string currWord;
    ifstream inFS;
    inFS.open(fileName);

    if ((*currList).size() != 0) {
        (*currList).clear();
    }

    if (!inFS.is_open()) {
        cout << "Error: File not opened." << endl;
        exit(0);
    }

    while (inFS >> currWord) {
        (*currList).push_back(currWord);
    }

    inFS.close();
}

void loadDict(LinkedList* currList, const int dictNum) {
    string currWord;
    string fileName;
    ifstream inFS;

    fileName = "dictionary" + to_string(dictNum) + ".txt";

    inFS.open(fileName);

    (*currList).clear();
    if (!inFS.is_open()) {
        cout << "Error: File not opened." << endl;
        exit(0);
    }

    while (inFS >> currWord) {
        (*currList).push_back(currWord);
    }

    inFS.close();
}


int pickDict(const int currDict, const int userMode) {

    int newDict = 0;
    bool isValid = false;

    if (userMode == MERGE_DICTS) {
        cout << "Reminder: for merge to work properly, dictionaries must already be sorted." << endl;
    }


    while (isValid == false) {
        cout << endl << "Which Dictionary should be opened? Enter a number from \"1\", to \"" << max_dict_option << "\":" << endl;

        cin >> newDict;


        if (newDict < 1 || newDict > max_dict_option) {
            cout << "ERROR! Cannot read chosen dictionary dictionary" << newDict << ".txt. Dictionary " << currDict << " remains open." << endl;
            return currDict;
        }

        else if (newDict == currDict) {
            cout << "That dictionary is already open! Pick another." << endl;
            continue;      //returns to the start of the while loop
        }

        else if (userMode == MERGE_DICTS) {
            isValid = true;
            cout << "Merging..." << endl;
            break;
        }

        else {
            isValid = true;
            cout << "Dictionary " << newDict << " is now open." << endl;
            break;      //probably don't need to do break/continue and bool isValid at the same time; just do one or the other
        }

    }

    return newDict;

}

void writeToDict(const LinkedList* currList) {

    ifstream inFS;
    ofstream outFS;
    string fileName;
    Node* currNode = (*currList).getHead();

    cout << "Enter name of file (.txt will be appended automatically), or enter 'd' to use default filename: ";
    cin >> fileName;

    if (fileName == "d") {

        fileName = DEFAULT_OUTPUT_FILE;

    }

    else {

        fileName += ".txt";

    }

    inFS.open(fileName);
    if (inFS.is_open()) {
        cout << "ERROR! The file " << fileName << " already exists." << endl;
        return;
    }

    outFS.open(fileName);
    cout << endl << "Writing to file..." << endl;
    while (currNode != NULL) {

        outFS << (*currNode).getData() << endl;
        currNode = (*currNode).getNext();

    }

    cout << "\t...Done!" << endl;
    outFS.close();

    /*
    inFS.open(fileName);
    if (inFS.is_open()) {
       cout << "Successful print" << endl;
    }

    inFS >> fileName;
    cout << fileName << endl;
    */
}

string cleanWord(const string& input) {

    string newString;
    unsigned int i;

    for (i = 0; i < input.size(); i++) {

        if (isalpha(input.at(i)) != 0) {        //isalpha() returns an int, not a bool... what the fuck??
            newString.push_back(input.at(i));
        }

    }

    for (i = 0; i < newString.size(); i++) {
        newString.at(i) = tolower(newString.at(i));
    }

    return newString;

}

void getPrevandNext(Node* currNode) {

    if ((*currNode).getPrev() == NULL) {
        cout << "There is no word before " << (*currNode).getData() << ". It is the first word." << endl;
    }

    else {
        cout << "The previous word would be '" << (*(*currNode).getPrev()).getData() << "'." << endl;
    }



    if ((*currNode).getNext() == NULL) {
        cout << "There is no word after " << (*currNode).getData() << ". It is the last word." << endl;
    }

    else {
        cout << "The next word would be '" << (*(*currNode).getNext()).getData() << "'." << endl;
    }

}

Node* findWord(LinkedList* myList, string userWord) {

    Node* currNode = (*myList).getHead();

    cout << "Your word was '" << userWord << "'." << endl;

    for (unsigned int i = 0; i < (*myList).size(); i++) {

        if ((*currNode).getData() == userWord) {
            getPrevandNext(currNode);

            return currNode;
        }

        currNode = (*currNode).getNext();

    }

    cout << "We did not find your word. ";
    return NULL;

}

void linearSearch(LinkedList* myList) {

    string userWord;

    cout << "Enter a word to find: ";
    cin >> userWord;
    userWord = cleanWord(userWord);
    findWord(myList, userWord);

}

void addWord(LinkedList* myList) {

    Node* currNode = NULL;
    string userWord = "";

    cout << "Enter a word to add to the end of the chosen dictionary: ";
    cin >> userWord;
    userWord = cleanWord(userWord);
    currNode = findWord(myList, userWord);

    if (currNode == NULL) {
        cout << "Adding word to dictionary..." << endl;
        (*myList).push_back(userWord);
        currNode = (*myList).getTail();

        cout << "\tAdded!" << endl;

        getPrevandNext(currNode);
    }

}

void deleteWord(LinkedList* myList) {

    Node* currNode = NULL;
    string userWord = "";

    cout << "Enter a word to delete from the chosen Dictionary: ";
    cin >> userWord;
    userWord = cleanWord(userWord);
    currNode = findWord(myList, userWord);

    if (currNode != NULL) {    //node has been found

        (*myList).deleteWord(currNode);
        cout << "The word '" << userWord << "' has been deleted." << endl;
    }

}

void insertWord(LinkedList* myList) {

    Node* currNode = NULL;
    string userWord = "";

    cout << "Enter a word to insert in order in the chosen Dictionary: ";
    cin >> userWord;
    userWord = cleanWord(userWord);
    currNode = findWord(myList, userWord);


    if (currNode == NULL) {    //word has not been found

        cout << "Adding word to dictionary..." << endl;
        currNode = (*myList).getHead();

        while (currNode != NULL) {

            if (userWord < (*currNode)) {

                currNode = (*myList).insert_before(userWord, currNode);
                cout << "Inserted!" << endl;

                getPrevandNext(currNode);
                return;

            }

            currNode = (*currNode).getNext();

        }

        //insert at end of list
        (*myList).push_back(userWord);
        currNode = (*myList).getTail();

        cout << "Inserted!" << endl;

        getPrevandNext(currNode);
        return;

    }

}


void mergeDictionaries(LinkedList* myList, const int currDict) {

    unsigned int userChoice = pickDict(currDict, MERGE_DICTS);


    //construct new Linked List for second dictionary
    LinkedList* newList = new LinkedList;
    loadDict(newList, userChoice);

    (*myList).mergeDicts(newList);
    (*newList).setHead(NULL);
    (*newList).setTail(NULL);
    delete newList;
    newList = NULL;
    cout << "\t...Done!" << endl;

}
