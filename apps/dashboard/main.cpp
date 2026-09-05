#include <iostream>

#include "AircraftTelemetry.h"

int main()
{
    AircraftTelemetry telemetry{
        101,
        27.1767,
        78.0081,
        12000.0,
        450.0
    };

    std::cout << "This is Aviation Ground Station Dashboard\n\n";

    std::cout << "Aircraft ID : " << telemetry.aircraftId << '\n';
    std::cout << "Latitude    : " << telemetry.latitude << '\n';
    std::cout << "Longitude   : " << telemetry.longitude << '\n';
    std::cout << "Altitude    : " << telemetry.altitude << " m\n";
    std::cout << "Speed       : " << telemetry.speed << " km/h\n";

    return 0;
}