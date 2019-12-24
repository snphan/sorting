#include <iostream>
#include <vector>
#include <chrono>
#include <iomanip>
using namespace std;

//------------------------------------------------------------//
//TODO: Add a function for timer start - Steven
//------------------------------------------------------------//
chrono::time_point<chrono::high_resolution_clock> timerStart() {
	auto start = chrono::high_resolution_clock::now();
    return start;
}

//------------------------------------------------------------//
//TODO: Add a function for timer finish - Steven
//------------------------------------------------------------//
void timerFinish(chrono::time_point<chrono::high_resolution_clock> startTime) {
	auto finish = chrono::high_resolution_clock::now();
	chrono::duration<double> elapsed = finish - startTime;
    double elapsedTime = elapsed.count();
	cout << "Elapsed time: " << setprecision(100) << elapsedTime << "s\n";
}

vector<double> convertStrToVector(string str){
	// Convert a comma delimited string into a vector of doubles.
	vector<double> numberArray(1);
	int j = 0, i;
	for (i = 0; str[i] != '\0'; i++){
		if (str[i] == ','){
			// if we get to a comma, go to the next index of the array and add another element
			j++;
            numberArray.push_back(0);
		}
		else {
			numberArray[j] = numberArray[j]*10 + (str[i] - 48);
      //cout << numberArray[j] << endl;
		}
    }
    return numberArray;
}

void swapNumbers(double &x, double &y) {
		//swap the value of the referenecd numbers x and y inputted into this function
    int z = x;
    x = y;
    y = z;
}

void displayVector(vector<double> numberVector) {
	// Format and display the inputted vector into the console.
	int i;
	for (i = 0; i < numberVector.size() - 1; i++) {
		cout << numberVector[i] << ", ";
	}
	cout << numberVector[i];
}

vector<double> bubbleSort(vector<double> originalVector) {
	// use bubble sort to sort from least to greatest.
	int vectorSize = originalVector.size();
	int i,j;
	do {
		j = 1;
		for (i = 0; i < vectorSize - 1; i++) {
				if (originalVector[i] > originalVector[i+1]) {
					swapNumbers(originalVector[i], originalVector[i+1]);
          //displayVector(originalVector);
          //cout << endl;
				}
				else {
					j++;
				}
		}
	}
    while (j != vectorSize);
	return originalVector;
}

//------------------------------------------------------------//
//TODO: Add a function for selection sort
vector<double> selectionSort(vector<double> originalVector) {
	int vectorSize = originalVector.size();
	int i,j,k,stopper;
	// i is the counter for the item being compared, j is the counter for the item,
	// that the first item is being compared to. k is the counter for the index of element
	// that is the smallest. Stopper is the counter for the stopper.
	do {
		stopper = 0;
		for (i = 0; i < vectorSize; i++) {
			// reset the counter to null
			k = -1;
				// Loop to check the first number with all the other numbers
				for (j = i+1; j < vectorSize; j++) {
					if (originalVector[i] > originalVector[j]) {
						k = j;
					}
				}
				if (k != -1) {
						swapNumbers(originalVector[i],originalVector[k]);
				}
				else {
					//if there is no swap, increase stopper by 1
					stopper++;
				}
			}
		} while (stopper != vectorSize);
	return originalVector;
}
//------------------------------------------------------------//
//TODO: Add a function for merge sort - Steven
vector<double> mergeSort(vector<double> originalVector) {
	// How does merge sort work? Keep splitting the list in half until there is
	// only one element left. Combine them in order. Divide and conquer algorithm.

}

bool ifOdd(int x) {
	// checks if the inputted value is odd.
	int y = x % 2;
	if (y = 0) {
		return false;
	}
	else {
		return true;
	}
}

vector<double> splitArrayLeft(vector<double> array) {
	// This function will split the array into its left half
		int arraySize = array.size();
		int middleIndex;
		vector<double> leftArray;
		if (ifOdd(arraySize)) {
			middleIndex = arraySize/2; // If the amount of elements is odd, then the function should round down
		}
		else {
			middleIndex = arraySize/2 - 1;
		}
		vector<double> leftArray(middleIndex + 1);
		for (int i = 0; i < middleIndex; i++) {
			leftArray[i] = array[i];
		}
		return leftArray;
}

vector<double> splitArrayRight(vector<double> array) {
	// This function will split the array into its right half

}
// We require some helper functions: one for merge and one for splitting the
// arrays up.
//------------------------------------------------------------//

int main() {
	string numberList;
    vector<double> intNumberList;
	cout << "Hello, this program will sort your list of numbers using the bubble \
sort).\nPlease choose some numbers separated by commas! (ex. 1,2,3,4,5)\n";
	cin >> numberList;
	if (numberList != "\0") {
        intNumberList = convertStrToVector(numberList);
		cout << "Awesome, your list of numbers is: ";
		displayVector(intNumberList);
		cout << endl;
	} else {
		cout << "Hmm, it doesn't seem like you entered anything\n";
		return 0;
	}
	auto startTime = timerStart();
	vector<double> sortedVector = bubbleSort(intNumberList);
  timerFinish(startTime);
	cout << "Done! your sorted list of numbers is: ";
	displayVector(sortedVector);
	cout << endl;
  return 0;
}
