/********************************************************************************
 *		TEST1.cpp
 *		author(s): Corey Carito   <ccarito@sfsu.edu>
 *		citations:
 *
 *		goal: test node and linked list data structures
 *
 *		overview:
 *
 *		(1) test that pointers are defined (in empty list, for instance)
 *		(2) test creation/deletion
 *		(3) test overload of comparison operators
 *    (4) test overload of += operator
 *
 ********************************************************************************/
#include <iostream> 
#include <string>
#include "LinkedList.h"
#include "testll.h"

using namespace std;

enum Choices { DONE, PRIVATE, NODE_BASIC, LL_BASIC, NODE_COMP_OPERATORS, LL_COMP_OPERATORS, RUN_ALL };

int max_test_menu_option = RUN_ALL;


void outputList(LinkedList* listPtr) {
	Node* current = (*listPtr).getHead();

	while (current != NULL) {
		cout << (*current).getData();

		current = (*current).getNext();
		if (current != NULL) {
			cout << ", ";
		}
	}
	cout << endl;
}

void testLinkedListCompOperator() {
	// test #LL_C: create lists, check push_back,  +=
	{
		cout << "\n-----Test LL_C --------------------" << endl;
		LinkedList* list1Ptr = new LinkedList;
		LinkedList* list2Ptr = new LinkedList;

		(*list1Ptr).push_back("apple");
		(*list1Ptr).push_back("banana");
		(*list1Ptr).push_back("cherry");
		(*list1Ptr).push_back("grape");

		cout << "# 1. ";
		outputList(list1Ptr);	//NEED TO MAKE THIS A COMPARISON TEST
		if ((*(*list1Ptr).getTail()).getNext() == NULL) 	cout << "# 1a. Tail->next is NULL" << endl;
		else 												cout << "\t\tERROR: # 1a. Tail->next is not NULL" << endl;
		if ((*(*list1Ptr).getHead()).getPrev() == NULL) 	cout << "# 1b. Head->Prev is NULL" << endl;
		else 												cout << "\t\tERROR: # 1b. Head->Prev is not NULL" << endl;
		if ((*list1Ptr).size() == 4) 	 					cout << "# 1c. size is " << (*list1Ptr).size() << endl;
		else 												cout << "\t\tERROR: # 1c. size is " << (*list1Ptr).size() << endl;

		Node* tNodeAptr = new Node("kiwi");
		Node* tNodeBptr = new Node("orange");
		Node* tNodeCptr = new Node("tangerine");

		(*list2Ptr).push_back(tNodeAptr);
		(*list2Ptr).push_back(tNodeBptr);
		(*list2Ptr).push_back(tNodeCptr);


		cout << "\n# 2. ";
		outputList(list2Ptr);	//NEED TO MAKE THIS A COMPARISON TEST
		if ((*(*list2Ptr).getTail()).getNext() == NULL) 	cout << "# 2a. Tail->next is NULL" << endl;
		else 												cout << "\t\tERROR: # 1a. Tail->next is not NULL" << endl;
		if ((*(*list2Ptr).getHead()).getPrev() == NULL) 	cout << "# 2b. Head->Prev is NULL" << endl;
		else 												cout << "\t\tERROR: # 1b. Head->Prev is not NULL" << endl;
		if ((*list2Ptr).size() == 3) 	 					cout << "# 2c. size is 3" << endl;
		else 												cout << "\t\tERROR: # 1c. size is " << (*list2Ptr).size() << endl;

		*list1Ptr += *list2Ptr;

		cout << "\n# 3. ";
		outputList(list1Ptr);	//NEED TO MAKE THIS A COMPARISON TEST
		if ((*list1Ptr).size() == 7) 	 					cout << "# 3a. size is 7" << endl;
		else 												cout << "\t\tERROR: # 3a. size is " << (*list1Ptr).size() << endl;
		if ((*(*list1Ptr).getTail()).getNext() == NULL) 	cout << "# 3b. Tail->next is NULL" << endl;
		else 												cout << "\t\tERROR: # 3b. Tail->next is not NULL" << endl;
		if ((*(*list1Ptr).getHead()).getPrev() == NULL) 	cout << "# 3c. Head->Prev is NULL" << endl;
		else 												cout << "\t\tERROR: # 3c. Head->Prev is not NULL" << endl;
		cout << "# 3d. ";
		outputList(list2Ptr);	//NEED TO MAKE THIS A COMPARISON TEST
		if ((*list2Ptr).size() == 0) 	 					cout << "# 3e. size is  " << (*list2Ptr).size() << endl;
		else 												cout << "\t\tERROR: # 3e. size is " << (*list2Ptr).size() << endl;
		if ((*list2Ptr).getTail() == NULL) 					cout << "# 3f. Tail is NULL" << endl;
		else 												cout << "\t\tERROR: # 3f. Tail is not NULL" << endl;
		if ((*list2Ptr).getHead() == NULL) 					cout << "# 3g. Head is NULL" << endl;
		else 												cout << "\t\tERROR: # 3g. Head is not NULL" << endl;


		delete list1Ptr;
		list1Ptr = NULL;
		delete list2Ptr;
		list2Ptr = NULL;


	}



} //end testLinkedListCompOperator()



