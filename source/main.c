/*
 * main.c
 *
 * Licensed under GNU GPL v3
 *
 */

#include <unixlib.h>
#include <unixlib-io.h>
#include <unixlib-string.h>
#include <stdio.h>
#include <stdint.h>
#include <unistd.h>
#include <fcntl.h>

#include <args.h>
#include <cmd.h>

#define MEM_SIZE 128
#define BUF_SIZE 128

static void dump_mem(const uint8_t *mem)
{
  size_t i;

  i = 0;
  while (i < MEM_SIZE)
    printf("|%02X| ", (unsigned int) mem[i++]);
  my_putc(CHAR_NEWLINE);
}

static int edit(t_args *args)
{
  int keep_running;
  char buf[BUF_SIZE];
  uint8_t mem[MEM_SIZE];
  size_t address;
  int fd;

  my_memset(mem, 0, MEM_SIZE);
  address = 0;

  keep_running = 1;
  while (keep_running)
  {
    printf("[ed | %s] ", args -> file_name);
    scanf("%s", buf);
    if (!my_strcmp(buf, CMD_EXIT))
      keep_running = 0;
    else if (!my_strcmp(buf, CMD_DISP))
      dump_mem(mem);
    else if (!my_strcmp(buf, CMD_JUMP))
    {
      printf("Address: 0x");
      scanf("%04X", (unsigned int *) &address);
      if (address >= MEM_SIZE)
        address = MEM_SIZE - 1;
    }
    else if (!my_strcmp(buf, CMD_NEXT))
    {
      if (address < (MEM_SIZE - 1))
        ++address;
    }
    else if (!my_strcmp(buf, CMD_PREV))
    {
      if (address > 0)
        --address;
    }
    else if (!my_strcmp(buf, CMD_SET))
    {
      printf("Value (2 digits, hex): 0x");
      scanf("%02X", (unsigned int *) &(mem[address]));
    }
    else if (!my_strcmp(buf, CMD_SAVE))
    {
      fd = open(args -> file_name, O_WRONLY);
      write(fd, mem, MEM_SIZE);
      close(fd);
      printf("File saved\n");
    }

    else
    {
      printf("Command not found: %s\n", buf);
    }
  }
  return (SUCCESS);
}

int main(int argc, char **argv)
{
  t_args args;

  init_args(&args);
  if (parse_args(&args, argc, argv) == FAILURE)
    return (FAILURE);
  if (check_args(&args) == FAILURE)
    return (FAILURE);

  return (edit(&args));
}
