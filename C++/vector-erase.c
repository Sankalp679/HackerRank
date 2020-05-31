#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int N,x,a,b,input;
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    vector <int> A;
    cin>>N;
    for (int i = 1; i <=N ; i++){
        cin>>input;
        A.push_back(input);
    }
    cin>>x;
    A.erase(A.begin()+x-1);
    cin>>a>>b;
    A.erase(A.begin()+a-1,A.begin()+b-1);
    cout<<A.size()<<"\n";
    for (auto it = A.begin(); it != A.end(); ++it){
        cout <<*it<<" ";
    }
    return 0;
}
