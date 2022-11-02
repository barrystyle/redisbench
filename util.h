#ifndef UTIL_H
#define UTIL_H

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <string.h>
#include <time.h>

#include <chrono>
#include <iostream>
#include <limits>

int64_t get_time_millis();
void hex_string(char str[], int length);

#endif // UTIL_H

