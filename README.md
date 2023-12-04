# CIS4930-ExtraCredit

## How to run code:


1. Clone this repository
2. Navigate to the local folder in a console window
3. To compile, run: `g++ -g src/*.cpp -o transactions.exe`
4. To run the program, run: `transactions.exe`

Note: tests that should cause errors have been commented out in main.cpp

## Suggestions for future versions of this assignment

I think there should be three templates for this assignment: c++, java, and python. The required methods should be empty for students to fill out, but by doing this the grading process could be more streamlined. I did notice that in Figure 1, the `get()` method should return an int; however, the instructions state that it should return null if the key doesn't exist. To do this in c++, you could have the function return an `Integer` instead of an int, or use pointers but doing so would mean changing what the function returned so I'm not sure that is intended.
