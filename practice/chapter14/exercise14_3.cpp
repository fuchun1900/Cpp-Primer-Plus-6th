#include "/home/DEV/C++_Project/Cpp-Primer-Plus-6th/bookcodes/chapter14/workermi.h"
#include "QueueTp.h"
#include <iostream>

const int MAX = 5;
QueueTp<Worker *> queue(MAX);
int main() {
    Worker *worker;
    int choice;

    while (true) {
        std::cout << "Enter the worker type:\n"
                  << "0: Waiter\n"
                  << "1: Singer\n"
                  << "2: Quit\n";
        std::cin >> choice;
        if (choice == 2) {
            break; // Exit the loop
        }

        if (choice < 0 || choice > 1) {
            std::cout << "Invalid choice. Try again.\n";
            continue; // Skip to the next iteration
        }

        if (queue.isFull()) {
            std::cout << "Queue is full. Cannot add more workers.\n";
            continue; // Skip to the next iteration
        }

        if (choice == 0) {
            worker = new Waiter();
        } else {
            worker = new Singer();
        }
        while (std::cin.get() != '\n')
            continue;
        worker->Set(); // Set worker details
        queue.enqueue(worker); // Add worker to the queue
    }

    std::cout << "Workers in the queue:\n";
    while (!queue.isEmpty()) {
        Worker *w;
        queue.dequeue(w);
        w->Show(); // Display worker details
        delete w; // Clean up memory
    }

    return 0;
}