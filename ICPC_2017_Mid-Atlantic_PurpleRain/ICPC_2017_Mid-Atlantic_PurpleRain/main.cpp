//
//  main.cpp
//  ICPC_2017_Mid-Atlantic_PurpleRain
//
//  Created by Le Zhang on 10/22/19.
//  Copyright © 2019 Le Zhang. All rights reserved.
//

#include <iostream>
#include <cstring>
using namespace std;
long len;
char origin[100001];
int number1[100001];
int number2[100001];
int solution1[100001];
int solution2[100001];
int maxresult = -2;
long maxpt = -1;
int maxarray = 0;
long ppt;

void process(long pt);

void compare();

int main() {
    string a;
    cin >> a;
    len = a.length();
    strcpy(origin, a.c_str());
    for (long i = 0; i < len; i ++){
        if (origin[i] == 'B'){
            number1[i] = 1;
        }
        else{
            number1[i] = -1;
        }
        if (origin[i] == 'B'){
            number2[i] = -1;
        }
        else{
            number2[i] = 1;
        }
    }
    process(0);
    bool flag = false;
    long fpt = maxpt;
    if (maxarray == 1){
        while ((flag == false) && (fpt >= 0)){
            if ((solution1[fpt] - number1[fpt]) != (solution1[fpt - 1])){
                flag = true;
                ppt = fpt;
            }
            fpt --;
        }
    }
    else{
        while ((flag == false) && (fpt >= 0)){
            if ((solution2[fpt] - number2[fpt]) != (solution2[fpt - 1])){
                flag = true;
                ppt = fpt;
            }
            fpt --;
        }
    }
    cout << ppt + 1 << " " << maxpt + 1 << endl;
    return 0;
}


void process(long pt){
    if (pt >= len){
        compare();
        return;
    }
    if (pt == 0){
        solution1[pt] = number1[pt];
        solution2[pt] = number2[pt];
    }
    else{
        if (number1[pt] > solution1[pt - 1]){
            solution1[pt] = number1[pt];
        }
        else{
            solution1[pt] = solution1[pt - 1] + number1[pt];
        }
        if (number2[pt] > solution2[pt - 1]){
            solution2[pt] = number2[pt];
        }
        else{
            solution2[pt] = solution2[pt - 1] + number2[pt];
        }
    }
    process(pt + 1);
}

void compare(){
    for (long i = 0; i < len; i ++){
        if (solution1[i] > maxresult){
            maxresult = solution1[i];
            maxpt = i;
            maxarray = 1;
        }
        if (solution2[i] > maxresult){
            maxresult = solution2[i];
            maxpt = i;
            maxarray = 2;
        }
    }
}
