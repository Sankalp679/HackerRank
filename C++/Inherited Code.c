#include <iostream>
#include <string>
#include <sstream>
#include <exception>
using namespace std;

/* Define the exception here */
class BadLengthException : public exception{
int num;
public:
BadLengthException(int n){
    num=n;
}
int what()
   {
       return num;
   }
};
// using namespace std;
// struct MyException : public exception
// {
//   const char * what () const throw () // <--- This
//   {
//     return "C++ Exception";
//   }
// };
// It's a member function definition.

// const char * is the return type, a pointer to a constant character, by convention the first character of a zero-terminated string array.
// what is the function name
// () is an empty parameter list, indicating that the function takes no arguments
// const qualifies the function, so it can be called on a const object, and can't directly modify the object's members
// throw () is an exception specification which prevents it from throwing any exceptions.
// const - declares this to be a const function (in general, this means it should not change the state of the object).
// he rest of the line is fairly standard:
// const char * what () const throw ()
// what() : A function named what.
// what() const: what() is a const function, so it can be used on const objects of type MyException
// const char* what() const: what is a const function, which returns a pointer to const char

// I had never done anything with exceptions before so I found this one quite confusing, especially since it doesn't specify that you are supposed to create a new class. For anyone else wondering,

// BadLengthException(n)
// is a class constructor, not just an external function. The variable "e" is an object of this class, and "what()" is a function inside the class.

// For anyone else unfamiliar with exceptions, an exception consists of a "throw" and a "catch". A "throw" is followed by an object or variable. When the "throw" is called, the program will jump to the "catch" using said object/variable as an input to the catch. In this case, the throw constructs a new object of class "BadLengthException", which is then used as the input to the catch (this is labelled as "e").

// The code that I used is as follows:
// Thank you for this beautiful explanation. I was unfamiliar with exception handling. I understood how we needed to make the class and that e is an object of that class. But the error number is refered to the length of the string that is invalid right?
// But the checkusername function is not defined within the class so how can it be accessed by a function within the class. Isnt it beyond the scope of the class?
// ans
// Don't forget that the throw "throws" the statement up the call stack (i.e keeps searching nested functions) until it reaches a relevant catch identifier where the exception is caught and dealt with.



bool checkUsername(string username) {
	bool isValid = true;
	int n = username.length();
	if(n < 5) {
		throw BadLengthException(n);
	}
	for(int i = 0; i < n-1; i++) {
		if(username[i] == 'w' && username[i+1] == 'w') {
			isValid = false;
		}
	}
	return isValid;
}

int main() {
	int T; cin >> T;
	while(T--) {
		string username;
		cin >> username;
		try {
			bool isValid = checkUsername(username);
			if(isValid) {
				cout << "Valid" << '\n';
			} else {
				cout << "Invalid" << '\n';
			}
		} catch (BadLengthException e) {
			cout << "Too short: " << e.what() << '\n';
		}
	}
	return 0;
}
