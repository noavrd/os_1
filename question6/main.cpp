#include <iostream>
#include <csignal>
#include <unistd.h>

volatile sig_atomic_t signal_count = 0;

void signal_handler(int signal) {
    signal_count++;
    std::cout << "Received signal " << signal << ", handling signal #" << signal_count << std::endl;

    if (signal_count < 4) {
        pause(); // ממתין לקבלת סיגנל נוסף
    }
}

int main() {
    // מקשר את כל הסיגנלים ל-signal_handler
    signal(SIGUSR1, signal_handler);
    signal(SIGUSR2, signal_handler);
    signal(SIGINT, signal_handler);
    signal(SIGTERM, signal_handler);

    std::cout << "Waiting for signals... (send signals using 'kill -SIGNAL <pid>')" << std::endl;

    while (signal_count < 4) {
        pause(); // ממתין לקבלת סיגנל
    }

    // המשך התוכנית לאחר קבלת 4 סיגנלים
    for (int i = 0; i < 10; i++) {
        std::cout << "Continuing execution: " << i << std::endl;
        sleep(1);
    }

    return 0;
}