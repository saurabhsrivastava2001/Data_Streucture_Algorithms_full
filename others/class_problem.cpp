#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;


struct Seat {
    char row;
    int seatNumber;

    void print() const {
        cout << row << seatNumber << " ";
    }
};

int partition(vector<Seat>& seats, int low, int high) {
    Seat pivot = seats[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (seats[j].row < pivot.row || 
            (seats[j].row == pivot.row && seats[j].seatNumber < pivot.seatNumber)) {
            i++;
            swap(seats[i], seats[j]);
        }
    }
    swap(seats[i + 1], seats[high]);
    return i + 1;
}

void quickSortIterative(vector<Seat>& seats, int low, int high) {
    stack<pair<int, int>> st;
    st.push({low, high});

    while (!st.empty()) {
        auto range = st.top();
        st.pop();
        int l = range.first, h = range.second;

        if (l < h) {
            int pi = partition(seats, l, h);
            if (pi - 1 > l) st.push({l, pi - 1});
            if (pi + 1 < h) st.push({pi + 1, h});
        }
    }
}

void displaySeats(const vector<Seat>& seats) {
    for (const auto& seat : seats) {
        seat.print();
    }
    cout << endl;
}

int main() {
    vector<Seat> availableSeats = {
        {'C', 5}, {'A', 2}, {'B', 3}, {'A', 1}, {'C', 2}, {'B', 1}, {'A', 3}
    };

    cout << "Before Sorting:\n";
    displaySeats(availableSeats);

    quickSortIterative(availableSeats, 0, availableSeats.size() - 1);

    cout << "After Sorting:\n";
    displaySeats(availableSeats);

    return 0;
}
