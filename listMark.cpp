// Copyright (c) 2021 Jonathan Kene All rights reserved.
//
// Created by: Jonathan Kene
// Created on: June 15, 2021
// The program uses a loop to enter each mark into a list of integers.
// When the user enters -1, the loop stops. It then calls a function that
// accepts a list of integers and returns the average of all the marks entered.

#include <math.h>
#include <list>
#include <string>
#include <stdexcept>
#include <iterator>
#include <iostream>

float calcAverage(std::list<int> listOfMarks) {
    // calculate the average in the list
    int sum = 0;
    float average = -1;

    for (int number : listOfMarks) {
        sum += number;
    }

    if (listOfMarks.size() == 0) {
        throw std::runtime_error("Cannot calculate the average of empty list");
    } else {
        int size = listOfMarks.size();
        average = static_cast<float>(sum) / static_cast<float>(size);
    }

    return average;
}


int main() {
    // initilizations
    // declaring variables
    std::list<int>listMarks;
    std::string userMarkString, listString = "", numberString;
    int userMarkInt, counter = 0, number;
    float userMarkFloat, userAverage;

    std::cout << "This program calculates the average of several marks.\n";
    std::cout << "\n";

    while (true) {
        // gets a mark for the list
        std::cout << "Enter a mark between 0 to 100. Enter -1 to stop: ";
        std::cin >> userMarkString;

        try {
            userMarkInt = std::stoi(userMarkString);

            userMarkFloat = std::stof(userMarkString);

            if (userMarkInt == -1) {
                // breaks from the loop
                break;
            } else if (userMarkInt < 0 || userMarkInt > 100) {
                std::cout << userMarkInt << "is not between 0 and 100.";
            } else if (userMarkFloat != userMarkInt) {
                std::cout <<userMarkString << "is not whole number.";
            } else {
                // adds the marks into the list
                listMarks.push_back(userMarkInt);
            }
        } catch (std::invalid_argument) {
            // The user did not enter an integer.
            std::cout << "\n";
            std::cout << "Please enter a valid number, try again.\n";
        }
    }

    std::cout << "\n";

    try {
        // calls the calcAverage funciton
        userAverage = calcAverage(listMarks);
        userAverage = round(userAverage);

        auto iter = listMarks.begin();
        auto iterEnd = (++listMarks.rbegin()).base();
        std::cout << "Here are the marks: [";
        while (iter != listMarks.end()) {
            if (iter == iterEnd) {
                number = *iter;
                std::cout << number << "]\n";
                break;
            } else {
                number = *iter;
                std::cout << number << ", ";
                iter++;
            }
        }
        // displays the average
        std::cout << "The average is: " << userAverage << ".\n";
    } catch (std::runtime_error& e) {
            // The user did not enter an integer.
            std::cout << "\n";
            std::cout << "Please enter a valid number, try again." << e.what();
        }
}
