#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n,q;
    scanf("%d %d",&n,&q);
    vector<int>v[n];
    for(auto i=0;i<n;i++)
    {
        int k=0,input=0;
        scanf("%d",&k);
        for(auto j=0;j<k;j++)
        {
            scanf("%d",&input);
            v[i].push_back(input);
        }

    }
for(int i=0;i<q;i++)
{
    int p=0,l=0;
    scanf("%d %d ",&p,&l);
    printf("%d\n",v[p][l]);
}

    // for (int i = 0; i < n; i++) {
    //     for (auto it = v[i].begin();
    //          it != v[i].end(); it++) {
    //         cout << *it << ' ';
    //     }
    //     cout << endl;
    // }

    // 2nd method
    // a[i].reserve(k); // make room for k elements
    // for (int j=0;j<k;j++) {
    //     cin >> a[i][j]; // and reading them
    // }

// 3rd method
// #include<stdlib.h>
// int main() {
//     int n,q,m,l,k;
//     scanf("%d%d",&n,&q);
//     int *arr[n];
//     for(int i = 0 ; i < n;i++){
//         scanf("%d",&m);
//         arr[i] = (int *)malloc(m * sizeof(int));
//         for(int j = 0 ; j < m ;j++){
//              scanf("%d",&arr[i][j]);
//         }
//     }
//     while(q--){
//         scanf("%d%d",&l,&k);
//         printf("%d\n",arr[l][k]);
//     }
//     return 0;
// }

// 4th method
// int n,q;
// cin >> n >> q;
// vector< vector<int> > a(n);
// // input each array
// for (int i=0;i<n;i++) {
//     int k;
//     cin >> k;
//     for (int j=0;j<k;j++) {
//         int data;
//         cin >> data;
//         a[i].push_back(data);
//     }
// }
// // do the queries
// for (int i=0;i<q;i++) {
//     int x,y;
//     cin >> x >> y;
//     cout << a[x][y] << endl;
// }
    return 0;
}
