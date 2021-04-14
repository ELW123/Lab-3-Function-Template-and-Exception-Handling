#include <vector>
#include <stdexcept>
#include <cstdlib>
#include <iostream>
#include <time.h>
#include <bits/stdc++.h>

using namespace std;

template <typename T>
unsigned min_index(const vector<T> &vals, unsigned index) {
    T value = vals[index];
    int minIndex = index;
    int size = vals.size();

    for (int i = index; i < size; i++) {
        
        /* String implementation is still buggy
        // first check if T is a string
        if (typeid(T) == typeid(std::string)) {
            // compares the lengths of strings - should double check later!
            if (vals[i].length() < value.length()) {
                value = vals[i];
                minIndex = i;    
            }   
        }
        
        // if T is not a string
        else if(vals[i] < value) {
            value = vals[i];
            minIndex = i;
        } */
        
        // This code passed the zybooks test for strings?????
        if(vals[i] < value) {
            value = vals[i];
            minIndex = i;
        }
    }

    return minIndex;
}

template <typename T>
void selection_sort(vector<T> &vals) {
    int minIndex;
    T temp;
    int size = vals.size();

    // I do not know why the function does not work if I directly put in vals.size() in the for loop instead of replacing it with int size
    for (int i = 0; i < size; i++) {
        minIndex = min_index(vals, i);
        temp = vals[minIndex];
        vals[minIndex] = vals[i];
        vals[i] = temp;
    }
}

vector<char> createVector(){
    int vecSize = rand() % 26;
    char c = 'a';
    vector<char> vals;
    for(int i = 0; i < vecSize; i++)
    {
        vals.push_back(c);
        c++;
    }
    return vals;
}

template <typename T>
T getElement(vector<T> vals, int index) {
    T element;   
    try {
       element = vals.at(index);
       return element;
    } catch(const std::out_of_range& e) {
        cout << "out of range exception occured ";
    }
    
    return 0;
}

int main(){

    //Part B
     srand(time(0));
     vector<char> vals = createVector();
     char curChar;
     int index;
     int numOfRuns = 10;
     while(--numOfRuns >= 0){
         cout << "Enter a number: " << endl;
         cin >> index;
         curChar = getElement(vals,index);
         cout << "Element located at " << index << ": is " << curChar << endl;
    }
    return 0;
}