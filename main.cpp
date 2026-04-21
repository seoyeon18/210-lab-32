#include <iostream>
#include <deque>
#include <cstdlib>
#include <ctime>
#include "car.h"

using namespace std;
const int INITIAL_QUEUE_SIZE = 2;

int main() {
    srand(time(0));

    deque<car> lane;

    // Milestone 1: create deque and populate with two Car objects
    for (int i = 0; i < INITIAL_QUEUE_SIZE; i++) {
        lane.push_back(car());
    }

    cout << "Initial queue:\n";
    printQueue(lane);
    cout << endl;

    
    int timePeriod = 0;
    // Milestone 2: loop until deque is empty
    while (!lane.empty()) {
        timePeriod++;

        int chance = rand() % 100;  // 0~99

        cout << "Time: " << timePeriod << " Operation: ";

        if (chance < 55) {
            // 55% probability: front car pays and leaves
           Car paidCar = lane.front();
            lane.pop_front();

            cout << "Car paid: ";
            printSingleCar(paidCar);
            cout << endl;
        } else {
            // 45% probability: another car joins
           Car newCar;
            lane.push_back(newCar);

            cout << "Joined lane: ";
            printSingleCar(newCar);
            cout << endl;
        }

    cout << "Queue:\n";
        if (lane.empty()) {
            cout << "    Empty\n";
        } else {
            printQueue(lane);
        }
        cout << endl;
    }

    cout << "This simulation ran " << timePeriod
         << " cycles until the queue was empty.\n";


    return 0;
}