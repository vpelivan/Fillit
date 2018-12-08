cmake_minimum_required(VERSION 3.12)
project(fillit C)

set(CMAKE_C_STANDARD 99)

add_executable(fillit main.c Fillit.h libft/ft_putstr.c libft/ft_strnew.c libft/ft_memalloc.c libft/get_next_line.c libft/ft_strjoin.c libft/ft_memcpy.c libft/ft_memset.c libft/ft_strcat.c libft/ft_strchr.c libft/ft_strcpy.c libft/ft_strdup.c libft/ft_strlen.c)