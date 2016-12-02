/*
 * args.c
 *
 * Licensed under GNU GPL v3
 *
 */

#include <args.h>
#include <err.h>

#include <unixlib.h>
#include <unixlib-string.h>
#include <sys/types.h>

void init_args(t_args *args)
{
  args -> file_name = MY_NULL;
}

int parse_args(t_args *args, int argc, char **argv)
{
  ssize_t i;

  i = 1;
  while (i < argc)
  {
    if (args -> file_name == MY_NULL)
      args -> file_name = argv[i];
    else
      return (my_retstr(FAILURE, ERR_SYNTAX));
    ++i;
  }
  return (SUCCESS);
}

int check_args(t_args *args)
{
  if (args -> file_name == MY_NULL)
    return (my_retstr(FAILURE, ERR_SYNTAX));
  return (SUCCESS);
}
