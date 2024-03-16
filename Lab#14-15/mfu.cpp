#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>

using namespace std;

// MFU (Most Frequently Used) Page Replacement Algorithm
int MFU(const vector<int>& referenceString, int numFrames) {
    unordered_map<int, int> pageFrequency;
    unordered_map<int, int> lastUsedIndex;
    vector<int> frames;
    int pageFaults = 0;

    for (int i = 0; i < referenceString.size(); ++i) {
        int currentPage = referenceString[i];

        if (find(frames.begin(), frames.end(), currentPage) == frames.end()) {
            ++pageFaults;

            if (frames.size() < numFrames) {
                frames.push_back(currentPage);
            } else {
                int maxFrequency = 0;
                int replaceIndex = -1;

                for (int j = 0; j < frames.size(); ++j) {
                    if (pageFrequency[frames[j]] > maxFrequency ||
                        (pageFrequency[frames[j]] == maxFrequency &&
                         lastUsedIndex[frames[j]] < lastUsedIndex[frames[replaceIndex]])) {
                        maxFrequency = pageFrequency[frames[j]];
                        replaceIndex = j;
                    }
                }

                frames[replaceIndex] = currentPage;
            }
        }

        ++pageFrequency[currentPage];
        lastUsedIndex[currentPage] = i;
    }

    return pageFaults;
}

int main() {
    // Example usage
    vector<int> referenceString = {1, 2, 3, 4, 5, 1, 2, 1, 2, 3, 4, 5};
    int numFrames = 3;

    cout << "MFU Page Faults: " << MFU(referenceString, numFrames) << endl;

    return 0;
}
