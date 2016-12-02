# ed - Not the standard UNIX editor

`ed` is a terminal based hexadecimal editor. After looking for a decent CLI based binary editor, I decided to make my own.

## Synopsis

    $ ed file_name -m MEM_SIZE

## Usage

The program is based on a shell. Here is a list of the different commands:

- exit        Exit without saving
- disp        Dumps the memory
- next        Jump to the next byte
- prev        Jump to the prev byte
- jump        Jump to a specific byte
- save        Save the edited program
- set         Set the value of the current byte
