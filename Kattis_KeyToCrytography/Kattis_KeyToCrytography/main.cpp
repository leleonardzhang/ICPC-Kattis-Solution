//
//  main.cpp
//  Kattis_KeyToCrytography
//
//  Created by Le Zhang on 2/23/20.
//  Copyright © 2020 Le Zhang. All rights reserved.
//

#include <iostream>
#include <string>
#include <cstring>

using namespace std;

char crypt[1000];

char key[1000];

char mess[1000];

void move(char c, char k, int pt);


int main(){
    int cryptlen;
    string crypt_str;
    cin >> crypt_str;
    cryptlen = (int) crypt_str.length();
    strcpy(crypt, crypt_str.c_str());
    
    int keylen;
    string key_str;
    cin >> key_str;
    keylen = (int) key_str.length();
    strcpy(key, key_str.c_str());
    
    for (int i = 0; i < cryptlen; i ++){
        move(crypt[i], key[i], i);
        key[i + keylen] = mess[i];
    }
    
    for (int i = 0; i < cryptlen; i ++){
        cout << mess[i];
    }
    
   
    cout << endl;
    
    
    return 0;
}

void move(char c, char k, int pt){
    if (c - (k - 'A') >= 'A'){
        mess[pt] = c - (k - 'A');
    }
    else{
        mess[pt] = c - (k - 'A') + 26;
    }
    
}
