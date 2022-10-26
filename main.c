#include <stdio.h>
#include <unistd.h>

#define PATH_SIZE 512

int main() {
    char path_name[PATH_SIZE];
    getcwd(path_name, PATH_SIZE);
    printf("current dir : %s\n", path_name);
    printf("Hello, World!\n");
    return 0;
}
