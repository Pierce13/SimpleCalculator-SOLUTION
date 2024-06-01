#include "SimpleCalculator.h"
#include <iostream>
#include <iomanip>
#include <sstream>
#include <cmath>
#include <cstring>

using namespace std;

// Helper functions for testing
template <typename T>
bool checkTest(int testNum, int& correct, T whatItShouldBe, T whatItIs) {
    if (whatItShouldBe == whatItIs) {
        correct++;
        cout << "***TEST " << testNum << " PASSED***" << endl;
        return true;
    } else {
        cout << "***TEST " << testNum << " FAILED*** " << endl;
        cout << "   Output was " << whatItIs << endl;
        cout << "   Output should have been " << whatItShouldBe << endl;
        return false;
    }
}

// Function to test calculateCircleArea()
void testCalculateCircleArea(int& correctTests) {
    string circleAreaInput = "5\n";
    stringstream inputBuffer(circleAreaInput);
    streambuf* oldCin = cin.rdbuf(inputBuffer.rdbuf());

    stringstream outputBuffer;
    streambuf* oldCout = cout.rdbuf(outputBuffer.rdbuf());

    double areaResult = calculateCircleArea();

    cin.rdbuf(oldCin);
    cout.rdbuf(oldCout);

    // Extract the actual result from the output buffer
    stringstream ss;
    ss << fixed << setprecision(10) << areaResult;
    string capturedOutput = ss.str();
    string expectedOutput = "78.5398163375";
    checkTest(1, correctTests, expectedOutput, capturedOutput);
}

// Function to test addFractions()
void testAddFractions(int& correctTests) {
    string addFractionsInput = "1/2 1/3\n";
    stringstream inputBuffer(addFractionsInput);
    streambuf* oldCin = cin.rdbuf(inputBuffer.rdbuf());

    stringstream outputBuffer;
    streambuf* oldCout = cout.rdbuf(outputBuffer.rdbuf());

    string capturedOutput2 = addFractions();

    cin.rdbuf(oldCin);
    cout.rdbuf(oldCout);

    string expectedOutput2 = "5/6";
    checkTest(2, correctTests, expectedOutput2, capturedOutput2);
}

// Function to test solveQuadraticFormula()
void testSolveQuadraticFormula(int& correctTests) {
    string solveQuadraticInput = "1 2 1\n";
    stringstream inputBuffer(solveQuadraticInput);
    streambuf* oldCin = cin.rdbuf(inputBuffer.rdbuf());

    stringstream outputBuffer;
    streambuf* oldCout = cout.rdbuf(outputBuffer.rdbuf());

    string capturedOutput3 = solveQuadraticFormula();

    cin.rdbuf(oldCin);
    cout.rdbuf(oldCout);

    string expectedOutput3 = "-1.000000, -1.000000";
    checkTest(3, correctTests, expectedOutput3, capturedOutput3);
}

// Function to run all tests
void runAllTests() {
    int correctTests = 0;
    testCalculateCircleArea(correctTests);
    testAddFractions(correctTests);
    testSolveQuadraticFormula(correctTests);
    cout << "Total tests passed: " << correctTests << " out of 3" << endl;
}

// Main function to run specific tests
int main(int argc, char* argv[]) {
    if (argc == 1) {
        runAllTests();
    } else if (argc == 2) {
        int correctTests = 0;
        int testNumber = atoi(argv[1]);

        switch (testNumber) {
            case 1:
                testCalculateCircleArea(correctTests);
                break;
            case 2:
                testAddFractions(correctTests);
                break;
            case 3:
                testSolveQuadraticFormula(correctTests);
                break;
            default:
                cerr << "Invalid test number. Please enter 1, 2, or 3." << endl;
                return 1;
        }

        cout << "Total tests passed: " << correctTests << " out of 1" << endl;
    } else {
        cerr << "Usage: " << argv[0] << " [testNumber]" << endl;
        return 1;
    }

    return 0;
}
