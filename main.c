#include <dirent.h>
#include <stdio.h>
#include <unistd.h>

#include "cleaner.h"

#define PATH_SIZE 512

int main() {
  //    char path_name[PATH_SIZE];
  //    getcwd(path_name, PATH_SIZE);
  //    printf("current dir : %s\n", path_name);
  //    printf("Hello, World!\n");
  //
  //    char filename[] = "/Users/uchienuruunari/Dockerfile";
  //    int result = remove(filename);
  //
  //    printf("%s", result);

  printf("Running...\n");

  clean();

  printf("All done\n");

  return 0;
}
