/********************************************************************************
 *		TEST1.h
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
#ifndef TESTLL_H 
#define TESTLL_H 

void testNodeBasic();
void testLinkedListBasic();
void testNodeCompOperators();
void testLinkedListCompOperator();
int getTestMenuChoice();
void promptUnitTest();



#endif // TESTLL_H 