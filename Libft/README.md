*This project has been created as part of the 42 curriculum by aserio.*

# Libft

## Description

**Libft** is the first major C project of the 42 curriculum. The goal is to build your own **C utility library** by reimplementing a set of functions from the standard C library (`libc`) and adding a few extra helpers you will reuse in later projects (e.g. *get_next_line*, *printf*, *minitalk*, *so_long*, etc.).

The project produces a static archive **`libft.a`** that can be linked into other programs with `-L.` and `-lft`. All public symbols are declared in **`libft.h`**.

The library is organized in three logical parts:

| Part | Content |
|------|---------|
| **Part 1 — Libc functions** | A set of functions from the libc. |
| **Part 2 — Additional functions** | A set of functions that are either not included in the libc, or exist in a different form. |
| **Part 3 — Linked list** | Functions using a structure to manipulate linked lists. |

Code follows the **42 Norm** (naming, file layout, forbidden constructs) and is compiled with **`-Wall -Wextra -Werror`**.

---

## Instructions

### Requirements

- A C compiler (`cc` / `gcc` / `clang`)
- `make`
- `ar` (for building the static library)

### Compilation

From the project directory:

```bash
make        # build libft.a
make clean  # remove object files (.o)
make fclean # remove objects and libft.a
make re     # full rebuild (fclean + all)
```

Successful compilation creates **`libft.a`** in the project root.

### Using the library in another project

1. Copy or reference the Libft folder.
2. Compile your program and link against the archive:

```bash
cc -Wall -Wextra -Werror your_program.c -L/path/to/libft -lft -I/path/to/libft
```

3. Include the header:

```c
#include "libft.h"
```

### Project layout

```
.
├── Makefile      # builds libft.a
├── libft.h       # prototypes and t_list definition
├── ft_*.c        # one function (or closely related group) per file
└── libft.a       # generated static library (after make)
```

---

## The library in detail

### Part 1 — Libc functions

| Category | Functions | Role |
|----------|-----------|------|
| **Character tests** | `ft_isalpha`, `ft_isdigit`, `ft_isalnum`, `ft_isascii`, `ft_isprint` | Test character properties (same idea as `<ctype.h>`). |
| **String length** | `ft_strlen` | Return length of a NUL-terminated string. |
| **Memory fill / copy** | `ft_memset`, `ft_bzero`, `ft_memcpy`, `ft_memmove` | Fill or copy raw memory; `memmove` handles overlapping regions. |
| **String copy / concat** | `ft_strlcpy`, `ft_strlcat` | Size-bounded copy and concatenate (BSD-style, return total length needed). |
| **Case** | `ft_toupper`, `ft_tolower` | Convert character case. |
| **String search** | `ft_strchr`, `ft_strrchr`, `ft_strncmp`, `ft_strnstr` | Find characters or substrings; compare strings up to `n` bytes. |
| **Memory search / compare** | `ft_memchr`, `ft_memcmp` | Search or compare raw memory blocks. |
| **Conversion / allocation** | `ft_atoi`, `ft_calloc`, `ft_strdup` | Parse integer from string; allocate zeroed memory; duplicate string. |

### Part 2 — Additional functions

| Function | Role |
|----------|------|
| `ft_substr` | Extract a substring from index `start` for at most `len` characters. |
| `ft_strjoin` | Concatenate two strings into a newly allocated result. |
| `ft_strtrim` | Remove leading/trailing characters present in `set`. |
| `ft_split` | Split a string on delimiter `c`; return a NULL-terminated array of strings. |
| `ft_itoa` | Convert integer to allocated string. |
| `ft_strmapi` | Apply function `f(index, char)` to each character; return new string. |
| `ft_striteri` | Apply function `f(index, char*)` to each character in place. |
| `ft_putchar_fd` | Write one character to file descriptor `fd`. |
| `ft_putstr_fd` | Write string to `fd`. |
| `ft_putendl_fd` | Write string followed by newline to `fd`. |
| `ft_putnbr_fd` | Write integer as decimal to `fd`. |

### Part 3 — Linked list

Functions using a structure to manipulate linked lists.

```c
typedef struct s_list
{
    void            *content;
    struct s_list   *next;
}   t_list;
```

Linked-list nodes store an opaque `content` pointer and a `next` pointer. Deletion and mapping functions accept a user-provided `del` callback to free content when needed.

| Function | Role |
|----------|------|
| `ft_lstnew` | Allocate a new node with `content`. |
| `ft_lstadd_front` | Insert node at the head of the list. |
| `ft_lstadd_back` | Append node at the tail. |
| `ft_lstsize` | Count nodes. |
| `ft_lstlast` | Return pointer to last node. |
| `ft_lstdelone` | Free one node's content (via `del`) and the node. |
| `ft_lstclear` | Free entire list. |
| `ft_lstiter` | Apply `f` to each node's content. |
| `ft_lstmap` | Build a new list by applying `f` to each content; on failure, call `del` and clean up. |

### Design notes

- Each `.c` file typically implements **one** function (Norm-friendly).
- Functions mirror **libc behavior** where applicable; edge cases (NULL pointers, empty strings, overflow in `ft_calloc`, etc.) should match project subject expectations.
- Dynamic memory (`malloc` / `free`) is used only where the subject requires it (e.g. `ft_strdup`, `ft_substr`, `ft_split`, Part 3 linked list).

---

## Resources

### Documentation and references

- [The C Programming Language (K&R)](https://en.wikipedia.org/wiki/The_C_Programming_Language) — fundamentals of C.
- [cppreference.com — C library](https://en.cppreference.com/w/c) — behavior of standard functions reimplemented here.
- [man7.org — Linux manual pages](https://man7.org/linux/man-pages/) — e.g. `man 3 strlen`, `man 3 malloc`.
- [42 Norm (PDF)](https://github.com/42School/norminette/blob/master/pdf/en.norm.pdf) — coding rules for 42 projects.
- [GNU `libc` source](https://www.gnu.org/software/libc/) — reference for expected semantics (read-only study).

### Use of AI

AI tools (e.g. Cursor) were used **only as learning aids**, not to submit autogenerated code without understanding. Typical uses:

| Task | How AI was used |
|------|------------------|
| **Understanding subject / libc** | Clarifying expected behavior of functions (e.g. `strlcpy` vs `strncpy`, `ft_split` memory layout). |
| **Debugging** | Explaining compiler or Norm errors and suggesting where to look in my own code. |
| **README** | Drafting and structuring this document; content was reviewed and edited by **aserio**. |

**Not** delegated to AI without manual review: final implementations in `ft_*.c`, Makefile, and evaluation-critical logic — those were written, tested, and understood by the author.

---

## Author

**aserio** — 42 Barcelona
