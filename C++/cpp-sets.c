#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <set>
#include <algorithm>
using namespace std;

int main() {
    int Q,a,b;
    cin>>Q;
    set<int>s;
    for(int i=0;i<Q;i++)
    {
        cin>>a>>b;
        if(a==1)
        {
            s.insert(b);
        }
        else if(a==2)
        {
            s.erase(b);
        }
        else if(a==3)
        {
            auto itr = s.find(b);
            if(itr==s.end())
            {
                cout<<"No"<<"\n";
            }
            else
            {
                cout<<"Yes"<<"\n";
            }
        }
    }
    return 0;
}

// You don't need to declare an iterator object just to check if the value exists. And switch looks more suitable here than lot of if-then...

// int main() {
// int iCount;
// set<int> ss;
// cin >> iCount;
// for (int i=0; i<iCount; ++i){
//     int type, query;
//     cin >> type >> query;
//     switch (type){
//         case 1:
//             ss.insert(query);
//             break;
//         case 2:
//             ss.erase(query);
//             break;
//         case 3:
//             cout << (ss.find(query) == ss.end() ? "No" : "Yes") << endl;
//             break;
//     }
// }
// return 0;
// }
// begin() – Returns an iterator pointing to the first element in the vector
// end() – Returns an iterator pointing to the theoretical element that follows the last element in the vector

