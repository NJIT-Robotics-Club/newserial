#include "serial.h"

FILE *serial_port = fopen("/dev/3", "r");
pros::Serial serial_port2(3, 115200U);
