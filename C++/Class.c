// imp comments

// Yes contructors and destructors are guidelines for good practises. Also when you are calling a your class members in a separate cpp file to define your functions, constructors are needed to set the default values.

// In class, declaration of variables is by default private. On the contrary, in structures declarations are by default public.

//  Discussion method

// class Student{
//     int age;
//     int standard;
//     string first_name;
//     string last_name;
// public:
//     Student()
//     {
//         age = 0;
//         standard = 0;
//         first_name.clear();
//         last_name.clear();
//     }
//     void set_age(int newAge)
//     {
//         age = newAge;
//     }
//     void set_standard(int newStandard)
//     {
//         standard = newStandard;
//     }
//     void set_first_name(string newFirst_name)
//     {
//         first_name = newFirst_name;
//     }
//     void set_last_name(string newLast_name)
//     {
//         last_name = newLast_name;
//     }
//     int get_age() {return age;}
//     int get_standard() {return standard;}
//     string get_first_name() {return first_name;}
//     string get_last_name() {return last_name;}

//     string to_string()
//     {
//         stringstream ss;
//         char c = ',';
//         ss << age << c << first_name << c << last_name << c << standard;
//         return ss.str();
//     }

// };


//    my method
#include <iostream>
#include <sstream>
#include <string>
using namespace std;

class Student{
    private:
    int age,standard;
    string first_name, last_name;
    public:
    void set_age(int a){
    age=a;
    }
    int get_age(){
    return age;
    }
    void set_first_name(string s1){
    first_name=s1;
    }
    string get_first_name(){
    return first_name;
    }
    void set_last_name(string s2){
    last_name=s2;
    }
    string get_last_name(){
    return last_name;
    }
    void set_standard(int b){
    standard=b;
    }
    int get_standard(){
    return standard;
    }
    string to_string(){
        stringstream ss;
        first_name=','+first_name+',';
        last_name=last_name+',';
        ss<<age<<first_name<<last_name<<standard;
        string s;
        ss>>s;
        return s;
    }
};

int main() {
    int age, standard;
    string first_name, last_name;
    cin >> age >> first_name >> last_name >> standard;

    Student st;
    st.set_age(age);
    st.set_standard(standard);
    st.set_first_name(first_name);
    st.set_last_name(last_name);

    cout << st.get_age() << "\n";
    cout << st.get_last_name() << ", " << st.get_first_name() << "\n";
    cout << st.get_standard() << "\n";
    cout << "\n";
    cout << st.to_string();

    return 0;
}

