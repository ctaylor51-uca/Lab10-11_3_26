#include <iostream>
#include <string>

using namespace std;

// Constant global capacity as required by Part One
const int CAPACITY = 6;

// Function Prototypes
void displayScores(const int arr[], int size);
double calculateAverage(const int arr[], int size);
int findMaxScore(const int arr[], int size);
int findMinScore(const int arr[], int size);
bool updateScore(int arr[], int size, int slotIndex, int newScore);
int countAboveThreshold(const int arr[], int size, int threshold);

int main() {
    // ==========================================
    // PART ONE: Array Setup
    // ==========================================
    cout << "=== Part 1: Arcade Leaderboard Setup ===" << endl;
    int scores[CAPACITY];

    for (int i = 0; i < CAPACITY; i++) {
        cout << "Enter arcade score for rank #" << (i + 1) << ": ";
        cin >> scores[i];
    }
    cout << endl;

    // ==========================================
    // PART TWO: Display and Average Tests
    // ==========================================
    cout << "=== Part 2: Testing Display and Average ===" << endl;
    displayScores(scores, CAPACITY);

    double avg = calculateAverage(scores, CAPACITY);
    cout << "The average score is: " << avg << endl << endl;

    // ==========================================
    // PART THREE: Min and Max Tests
    // ==========================================
    cout << "=== Part 3: Testing Min and Max ===" << endl;
    int maxScore = findMaxScore(scores, CAPACITY);
    int minScore = findMinScore(scores, CAPACITY);
    cout << "Highest Score: " << maxScore << endl;
    cout << "Lowest Score:  " << minScore << endl << endl;

    // ==========================================
    // PART FOUR: Update Score Tests
    // ==========================================
    cout << "=== Part 4: Testing Update Score ===" << endl;
    int targetSlot, newScore;

    // Test a valid update
    cout << "Enter a zero-based index to update (0 to " << (CAPACITY - 1) << "): ";
    cin >> targetSlot;
    cout << "Enter the new score: ";
    cin >> newScore;

    if (updateScore(scores, CAPACITY, targetSlot, newScore)) {
        cout << "Success! Score updated." << endl;
        cout << "Updated Leaderboard:" << endl;
        displayScores(scores, CAPACITY);
    }
    else {
        cout << "Error: Update failed due to invalid index." << endl;
    }

    // Explicit test for an out-of-bounds invalid index
    cout << "\nTesting out-of-bounds safety check (Index 10)..." << endl;
    if (!updateScore(scores, CAPACITY, 10, 9999)) {
        cout << "Pass: Function safely rejected out-of-bounds index 10." << endl;
    }
    cout << endl;

    // ==========================================
    // PART FIVE: Count Above Threshold Tests
    // ==========================================
    cout << "=== Part 5: Testing Count Above Threshold ===" << endl;
    int threshold;
    cout << "Enter a score threshold to count above: ";
    cin >> threshold;

    int count = countAboveThreshold(scores, CAPACITY, threshold);
    cout << "Number of scores strictly greater than " << threshold << ": " << count << endl << endl;

    cout << "=== End of Leaderboard Test Suite ===" << endl;
    return 0;
}

// ============================================================================
// FUNCTION IMPLEMENTATIONS & DOCUMENTATION
// ============================================================================

/**
 * Purpose: Iterates through the score array and displays each item neatly.
 * Parameters:
 *   - const int arr[]: The immutable array of scores.
 *   - int size: The logical number of items in the array.
 * Return: void
 */
void displayScores(const int arr[], int size) {
    cout << "---------------------------" << endl;
    cout << "    ARCADE LEADERBOARD     " << endl;
    cout << "---------------------------" << endl;
    for (int i = 0; i < size; i++) {
        cout << "Slot [" << i << "]: " << arr[i] << " points" << endl;
    }
    cout << "---------------------------" << endl;
}

/**
 * Purpose: Accumulates the elements of the array and computes the mean value.
 * Note: Casts the total to a double before dividing to prevent integer truncation.
 * Parameters:
 *   - const int arr[]: The array of scores to process.
 *   - int size: Total elements to calculate.
 * Return: The average score as a double precision float.
 */
double calculateAverage(const int arr[], int size) {
    int total = 0;
    for (int i = 0; i < size; i++) {
        total += arr[i];
    }
    return static_cast<double>(total) / size;
}

/**
 * Purpose: Scans the array to track down and identify the maximum value.
 * Parameters:
 *   - const int arr[]: The leaderboard scores.
 *   - int size: Size of the array.
 * Return: The highest integer found in the array.
 */
int findMaxScore(const int arr[], int size) {
    int highest = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] > highest) {
            highest = arr[i];
        }
    }
    return highest;
}

/**
 * Purpose: Scans the array to track down and identify the minimum value.
 * Parameters:
 *   - const int arr[]: The leaderboard scores.
 *   - int size: Size of the array.
 * Return: The lowest integer found in the array.
 */
int findMinScore(const int arr[], int size) {
    int lowest = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] < lowest) {
            lowest = arr[i];
        }
    }
    return lowest;
}

/**
 * Purpose: Overwrites a score in a precise slot index after safety validation.
 * Question Answer: The array parameter cannot be modified with 'const' here
 *                  because the explicit purpose of this function is to change
 *                  and mutate the underlying data stored inside the array elements.
 * Parameters:
 *   - int arr[]: The mutable array being updated (no const prefix).
 *   - int size: Bounds indicator for safe modification.
 *   - int slotIndex: The target location requested to change.
 *   - int newScore: The payload variable to save at the index.
 * Return: True if updating an in-bounds element; false if out-of-bounds.
 */
bool updateScore(int arr[], int size, int slotIndex, int newScore) {
    if (slotIndex < 0 || slotIndex >= size) {
        return false;
    }
    arr[slotIndex] = newScore;
    return true;
}

/**
 * Purpose: Tallies up how many scores clear a targeted point milestone.
 * Parameters:
 *   - const int arr[]: The immutable array of values to evaluate.
 *   - int size: Amount of elements to read.
 *   - int threshold: The target score benchmark to test against.
 * Return: An integer count of items greater than the threshold milestone.
 */
int countAboveThreshold(const int arr[], int size, int threshold) {
    int counter = 0;
    for (int i = 0; i < size; i++) {
        if (arr[i] > threshold) {
            counter++;
        }
    }
    return counter;
}