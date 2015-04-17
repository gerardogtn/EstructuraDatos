//
//  main.cpp
//  ejerciciosSTL
//
//  Created by Gerardo Teruel on 4/16/15.
//  Copyright (c) 2015 Gerardo Teruel. All rights reserved.
//

#include <iostream>
#include <list>
#include <vector>
#include <iomanip>

using  namespace std;

int main(int argc, const char * argv[]) {
    
    
    vector<pair<int, int>> elementFrequency(100);
    srand((unsigned int) time(nullptr));
    
    
    for (int i = 0; i < 100; i++) {
        elementFrequency[i].first = i;
    }
    
    for (int i = 0; i < 1000; i++) {
        elementFrequency[rand() % 100].second++;
    }
    
    for (int i = 0; i < 100; i++){
        cout << setw(3) << elementFrequency[i].first << ": " << elementFrequency[i].second << endl;
    }
    
    cout << endl;
    
    
    sort(elementFrequency.begin(), elementFrequency.end(), [](pair<int, int> a, pair<int, int> b)
         {return a.second > b.second;});
    
    for (int i = 0; i < 100; i++){
        cout << setw(3) << elementFrequency[i].first << ": " << elementFrequency[i].second << endl;
    }
    
}
