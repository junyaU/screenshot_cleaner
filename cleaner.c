//
// Created by 内園潤也 on 2022/10/29.
//

#include "cleaner.h"

#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const char SCREEN_SHOT_PATH_NAME_JA[] = "スクリーンショット";
const char SCREEN_CAPTURE_PATH_NAME_JA[] = "画面収録";

void search_target_file(char path_name[]);

void clean(int signal) {
  if (signal != SIGALRM) {
    return;
  }

  char home_path[128];
  strncpy(home_path, getenv("HOME"), sizeof(home_path));

  search_target_file(home_path);
}

void search_target_file(char path_name[]) {
  DIR *dir;
  struct dirent *dp;
  dir = opendir(path_name);

  if (dir == NULL) {
    return;
  }

  dp = readdir(dir);
  while (dp != NULL) {
    u_int64_t path_len = strlen(path_name) + dp->d_namlen + 2;
    char target_path[path_len];
    snprintf(target_path, path_len, "%s%s%s", path_name, "/", dp->d_name);

    if (dp->d_type == DT_DIR && dp->d_name[0] != '.') {
      search_target_file(target_path);
    }

    if (strstr(dp->d_name, SCREEN_CAPTURE_PATH_NAME_JA) != NULL ||
        strstr(dp->d_name, SCREEN_SHOT_PATH_NAME_JA) != NULL) {
      int result = remove(target_path);
      if (result != 0) {
        exit(1);
      }
    }

    dp = readdir(dir);
  }

  if (dir != NULL) {
    closedir(dir);
  }
}
