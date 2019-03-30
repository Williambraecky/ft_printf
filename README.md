# ft_printf

Printf implementation

# Goal

Implement a basic printf implementation (floats are not done as I don't handle the full range of floats yet)

Undefined behaviours are copyed from macos's implementation of printf (sierra version)

# How did I do it?

Since most of int to string functions were already done in my libft, most of the work was in the string parsing and va_arg learning as well as unicode understanding.

The parsing will run in loops as long as key caracters are being found (0- +#$.*  or digits), then when nothing else is found it will find which converter has to be executed and execute it.

Intensive testing has been done to ensure everything works correctly (besides floats of course)

WIP: Floats are being worked on using VLQ however it's not a priority at all

# Usage

Compile this project

Include either ft_printf.h or libft.h (both in ./includes/)

Usage is the same as the real printf except it's ft_printf instead. (ft_printf_fd for another fd)

You can also use ft_strformat (with libft.h) to format a string instead of printing it!
