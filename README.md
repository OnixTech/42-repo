*This project has been created as pasrt of the 42 curriculum by lupetill.*

## Description
The main task of this project is to write your own library of functions in C language for use them as the original functions. The project is divided in three parts where the Part 1 contains the Libc functions, Part 2 with additional functions that are not included in the libc and Part 3 where you have to manipulate linked list using a structure. 

### **Part 1 - Libc**
- Character: `ft_isalpha, ft_isdigit, ft_isalnum, ft_isascii, ft_isprint`
- Memory: `ft_memset, ft_bzero, ft_memcpy, ft_memmove, ft_memchr, ft_memcmp`
- String: `ft_strlen, ft_strlcpy, ft_strlcat, ft_strchr, ft_strrchr, ft_strncmp, ft_strnstr`
- Conversion: `ft_atoi, ft_toupper, ft_tolower`
- Allocation and duplication: `ft_calloc ft_strdup`
### **Part 2 – Additional Functions**
- `ft_substr`
- `ft_strjoin`
- `ft_strtrim`
- `ft_split`
- `ft_itoa`
- `ft_strmapi`
- `ft_striteri`
- `ft_putchar_fd`
- `ft_putstr_fd`
- `ft_putendl_fd`
- `ft_putnbr_fd`
### **Part 3 – Linked List**
- `ft_lstnew`
- `ft_lstadd_front`
- `ft_lstsize`
- `ft_lstlast`
- `ft_lstadd_back`
- `ft_lstdelone`
- `ft_lstclear`
- `ft_lstiter`
- `ft_lstmap`
 
## Instructions
Each function should contain his own file named with the prefix "ft_". A Makefile should implement to compile the library into the libft.a library with the flags -Wall -Wextra -Werror.
### Commands
`make`        - *builds the libft.a*
`make clean`  - *removes .o files only*
`make fclean` - *removes .o plus libft.a*
`make re`     - *removes everything and rebuilds libft.a*

## Resources
- 42 subject PDF
- man pages
- Standard Library documentation

AI:
this README was formatted with help from ChatGPT. All code and logic were implemented manually.
