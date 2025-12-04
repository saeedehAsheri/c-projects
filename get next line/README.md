# get_next_line

This project implements a `get_next_line` function that reads a file descriptor line by line. Each call returns the next line, including the newline character when present, or `NULL` when there is nothing more to read or an error occurs.

## Why this project matters

Reading a stream one line at a time is a very common task in C: parsing configuration files, logs, text protocols, or standard input. This project is a good exercise in:

- Working with low-level I/O (`read`)
- Managing dynamic memory safely
- Handling partial reads and buffering between function calls

Understanding this pattern helps you write more robust C programs that deal with real-world input.

## How it works

- A **static buffer** stores leftover data between calls to `get_next_line`.
- `read_file` repeatedly calls `read` and appends new data to the buffer until it finds a newline or reaches EOF.
- `fetch_line` extracts the next line from the buffer (up to and including `\n` if it exists).
- `save_after_n` keeps only the part of the buffer after that line, to be used in the next call.
- Utility functions (`ft_strlen`, `ft_strchr`, `ft_memcpy`, `ft_strjoin`) handle basic string and memory operations.

This design allows the function to return exactly one line per call, even if lines span multiple `read` calls.

## Memory management

- Internal buffers are dynamically allocated and freed when no longer needed (on EOF or error).
- On success, `get_next_line` returns a newly allocated string for the caller.
- The caller is responsible for calling `free(line)` after using each returned line.
- If an allocation fails or `read` returns an error, the function cleans up its internal memory and returns `NULL`.

Used correctly (always freeing the returned line), this design avoids memory leaks.

