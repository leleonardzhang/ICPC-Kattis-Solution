//
//  main.cpp
//  ICPC_2015_Mid-Central_goatrope
//
//  Created by Le Zhang on 8/29/19.
//  Copyright © 2019 Le Zhang. All rights reserved.
//

#include <iostream>
#include <cmath>
using namespace std;

int main(int argc, const char * argv[]) {
    int x, y, x1, y1, x2, y2;
    double dis;
    cin >> x;
    cin >> y;
    cin >> x1;
    cin >> y1;
    cin >> x2;
    cin >> y2;
    if ((x > x1) && (x < x2)){
        if (y < y1){
            dis = y1 - y;
        }
        else{
            dis = y - y2;
        }
    }
    else if ((y > y1) && (y < y2)){
        if (x < x1){
            dis = x1 - x;
        }
        else{
            dis = x - x2;
        }
    }
    else{
        if ((x < x1) && (y < y1)){
            dis = sqrt((x1 - x) * (x1 - x) + (y1 - y) * (y1 - y));
        }
        else if ((x < x1) && (y > y2)){
            dis = sqrt((x1 - x) * (x1 - x) + (y2 - y) * (y2 - y));
        }
        else if ((x > x2) && (y > y2)){
            dis = sqrt((x2 - x) * (x2 - x)+ (y2 - y) * (y2 - y));
        }
        else {
            dis = sqrt((x - x2) * (x - x2) + (y1 - y) * (y1 - y));
        }
    }
    cout << dis << endl;
    return 0;
}
