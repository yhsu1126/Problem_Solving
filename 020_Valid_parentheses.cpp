class Solution {
public:
    bool findLeft( char input, stack<char>& myStack ){
        while( !myStack.empty() ){
            if( myStack.top()=='(' && input == ')' ){
                myStack.pop();
                return true;
            }
            else if( myStack.top()=='[' && input == ']' ){
                myStack.pop();
                return true;
            }
            else if( myStack.top()=='{' && input == '}' ){
                myStack.pop();
                return true;
            }
            else{
                return false;
            }
        }
        return false;
    }
    bool isValid(string s) {
        stack<char> myStack;
        for( auto it = s.begin(); it != s.end() ; it++ ){
            if( *it == '(' || *it == '[' || *it == '{' ){
                myStack.push( *it );
            }
            else{
                if( findLeft( *it, myStack ) == false ){
                    return false;
                }
            }
        }
        if( !myStack.empty() ){
            return false;
        }
        else{
            return true;
        }
    }
};

/*
Use a stack to handle all the parentheses

if you saw a left one, push it , when a right one entered, pop the stack to check if the left parentheses exist

Example ([)] --> false
Example ((( ) --> false

Time Complexity
O(n)
Space Complexity
O(n) --> consider case (((()))) n/2 is used

*/