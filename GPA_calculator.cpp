#include <iostream>
using namespace std;

int main() {
    // Step 1: Greet the user
    cout << "Hi! Let's calculate your GPA.\n";

    // Step 2: Ask how many subjects they have
    int numSubjects;
    cout << "How many subjects do you have? ";
    cin >> numSubjects;

    // Step 3: Simple validation for number of subjects
    if (numSubjects <= 0) {
        cout << "Oops! Number of subjects must be positive.\n";
        return 0; // End the program if input is invalid
    }

    // Step 4: Initialize total points variable
    double totalPoints = 0; // We will add GPA points here
    char grade; // To store letter grade for each subject

    // Step 5: Loop through each subject
    for (int i = 1; i <= numSubjects; i++) {
        cout << "Enter your grade for subject " << i << " (A, B, C, D, F): ";
        cin >> grade;

        // Step 6: Convert letter grade to GPA points
        double points;
        switch (grade) {
            case 'A': case 'a': points = 4.0; break;
            case 'B': case 'b': points = 3.0; break;
            case 'C': case 'c': points = 2.0; break;
            case 'D': case 'd': points = 1.0; break;
            case 'F': case 'f': points = 0.0; break;
            default: // Handle invalid input
                cout << "Invalid grade! Counting as 0 points.\n";
                points = 0.0;
        }

        // Step 7: Add this subject's points to total
        totalPoints += points;
    }

    // Step 8: Calculate GPA
    double gpa = totalPoints / numSubjects;

    // Step 9: Display GPA
    cout << "\nYour GPA is: " << gpa << " / 4.0\n";
    cout << "Good job! Keep improving! \n";

    return 0; // End of program
}
