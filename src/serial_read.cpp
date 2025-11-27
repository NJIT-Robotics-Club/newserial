#include "serial_read.h"

static FILE *serial_port = std::fopen("/dev/3", "r");

void readit()
{
    if (serial_port == nullptr)
    {
        // Handle error opening the serial port
        return;
    }

    std::vector<char> buffer(1024);
    size_t bytesRead = std::fread(buffer.data(), 1, buffer.size(), serial_port);

    if (bytesRead > 0)
    {
        // Process the data read from the serial port
    }
}