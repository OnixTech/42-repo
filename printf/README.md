*This project has been created as pasrt of the 42 curriculum by lupetill.*

## Description
The main task of this project is to write your own "printf" function in C language for use it as the original function. The function should manage all the same formats as the original. 

### **Libraries**
- `libft`
- `stdarg`
- `stdlib`
### **External Functions**
- `ft_putchar_fd`
- `ft_putstr_fd`
- `ft_putnbr_fd`
- `ft_putptr`
- `ft_strlen`
- `va_start`
- `va_arg`
- `va_copy`
- `va_end`
- `malloc`
- `free`
- `write`

 
## Instructions
Recode the printf() function from libc witht the next requirements:
- `Do not implement the buffer management of the original printf().`
- `The function has to handle the following conversions:`
%                   (% character)
c    char           (character)
s    char *         (string)
p    void *         (pointer's address)
u    unsigned int   (unsigned decimal integer)
x/X: unsigned int   (hexadecimal)
d/i: int            (integer)

### Commands
- `make`        - *builds the libftprintf.a*
- `make clean`  - *removes .o files only*
- `make fclean` - *removes .o plus libftprintf.a*
- `make re`     - *removes everything and rebuilds libft.a*

## Resources
- 42 subject PDF
- man pages
