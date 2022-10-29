#include <dirent.h>
#include <stdio.h>
#include <unistd.h>

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

  DIR *dir;
  struct dirent *dp;
  char dir_path[] = "/Users/uchienuruunari";
  dir = opendir(dir_path);

  if (dir == NULL) {
    return 1;
  }

  dp = readdir(dir);
  while (dp != NULL) {
    printf("%s\n", dp->d_name);
    dp = readdir(dir);
  }

  if (dir != NULL) {
    closedir(dir);
  }

  return 0;
}
