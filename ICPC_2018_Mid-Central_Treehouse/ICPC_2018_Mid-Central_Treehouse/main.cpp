//
//  main.cpp
//  ICPC_2018_Mid-Central_Treehouse
//
//  Created by Le Zhang on 9/2/19.
//  Copyright © 2019 Le Zhang. All rights reserved.
//

#include <iostream>
#include <math.h>

using namespace std;

int n, e, p;
double dist[1001][1001];
double loc[1001][3];
int connect[1001][3];
bool activenode[1001];
void computeDist();
int findNearest(int x);
void activate(int x);
void search(int re);
double cable = 0;

int main() {
    cin >> n;
    cin >> e;
    cin >> p;
    for (int i = 1; i <= n; i ++){
        cin >> loc[i][1];
        cin >> loc[i][2];
    }
    for (int i = 1; i <= p; i ++){
        cin >> connect[i][1];
        cin >> connect[i][2];
    }
    computeDist();
    int remain = n;
    for (int i = 1; i <= e; i ++){
        activate(i);
        remain --;
        for (int j = 1; j <= p; j ++){
            if ((connect[j][1] == i) && (!activenode[connect[j][2]])){
                activate(connect[j][2]);
                remain --;
            }
            else if ((connect[j][2] == i) && (!activenode[connect[j][1]])){
                activate(connect[j][1]);
                remain --;
            }
        }
    }
    search(remain);
    cout << cable << endl;
    return 0;
}

void search(int re){
    if (re == 0){
        return;
    }
    double nearest = 1000 * sqrt(2);
    int nearnode = 0;
    for (int i = 1; i <= n; i ++){
        if (activenode[i] == 0){
            if (dist[i][findNearest(i)] < nearest){
                nearest = dist[i][findNearest(i)];
                nearnode = i;
            }
        }
    }
    activate(nearnode);
    re --;
    for (int i = 1; i <= p; i ++){
        if ((connect[i][1] == nearnode) && (activenode[connect[i][2]] == 0)){
            activate(connect[i][2]);
            re --;
        }
        else if ((connect[i][2] == nearnode) && (activenode[connect[i][1]] == 0)){
            activate(connect[i][1]);
            re --;
        }
    }
    cable += nearest;
    search(re);
}


void computeDist(){
    for (int i = 1; i <= n; i ++){
        for (int j = 1; j <= n; j ++){
            if (i != j){
                double ydist = loc[i][2] - loc[j][2];
                double xdist = loc[i][1] - loc[j][1];
                dist[i][j] = sqrt(pow(xdist, 2.0) + pow(ydist, 2.0));
            }
            else{
                dist[i][j] = 0;
            }
        }
    }
}

int findNearest(int x){
    double nearest = 10000 * sqrt(2);
    int nearnode = x;
    for (int i = 1; i <= n; i ++){
        if ((nearest > dist[x][i]) && (activenode[i])){
            nearest = dist[x][i];
            nearnode = i;
        }
    }
    return nearnode;
}

void activate(int x){
    activenode[x] = 1;
}
