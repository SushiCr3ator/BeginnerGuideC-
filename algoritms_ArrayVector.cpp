//
// Created by gold1 on 10/09/2025.
//

#ifndef BEGINNERGUIDE_WARRAY_H
#define BEGINNERGUIDE_WARRAY_H

#include <iostream>
#include <vector>


class wArray {
private:
    std::pmr::vector<int> vec = {100,23,5,69,1,43,99,20,67,101};
    //difference between this and array is that array's size is declared beforehand
    //sorted: < 1, 5, 20, 23 ,43, 67, 69, 99, 100, 101 >
    int length = vec.size();//needed for all algorithms

    int myTestArray[5] ={1,2,3,4,5};
    double highArray[6]={23,1,980,10,1000,666};
public:
    void writeArray() {
        for (auto i: myTestArray)
            std::cout << i << " ";
    }
    void maxArray() {
        double result;
        for (int i : highArray) {
            if (result < i) {
                result = i;
            }
            std::cout << result << std::endl;
        }
        std::cout << "The maximum value in array is :" << result << std::endl;
    }

    //algorithms
    void buble_Sort() {
        for (int i =0; i < length-1; i++) {
            for (int j = 0; j < length-i-1; j++) {
                // it looks at the first 2 index and changes them if the first is bigger than second else moves one to the next pair
                if (vec.at(j) > vec.at(j+1)) {
                    int temp = vec.at(j);
                    vec.at(j)= vec.at(j+1);
                    vec.at(j+1)= temp;
                    std::cout << vec.at(j) << " and " << vec.at(j+1) << " changed positions!"<< std::endl;
                }
            }
        }
        std::cout << "The sorted vector is :" << std::endl;
        for (int y = 0 ; y < length; y++) {
            std::cout << vec.at(y) << std::endl;
        }
    }
    void selection_Sort() {
        for (int i = 0; i < length-1 ;i++) {
            int curr_Min = i;
            std::cout << vec.at(curr_Min) << " is currently the smallest bfr 2nd loop"<< std::endl;
            for (int j = i+1; j < length-1 ; j++) {//finds the smallest index available
                if (vec.at(j) < vec.at(curr_Min)) {
                    curr_Min = j;
                    std::cout << vec.at(curr_Min) << " is currently the smallest after 2nd loop"<< std::endl;
                }
            }
            int temp = vec.at(i);
            vec.at(i) = vec.at(curr_Min);
            vec.at(curr_Min)= temp;
            std::cout << vec.at(i) << " and " << vec.at(curr_Min) << " changed positions!"<< std::endl;
            //switches the smallest index with current index
        }
        std::cout << "The sorted vector is :" << std::endl;
        for (int y = 0 ; y < length; y++) {
            std::cout << vec.at(y) << std::endl;
        }
    }
    void insertion_Sort() {
        for (int i = 1 ; i < length ; i++) {
            int key = vec.at(i);//holds the current index as a key
            int j = i-1;
            std::cout << vec.at(i) << " is the inserting index"<< std::endl;
                while (j >= 0 && vec.at(j) > key) {//finds where the key should be inserted
                    vec.at(j+1) = vec.at(j);
                    j--;
                }
                vec.at(j+1) = key;
                std::cout << vec.at(j+1) << " is the inserted index"<< std::endl;
        }
        std::cout << "The sorted vector is :" << std::endl;
        for (int y = 0 ; y < length; y++) {
            std::cout << vec.at(y) << std::endl;
        }
    }

    // Merges two subarrays of vec.
    // First subarray is vec[left..mid]
    // Second subarray is vec[mid+1..right]
    void merge(std::pmr::vector<int>& vec, int left, int mid, int right) {
        int i, j, k;
        int n1 = mid - left + 1;
        int n2 = right - mid;

        // Create temporary vectors
        std::pmr::vector<int> leftVec(n1), rightVec(n2);

        // Copy data to temporary vectors
        for (i = 0; i < n1; i++)
            leftVec.at(i) = vec.at(left + i);
        for (j = 0; j < n2; j++)
            rightVec.at(j) = vec.at(mid+1+j);

        // Merge the temporary vectors back into vec[left..right]
        i = 0;
        j = 0;
        k = left;

        while (i < n1 && j < n2) {
            if (leftVec.at(i) <= rightVec.at(j)) {
                vec.at(k) = leftVec.at(i);
                i++;
            } else {
                vec.at(k) = rightVec.at(j);
                j++;
            }
            k++;
        }

        while (i < n1) {
            vec.at(k) = leftVec.at(i);
            i++;
            k++;
        }
        while (j < n2) {
            vec.at(k) = rightVec.at(j);
            j++;
            k++;
        }
    }
    void mergeSort(std::pmr::vector<int>& vec, int left, int right) {
        if (left < right) {

            // Calculate the midpoint
            int mid = left + (right - left) / 2;

            // Sort first and second halves
            mergeSort(vec, left, mid);
            mergeSort(vec, mid + 1, right);

            // Merge the sorted halves
            merge(vec, left, mid, right);
        }
    }

    int merge_Sort() {
        std::pmr::vector<int> mergingVec = vec;
        int n = mergingVec.size();

        // Sorting vec using mergesort
        mergeSort(mergingVec, 0, n - 1);

        std::cout << "The sorted vector is :" << std::endl;
        for (int y = 0 ; y < n; y++) {
            std::cout << mergingVec.at(y) << std::endl;
        }
    }

};


#endif //BEGINNERGUIDE_WARRAY_H
