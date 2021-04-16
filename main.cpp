/**
 * Collaborated with: 
 * Ethan Wan,  
 * Mariam Golwalla,  
 * zybooks.com - CS 10C,
 * previous CS 10C labs
 * github.com to host our code
**/

#include <vector>
#include <stdexcept>
#include <cstdlib>
#include <iostream>
#include <time.h>

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
    element = vals.at(index);
    
    return element;
}

// helper function for part a
template <typename T>
void displayVector(const vector<T> &vals, int size) {
    for (int i = 0; i < size; i++) {
        cout << getElement(vals, i) << " ";
    }

    cout << endl << endl;
}

// test harness for part a
void createTestVector() {
	string userInput;
    int intValue;
    string stringValue;
    double doubleValue;
    int size;
    char charValue;
    int i;

	cout << "Testing Part A" << endl
      << "i - Test int vector" << endl
      << "c - Test char vector" << endl
      << "s - Test String vector" << endl
      << "d - Test double vector" << endl
      << endl;

	userInput.clear();
    cout << "Choose an option:" << endl;
    cin >> userInput;

    if (userInput != "i" && userInput != "c" && userInput != "s" && userInput != "d") {
        return;
    }
    
	if (userInput == "i") {
        vector<int> valsInt;

        cin.clear();
        cout << "Enter the desired number of values for the int vector" << endl;
        cin >> size;

        for (i = 0; i < size; i++) {
			cout << endl << "Enter value to push back into int vector" << endl;
			cin.clear();
        	cin >> intValue;
            valsInt.push_back(intValue);
        }

        size = valsInt.size();

        cout << endl << "Here is your initial int vector:" << endl;
        displayVector(valsInt, size);

        selection_sort(valsInt);

        cout << "Here is your int vector sorted:" << endl;
        displayVector(valsInt, size);
	}

    if (userInput == "c") {
        vector<char> valsChar;

        cin.clear();
        cout << "Enter the desired number of values for the char vector" << endl;
        cin >> size;

        for (i = 0; i < size; i++) {
			cout << endl << "Enter value to push back into char vector" << endl;
			cin.clear();
        	cin >> charValue;
            valsChar.push_back(charValue);
        }

        size = valsChar.size();

        cout << endl << "Here is your initial char vector:" << endl;
        displayVector(valsChar, size);

        selection_sort(valsChar);

        cout << "Here is your char vector sorted:" << endl;
        displayVector(valsChar, size);
	}

    if (userInput == "s") {
        cin.clear();
        cout << "Enter the desired number of values for the string vector" << endl;
        cin >> size;

        vector<string> valsString(size);

        for (i = 0; i < size; i++) {
            cout << endl << "Enter string value for string vector" << endl;
            cin.clear();
            cin >> stringValue;
            valsString.at(i) = stringValue;
        }

        cout << endl << "Here is your initial string vector:" << endl;
        displayVector(valsString, size);

        selection_sort(valsString);

        cout << "Here is your string vector sorted:" << endl;
        displayVector(valsString, size);
	}

    if (userInput == "d") {
        vector<char> valsDouble;

        cin.clear();
        cout << "Enter the desired number of values for the doubles vector" << endl;
        cin >> size;

        for (i = 0; i < size; i++) {
			cout << endl << "Enter value to push back into doubles vector" << endl;
			cin.clear();
        	cin >> doubleValue;
            valsDouble.push_back(doubleValue);
        }

        size = valsDouble.size();

        cout << endl << "Here is your initial doubles vector:" << endl;
        displayVector(valsDouble, size);

        selection_sort(valsDouble);

        cout << "Here is your doubles vector sorted:" << endl;
        displayVector(valsDouble, size);
	}
}

int main(){
    // part A
    createTestVector();

    /*    
    //vector<char> vals = createVector();
    vector<char> valsChar = createVector();
    vector<int> valsInt{10, 15, 20, 34, 76};
    vector<double> valsDouble{1.4, 2.6, 5.7, 8.5};
    vector<string> valsString{"First", "Second", "Third", "Last"};

    // Part A
    int i;
    try {
        selection_sort(valsChar);
        selection_sort(valsInt);
        selection_sort(valsDouble);
        selection_sort(valsString);

        for (i = 0; i < 4; i++) {
            // char
            if (getElement(valsChar,i) > getElement(valsChar,i))
                throw runtime_error("Selection Sort Error");

            // int
            if (getElement(valsInt,i) > getElement(valsInt,i))
                throw runtime_error("Selection Sort Error");

            // double
            if (getElement(valsDouble,i) > getElement(valsDouble,i))
                throw runtime_error("Selection Sort Error");

            // string
            if (getElement(valsString,i) > getElement(valsString,i))
                throw runtime_error("Selection Sort Error");    

        }

    } catch(runtime_error &excpt) {
            cout << "selection sort error";
        }
    */

    //Part B
    /*
     srand(time(0));

    vector<char> vals = createVector();
    int size = vals.size();
     char curChar;
     int index;
     int numOfRuns = 10;
     while(--numOfRuns >= 0){
        try {
            cout << "Enter a number: " << endl;
            cin >> index;
            
            if (index < 0 || index >= size)
                throw out_of_range("Invalid index");
                
            curChar = getElement(vals,index);
            cout << "Element located at " << index << ": is " << curChar << endl;

        } catch(const std::out_of_range& excpt) {
            cout << "out of range exception occured ";
        }

    } */

    return 0;
}