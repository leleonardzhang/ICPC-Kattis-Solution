//
//  main.cpp
//  ICPC_2018_MidCentral_RepeatedSubstrings
//
//  Created by Le Zhang on 9/24/19.
//  Copyright © 2019 Le Zhang. All rights reserved.
//

#include <iostream>
#include <cstring>
using namespace std;
int len, biggestlen = 0;
int m = 0;
int ptx = 0;
int biggestcharpt = -1;
int maxtric[10000][10000] = {};
char charlist[100000] = {};
char biggestchar = 'z';
int pt[100000][2] = {0};

void compare(int i, int j);
void alphabetical(void);

int main() {
    string a, b;
    cin >> a;
    strcpy(charlist, a.c_str());
    len = (int) a.length();
    compare(len - 1, len - 2);
    alphabetical();
    for (int i = 0; i < biggestlen; i ++){
        cout << charlist[pt[biggestcharpt][0] + i];
    }
    cout << endl;
    return 0;
}

void compare(int i, int j){
    if ((i < 0) || (j < 0)) return;
    if (charlist[i] != charlist[j]){
        maxtric[i][j] = 0;
    }
    else{
        maxtric[i][j] = maxtric[i + 1][j + 1] + 1;
    }
    if (maxtric[i][j] > biggestlen){
        ptx = 0;
        biggestlen = maxtric[i][j];
        pt[ptx][0] = i;
        pt[ptx][1] = j;
        ptx ++;
    }
    else if (maxtric[i][j] == biggestlen){
        pt[ptx][0] = i;
        pt[ptx][1] = j;
        ptx ++;
    }
    if (((i - 1) != j)){
        compare(i - 1, j);
    }
    if (i != (j - 1)){
        compare(i, j - 1);
    }
}

void alphabetical(void){
    for (int i = 0; i < ptx; i ++){
        m = 0;
        while (m < biggestlen){
            if (biggestchar > charlist[pt[i][0]]){
                biggestchar = charlist[pt[i][0]];
                biggestcharpt = i;
                break;
            }
            m ++;
        }
    }
}
