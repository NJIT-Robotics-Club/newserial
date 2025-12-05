#include "serial.h"

FILE *serial_port = fopen("/dev/4", "r");
pros::Serial serial_port2(4, 115200U);
