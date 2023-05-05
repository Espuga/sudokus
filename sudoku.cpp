#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
// Hola

bool solution(vector<vector<char>> grid) {
    // Comprovar no repetir en rows.
    for(int row = 0; row < size(grid); row++){
        vector<char> nums;
        for(int column = 0; column < size(grid[row]); column++){
            if(isdigit(grid[row][column])){
                if(find(nums.begin(), nums.end(), grid[row][column]) != nums.end()){
                    return false;
                }else{
                    nums.push_back(grid[row][column]);
                } 
            }
        }
    }
    // Comprovar no repetir en columns
    for(int column = 0; column < size(grid[0]); column++){
        vector<char> nums;
        for(int row = 0; row < size(grid); row++){
            // Si ja hi hes dins de nums
            if(isdigit(grid[row][column])){
                if(find(nums.begin(), nums.end(), grid[row][column]) != nums.end()){
                    return false;
                }else{
                    nums.push_back(grid[row][column]);
                } 
            }
            
        }
    }
    // Comprovar dins del mateix requadre de 3x3
    vector<int> blocked = {1, 2, 4, 5, 7, 8};
    int column = 0;
    vector<char> group1;
    vector<char> group2;
    vector<char> group3;

    // Per cada row
    for(int row = 0; row < size(grid); row++){
        if(row == 3 || row == 6){
            vector<char> group1;
            vector<char> group2;
            vector<char> group3;
        }
        // Per cada column
        for(int column = 0; column < size(grid[0]); column ++){
            if(isdigit(grid[row][column])){
                if(column < 3){
                    group1.push_back(grid[row][column]);
                }else if(column < 6){
                    group2.push_back(grid[row][column]);
                }else{
                    group3.push_back(grid[row][column]);
                }
            }
            
        }
        
        // Printar blocks 3x3
        
        

        // Si row == 2 / 5 / 8, comprovar si estan repetits dins de cada group
        if(row == 2 ||row == 5 || row == 8){
            // 1
            cout << "group1:" << endl;
            for(int c1 = 0; c1 < size(group1); c1++){
                cout << group1[c1] << endl;
            }
            // Comprovar si estan repetits als blocs de 3x3
            for(int index = 0; index < size(group1); index++){
                if(count(group1.begin(), group1.end(), group1[index]) > 1){
                    return false;
                }
            }
            group1.clear();
            // 2
            cout << "group2:" << endl;
            for(int c1 = 0; c1 < size(group2); c1++){
                cout << group2[c1] << endl;
            }
            for(int index = 0; index < size(group2); index++){
                if(count(group2.begin(), group2.end(), group2[index]) > 1){
                    return false;
                }
            }
            group2.clear();

            // 3
            cout << "group3:" << endl;
            for(int c1 = 0; c1 < size(group3); c1++){
                cout << group3[c1] << endl;
            }
            for(int index = 0; index < size(group3); index++){
                if(count(group3.begin(), group3.end(), group3[index]) > 1){
                    return false;
                }
            }
            group3.clear();
        }
    }
    return true;
}

int main(){
    // Test 1
    vector<vector<char>> test1 = {
        {'.', '.', '.', '1', '4', '.', '.', '2', '.'}, 
        {'.', '.', '6', '.', '.', '.', '.', '.', '.'}, 
        {'.', '.', '.', '.', '.', '.', '.', '.', '.'}, 
        {'.', '.', '1', '.', '.', '.', '.', '.', '.'}, 
        {'.', '6', '7', '.', '.', '.', '.', '.', '9'}, 
        {'.', '.', '.', '.', '.', '.', '8', '1', '.'}, 
        {'.', '3', '.', '.', '.', '.', '.', '.', '6'}, 
        {'.', '.', '.', '.', '.', '7', '.', '.', '.'}, 
        {'.', '.', '.', '5', '.', '.', '.', '7', '.'}
    };
    // Test 2
    vector<vector<char>> test2 = {
        {'.', '.', '.', '.', '2', '.', '.', '9', '.'},
        {'.', '.', '.', '.', '6', '.', '.', '.', '.'},
        {'7', '1', '.', '.', '7', '5', '.', '.', '.'},
        {'.', '7', '.', '.', '.', '.', '.', '.', '.'},
        {'.', '.', '.', '.', '8', '3', '.', '.', '.'},
        {'.', '.', '8', '.', '.', '7', '.', '6', '.'},
        {'.', '.', '.', '.', '.', '2', '.', '.', '.'},
        {'.', '1', '.', '2', '.', '.', '.', '.', '.'},
        {'.', '2', '.', '.', '3', '.', '.', '.', '.'}
    };

    if(solution(test1)){
        cout << "Test 1: OK" << endl;
    }else{
        cout << "Test 1: PROBLEM" << endl;
    }
    if(solution(test2)){
        cout << "Test 2: OK" << endl;
    }else{
        cout << "Test 1: PROBLEM" << endl;
    }

    return 0;
}