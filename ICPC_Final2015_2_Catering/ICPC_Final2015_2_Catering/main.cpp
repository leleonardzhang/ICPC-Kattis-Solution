//
//  main.cpp
//  ICPC_Final_2015_2_Catering
//
//  Created by Le Zhang on 8/26/19.
//  Copyright © 2019 Le Zhang. All rights reserved.
//

#include <iostream>
using namespace std;

long costlist[102][102];
long costsum[102][102];
long minsum = 100000001;
bool nodes[102][102];
int n, k, j;

void getsum(int j);
int getprenode(int i, int j);

int main() {
    cin >> n;
    cin >> k;
    for (int i = 1; i <= n; i++){
        for (int j = i + 1; j <= n + 1; j++){
            cin >> costlist[i][j];
        }
    }
    for (int i = 1; i <= k; i++){
        nodes[i][1] = 1;
    }
    getsum(2);
    cout << minsum << endl;
    return 0;
}

void getsum(int j){
    if (j > (n + 1)){
        int sum = 0;
        for (int i = 1; i <= k; i++){
            sum += costsum[i][n + 1];
        }
        if (sum < minsum){
            minsum = sum;
        }
        return;
    }
    for (int i = 1; i <= k; i++){
        for (int i1 = 1; i1 <= k; i1++){
            if (i1 != i){
                costsum[i1][j] = costsum[i1][j - 1];
            }
            else{
                costsum[i][j] = costsum[i][j - 1] + costlist[getprenode(i, j)][j];
                nodes[i][j] = 1;
            }
        }
        getsum(j + 1);
        for (int i1 = 1; i1 <= k; i1++){
            costsum[i1][j] = 0;
        }
        nodes[i][j] = 0;
    }
}

int getprenode(int i, int j){
    for (int m = j; m > 1; m--){
        if (nodes[i][m]!= 0){
            return m;
        }
    }
    return 1;
}