void testPrivate() {
	// everything in this block should fail to compile
	// check the compilation and comment out one at a time as they (properly) fail

	/*

	Node * tNodePtr = new Node;

	if ((*tNodePtr).data == "") 	cout << "# 1. Word is empty" << endl;
	if ((*tNodePtr).next == NULL) 	cout << "# 2. Next is NULL" << endl;
	if ((*tNodePtr).prev == 0) 	cout << "# 3. Prev is NULL" << endl;
	delete tNodePtr;
	tNodePtr = NULL;


	// everything in this block should fail to compile
	// check the compilation and comment out one at a time as they (properly) fail

	LinkedList * lTestPtr = new LinkedList;

	if ((*lTestPtr).tail == NULL) 	cout << "# 1. Tail is NULL" << endl;
	if ((*lTestPtr).head == NULL) 	cout << "# 2. Head is NULL" << endl;
	if ((*lTestPtr).count == 0) 	 	cout << "# 3. size is 0" << endl;
	delete lTestPtr;
	lTestPtr = NULL;

	*/

	cout << "Done with \'testPrivate()\'." << endl;
}


void testNodeBasic() {
	// test #A: create Node

	cout << "\n-----Test A --------------------" << endl;
	Node* tNodePtr = new Node;

	if ((*tNodePtr).getData() == "") 	cout << "# 1. Word is empty" << endl;
	else 								cout << "\t\tERROR: # 1. Word is " << (*tNodePtr).getData() << endl;
	if ((*tNodePtr).getNext() == NULL) 	cout << "# 2. Next is NULL" << endl;
	else 								cout << "\t\tERROR: # 2. Next is not NULL" << endl;
	if ((*tNodePtr).getPrev() == NULL) 	cout << "# 3. Prev is NULL" << endl;
	else 								cout << "\t\tERROR: # 3. Prev is not NULL" << endl;
	delete tNodePtr;
	tNodePtr = NULL;


	// test #B: create Node with word

	cout << "\n-----Test B --------------------" << endl;
	tNodePtr = new Node("test");

	if ((*tNodePtr).getData() == "test")cout << "# 1. Word is \'test\'" << endl;
	else 								cout << "\t\tERROR: # 1. Word is " << (*tNodePtr).getData() << endl;
	if ((*tNodePtr).getNext() == NULL) 	cout << "# 2. Next is NULL" << endl;
	else 								cout << "\t\tERROR: # 2. Next is not NULL" << endl;
	if ((*tNodePtr).getPrev() == NULL) 	cout << "# 3. Prev is NULL" << endl;
	else 								cout << "\t\tERROR: # 3. Prev is not NULL" << endl;
	delete tNodePtr;
	tNodePtr = NULL;


	// test #C: create Node with word & update

	cout << "\n-----Test C --------------------" << endl;
	tNodePtr = new Node("test");

	if ((*tNodePtr).getData() == "test")	cout << "# 1. Word is \'test\'" << endl;
	else 									cout << "\t\tERROR: # 1. Word is " << (*tNodePtr).getData() << endl;
	(*tNodePtr).setData("change");
	if ((*tNodePtr).getData() == "change")	cout << "# 2. Word is \'change\'" << endl;
	else 									cout << "\t\tERROR: # 2. Word is " << (*tNodePtr).getData() << endl;

	Node* tNextPtr = new Node("second");
	(*tNodePtr).setNext(tNextPtr);

	Node* tPrevPtr = new Node("first");
	(*tNodePtr).setPrev(tPrevPtr);

	if ((*tNodePtr).getNext() == tNextPtr && (*(*tNodePtr).getNext()).getData() == "second")
		cout << "# 3. Next is new next pointer whose word is \'" << (*(*tNodePtr).getNext()).getData() << "\'" << endl;
	else 									cout << "\t\tERROR: # 3. Next fails" << endl;
	if ((*(*tNodePtr).getNext()).getNext() == NULL) 	cout << "# 4. Next->next is NULL " << endl;
	else 									cout << "\t\tERROR: # 4. Next->next is not NULL" << endl;
	if ((*tNodePtr).getPrev() == tPrevPtr && (*(*tNodePtr).getPrev()).getData() == "first")
		cout << "# 5. Prev is new prev pointer whose word is \'" << (*(*tNodePtr).getPrev()).getData() << "\'" << endl;
	else 									cout << "\t\tERROR: # 5. Prev is not NULL" << endl;
	if ((*(*tNodePtr).getPrev()).getPrev() == NULL) 	cout << "# 6. Prev->prev is NULL " << endl;
	else 									cout << "\t\tERROR: # 6. Prev->prev is not NULL" << endl;
	delete tNodePtr;
	tNodePtr = NULL;
	delete tNextPtr;
	tNextPtr = NULL;
	delete tPrevPtr;
	tPrevPtr = NULL;

} // end testNodeBasic()


