#include <stdio.h>
#include "power_calculator.h"

// Function to calculate power consumption
float calculate_power(float voltage, float current) {
    return voltage * current;
}

// Function to calculate energy usage in kWh
float calculate_energy(float power, float time) {
    return (power * time) / 1000;
}

// Function to log data to a file
void log_data(Appliance a, float power, float energy) {
    FILE *file = fopen("logs/power_log.txt", "a");
    if (file == NULL) {
        printf("Error opening file!\n");
        return;
    }
    fprintf(file, "Appliance: %s, Voltage: %.2fV, Current: %.2fA, Time: %.2fh, Power: %.2fW, Energy: %.2fkWh\n",
            a.name, a.voltage, a.current, a.usage_time, power, energy);
    fclose(file);
}
