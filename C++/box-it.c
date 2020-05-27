#include<bits/stdc++.h>

using namespace std;
#include<iostream>
//Implement the class Box
//l,b,h are integers representing the dimensions of the box
class Box{
    private:
    double l,b,h; //long long also works
    public:
    friend ostream& operator<<(ostream& os, const Box&B);
    Box(){
        l=0;
        b=0;
        h=0;
    }
    Box(int length, int breadth, int height){
        l=length;
        b=breadth;
        h=height;
    }
    Box(const Box&obj)
    {
      l=obj.l;
      b=obj.b;
      h=obj.h;
    }
    int getLength(){
        return l;
    }
    int getbreadth(){
        return b;
    }
    int getheight(){
        return h;
    }
    long long CalculateVolume(){
        //1. long long volume = l;
        // volume *= b;
        // volume *= h;
        // return volume;
        //2. return 1LL * l * b * h;
        //3. (long long)(l) * b * h
        return l*b*h;      // 4.static_cast<long long>(l)*b*h
    }
    bool operator<(Box& B){     //implicit declaration of Box A so l is used,A.l is not used.
        return ((l<B.l) || ((b<B.b)&&(l==B.l)) || (h<B.h && b==B.b && l==B.l));
    }

};
   ostream& operator<<(ostream& out,const Box&B){
        return out<<B.l<<' '<<B.b<<' '<<B.h;
    }



// The class should have the following functions :

// Constructors:
// Box();
// Box(int,int,int);
// Box(Box);


// int getLength(); // Return box's length
// int getBreadth (); // Return box's breadth
// int getHeight ();  //Return box's height
// long long CalculateVolume(); // Return the volume of the box

//Overload operator < as specified
//bool operator<(Box& b)

//Overload operator << as specified
//stream& operator<<(ostream& out, Box& B)
// 1039 3749 8473
// 33004122803
// Greater
// Lesser
// 4839 283 273
// 373856301

