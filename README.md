*This activity has been created as part of the 42 curriculum by liovine.*

# Description
This repository contain the code for the libft library.
The lib is a replica of some glibc function,
complemented with other useful function.
It is meant to be used in other projects.

## Character functions
These are the function that takes a single character (ascii) as parameter
- `ft_isspace`: the character is in the *space* section
- `ft_islower`: the character is in the *lower alphabetical* section
- `ft_isupper`: the character is in the *upper alphabetical* section
- `ft_isalpha`: the character is in the *alphabetical* section (lower or upper)
- `ft_isdigit`: the character is in the *digit* section (0-9)
- `ft_isalnum`: the character is in the *alphabetical* or *digit* section
- `ft_isascii`: the character don't has other than the 7 less significant bits up
- `ft_isprint`: the character is *printable*
- `ft_toupper`: convert the given character to it's upper equivalent
- `ft_tolower`: convert the given character to it's lower equivalent

## Memory functions
These functions are used to manipulate chunk of memory
- `ft_memcpy`: copy a memory chunk to another place
- `ft_memmove`: copy a memory chunk to another place, even within itself
- `ft_memset`: set all bytes in the given chunk to the given reference byte
- `ft_bzero`: set all bytes in the given chunk to zero
- `ft_calloc`: allocate requested memory and initialize it at zero
- `ft_memcmp`: compare two given memory place and return hierarchy of the first different char
- `ft_memchr`: find the first occurrence of the given character

## String functions
These functions are used to manipulate standard c **NULL terminated string**
- `ft_strlen`: return the number of character before the NULL find in a strings
- `ft_strchr`: find the first occurrence of the given character
- `ft_strrchr`: find the last occurrence of the given character
- `ft_strdup`: return a copy of the given string
- `ft_striteri`: call a given function at each character
- `ft_strjoin`: create a new string from two other strings
- `ft_strlcpy`: copy a string to an other place, using a limit
- `ft_strlcat`: concatenate a string to an other, using a limit
- `ft_strmapi`: create a new string from an other applying a functions at each character
- `ft_strncmp`: compare two string and return hierarchy of the first different char
- `ft_strnstr`: find a string into another string, using a limit
- `ft_strtrim`: return a copy of the given string without the heading and trailing character present in the given set
- `ft_substr`: return a portion of the given string
- `ft_split`: return a list of word present in the given string
- `ft_atoi`: parse a string into a integer
- `ft_itoa`: build the string equivalent of a integer

## Write functions
These functions are used to write characters, strings and integer into a *file descriptor*
- `ft_putchar_fd`: write the given character
- `ft_putstr_fd`: write the given string
- `ft_putendl_fd`: write the given string and terminate the line
- `ft_putnbr_fd`: write the string representation of the given integer

## list functions
These functions are used to handle chained list
- `ft_lstnew`: create a new list object
- `ft_lstadd_back`: slice in at the start of the chain
- `ft_lstadd_front`: append to the end of the chain
- `ft_lstlast`: return the last element of the chain
- `ft_lstsize`: return the number of element in the chain
- `ft_lstdelone`: free a single element of the chain
- `ft_lstclear`: clean all element of a given chain
- `ft_lstiter`: iterate into a chain calling a callback
- `ft_lstmap`: create a new chain from another applying a given function at each element

## printf
This is a partial recreation of the printf function.

It re implements conversion for:
- '%': print the '%' character
- 'c': print a character
- 's': print a string
- 'd' or 'i': print a integer
- 'u': print a unsigned integer
- 'x': print a unsigned integer in hexadecimal
- 'X': print a unsigned integer in upper case hexadecimal
- 'p': print a pointer value in stylized way

# Instructions
To compile this library into a *.a* use the `make` command

to use a *.a* library into other programes add it at the end of the compilation command (e.g. gcc mycode.c libft.a)

# Resources
## MAN pages
Used to get the main information about the needed function

## openbsd source code
> https://github.com/openbsd/src

Mainly used for code comparison

## stackoverflow
For unstuck

