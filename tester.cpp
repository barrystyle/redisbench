#include <cstdlib>
#include <iostream>

#include <redis-cpp/stream.h>
#include <redis-cpp/execute.h>

#include <util.h>

int main()
{
    auto stream = rediscpp::make_stream("localhost", "6379");

    char key_chr[64];
    char val_chr[64];

    std::string key;
    std::string value;

    int calls = 0;
    int64_t time_start = get_time_millis();

    while (true) {

        calls++;

        hex_string(key_chr, 16);
        hex_string(val_chr, 16);

        key = std::string(key_chr);
        value = std::string(val_chr);

        auto response = rediscpp::execute(*stream, "set", key, value);
        response = rediscpp::execute(*stream, "get", key);

        if (get_time_millis() - time_start > 5000) {
            printf("%d calls\n", calls/5);
            return EXIT_SUCCESS;
        }
    }

    return EXIT_SUCCESS;
}
