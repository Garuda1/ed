/*
 * args.h
 *
 * Licensed under GNU GPL v3
 *
 */

#ifndef ARGS_H
#define ARGS_H

typedef struct s_args t_args;
struct s_args
{
  char *file_name;
};

void init_args(t_args *args);
int parse_args(t_args *args, int argc, char **argv);
int check_args(t_args *args);

#endif
