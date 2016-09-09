#include <iostream>
#include "Stack.h"

using namespace std;

int main() {
    typedef int tip;

    Stack<tip> stack(5);
    tip element = 1;

    while(stack.push(element)) {
        element+=2;
        stack.printStack();
    }

    while(stack.pop()) stack.printStack();
}