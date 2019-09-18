//
//  main.cpp
//  Kattis_cetvrta
//
//  Created by Le Zhang on 9/17/19.
//  Copyright © 2019 Le Zhang. All rights reserved.
//

#include <iostream>
using namespace std;

int main(){
    int x[3], y[3], x4 = 0, y4 = 0;
    for (int i = 0; i < 3; i ++){
        cin >> x[i];
        cin >> y[i];
    }
    if (x[0] == x[1]){
        x4 = x[2];
    }
    if (x[0] == x[2]){
        x4 = x[1];
    }
    if (x[2] == x[1]){
        x4 = x[0];
    }
    if (y[0] == y[1]){
        y4 = y[2];
    }
    if (y[0] == y[2]){
        y4 = y[1];
    }
    if (y[2] == y[1]){
        y4 = y[0];
    }
    cout << x4 << " " << y4 << endl;
    return 0;
}
