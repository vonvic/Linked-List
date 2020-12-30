/**
 * File: test.cpp
 * Author: Cayas, Von Vic
 * Date Created: December 28, 2020
 * 
 * Description: This is a program to test the List and Iterator classes,
 *      as well as the Node structure.
 * 
 * TODO:
 * Dec 29, 2020: In the future, this file should be broken up to have its classes and
 *      functions to be in its own header files. The reason why it has not been
 *      implemented yet is for time sake; However, once time is no longer a
 *      problem, tests/include/ and tests/lib/ will be added - alnog with the 
 *      test target in makefile to be updated.
 */

#include <iostream>
#include <sstream>
#include "list.h"
#include "iter.h"
#include "node.h"
using namespace std;

class Validator {
private:
    string testingClass;
    unsigned int assertID;
public:
    Validator(string classToTest) {
        testingClass = classToTest;
        assertID = 0;
    }

    /**
     * Validate test functions
     * Tests a test function by comparing an expected value
     *      with the parameter function call. If the two values
     *      are equal, then program continues normally. Else, a
     *      runtime_error is thrown.
     * 
     * @param expected The expected value of the function call.
     * @param actual The actual value of the function call.
     * 
     * @returns none
     * 
     * Precondition: None
     * Postcondition: None
     * Exception: Throws runtime_error if expected and actual
     *      are not equal.
     */
    void assert(string expected, string actual) {
        if (expected != actual) {
            string errorMessage;
            errorMessage = "Testing Class: " + testingClass + '\n';
            errorMessage = "Assert ID: " + assertID + '\n';
            errorMessage = "Expected: " + expected + "\n";
            errorMessage = "Actual: " + expected + "\n";

            ++assertID;

            throw runtime_error(errorMessage);
        }
    }
};


/**
 * Functions to test classes
 * The three functions below test their respective classes,
 *      which is given by their identifer:
 *      
 *      - testNodeClass     -> Tests the Node class
 *      - testIteratorClass -> Test the Iterator class
 *      - testListClass     -> Test the List Class
 * 
 * @param none
 * 
 * @returns none
 * 
 * Precondition: none
 * Postcondition: none
 * Exception: none
 */
bool testNodeClass();
bool testIteratorClass();
bool testListClass();

/**
 * =========================
 * Subtests to be executed under the
 *      testNodeClass,
 *      testIteratorClass,
 *      and testListClass
 * functions.
 * =========================
 */
template <class T>
string createNodeWithVal(T value);

template <class T>
string createIterWithOneNode(T value);
template <class T>
string createIterWithAtLeastOneNode(T arrOfVal[], int len);

string prefixIncrementIter();
string postfixIncrementIter();

string equalIters();
string unequalIters();

/**
 * =================
 * DISPLAY FUNCTIONS
 * =================
 */
/**
 * displayTitle function
 * Displays the output message with lines before and
 *      after the message
 * 
 * @param message The message to be displayed.
 * 
 * @returns none
 * 
 * Precondition: None
 * Postcondition: None
 * Exception: None
 */
void displayTitle(string message);

/**
 * =================
 * MAIN FUNCTION
 * =================
 */
int main() {
    displayTitle("Test driver program");
    
    const unsigned int numOfOptions = 4;
    string options[numOfOptions] =
    {
        "Exit",
        "Node",
        "Iterator",
        "List"
    };

    // MAIN PROGRAM LOOP
    int selection;
    do {
        // Display menu
        cout << "Which class to test (enter number for selection)?";
        cout << endl;

        for (unsigned int i=0; i<numOfOptions; ++i) {
            cout << "Input " << i;
            cout << " for " << options[i];
            cout << endl;
        }

        cout << endl;
        cout << ": ";
        cin >> selection;
        cout << endl;
        
        switch(selection) {
            case 0:
            {
                continue;
                break;
            }
            case 1:
            {
                // Execute node tests
                if(!testNodeClass())
                    selection = 0;
                break;
            }
            case 2:
            {
                // Execute iterator tests
                if(!testIteratorClass())
                    selection = 0;
                break;
            }
            case 3:
            {
                // Execute list tests
                if(!testListClass())
                    selection = 0;
                break;
            }
            default: {
                // Display "wrong selection" error
                // message.
                cout << "Your selection ";
                cout << "\"" << selection << "\"";
                cout << " is invalid." << endl;
            }
        }
        cout << endl;
    }
    while (selection != 0);

    return 0;
}

