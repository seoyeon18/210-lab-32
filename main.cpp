#include <iostream>
#include <deque>
#include <cstdlib>
#include <ctime>
#include "Car.h"

using namespace std;
const int INITIAL_QUEUE_SIZE = 2;
const int NUM_LANES = 4;
const int TOTAL_TIME = 20;
const int PAY_PROB = 46;
const int JOIN_PROB = 39;


void printSingleCar(Car car)
{
    cout << "[" << car.getYear()<< " "
         << car.getMake()<< " "
         << car.getTransponder()<< ")]";
}

void printQueue(deque<Car> lane)
{
    if (lane.empty())
    {
        cout << "   Empty\n";
        return;
    }

    for (Car car : lane)
    {
        car.print();
    }
}

int main()
{
    srand(time(0));

    deque<Car> plaza[NUM_LANES];

    // Milestone 1: create deque and populate with two Car objects
    for (int i = 0; i < NUM_LANES; i++)
    {
        for (int j = 0; j < INITIAL_QUEUE_SIZE; j++)
        {
            plaza[i].push_back(Car());
        }
    }

    cout << "Initial queue:\n";
    for (int i = 0; i < NUM_LANES; i++)
    {
        cout << "Lane " << i + 1 << ":\n";
        printQueue(plaza[i]);
    }
    cout << endl;

    // int timePeriod = 0;
    // Milestone 2: loop until deque is empty
    // while (!lane.empty()) {
    //     timePeriod++;

    //     int chance = rand() % 100;  // 0~99

    //     cout << "Time: " << timePeriod << " Operation: ";

    //     if (chance < 55) {
    //         // 55% probability: front car pays and leaves
    //        Car paidCar = lane.front();
    //         lane.pop_front();

    //         cout << "Car paid: ";
    //         printSingleCar(paidCar);
    //         cout << endl;
    //     } else {
    //         // 45% probability: another car joins
    //        Car newCar;
    //         lane.push_back(newCar);

    //         cout << "Joined lane: ";
    //         printSingleCar(newCar);
    //         cout << endl;
    //     }

    // cout << "Queue:\n";
    //     if (lane.empty()) {
    //         cout << "    Empty\n";
    //     } else {
    //         printQueue(lane);
    //     }
    //     cout << endl;
    // }

    // cout << "This simulation ran " << timePeriod
    //      << " cycles until the queue was empty.\n";

    for (int timePeriod = 1; timePeriod <= TOTAL_TIME; timePeriod++)
    {
        cout << "Time: " << timePeriod << endl;

        for (int i = 0; i < NUM_LANES; i++)
        {
            if (plaza[i].empty())
            {
                int emptyChance = rand() % 2;

                if (emptyChance == 0)
                {
                    Car newCar;
                    plaza[i].push_back(newCar);
                    cout << "Lane: " << i + 1 << " Joined: ";
                    printSingleCar(newCar);
                    cout << endl;
                }
            }
            else
            {
                int chance = rand() % 100;

                if (chance < PAY_PROB)
                {
                    Car paidCar = plaza[i].front();
                    plaza[i].pop_front();
                    cout << "Lane: " << i + 1 << " Paid: ";
                    printSingleCar(paidCar);
                    cout << endl;
                }
                else if (chance < PAY_PROB + JOIN_PROB)
                {
                    Car newCar;
                    plaza[i].push_back(newCar);
                    cout << "Lane: " << i + 1 << " Joined: ";
                    printSingleCar(newCar);
                    cout << endl;
                }
                else
                {
                    Car switchedCar = plaza[i].back();
                    plaza[i].pop_back();

                    int targetLane;
                    do
                    {
                        targetLane = rand() % NUM_LANES;
                    } while (targetLane == i);

                    plaza[targetLane].push_back(switchedCar);

                    cout << "Lane: " << i + 1 << " Switched: ";
                    printSingleCar(switchedCar);
                    cout << endl;
                }
            }
        }

        for (int i = 0; i < NUM_LANES; i++)
        {
            cout << "Lane " << i + 1 << " Queue:\n";
            printQueue(plaza[i]);
        }

        cout << endl;
    }

    cout << "This simulation ran " << TOTAL_TIME << " cycles.\n"; 

    return 0;
}