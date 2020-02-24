//
//  main.cpp
//  Kattis_8queens
//
//  Created by Le Zhang on 2/18/20.
//  Copyright © 2020 Le Zhang. All rights reserved.
//

#include <iostream>
using namespace std;

char chart[8][8];
char result[8][8];
bool compare();
bool flag = false;

void search(int k);
bool checkrowcolumn(int x, int y);
bool checkdiag(int x, int y);
bool check(int x, int y);

int main(){
    for (int i = 0; i < 8; i ++){
        for (int j = 0; j < 8; j ++){
            chart[i][j] = '.';
        }
    }
    for (int i = 0; i < 8; i ++){
        for (int j = 0; j < 8; j ++){
            cin >> result[i][j];
        }
    }
    search(0);
    if (flag){
        cout << "valid" << endl;
    }
    else{
        cout << "invalid" << endl;
    }
}

void search(int k){
    if (k >= 8) {
        flag = flag || compare();
        return;
    }
    for (int i = 0; i < 8; i ++){
        if (check(k, i) == true){
            chart[k][i] = '*';
            search(k + 1);
            chart[k][i] = '.';
        }
    }
}

bool check(int x, int y){
    return checkdiag(x, y) && checkrowcolumn(x, y);
}


bool checkrowcolumn(int x, int y){
    for (int i = 0; i < 8; i ++){
        if (chart[x][i] == '*' && y != i){
            return false;
        }
        if (chart[i][y] == '*' && x != i){
            return false;
        }
    }
    return true;
}


bool checkdiag(int x, int y){
    int i = x;
    int j = y;
    while (i >= 0 && i < 8 && j >= 0 && j < 8){
        i ++;
        j ++;
        if (i >= 0 && i < 8 && j >= 0 && j < 8){
            if (chart[i][j] == '*'){
                return false;
            }
        }
    }
    i = x;
    j = y;
    while (i >= 0 && i < 8 && j >= 0 && j < 8){
        i ++;
        j --;
        if (i >= 0 && i < 8 && j >= 0 && j < 8){
            if (chart[i][j] == '*'){
                return false;
            }
        }
    }
    i = x;
    j = y;
    while (i >= 0 && i < 8 && j >= 0 && j < 8){
        i --;
        j --;
        if (i >= 0 && i < 8 && j >= 0 && j < 8){
            if (chart[i][j] == '*'){
                return false;
            }
        }
    }
    i = x;
    j = y;
    while (i >= 0 && i < 8 && j >= 0 && j < 8){
        i --;
        j ++;
        if (i >= 0 && i < 8 && j >= 0 && j < 8){
            if (chart[i][j] == '*'){
                return false;
            }
        }
    }
    return true;
}

    
bool compare(){
    for (int i = 0; i < 8; i ++){
        for (int j = 0; j < 8; j ++){
            if (chart[i][j] != result[i][j]){
                return false;
            }
        }
    }
    return true;
}
