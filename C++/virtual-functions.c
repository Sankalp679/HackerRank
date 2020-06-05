#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
// Discussion Method
// class Person{
//     public :
//     int age;
//     string name;
//     virtual void getdata(){}
//     virtual void putdata(){}
//     };

// class Professor : public Person{
//     public :
//     static int cur_id;
//     int cur;
//     int publications;
//     Professor(){
//      cur=++cur_id;
//     }
//     void getdata()
//     {
//         cin>>name>>age>>publications;
//     }
//     void putdata(){
//         cout<<name<<" "<<age<<" "<<publications<<" "<<cur<<"\n";
//         }
//     };
//     int Professor:: cur_id=0;

// class Student : public Person{
//     public:
//     static int cur_id;
//     int cur;
//     int marks[6];
//     int mark;
//     Student(){
//     cur=++cur_id;
//     mark=0;
//     }
//     void getdata(){
//         cin>>name>>age;
//         for(int i=0;i<6;i++)
//         {
//             cin>>marks[i];
//         }
//     }
//     void putdata(){
//         cout<<name<<" "<<age<<" ";
//         for(int i=0;i<6;i++)
//         {
//             mark=marks[i]+mark;
//         }
//         cout<<mark<<" "<<cur<<"\n";
//     }
//     };
//     int Student :: cur_id = 0;

//     class Person {
// public:
//     string name;
//     int age;
//     virtual void getdata() {
//         cin >> this->name >> this->age;
//     }
//     virtual void putdata() {
//         cout << this->name << " " << this->age << endl;
//     }
// };

// class Professor : public Person {
// public:
//     Professor() {
//         this->cur_id = ++id;
//     }
//     int publications;
//     static int id;
//     int cur_id;
//     void getdata() {
//         cin >> this->name >> this->age >> this->publications;
//     }
//     void putdata() {
//         cout << this->name << " "
//             << this->age << " "
//             << this->publications << " "
//             << this->cur_id << endl;
//     }
// };
// int Professor::id = 0;

// class Student : public Person {
// #define NUM_OF_MARKS 6
// public:
//     Student() {
//         this->cur_id = ++id;
//     }
//     int marks[NUM_OF_MARKS];
//     static int id;
//     int cur_id;
//     void getdata() {
//         cin >> this->name >> this->age;
//         for (int i=0; i<NUM_OF_MARKS; i++) {
//             cin >> marks[i];
//         }
//     }
//     void putdata() {
//         int marksSum = 0;
//         for (int i=0; i<NUM_OF_MARKS; i++) {
//             marksSum += marks[i];
//         }
//         cout << this->name << " "
//             << this->age << " "
//             << marksSum << " "
//             << this->cur_id << endl;
//     }
// };

// Comments
// This could've been done without the use of "this->" as well. Can you tell me the advantages of using this-> ?
// Just a habit. Emphasises that you are using a data member and not a local variable.

// Virtual Function(Bucky Roberts)
// Ninja n;
// Monster m;
// Enemy * enemy1=&n;
// Enemy * enemy2=&m;
// enemy1->attack();
// enemy2->attack();
int main(){

    int n, val;
    cin>>n; //The number of objects that is going to be created.
    Person *per[n];

    for(int i = 0;i < n;i++){

        cin>>val;
        if(val == 1){
            // If val is 1 current object is of type Professor
            per[i] = new Professor;

        }
        else per[i] = new Student; // Else the current object is of type Student

        per[i]->getdata(); // Get the data from the user.

    }

    for(int i=0;i<n;i++)
        per[i]->putdata(); // Print the required output for each object.

    return 0;

}
