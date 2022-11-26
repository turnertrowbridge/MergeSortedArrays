#include <iostream>
#include <vector>

using namespace std;

vector<int>  MergeSortedArrays(vector<int> array1, vector<int> array2){

    // check if array 1 is empty
    if(array1.empty()){
        return array2;
    }

    // merge array 2 into array 1
    for(auto x : array2){
        array1.push_back(x);
    }

    // sort the combined array
    sort(array1.begin(),array1.end());
    return array1;
}

vector<int> otherMergeSortedArrays(vector<int> array1, vector<int> array2){
    vector<int> sortedArray;
    int i = 0;
    int j = 0;

    // loop while not at the end of either array
    while(i < array1.size() && j < array2.size()){

        // add array1 value to sortedArray if lower than array2
        // else add array2 item to sortedArray
        if (array1.at(i) <= array2.at(j)){
            sortedArray.push_back(array1.at(i));
            i++; // increase array1 index
        } else {
            sortedArray.push_back(array2.at(j));
            j++; // increase array2 index
        }
    }

    // loops run if one array has reached the end

    // add remaining array1 values
    while(i < array1.size()) {
        sortedArray.push_back(array1.at(i));
        i++;
    }

    // add remaining array2 values
    while(j < array2.size()) {
        sortedArray.push_back(array2.at(j));
        j++;
    }

    return sortedArray;
}

int main() {

    // sort arrays
    vector<int> array1 {1,3,5,7,9,11};
    vector<int> array2 {2,4,6,8,8,10,12};

    // first method test
    // expected 1 2 3 4 5 6 7 8 8 9 10 11 12
    vector<int> sortedArray = MergeSortedArrays(array1, array2);
    for(auto x : sortedArray){
        cout << x << " ";
    }
    cout << endl;

    // second method test
    // expected 1 2 3 4 5 6 7 8 8 9 10 11 12
    sortedArray = otherMergeSortedArrays(array1, array2);
    for(auto x : sortedArray){
        cout << x << " ";
    }
    cout << endl;


    // check if array1 is empty
    array1 = {};

    // first method test
    // expected 2 4 6 8 8 10 12
    sortedArray = MergeSortedArrays(array1, array2);
    for(auto x : sortedArray){
        cout << x << " ";
    }
    cout << endl;

    // second method test
    // expected 2 4 6 8 8 10 12
    sortedArray = otherMergeSortedArrays(array1, array2);
    for(auto x : sortedArray){
        cout << x << " ";
    }
    cout << endl;


    // check if array2 is empty
    array1 = {1,2,3};
    array2 = {};

    // first method test
    // expected 1 2 3
    sortedArray = MergeSortedArrays(array1, array2);
    for(auto x : sortedArray){
        cout << x << " ";
    }
    cout << endl;

    // second method test
    // expected 1 2 3
    sortedArray = otherMergeSortedArrays(array1, array2);
    for(auto x : sortedArray){
        cout << x << " ";
    }
    cout << endl;

    // check if both arrays are empty
    array1 = {};
    array2 = {};

    // first method test
    // expected
    sortedArray = MergeSortedArrays(array1, array2);
    for(auto x : sortedArray){
        cout << x << " ";
    }
    cout << endl;

    // second method test
    // expected
    sortedArray = otherMergeSortedArrays(array1, array2);
    for(auto x : sortedArray){
        cout << x << " ";
    }
    return 0;
}
