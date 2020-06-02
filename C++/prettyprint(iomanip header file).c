#include <iostream>
#include <iomanip>
using namespace std;

int main() {
	int T; cin >> T;
	cout << setiosflags(ios::uppercase);
	cout << setw(0xf) << internal;
	while(T--) {
		double A; cin >> A;
		double B; cin >> B;
		double C; cin >> C;
    cout<<setw(3)<<setiosflags(ios::left)<<setprecision(0)<<resetiosflags(ios::uppercase)    <<setiosflags(ios::fixed);
    cout<<setbase(16)<<showbase<<long(A)<<"\n";     // show the 0x prefix
    cout<<setiosflags(ios::showpos)<<setprecision(2)<<fixed<<setfill ('_')<<setw(15)<<B<<"\n";
    cout<<setprecision(9)<<resetiosflags(ios::showpos)<< setiosflags(ios::uppercase)<<scientific<<C<<"\n";
// aur setfill agar kisi chiz ko set kiya toh har dum vo vaise hi print karte jayega aur setw se jagah mili toh agar kisi dusri chiz se fill karna hai toh vapus setfill use karna padega
//     0x3bf
// ________+199.25
// 4.708880000E+02
// 0x3bf
// ________+199.25
// 4.708880000E+02
// 0x4a
// ________+802.75
// 3.962950000E+02
// 0x4a
// +0x1.915f7ced91687p+9
// 3.962950000E+02
// 0x182
// ________+721.20
// 6.286550000E+02
// 0x2d2
// ________+207.87
// 6.479420000E+02
// 0x57
// ________+792.72
// 7.614980000E+02
// 0x395
// ________+843.34
// 9.080430000E+02
// 0x3b8

// Disussion Method
// Here is my code as well as an explanation of what I'm doing. there is really no explanation of any of this given in the problem so hopefully this is helpful to some, because it's actually not that bad:

// // LINE 1
//         cout << hex << left << showbase << nouppercase; // formatting
//         cout << (long long) A << endl; // actual printed part

//         // LINE 2
//         cout << dec << right << setw(15) << setfill('_') << showpos << fixed << setprecision(2); // formatting
//         cout << B << endl; // actual printed part

//         // LINE 3
//         cout << scientific << uppercase << noshowpos << setprecision(9); // formatting
//         cout << C << endl; // actual printed part
// So for anyone unfamiliar, C++ has a variety of things called "manipulators" that will change the format of the output printed with "cout". These things are not printed themselves, they just affect the part you are actually printing. A list of these manipulators can be found on this page.

// In each of the three outputs, I have put all the relevant manipulators on one line, followed by the actual value which is being printed on the next line.

// Initial Code

// This problem actually forces two manipulators on you initially which don't seem to be helpful at all. These manipulators are setw and internal. The former sets a fixed width for the output (in this case 15 characters wide) and the latter will align it to the right. We need to basically undo this in the first printed line because we want the hexadecimal printout to be left-aligned instead.

// Printed Line 1

// The manipulators I used here are hex (which will output the number in hexadecimal format), left (which will align the number to the left), showbase (which will make sure the hexadecimal number has a '0x' at the beginning), and nouppercase (which converts all alphabetic hexadecimal values to lowercase).

// Printed Line 2 In this section, I actually have to undo some of the previous manipulations.

// dec: switches numbers from hexadecimal back to decimal.
// right: aligns values to the right instead of the left
// setw(15): sets a fixed width of 15, as the effect from the initial code only impacts the first printed line.
// setfill('_'): by default, when you have a fixed width, if your printed value doesn't fill up the entire length (for example, if you have a width of 15 and only print 7 characters), the extra characters used to pad are whitespaces. This function lets you change the padding to whatever character you want.
// showpos: Makes sure there is a plus sign before any positive numbers
// fixed: ensures that number is printed out entirely and that scientific notation isn't used for larger numbers
// setprecision(2): sets the number of decimal places to 2.
// Printed Line 3

// scientific: Prints output in scientific notation format
// uppercase: Undoes previous nouppercase manipulator and ensures that the 'E' in the scientific notation is capitalised
// noshowpos: Undoes previous showpos manipulator and gets rid of the plus at the start of positive values
// setprecision: Changes the number of digits after the decimal place from 2 to 9.

// cout << setiosflags(ios::fixed) << setprecision(0)
// << endl << "The square root of "<< x << " is " << GetSquare(x)
// << endl <<endl;

// by saying set precision (0) you have left no room for the output. so the system will always try and print and make the room it needs. if there is not enough room it will automatically print in scientific notation.
// in this case, whenever you say ios::fixed *along with* setprecision() it means that you are telling it how many places after the decimal place you want printed.
// setprecision( #) without the ios::fixed means how many places you want for the entire number.
// it was confusing to me that it means 2 different things depending on if you choose ::fixed or not.

// try changing the zero to a bigger number.

// susan
// [5:52 PM, 6/2/2020] Sankalp Jain: ye chalne wala code hai
// [5:52 PM, 6/2/2020] Sankalp Jain: final conclusion mujhe itna samjha ki
// [5:52 PM, 6/2/2020] Sankalp Jain: 1: setiosflags(ios::scientific) use kiya "scientific" ki jagah toh third number pehle bar mein hi hex print hone wala hai
// [5:52 PM, 6/2/2020] Sankalp Jain: 2: setiosflags(ios::fixed) use kiya "fixed" ki jagah toh second number pehle bar sahi print ho raha par dusri bar hex print ho raha
// [5:52 PM, 6/2/2020] Sankalp Jain: 3: Agar hona hi hai second aur third number mein pehli bar mein hi hex print hona chaiye tha
// [5:52 PM, 6/2/2020] Sankalp Jain: 4: Aisa kyu nahi ho raha 3 number pehli bar mein hex ah raha aur second number second time mein hex ah raha
// [5:52 PM, 6/2/2020] Sankalp Jain: 5: Aur agar sidha fixed aur scientic use kiye toh
// [5:52 PM, 6/2/2020] Sankalp Jain: 6: kuch problem nahi ata
// [5:52 PM, 6/2/2020] Sankalp Jain: 8 : par agar fixed aur scientific use kiya toh ye conversion nahi karna padega
// [5:56 PM, 6/2/2020] Sankalp Jain: 7 : Aur agar mujhe setiosflags(ios::scientific) aur setiosflags(ios::fixed) hi use karna hai toh phir mujhe  second vale aur third wale mein dono mein hex se decimal mein lana (defaultfloat) padega pihr hi chalega
// [5:57 PM, 6/2/2020] Sankalp Jain: 9: Ek mein hi karke defaultfloat include karke nahi chalega, second aur third dono mein hi karna padega
// [5:57 PM, 6/2/2020] Sankalp Jain: include
// [6:04 PM, 6/2/2020] Sankalp Jain: 10: agar dec use kiya defaultfloat ki jagah toh 1,2,3,4 repeat ho raha 1,2 ek sath ho raha.
// [6:04 PM, 6/2/2020] Sankalp Jain: 11: jidhar bhi fixed aur scientific use karaha vo sahi chal raha
	}
