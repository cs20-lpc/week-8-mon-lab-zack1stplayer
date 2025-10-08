#include <iostream>

#include "ArrayStack.hpp"

using namespace std;

int main() {
    ArrayStack<int> stack1 = ArrayStack<int>(10);

    cout << stack1.getMaxSize() << endl;

    stack1.push(11);
    stack1.push(22);
    stack1.push(33);
    stack1.push(44);
    
    cout << stack1.getLength() << " ";
    cout << stack1.peek() << endl << endl;

    ArrayStack<int> stack2 = stack1;

    cout << stack2.getMaxSize() << " ";
    cout << stack2.getLength() << " ";
    cout << stack2.peek() << endl;

    stack1.pop();

    cout << stack1.getLength() << " ";
    cout << stack1.peek() << endl;

    cout << stack2.getLength() << " ";
    cout << stack2.peek() << endl;


    stack1.pop();
    cout << stack1.peek() << endl;

    stack1.clear();

    try { cout << stack1.peek() << endl; }
    catch(const string e) { cerr << e << endl; }

    try { stack1.pop(); }
    catch(const string e) { cerr << e << endl; }

    try { stack1.push(1); }
    catch(const string e) { cerr << e << endl; }

    try { stack1.rotate(Stack<int>::LEFT); }
    catch(const string e) { cerr << e << endl; }

    stack1 = stack2;

    cout << stack1.peek() << endl;

    stack1.push(55);

    cout << stack1.getLength() << " ";
    cout << stack1.peek() << endl;

    stack1.push(66);
    stack1.push(77);
    stack1.push(88);
    stack1.push(99);
    stack1.push(100);

    cout << stack1;
    
    try { stack1.push(111); }
    catch(const string e) { cerr << e << endl; }

    cout << endl;

    stack1.rotate(Stack<int>::LEFT);
    cout << stack1 << endl;
    
    stack1.rotate(Stack<int>::RIGHT);
    stack1.rotate(Stack<int>::RIGHT);
    cout << stack1 << endl;

    stack1 = stack2;

    cout << stack1 << endl;

    stack1.rotate(Stack<int>::RIGHT);
    cout << stack1 << endl;

    stack1.rotate(Stack<int>::LEFT);
    stack1.rotate(Stack<int>::LEFT);
    cout << stack1 << endl;

    ArrayStack<string> helloWorld = ArrayStack<string>(7);

    // The following is a short snippet of lyrics from the song "Hello World" by Louie Zong
    helloWorld.push("Hello World");
    cout << helloWorld.peek() << endl;

    helloWorld.push("Programmed to work and not to feel");
    cout << helloWorld.peek() << endl;

    helloWorld.push("Not even sure that this is real");
    cout << helloWorld.peek() << endl;
    
    helloWorld.rotate(Stack<string>::RIGHT);
    cout << helloWorld.peek() << endl;

    return 0;
}