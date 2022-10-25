#include <iostream>
using namespace std;

// This is the main function, the entry point of the program
int main()
{
    // These four arrays store the calorie counts of each item in each part of the menu sequentially
    // Because the last item (no item) in each menu section will have no impact on the calorie count, they can be set to 0.
    int burgers[4] = {461, 431, 420, 0};
    int sides[4] = {100, 57, 70, 0};
    int drinks[4] = {130, 160, 118, 0};
    int desserts[4] = {167, 266, 75, 0};

    // These integers store the item ordered from each part of the menu, according to the input
    // As for right now, the program has received no input, so they must not be set to any value yet
    int burgerChoice;
    int sideChoice;
    int drinkChoice;
    int dessertChoice;

    // This stores the total number of calories. Because the calorie count of each item will be added to find the total sum, it must start from 0
    int calories = 0;

    // Because the input will be received on four different lines, they can be split into 4 different statements
    // These four lines recieve the input for each item ordered
    cin >> burgerChoice;
    cin >> sideChoice;
    cin >> drinkChoice;
    cin >> dessertChoice;

    // The += operator increases whatever is on the left side by whatever is on the right side
    // These four lines are adding together the calorie count of each ordered item on the menu
    // The index is the actual choice minus one because array access starts counting from zero
    calories += burgers[burgerChoice - 1];
    calories += sides[sideChoice - 1];
    calories += drinks[drinkChoice - 1];
    calories += desserts[dessertChoice - 1];

    // Print the final output statement as specified by the problem's outline
    // ".\n" is printed afterwards to print the period (.) and a newline (\n)
    cout << "Your total Calorie count is " << calories << ".\n";

    return 0;
}
