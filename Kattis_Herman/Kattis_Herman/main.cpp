//
//  main.cpp
//  Kattis_Herman
//
//  Created by Le Zhang on 9/17/19.
//  Copyright © 2019 Le Zhang. All rights reserved.
//

#include <iostream>
#include <cmath>
using namespace std;

int main(){
    double n;
    cin >> n;
    double a1, a2;
    a1 = M_PI * n * n;
    a2 = 2 * n * n;
    cout.precision(15);
    cout << a1<< endl;
    cout << a2 << endl;
    return 0;
}

