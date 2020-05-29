#include <iostream>
#include <exception>
#include <string>
#include <stdexcept>
#include <vector>
#include <cmath>
using namespace std;

class Server {
private:
	static int load;
public:
	static int compute(long long A, long long B) {
		load += 1;
		if(A < 0) {
			throw std::invalid_argument("A is negative");
		}
		vector<int> v(A, 0);
		int real = -1, cmplx = sqrt(-1);
		if(B == 0) throw 0;
		real = (A/B)*real;
		int ans = v.at(B);
		return real + A - B*ans;
	}
	static int getLoad() {
		return load;
	}
};
int Server::load = 0;

int main() {
	int T; cin >> T;
	while(T--) {
		long long A, B;
		cin >> A >> B;
        try{
            cout<<Server::compute(A,B)<<'\n';
            //  In this block we just have the call to use the compute(A,B) function and to print the result. Since this is a static function (see line 13), we don't need to create any objects of type Server, we can just call it directly instead.
        }
        catch (invalid_argument& e)
        {
            cout<<"Exception: "<<e.what()<< '\n';
        }
        catch (bad_alloc& excepObj)
        {
        cout <<"Not enough memory"<< '\n';
        }
        catch (out_of_range oor)
        {
        cout<< "Exception: " << oor.what() << '\n';
        }
        // catch (exception& oor) {         //by reference  this class contains all
        // cout<< "Exception: " << oor.what() << '\n';   standard errors.
        // }
        //by value
        // catch (out_of_range outofrange) { //if the index is out of range
        // cout<< outofrange.what()<<'\n'; //throw this exception
        // }
        catch(...)
        {
            cout <<"Other Exception"<<'\n';
        }
//         As someone who didn't know much about exceptions coming into this problem, I thought I would give some explanation to anyone else who doesn't understand the problem at first. A lot of people are posting their code but I wanted to give an explanation too. If I've made any mistakes, I would appreciate a correction.
// The first thing to know is that the actual computation is basically entirely irrelevant and completely pointless. The result is simply A - A/B. It throws in some confounding and useless variables like "ans" and "cmplx" that serve no purpose. Line 18 creates a vector of zeroes, so the result of line 21 is always either zero or an error (if B is larger than A). Therefore, "ans" is always zero and "B*ans" is also always zero.
// Now that that's out of the way, your actual task is to write exceptions for what will happen under 3 different circumstances. If you don't know anything about exceptions, I recommend watching this short video for a quick introduction, as well as this handy article on TutorialsPoint. An exception is an error that will cause the program to exit the current iteration of whatever loop it is in.
// Exceptions work by first making a "try" block, and following this with one or more "catch" blocks. If a "throw" is executed from inside the "try" block, it will exit the "try" block and search for a relevant "catch" block to tell it what to do. In general, if there are multiple catch blocks, they will each deal with a different type of exception. The general format looks like this:
// try {
//     //code that may result in exceptions being thrown
// }
// catch (type of exception to be caught) {
//     //action to take when this exception is caught
// }
// catch (alternative type of exception to be caught) {
//     //action to take when this alternative exception is caught
// }
// In addition to manually entered exceptions (such as the one on line 20, which throws the number 0), C++ will also automatically throw an exception by itself in some circumstances. For example, if memory has not been allocated properly, or if the user attempts to access a vector element which is out of range. These exceptions are all objects and the individual types are all children of the class "std::exception". A reference list of these can be found here.
// When an excetion is thrown, it will usually throw with it some kind of object or variable. This will be used to decide which catch block to execute. For example, line 16 throws an object of class "std::invalid_argument". This means that if you create a catch that listens for this class of objects, it will activate when this object is thrown. For example:
// catch(invalid_argument& e)  {
//     // what to do in this case here
// }
// Within this block, the object thrown has been assigned the label "e" and the quoted text input on line 16 can be accessed with the function "e.what()". In this case, replacing "invalid_argument" with "exception" would also have caught this exception, as invalid_argument is a child of exception (see aforementioned reference list).
// My actual code for this one is quite simple:
//         try {
//             cout << Server::compute(A,B) << endl;
//         }
//         catch (bad_alloc& error) {
//             cout << "Not enough memory" << endl;
//         }
//         catch (exception& error) {
//             cout << "Exception: " << error.what() << endl;
//         }
//         catch (...) {
//             cout << "Other Exception" << endl;
//         }
// This code passed all test cases. But I want to explain what I did in the context of my previous explanations of exceptions. The first 3 lines are the "try" block. In this block we just have the call to use the compute(A,B) function and to print the result. Since this is a static function (see line 13), we don't need to create any objects of type Server, we can just call it directly instead.
// If there is something wrong with the inputs, then executing this function will throw out the relevant exception. As the problem states, we need to be able to handle 3 different scenarios:
// 1. Not enough memory allocated
// 2. Other standard C++ exception
// 3. Other non-standard C++ exception
// The first catch will be triggered whenever a "bad_alloc" exception occurs. Scenario 1 is actually a standard C++ exception, but we need to give it special treatment with a unique message for the challenge. This is why we put this catch first and the catch for all standard C++ exceptions second, because otherwise the "bad_alloc" exception would be treated the same as the others.
// The second scenario will trigger when any other exceptions in the C++ exception library occur (again, find a list of these exceptions here). Because the line 16 has manual text, this text will print whenever this throw occurs. All other exceptions will print some standard code that gives some clue as to what caused the exception.
// The final catch uses an ellipses (...) as the catch condition. This means that this catch will be triggered by any other exceptions not caught by the previous catches. Notably, this will be caused by the throw on line 20, as this is throwing a zero, which is not a standard C++ exception.
// Any of these catches being triggered will cause the loop to immediately move to the next iteration, so you don't have to worry about the computation being printed if they occur.
	}
	cout << Server::getLoad() << endl;
	return 0;
}
