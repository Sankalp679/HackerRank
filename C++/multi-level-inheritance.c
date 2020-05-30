#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Triangle{
	public:
		void triangle(){
			cout<<"I am a triangle\n";
		}
};

class Isosceles : public Triangle{
  	public:
  		void isosceles(){
    		cout<<"I am an isosceles triangle\n";
  		}
};

//Write your code here.
class Equilateral : public Isosceles{
    public:
    void equilateral(){
        cout<<"I am an equilateral triangle\n";
    }
};

int main(){

    Equilateral eqr;
    eqr.equilateral();
    eqr.isosceles();
    eqr.triangle();
    return 0;
}
// This problem is really super obvious.
// Am I the only one who's disappointed that virtual functions, abstract classes, and polymorphism - the real guts of inheritance - are conspicuously absent from this category? Seriously.
// Also virtual inheritance is never mentioned or used, but is vital to a good understanding of inheritance in C++ (esp since multiple inheritance is often used in lieu of interfaces and one needs to know how to avoid the "dreaded diamond").

// #include <iostream>
// #include <memory> // std::unique_ptr, std::make_unique
// #include <array>  // std::array

// struct Shape
// {
//  // optional noexcept specifier
//  virtual void triangle() const noexcept = 0;
//  virtual ~Shape() = default;
// };

// struct Triangle : public Shape
// {
//   void triangle() const noexcept override {
//   std::cout << "I am a triangle\n";
//  }
// };

// struct Isosceles : public Triangle
// {
//   void triangle() const noexcept override {
//   std::cout << "I am an isosceles triangle\n";
//  }
// };

// struct Equilateral final : public Isosceles
// {
//   void triangle() const noexcept override {
//   std::cout << "I am an equilateral triangle\n";
//  }
// };

// int main()
// {
//  const std::array<std::unique_ptr<Shape>, 3> obj
//  {
//      std::make_unique<Equilateral>(), // element 1
//      std::make_unique<Isosceles>(),   // element 2
//      std::make_unique<Triangle>()     // element 3
//  };
// for (auto& it : obj)
//     it->triangle();
//  return 0;
// }
// The
// const void fun(....
// that part does not make much sense. It means, the function returns a constant void type. That is unnecessary and I have removed. I hope the rest is understandable, as it is just basic, polymorphism with C++ smart pointers.
