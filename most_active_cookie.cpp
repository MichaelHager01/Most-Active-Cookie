#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>

using namespace std;


bool sameDate(string date, const string dateOfInterest) {           // Checking if the date is same as the date of interest
    for (int i = 0; i < 10; i++) {
        if (date[i] == dateOfInterest[i]) {
            continue;
        }
        else { return false; }
    }
    return true;
}

vector<string> mostRepeated(vector<string> x) {         // Finds most repeated items in vector and creates new vector with those
    vector<string> y;                                   // Returns same vector being tested of no more repeated items
    for (int i = 0; i < x.size(); i++) {
        if (i == x.size() - 1) {
            break;
        }
        for (int j = i + 1; j < x.size(); j++) {
            if (x[i] == x[j]) {
                y.push_back(x[i]);
            }
        }
    }
    if (y.empty()) {
        return x;
    }
    return y;
}

int main(int count, char ** vec) {
    ifstream file;          // Variable initializations
    string first, line, data, prev;
    vector<string> total, result;
    string dateOfInterest = vec[3];

    file.open(vec[1]);          // Checking if file opens and gets rid of first row of csv
    if (!file.is_open()) { cout << "Unable to open file\n"; return 0; }
    getline(file, first);

    while (getline(file, line)) {           // Moving all cookies whithin date of interest into a vector
        istringstream s(line);
        while (getline(s, data, ',')) {
            if (sameDate(data, dateOfInterest)) {
                total.push_back(prev);
            }
            prev = data;
        }
    }

    result = mostRepeated(total);           // Continuing to repeat function until having a vector with no more repeated items
    while (mostRepeated(result) != result) {
        result = mostRepeated(result);
    }

    for (int k = 0; k < result.size(); k++) {           // Output most repeated cookies in desired time
        cout << result[k] << endl;
    }

    file.close();           // Closing file

    return 0;
}
