/* 	Collaborated with: 
	Ethan Wan,  
	Mariam Golwalla,  
	zybooks.com - CS 10C, 
	github.com to host our code
*/

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
    } catch(const std::out_of_range& excpt) {
        cout << "out of range exception occured" << endl;
    }

    // something is wrong if the function returns -1
    return -1;
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