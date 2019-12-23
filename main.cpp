#include <iostream>
#include <vector>
using namespace std;

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
          displayVector(originalVector);
          cout << endl;
				}
				else {
					j++;
				}
		}
	}
    while (j != vectorSize);
	return originalVector;
}

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
	//create a bubblesort function
	vector<double> sortedVector = bubbleSort(intNumberList);
	cout << "Done! your sorted list of numbers is: ";
	displayVector(sortedVector);
	cout << endl;
  return 0;
}
