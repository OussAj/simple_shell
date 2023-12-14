#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>

#define MAX_ARGS 64

extern char **environ;

char *get_path(char **env);

int _atoi(const char *s);

char *get_command(char *command, char **env);

char **splitter(char *buffer, char *del);

int _check(int count);

#endif