void testNodeCompOperators() {

	// test #D: test comparison operators, Node v Node
	cout << "\n-----Test D --------------------" << endl;
	Node* tNodeAptr = new Node("apple");
	Node* tNodeBptr = new Node("banana");
	Node* tNodeB2ptr = new Node("banana");
	Node* tNodeCptr = new Node("cherry");

	if (*tNodeAptr == *tNodeBptr)		cout << "\t\tERROR: # 1. \'apple\' should NOT == \'banana\'" << endl;
	else 								cout << "# 1. (\'apple\' == \'banana\') is FALSE" << endl;
	if (*tNodeAptr != *tNodeBptr)		cout << "# 2. (\'apple\' != \'banana\') is TRUE" << endl;
	else 								cout << "\t\tERROR: # 2. \'apple\' should != \'banana\'" << endl;
	if (*tNodeBptr == *tNodeB2ptr)		cout << "# 3. (\'banana\' == \'banana\') is TRUE" << endl;
	else 								cout << "\t\tERROR: # 3. \'banana\' should == \'banana\'" << endl;
	if (*tNodeBptr != *tNodeB2ptr)		cout << "\t\tERROR: # 4. \'banana\' should NOT != \'banana\'" << endl;
	else 								cout << "# 4. (\'banana\' != \'banana\') is FALSE" << endl;
	cout << endl;

	if (*tNodeAptr > *tNodeBptr)		cout << "\t\tERROR: # 5. \'apple\' is NOT > \'banana\'" << endl;
	else 								cout << "# 5. (\'apple\' > \'banana\') is FALSE" << endl;
	if (*tNodeCptr > *tNodeBptr)		cout << "# 6. (\'cherry\' > \'banana\') is TRUE" << endl;
	else 								cout << "\t\tERROR: # 6. \'cherry\' should be > \'banana\'" << endl;
	if (*tNodeBptr > *tNodeB2ptr)		cout << "\t\tERROR: # 7. \'banana\' should NOT > \'banana\'" << endl;
	else 								cout << "# 7. (\'banana\' > \'banana\') is FALSE" << endl;
	cout << endl;


	if (*tNodeAptr < *tNodeBptr)		cout << "# 8. (\'apple\' < \'banana\') is TRUE" << endl;
	else 								cout << "\t\tERROR: # 8. \'apple\' is  < \'banana\'" << endl;
	if (*tNodeCptr < *tNodeBptr)		cout << "\t\tERROR: # 9. \'cherry\' should NOT be < \'banana\'" << endl;
	else 								cout << "# 9. (\'cherry\' < \'banana\') is FALSE" << endl;
	if (*tNodeBptr < *tNodeB2ptr)		cout << "\t\tERROR: # 10. \'banana\' should NOT < \'banana\'" << endl;
	else 								cout << "# 10. (\'banana\' < \'banana\') is FALSE" << endl;
	cout << endl;


	if (*tNodeAptr >= *tNodeBptr)		cout << "\t\tERROR: # 11. \'apple\' is NOT >= \'banana\'" << endl;
	else 								cout << "# 11. (\'apple\' >= \'banana\') is FALSE" << endl;
	if (*tNodeCptr >= *tNodeBptr)		cout << "# 12. (\'cherry\' >= \'banana\') is TRUE" << endl;
	else 								cout << "\t\tERROR: # 12. \'cherry\' should be >= \'banana\'" << endl;
	if (*tNodeBptr >= *tNodeB2ptr)		cout << "# 13. (\'banana\' >= \'banana\') is TRUE" << endl;
	else 								cout << "\t\tERROR: # 13. \'banana\' is >= \'banana\'" << endl;
	cout << endl;


	if (*tNodeAptr <= *tNodeBptr)		cout << "# 14. (\'apple\' <= \'banana\') is TRUE" << endl;
	else 								cout << "\t\tERROR: # 14. \'apple\' is  <= \'banana\'" << endl;
	if (*tNodeCptr <= *tNodeBptr)		cout << "\t\tERROR: # 15. \'cherry\' should NOT be <= \'banana\'" << endl;
	else 								cout << "# 15. (\'cherry\' <= \'banana\') is FALSE" << endl;
	if (*tNodeBptr <= *tNodeB2ptr)		cout << "# 16. (\'banana\' <= \'banana\') is TRUE" << endl;
	else 								cout << "\t\tERROR: # 16. \'banana\' is <= \'banana\'" << endl;


	delete tNodeAptr;
	tNodeAptr = NULL;
	delete tNodeBptr;
	tNodeBptr = NULL;
	delete tNodeB2ptr;
	tNodeB2ptr = NULL;
	delete tNodeCptr;
	tNodeCptr = NULL;


	// test #E: test comparison operators, Node v String
	cout << "\n-----Test E --------------------" << endl;
	tNodeAptr = new Node("apple");
	tNodeBptr = new Node("banana");
	tNodeB2ptr = new Node("banana");
	tNodeCptr = new Node("cherry");

	string	strB = "banana";

	if (*tNodeAptr == strB)		cout << "\t\tERROR: # 1. \'apple\' should NOT == \"banana\"" << endl;
	else 								cout << "# 1. (\'apple\' == \"banana\") is FALSE" << endl;
	if (*tNodeAptr != strB)		cout << "# 2. (\'apple\' != \"banana\") is TRUE" << endl;
	else 								cout << "\t\tERROR: # 2. \'apple\' should != \"banana\"" << endl;
	if (*tNodeBptr == strB)		cout << "# 3. (\'banana\' == \"banana\") is TRUE" << endl;
	else 								cout << "\t\tERROR: # 3. \"banana\" should == \"banana\"" << endl;
	if (*tNodeBptr != strB)		cout << "\t\tERROR: # 4. \'banana\' should NOT != \"banana\"" << endl;
	else 								cout << "# 4. (\'banana\' != \"banana\") is FALSE" << endl;
	cout << endl;

	if (*tNodeAptr > strB)		cout << "\t\tERROR: # 5. \'apple\' is NOT > \"banana\"" << endl;
	else 								cout << "# 5. (\'apple\' > \"banana\") is FALSE" << endl;
	if (*tNodeCptr > strB)		cout << "# 6. (\'cherry\' > \"banana\") is TRUE" << endl;
	else 								cout << "\t\tERROR: # 6. \'cherry\' should be > \"banana\"" << endl;
	if (*tNodeBptr > strB)		cout << "\t\tERROR: # 7. \'banana\' should NOT > \"banana\"" << endl;
	else 								cout << "# 7. (\'banana\' > \"banana\") is FALSE" << endl;
	cout << endl;


	if (*tNodeAptr < strB)		cout << "# 8. (\'apple\' < \"banana\") is TRUE" << endl;
	else 								cout << "\t\tERROR: # 8. \'apple\' is  < \"banana\"" << endl;
	if (*tNodeCptr < strB)		cout << "\t\tERROR: # 9. \'cherry\' should NOT be < \"banana\"" << endl;
	else 								cout << "# 9. (\'cherry\' < \"banana\") is FALSE" << endl;
	if (*tNodeBptr < strB)		cout << "\t\tERROR: # 10. \'banana\' should NOT < \"banana\"" << endl;
	else 								cout << "# 10. (\'banana\' < \"banana\") is FALSE" << endl;
	cout << endl;


	if (*tNodeAptr >= strB)		cout << "\t\tERROR: # 11. \'apple\' is NOT >= \"banana\"" << endl;
	else 								cout << "# 11. (\'apple\' >= \"banana\") is FALSE" << endl;
	if (*tNodeCptr >= strB)		cout << "# 12. (\'cherry\' >= \"banana\") is TRUE" << endl;
	else 								cout << "\t\tERROR: # 12. \'cherry\' should be >= \"banana\"" << endl;
	if (*tNodeBptr >= strB)		cout << "# 13. (\'banana\' >= \"banana\") is TRUE" << endl;
	else 								cout << "\t\tERROR: # 13. \'banana\' is >= \"banana\"" << endl;
	cout << endl;


	if (*tNodeAptr <= strB)		cout << "# 14. (\'apple\' <= \"banana\") is TRUE" << endl;
	else 								cout << "\t\tERROR: # 14. \'apple\' is  <= \"banana\"" << endl;
	if (*tNodeCptr <= strB)		cout << "\t\tERROR: # 15. \'cherry\' should NOT be <= \"banana\"" << endl;
	else 								cout << "# 15. (\'cherry\' <= \"banana\") is FALSE" << endl;
	if (*tNodeBptr <= strB)		cout << "# 16. (\'banana\' <= \"banana\") is TRUE" << endl;
	else 								cout << "\t\tERROR: # 16. \'banana\' is <= \"banana\"" << endl;


	delete tNodeAptr;
	tNodeAptr = NULL;
	delete tNodeBptr;
	tNodeBptr = NULL;
	delete tNodeB2ptr;
	tNodeB2ptr = NULL;
	delete tNodeCptr;
	tNodeCptr = NULL;



	// test #F: test comparison operators, Node v Node
	cout << "\n-----Test F --------------------" << endl;
	tNodeAptr = new Node("apple");
	tNodeBptr = new Node("banana");
	tNodeB2ptr = new Node("banana");
	tNodeCptr = new Node("cherry");

	string	strA = "apple",
		//strB = "banana",
		strC = "cherry";

	if (strA == *tNodeBptr)		cout << "\t\tERROR: # 1. \"apple\" should NOT == \'banana\'" << endl;
	else 								cout << "# 1. (\"apple\" == \'banana\') is FALSE" << endl;
	if (strA != *tNodeBptr)		cout << "# 2. (\"apple\" != \'banana\') is TRUE" << endl;
	else 								cout << "\t\tERROR: # 2. \"apple\" should != \'banana\'" << endl;
	if (strB == *tNodeB2ptr)		cout << "# 3. (\"banana\" == \'banana\') is TRUE" << endl;
	else 								cout << "\t\tERROR: # 3. \"banana\" should == \'banana\'" << endl;
	if (strB != *tNodeB2ptr)		cout << "\t\tERROR: # 4. \"banana\" should NOT != \'banana\'" << endl;
	else 								cout << "# 4. (\"banana\" != \'banana\') is FALSE" << endl;
	cout << endl;

	if (strA > *tNodeBptr)		cout << "\t\tERROR: # 5. \"apple\" is NOT > \'banana\'" << endl;
	else 								cout << "# 5. (\"apple\" > \'banana\') is FALSE" << endl;
	if (strC > *tNodeBptr)		cout << "# 6. (\"cherry\" > \'banana\') is TRUE" << endl;
	else 								cout << "\t\tERROR: # 6. \"cherry\" should be > \'banana\'" << endl;
	if (strB > *tNodeB2ptr)		cout << "\t\tERROR: # 7. \"banana\" should NOT > \'banana\'" << endl;
	else 								cout << "# 7. (\"banana\" > \'banana\') is FALSE" << endl;
	cout << endl;


	if (strA < *tNodeBptr)		cout << "# 8. (\"apple\" < \'banana\') is TRUE" << endl;
	else 								cout << "\t\tERROR: # 8. \"apple\" is  < \'banana\'" << endl;
	if (strC < *tNodeBptr)		cout << "\t\tERROR: # 9. \"cherry\" should NOT be < \'banana\'" << endl;
	else 								cout << "# 9. (\"cherry\" < \'banana\') is FALSE" << endl;
	if (strB < *tNodeB2ptr)		cout << "\t\tERROR: # 10. \"banana\" should NOT < \'banana\'" << endl;
	else 								cout << "# 10. (\"banana\" < \'banana\') is FALSE" << endl;
	cout << endl;


	if (strA >= *tNodeBptr)		cout << "\t\tERROR: # 11. \"apple\" is NOT >= \'banana\'" << endl;
	else 								cout << "# 11. (\"apple\" >= \'banana\') is FALSE" << endl;
	if (strC >= *tNodeBptr)		cout << "# 12. (\"cherry\" >= \'banana\') is TRUE" << endl;
	else 								cout << "\t\tERROR: # 12. \"cherry\" should be >= \'banana\'" << endl;
	if (strB >= *tNodeB2ptr)		cout << "# 13. (\"banana\" >= \'banana\') is TRUE" << endl;
	else 								cout << "\t\tERROR: # 13. \"banana\" is >= \'banana\'" << endl;
	cout << endl;


	if (strA <= *tNodeBptr)		cout << "# 14. (\"apple\" <= \'banana\') is TRUE" << endl;
	else 								cout << "\t\tERROR: # 14. \"apple\" is  <= \'banana\'" << endl;
	if (strC <= *tNodeBptr)		cout << "\t\tERROR: # 15. \"cherry\" should NOT be <= \'banana\'" << endl;
	else 								cout << "# 15. (\"cherry\" <= \'banana\') is FALSE" << endl;
	if (strB <= *tNodeB2ptr)		cout << "# 16. (\"banana\" <= \'banana\') is TRUE" << endl;
	else 								cout << "\t\tERROR: # 16. \"banana\" is <= \'banana\'" << endl;


	delete tNodeAptr;
	tNodeAptr = NULL;
	delete tNodeBptr;
	tNodeBptr = NULL;
	delete tNodeB2ptr;
	tNodeB2ptr = NULL;
	delete tNodeCptr;
	tNodeCptr = NULL;

} //end testNodeCompOperators()


