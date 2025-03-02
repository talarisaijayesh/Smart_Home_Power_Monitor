#include <stdio.h>
#include <stdlib.h>
#include "power_calculator.h"

int main() {
    int num;
    printf("Enter the number of appliances: ");
    scanf("%d", &num);

    Appliance appliances[num];

    for (int i = 0; i < num; i++) {
        printf("\nEnter details for appliance %d:\n", i + 1);
        printf("Name: ");
        scanf("%s", appliances[i].name);
        printf("Voltage (V): ");
        scanf("%f", &appliances[i].voltage);
        printf("Current (A): ");
        scanf("%f", &appliances[i].current);
        printf("Usage Time (hours): ");
        scanf("%f", &appliances[i].usage_time);
    }

    printf("\nPower Consumption Report:\n");
    printf("--------------------------------------------------------\n");
    printf("%-15s %-10s %-10s %-10s %-10s %-10s\n", "Appliance", "Voltage", "Current", "Time", "Power", "Energy");
    printf("--------------------------------------------------------\n");

    for (int i = 0; i < num; i++) {
        float power = calculate_power(appliances[i].voltage, appliances[i].current);
        float energy = calculate_energy(power, appliances[i].usage_time);

        printf("%-15s %-10.2f %-10.2f %-10.2f %-10.2f %-10.2f\n",
               appliances[i].name, appliances[i].voltage, appliances[i].current, appliances[i].usage_time, power, energy);
        log_data(appliances[i], power, energy);
    }
    printf("\nData logged successfully in logs/power_log.txt!\n");

    return 0;
}
