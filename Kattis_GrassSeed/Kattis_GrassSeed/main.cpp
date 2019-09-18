//
//  main.cpp
//  Kattis_GrassSeed
//
//  Created by Le Zhang on 9/17/19.
//  Copyright © 2019 Le Zhang. All rights reserved.
//

#include <iostream>
using namespace std;

int main(){
    int n;
    double per, w, l, sum = 0;
    cin >> per;
    cin >> n;
    for (int i = 1; i <= n; i ++){
        cin >> w;
        cin >> l;
        sum += w * l * per;
    }
    cout.precision(20);
    cout << sum << endl;
    return 0;
}
