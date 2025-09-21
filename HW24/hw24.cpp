#include <iostream>
#include <queue> // priority_queue
#include <random>
#include <ctime>
#include <string>

using namespace std;

struct Passenger {
    int arrivalTime;
};

struct Bus {
    int arrivalTime;
    int freeSeats;
};

struct PrintJob {
    int priority;
    string user;
    int time;
    bool operator<(const PrintJob& other) const {
        return priority < other.priority;
    }
};

int main() {
    // Task 1
    int avgPassengerArrivalTime, avgBusArrivalTime, maxPeople, stopType;
    cout << "Enter average passenger arrival time: ";
    cin >> avgPassengerArrivalTime;
    cout << "Enter average bus arrival time: ";
    cin >> avgBusArrivalTime;
    cout << "Enter stop type (0 for non-terminal, 1 for terminal): ";
    cin >> stopType;
    cout << "Enter maximum number of people at the stop: ";
    cin >> maxPeople;


    queue<Passenger> passengers;
    queue<Bus> buses;
    int currentTime = 0;
    int totalWaitTime = 0;
    int totalPassengers = 0;

    while (currentTime < 1000) { 
        if (rand() % avgPassengerArrivalTime == 0) {
            passengers.push({ currentTime });
        }
        if (rand() % avgBusArrivalTime == 0) {
            buses.push({ currentTime, rand() % 50 + 1 }); 
        }
        if (!buses.empty() && !passengers.empty()) {
            Bus bus = buses.front();
            buses.pop();
            while (!passengers.empty() && bus.freeSeats > 0) {
                Passenger passenger = passengers.front();
                passengers.pop();
                totalWaitTime += currentTime - passenger.arrivalTime;
                totalPassengers++;
                bus.freeSeats--;
            }
        }
        currentTime++;
    }

    cout << "Average wait time: " << (totalPassengers ? totalWaitTime / totalPassengers : 0) << endl;

    // Task 2:
    priority_queue<PrintJob> printQueue;
    queue<PrintJob> printStats;

    srand(time(0));

    int numJobs;
    cout << "Enter the number of print jobs: ";
    cin >> numJobs;

    for (int i = 0; i < numJobs; ++i) {
        int priority, time;
        string user;
        cout << "Enter priority, user, and time for job " << i + 1 << ": ";
        cin >> priority >> user >> time;
        PrintJob job = { priority, user, time };
        printQueue.push(job);
    }

    while (!printQueue.empty()) {
        PrintJob job = printQueue.top();
        printQueue.pop();
        printStats.push(job);
    }

    while (!printStats.empty()) {
        PrintJob job = printStats.front();
        printStats.pop();
        cout << "User: " << job.user << ", Time: " << job.time << endl;
    }
}
