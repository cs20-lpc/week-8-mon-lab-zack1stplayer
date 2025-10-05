#include "ArrayStack.hpp"
#include <cstdlib>
#include <ctime>

template <typename T>
void testRotate(ArrayStack<T>*);

int main() {
    // create a stack of 10 integers
    ArrayStack<int> stackA(10);

    for (int i = 0; i < stackA.getMaxSize(); i++) {
        stackA.push(i);
        cout << stackA.peek() << ' ';
    }

    // ensure that stack A is now full
    if (stackA.isFull()) {
        cout << "Stack A is full! ";
    }
    else {
        cout << "Stack A is not full [ERROR] ";
    }

    // create a copy of stack A using the copy constructor
    ArrayStack<int> stackB = stackA;

    // check their lengths
    cout << "Stack A length: " << stackA.getLength();
    cout << "Stack B length: " << stackB.getLength();

    // display the stack
    cout << stackB;

    // try pushing to stack B
    // should display error
    try {
        stackB.push(501);
    }
    catch (string& e) {
        cout << e;
    }

    // pop half the elements from stack B
    for (int i = 0; i < stackB.getMaxSize() / 2; i++) {
        cout << "Popping " << stackB.peek() << " from stack B";
        stackB.pop();
    }

    // check stack B's length
    cout << "Stack B length: " << stackB.getLength();

    // display the stack
    cout << stackB;

    // clear out stack B
    stackB.clear();

    // ensure that stack B was cleared
    if (stackB.isEmpty()) {
        cout << "Stack B is now empty after being cleared";
    }
    else {
        cout << "Stack B is not empty after being cleared [ERROR]";
    }

    // create an empty stack
    ArrayStack<int> stackC;

    // display the stack
    cout << stackC;

    // try popping from stack C
    // should display error
    try {
        stackC.pop();
    }
    catch (string& e) {
        cout << e ;
    }

    // try accessing the top of stack C
    // should display error
    try {
        int temp = stackC.peek();
        cout << temp;
    }
    catch (string& e) {
        cout << e;
    }

    // create a copy of stack A using the assignment overload
    stackC = stackA;

    // check their lengths
    cout << "Stack A length: " << stackA.getLength();
    cout << "Stack C length: " << stackC.getLength();

    // rotate stack C
    testRotate(&stackC);

    // terminate
    return 0;
}

template <typename T>
void testRotate(ArrayStack<T>* stk) {
    cout << "Stack C before rotation:" << *stk;

    for (int i = 0; i < stk->getLength() / 2; i++) {
        stk->rotate(Stack<T>::RIGHT);
    }

    cout << "Stack C after right rotating half the elements:" << *stk;

    for (int i = 0; i < stk->getLength() / 2; i++) {
        stk->rotate(Stack<T>::LEFT);
    }

    cout << "Stack C after the same number of left rotations "
         << "(should match beginning):" << *stk;
}
