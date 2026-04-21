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

    for (int i = 0; i < INITIAL_QUEUE_SIZE; i++) {
        lane.push_back(car());
    }

    return 0;
}