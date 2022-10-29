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

void searchTargetFile(char path_name[]);

void clean() {
  char home_path[128];
  strncpy(home_path, getenv("HOME"), sizeof(home_path));

  searchTargetFile(home_path);
}

void searchTargetFile(char path_name[]) {
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
      searchTargetFile(target_path);
    }

    if (strstr(dp->d_name, SCREEN_CAPTURE_PATH_NAME_JA) != NULL ||
        strstr(dp->d_name, SCREEN_SHOT_PATH_NAME_JA) != NULL) {
      int result = remove(target_path);
      if (result == 0) {
        printf("%sの削除に成功しました\n", target_path);
      } else {
        printf("%sの削除に失敗しました\n", target_path);
      }
    }

    dp = readdir(dir);
  }

  if (dir != NULL) {
    closedir(dir);
  }
}
