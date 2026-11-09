// Smart Temperature Monitor - C++
// Built by Ali Mursal Shah
// BS Electronics, COMSATS University Islamabad
// Simulates a temperature sensor (like DHT11 / LM35)
// and controls a fan + alarm, like a real embedded system.
//
// How to run:
//   g++ -std=c++17 -o monitor main.cpp
//   ./monitor
//
// Choose:
//   1 = Auto simulation (10 live readings)
//   2 = Manual test (enter your own temperature)

#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <thread>
#include <chrono>

using namespace std;

// --- Sensor simulation ---
// In a real Arduino project, this would read from a sensor pin.
// Here we simulate it so the logic can be tested on any computer.
double readSensor() {
    // Simulate a room warming up: 22C to 42C
    return 22.0 + (rand() % 210) / 10.0;
}

string fanStatus(double temp) {
    if (temp >= 30.0) return "FAN: ON  (cooling)";
    if (temp >= 25.0) return "FAN: ON  (low speed)";
    return "FAN: OFF";
}

string alarmStatus(double temp) {
    if (temp > 35.0) return "ALARM: ON  - TOO HOT!";
    return "ALARM: OFF";
}

string level(double temp) {
    if (temp > 35.0) return "DANGER";
    if (temp >= 30.0) return "HOT";
    if (temp >= 25.0) return "WARM";
    return "NORMAL";
}

void showReading(int n, double temp) {
    cout << "Reading " << n << "  |  Temp: " << temp << " C"
         << "  |  " << level(temp)
         << "  |  " << fanStatus(temp)
         << "  |  " << alarmStatus(temp) << endl;
}

void autoMode() {
    cout << "\n--- AUTO SIMULATION: 10 live readings ---\n" << endl;
    srand(time(0));
    for (int i = 1; i <= 10; i++) {
        double temp = readSensor();
        showReading(i, temp);
        this_thread::sleep_for(chrono::milliseconds(600));
    }
    cout << "\nSimulation finished. Fan and alarm worked as expected.\n";
}

void manualMode() {
    cout << "\n--- MANUAL TEST ---\n";
    cout << "Enter temperature in C (or -1 to exit): ";
    double temp;
    while (cin >> temp && temp != -1) {
        showReading(1, temp);
        cout << "Enter temperature in C (or -1 to exit): ";
    }
    cout << "Manual test finished.\n";
}

int main() {
    cout << "======================================" << endl;
    cout << "  SMART TEMPERATURE MONITOR - C++" << endl;
    cout << "  BS Electronics | COMSATS Islamabad" << endl;
    cout << "======================================" << endl;
    cout << "Sensor: DHT11 / LM35 (simulated)" << endl;
    cout << "Rules: <25C Normal | 25-30C Fan Low" << endl;
    cout << "       30-35C Fan ON | >35C ALARM" << endl;
    cout << "--------------------------------------" << endl;
    cout << "1. Auto simulation" << endl;
    cout << "2. Manual test" << endl;
    cout << "Choose 1 or 2: ";

    int choice;
    if (!(cin >> choice)) return 0;

    if (choice == 1) autoMode();
    else if (choice == 2) manualMode();
    else cout << "Invalid choice." << endl;

    return 0;
}
