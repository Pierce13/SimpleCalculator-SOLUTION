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

// Function to test the SimpleCalculator program
void testSimpleCalculator() {
    int correctTests = 0;

    // Test calculateCircleArea()
    {
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


    // Test addFractions()
    {
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

    // Test solveQuadraticFormula()
    {
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

    // Print total tests passed
    cout << "Total tests passed: " << correctTests << " out of 3" << endl;
}

#ifdef TESTING
int main() {
    testSimpleCalculator();
    return 0;
}
#endif
