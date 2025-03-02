#ifndef POWER_CALCULATOR_H
#define POWER_CALCULATOR_H

typedef struct {
    char name[50];
    float voltage;
    float current;
    float usage_time;
} Appliance;

float calculate_power(float voltage, float current);
float calculate_energy(float power, float time);
void log_data(Appliance a, float power, float energy);

#endif
