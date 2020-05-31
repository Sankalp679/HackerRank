#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int N,input,Q,input1;
    vector <int> A;
    cin>>N;
    for(int i=1;i<=N;i++)
    {
      cin>>input;
      A.push_back(input);
    }
    cin>>Q;
    for(int i=1;i<=Q;i++)
    {
        cin>>input1;
        auto it = lower_bound(A.begin(),A.end(),input1);
        bool present= binary_search(A.begin(),A.end(),input1);
        if (!present)
        {
           cout<<"No"<<" "<<it-A.begin()+1<<"\n";
        }
        else{
           cout<<"Yes"<<" "<<it-A.begin()+1<<"\n";
        }
    }
    return 0;
}
