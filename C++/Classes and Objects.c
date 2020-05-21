#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cassert>
using namespace std;

// // Discussion code
// class Student {
//   private:
//     int scores[5];
//     int sum;
//   public:
//     Student() : sum(0) {}
//     int calculateTotalScore() {return sum;}
//     void input() {
//         for(int i=0; i<5; i++) {
//             cin >> scores[i];
//             sum+=scores[i];
//         }
//     }
// };

// imp comments
// It's the syntax for initializing members of the class and it is valid when using constructors. It is called initializer list and it follows the geneal syntax:

// class_name(type1 arg1, type2 arg2, type3 arg3): member1(arg1), member2(arg2), member3(arg3){}
// Instead of assignation:

// class_name(type1 arg1, type2 arg2, type3 arg3){member1 = arg1; member2 = arg2; member3 = arg3}
// There is a subtle difference between this two at implementation level, making initializations more efficient.

// its so that whenever we make a "Student" object, sum is initialized to zero. you also could of put that logic inside the constructor class like this:

// Student() { sum = 0; }

// same thing as the shorthand above.

// this is a constructor which intialises the sum=0. It is invoked automatically after object of class is declared.



// Write your Student class here
class Student{
    public:
    int scores[6];
    void input()
    {
        for(auto i=0;i<5;i++)
        {
            scanf("%d",&scores[i]);
        }
    }
    int calculateTotalScore()
    {
        int total=0;
        for(auto i=0;i<5;i++)
        {
            total=total+scores[i];
        }
        return total;
    }
};

int main() {
    int n; // number of students
    cin >> n;
    Student *s = new Student[n]; // an array of n students

    for(int i = 0; i < n; i++){
        s[i].input();
    }

    // calculate kristen's score
    int kristen_score = s[0].calculateTotalScore();

    // determine how many students scored higher than kristen
    int count = 0;
    for(int i = 1; i < n; i++){
        int total = s[i].calculateTotalScore();
        if(total > kristen_score){
            count++;
        }
    }

    // print result
    cout << count;

    return 0;
}