void testLinkedListBasic() {
	// test #X: create empty list, check NULL

	cout << "\n-----Test LL_A --------------------" << endl;
	LinkedList* lTestPtr = new LinkedList;

	if ((*lTestPtr).getTail() == NULL) 	cout << "# 1. Tail is NULL" << endl;
	else 								cout << "\t\tERROR: # 1. Tail is not NULL" << endl;
	if ((*lTestPtr).getHead() == NULL) 	cout << "# 2. Head is NULL" << endl;
	else 								cout << "\t\tERROR: # 2. Head is not NULL" << endl;
	if ((*lTestPtr).size() == 0) 	 	cout << "# 3. size is 0" << endl;
	else 								cout << "\t\tERROR: # 3. size is " << (*lTestPtr).size() << endl;
	delete lTestPtr;
	lTestPtr = NULL;


	// test #Y: create list, check NULL

	cout << "\n-----Test LL-B --------------------" << endl;
	lTestPtr = new LinkedList("word");

	if ((*lTestPtr).getTail() == NULL) 	cout << "\t\tERROR: # 1. Tail is NULL" << endl;
	else 								cout << "# 1. Tail is not NULL, points to \'" << (*(*lTestPtr).getTail()).getData() << "\'" << endl;
	if ((*lTestPtr).getHead() == NULL) 	cout << "\t\tERROR: # 2. Head is NULL" << endl;
	else 								cout << "# 2. Head is not NULL, points to \'" << (*(*lTestPtr).getHead()).getData() << "\'" << endl;
	if ((*lTestPtr).size() == 0) 	 	cout << "\t\tERROR: # 3. size is 0" << endl;
	else 								cout << "# 3. size is " << (*lTestPtr).size() << endl;
	delete lTestPtr;
	lTestPtr = NULL;


} //end testLinkedListBasic()



