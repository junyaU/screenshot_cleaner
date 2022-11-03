#include "cleaner.h"
#include "scheduler.h"

#define THREE_DAYS_OF_SECONDS 259200

int main() {
  make_schedule(THREE_DAYS_OF_SECONDS, clean);

  exec();

  return 0;
}