/**
 * ===================
 * test class functions
 * ===================

 * Tests the Node, Iterator, or List class through a series of tests.
 *      If all test pass, then function returns true. If at least one
 *      test fails, then error message is outputted and returns false.
 * 
 * @param none
 * 
 * @returns bool
 *      Returns true if all tests pass. Returns false otherwise.
 * 
 * Precondition: None
 * Postcondition: None
 * Exception: None
 */
bool testNodeClass() {
    displayTitle("Testing Node class");

    Validator NodeValidator("Node");
    try {
        cout << "Testing Nodes with different values..." << endl;
        NodeValidator.assert("0", createNodeWithVal(0));
        NodeValidator.assert("1", createNodeWithVal(1));
        NodeValidator.assert("10", createNodeWithVal(10));
        NodeValidator.assert("100", createNodeWithVal(100));
        NodeValidator.assert("0", createNodeWithVal("0"));
        NodeValidator.assert("1", createNodeWithVal("1"));
        NodeValidator.assert("10", createNodeWithVal("10"));
        NodeValidator.assert("100", createNodeWithVal("100"));
        
        displayTitle("All tests passed successfully!");
        return true;
    }
    catch (exception& e) {
        displayTitle("Failed test!");
        cout << e.what();
        return false;
    }
}

bool testIteratorClass() {
    displayTitle("Testing Iterator class");
    
    Validator IteratorValidator("Iterator");
    try {
        IteratorValidator.assert("5", createIterWithOneNode(5));
        IteratorValidator.assert("5", createIterWithOneNode("5"));
        int values[3] = {5, 5, 5};
        IteratorValidator.assert("success!", createIterWithAtLeastOneNode(values, 3));
        IteratorValidator.assert("success!", prefixIncrementIter());
        IteratorValidator.assert("success!", postfixIncrementIter());
        IteratorValidator.assert("success!", equalIters());
        IteratorValidator.assert("success!", unequalIters());

        displayTitle("All tests passed successfully!");
        return true;
    }
    catch (exception& e) {
        displayTitle("Failed test!");
        cout << e.what() << endl;
        return false;
    }
}

bool testListClass() {
    displayTitle("Testing List class");
    try {
        throw runtime_error("test");

        displayTitle("All tests passed successfully!");
        return true;
    }
    catch (exception& e) {
        displayTitle("Failed test!");
        cout << e.what() << endl;
        return false;
    }
}

/**
 * =========================
 * Subtests to be executed under the
 *      testNodeClass,
 *      testIteratorClass,
 *      and testListClass
 * functions.
 * =========================
 */
template <class T>
string createNodeWithVal(T value) {
    stringstream ss;
    Node<T> node;
    node.value = value;

    ss << node;

    return ss.str();
}

template <class T>
string createIterWithOneNode(T value) {
    return "";
}

template <class T>
string createIterWithAtLeastOneNode(T arrOfVal[], int len) {
    return "";
}

string prefixIncrementIter() {
    return "";
}
string postfixIncrementIter() {
    return "";
}

string equalIters() {
    return "";
}
string unequalIters() {
    return "";
}

/**
 * displayTitle function
 * Displays the output message with lines before and
 *      after the message
 * 
 * @param message The message to be displayed.
 * 
 * @returns none
 * 
 * Precondition: None
 * Postcondition: None
 * Exception: None
 */
void displayTitle(string message) {
    cout << "==========";
    cout << message;
    cout << "==========";
    cout << endl;
}