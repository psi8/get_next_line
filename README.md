# get_next_line

✅ Passed with 100/100

Project Overview:
The task involves programming a function that retrieves a line from a file descriptor. Successive calls to the get_next_line() function, such as in a loop, enable reading the text file associated with the given file descriptor, one line at a time.

The function should return the read line, and in case of no further content or an error, it should return NULL. Ensure the function functions correctly for both file and standard input reading.

It's crucial that the returned line includes the terminating \n character, except when reaching the end of the file without ending with a \n character.

To accommodate file reading in get_next_line(), include the option in your compiler call: -D BUFFER_SIZE=n. This defines the buffer size for read(), and the value will be adjusted by peer evaluators and the Moulinette for testing.

The project must be compilable with and without the -D BUFFER_SIZE flag, alongside the usual compilation flags. You have the liberty to choose a default buffer size, and for illustration, the example compiler call with a buffer size of 42 is as follows:

```c
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 <files>.c
```

