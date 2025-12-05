// #include "serial_write.h"
// #include "Nanopb/pb_decode.h"
// uint8_t buffer[255];
// uint8_t bytes_read = 0;
// uint8_t curr;
// // DataMessage serial_data = DataMessage_init_zero;
// DataMessage serial_data_LOCAL = DataMessage_init_zero;

// void readit()
// {

//     bytes_read = 0;

//     if (serial_port2.get_read_avail() == 0)
//     {
//         printf("WAITING FOR DATA\n");
//         return;

//     } // fgets loop until null char
//     while (fread(&curr, 1, 1, serial_port) == 1)
//     {
//         if (curr == '\0')
//         {
//             if (serial_port2.get_read_avail() > 5)
//             {
//                 printf("HOLD ON THERES MORE\n");
//                 pros::delay(1);
//                 readit();
//                 return;
//             }
//             else
//             {
//                 break;
//             }
//         }
//         buffer[bytes_read++] = curr;
//         if (bytes_read >= 255)
//         {
//             printf("FAILED READ TOO MUCH\n");
//             return;
//         }
//         // Process the received data (for demonstration, we print it)
//     }
//     // printf("Received: %s", buffer);
//     // printf("startfr1\n");
//     cobs::decode(buffer, bytes_read);
//     // for (size_t i = 0; i < bytes_read; ++i)
//     // {
//     //     printf("%02X", buffer[i]);
//     // }
//     // printf("\n");
//     // printf("endfr1\n");
//     auto crc = CRC::CalculateBits(buffer + 1, bytes_read - 2, CRC::CRC_8());
//     // printf("\n%02X", crc);

//     if (crc != buffer[bytes_read - 1])
//     {
//         printf("CHECKSUM FAILED\n");
//         return;
//     }

//     pb_istream_t stream = pb_istream_from_buffer(buffer + 1, bytes_read - 1);
//     if (!pb_decode_nullterminated(&stream, DataMessage_fields, &serial_data_LOCAL))
//     {
//         printf("DECODE FAILED\n");
//         printf("Error: %s\n", stream.errmsg);

//         return;
//     }
//     serial_data = serial_data_LOCAL;
//     printf("SUCCESS\n");
// }