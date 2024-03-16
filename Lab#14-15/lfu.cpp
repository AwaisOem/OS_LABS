#include <climits>
#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>

using namespace std;

// LFU (Least Frequently Used) Page Replacement Algorithm
int LFU(const vector<int>& referenceString, int numFrames) {
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
                int minFrequency = INT_MAX;
                int replaceIndex = -1;

                for (int j = 0; j < frames.size(); ++j) {
                    if (pageFrequency[frames[j]] < minFrequency ||
                        (pageFrequency[frames[j]] == minFrequency &&
                         lastUsedIndex[frames[j]] < lastUsedIndex[frames[replaceIndex]])) {
                        minFrequency = pageFrequency[frames[j]];
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

    cout << "LFU Page Faults: " << LFU(referenceString, numFrames) << endl;

    return 0;
}
