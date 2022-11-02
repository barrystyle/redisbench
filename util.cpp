#include <util.h>

template <typename T>
static T get_system_time()
{
    return std::chrono::duration_cast<T>(std::chrono::system_clock::now().time_since_epoch());
}

int64_t get_time_millis()
{
    return int64_t { get_system_time<std::chrono::milliseconds>().count() };
}

void hex_string(char str[], int length)
{
  char hex_characters[]={'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};

  int i;
  for (i=0;i<length;i++) {
      str[i]=hex_characters[rand()%16];
  }
  str[length]=0;
}
