#include<iostream>

using namespace std;

class A
{
    public:
        A(){
            callA = 0;
        }
    private:
        int callA;
        void inc(){
            callA++;
        }

    protected:
        void func(int & a)
        {
            a = a * 2;
            inc();
        }
    public:
        int getA(){
            return callA;
        }
};

class B
{
    public:
        B(){
            callB = 0;
        }
    private:
        int callB;
        void inc(){
            callB++;
        }
    protected:
        void func(int & a)
        {
            a = a * 3;
            inc();
        }
    public:
        int getB(){
            return callB;
        }
};

class C
{
    public:
        C(){
            callC = 0;
        }
    private:
        int callC;
        void inc(){
            callC++;
        }
    protected:
        void func(int & a)
        {
            a = a * 5;
            inc();
        }
    public:
        int getC(){
            return callC;
        }
};

class D : public A, public B,public C
{

	int val;
	public:
		//Initially val is 1
		 D()
		 {
		 	val = 1;
		 }
		 //Implement this function
		 void update_val(int new_val)
		 {
             while(new_val%2==0)
             {
                 new_val=new_val/2;
                 A::func(val);
             }
             while(new_val%3==0)
             {
                 new_val=new_val/3;
                 B::func(val);
             }
             while(new_val%5==0)
             {
                 new_val=new_val/5;
                 C::func(val);
             }
		 }
		 //For Checking Purpose
		 void check(int); //Do not delete this line.
};
// This "workaround" is actually a MORE straightforward and logical way of solving the problem!
// void update_val(int new_val)
// {
//     while (!(new_val%2))
//     {
//          new_val /= 2;
//          val *= 2;
//          callA++;
//     }
//     while (!(new_val%3))
//     {
//          new_val /= 3;
//          val *= 3;
//          callB++;
//     }
//     while (!(new_val%5))
//     {
//          new_val /= 5;
//          val *= 5;
//          callC++;
//     }
// }
// Is func function of A,B,C are static,as you are using "::" ?what about taking object of a,b,c and calling func function with object but that produces compilation error,I don't know why.Pl correct me if iam wrong .

// A::func(val) is the same as this->A::func(val). That is, it is calling a member function on the current D instance. The A:: is there because D inherits from both A, B, and C and the compiler wouldn't know which func to call if you just did func(val) or this->func(val). The A:: is just for clarification for the compiler.

// You cannot reach protected area using objects. That's why we have to use inheritence here. "::"'s meaning is scope resolution, it is about static code but not just about static variables. By saying "static", I mean "not related to objects", you can see in below reference that no objects are used when using :: https://msdn.microsoft.com/en-us/library/b451xz31.aspx

// yeah we inherit the classes into class D bcoz we have to use their functions, and another classes function used in class D we have to inherit all classes to this class D, this is the only way to use another class function which are protected by their class. And this will simply call thier function in this class ex: A::func(val); B::func(val); B::func(val);

// I have an inocent doubt. You are calling the func() using scope resolution operator and its works fine. But I tried in different way. I have created the objects of particular class and called the function through objects created. But was getting the following error: error: ‘void A::func(int&)’ is protected within this context

// To access protected function first inherit and than use it using scope resolution as there are function with same name and parameters in class A,B,C.To access protected member from a function you have to use friend function so that it can access the class protected member.
//You can indeed make the main function a friend of a class like so:

// int main(int, char**);

// namespace N {
//     struct C {
//         friend int ::main(int, char**);

//     private:
//         int privateer = 42;
//     };
// }

// int main(int, char**) {
//     ::std::cout << N::C().privateer << "\n";
// }


void D::check(int new_val)
{
    update_val(new_val);
    cout << "Value = " << val << endl << "A's func called " << getA() << " times " << endl << "B's func called " << getB() << " times" << endl << "C's func called " << getC() << " times" << endl;
}


int main()
{
    D d;
    int new_val;
    cin >> new_val;
    d.check(new_val);

}