int getTestMenuChoice() {

	int choiceOption;

	do {
		choiceOption = -678123; //init with unlikely value so it will loop again if no valid input is entered
		cout << "\n--------------------------------------------\n"
			<< "Test options menu: \n"
			<< "  (" << PRIVATE << ") Run public/private tests\n"
			<< "  (" << NODE_BASIC << ") Run basic Node tests\n"
			<< "  (" << LL_BASIC << ") Run basic Linked List tests\n"
			<< "  (" << NODE_COMP_OPERATORS << ") Test comparison operator overload of Node\n"
			<< "  (" << LL_COMP_OPERATORS << ") Test += operator overload of LinkedList\n"
			<< "  (" << RUN_ALL << ") Run all tests \n"
			<< "Enter a number from 1 to " << max_test_menu_option << ", or " << DONE << " to exit: ";
		cin >> choiceOption;
		/* check for failure of cin (for instance, when data type read in is not int */
		if (cin.fail()) {
			cin.clear();
			//discard bad characters
			/*zyBooks rejects: cin.ignore (numeric_limits<streamsize>::max(), '\n');
			 */
		}
		/* check if input is in valid range */
		if ((choiceOption < 0) || (choiceOption > max_test_menu_option)) {
			cout << "\nError! Input must be a number between 1 and " << max_test_menu_option
				<< ", or " << DONE << " to exit." << endl;
			choiceOption = -678123; // loop again. 
		}
		cout << endl;
	} while (choiceOption == -678123);


	return choiceOption;


} // end getTestMenuChoice()


void promptUnitTest() {
	/* variables */
	int menuChoice;

	do {
		menuChoice = getTestMenuChoice();

		switch (menuChoice) {
		case PRIVATE:
			testPrivate();
			break;
		case NODE_BASIC:
			testNodeBasic();
			break;
		case LL_BASIC:
			testLinkedListBasic();
			break;
		case NODE_COMP_OPERATORS:
			testNodeCompOperators();
			break;
		case LL_COMP_OPERATORS:
			testLinkedListCompOperator();
			break;
		case RUN_ALL:
			testPrivate();
			testNodeBasic();
			testLinkedListBasic();
			testNodeCompOperators();
			testLinkedListCompOperator();
			break;
		default: 	//DONE entered zero, exit
			cout << "Returning to main menu." << endl;
			menuChoice = 0;				//in case it was a non-listed option
		} //end switch


	} while (menuChoice != 0);

} //end promptUnitTest()

