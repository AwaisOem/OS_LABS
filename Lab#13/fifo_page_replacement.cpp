#include <iostream>
#include <queue>
#include <unordered_set>

using namespace std;

class FirstInFirstOut {
private:
    int PageFault;
    int TotalFrame;
    queue<int> frames;
    unordered_set<int> inMemory;

public:
    FirstInFirstOut(void);
    void Welcome(void);
    void TakeFrame(void);
    void ShowFault(void);
    void FindFault(void);
    void EnterReferenceString(void);
    void ShowReferenceString(void);
    virtual ~FirstInFirstOut(void);
};

FirstInFirstOut::FirstInFirstOut(void) {
    PageFault = 0;
    TotalFrame = 0;
}

void FirstInFirstOut::FindFault(void) {
    int page;
    while (!frames.empty()) {
        page = frames.front();
        frames.pop();
        inMemory.erase(page);
    }

    cout << "Total page faults are: " << PageFault << endl;
}

void FirstInFirstOut::TakeFrame(void) {
    cout << "How many free frames do you want to take for the process: ";
    cin >> TotalFrame;
    cout << endl;
}

void FirstInFirstOut::ShowFault(void) {
    cout << "Total page faults are: " << PageFault << endl;
}

void FirstInFirstOut::EnterReferenceString(void) {
    int length;
    cout << "Please specify the length of the reference string: ";
    cin >> length;
    cout << endl;

    int page;
    cout << "Please enter the reference string: ";
    for (int i = 0; i < length; ++i) {
        cin >> page;
        frames.push(page);
    }
}

void FirstInFirstOut::ShowReferenceString(void) {
    cout << "Reference String: ";
    queue<int> temp = frames;
    while (!temp.empty()) {
        cout << temp.front() << " ";
        temp.pop();
    }
    cout << endl;
}

FirstInFirstOut::~FirstInFirstOut(void) {}

int main() {
    FirstInFirstOut fifo;
    fifo.EnterReferenceString();
    fifo.ShowReferenceString();
    fifo.TakeFrame();
    fifo.FindFault();
    fifo.ShowFault();

    return 0;
}
