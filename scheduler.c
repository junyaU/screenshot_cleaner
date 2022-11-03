//
// Created by 内園潤也 on 2022/11/03.
//

#include "scheduler.h"

#include <signal.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <time.h>
#include <unistd.h>

void make_schedule(int span, void *function) {
  struct sigaction action = {0, 0, SA_ONSTACK}, old_action = {0, 0, 0};
  struct itimerval timer = {span, 0, 1, 0};

  action.sa_handler = function;

  if (sigaction(SIGALRM, &action, &old_action) == -1) {
    perror("sigaction");
    exit(1);
  }

  if (setitimer(ITIMER_REAL, &timer, NULL) == -1) {
    perror("setitimer");
    exit(2);
  }
}

void exec() {
  while (true) {
    pause();
  }
}