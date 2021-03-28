cmake_minimum_required(VERSION 3.12)
project(push_swap)
set(CMAKE_C_STANDARD 99)
#set(CMAKE_C_FLAGS "-Lmlx -lmlx -framework OpenGL -framework AppKit")
#set(CMAKE_C_FLAGS "-Wall -Werror -Wextra")
include_directories(./srcs/libft ./srcs/list ./mlx ./includes ./mlx)
#link_directories(./srcs/libft ./srcs/list ./mlx ./includes)

add_executable(push_swap
        srcs/algo_core.c
        srcs/algo_core_utils.c
        srcs/three_elem_cases.c
        srcs/count_command_for_every_elem.c
        srcs/rr_rra_ra_rrr_rb_rrb.c
        srcs/parser.c
#        srcs/exec_command_bonus.c
        srcs/exec_command.c
#        srcs/draw_bonus.c
#        srcs/options_bonus.c
#        srcs/help_me.c
#        srcs/push_swap.c
        srcs/checker.c
#        srcs/checker_bonus.c
#        srcs/visualizer.c
        srcs/utils.c
        includes/push_swap.h
        srcs/libft/ft_atoi.c
        srcs/libft/ft_bzero.c
        srcs/libft/ft_calloc.c
        srcs/libft/ft_isalnum.c
        srcs/libft/ft_isalpha.c
        srcs/libft/ft_isascii.c
        srcs/libft/ft_isdigit.c
        srcs/libft/ft_isprint.c
        srcs/libft/ft_itoa.c
        srcs/libft/ft_memccpy.c
        srcs/libft/ft_memchr.c
        srcs/libft/ft_memcmp.c
        srcs/libft/ft_memcpy.c
        srcs/libft/ft_memmove.c
        srcs/libft/ft_memset.c
        srcs/libft/ft_putchar_fd.c
        srcs/libft/ft_putendl_fd.c
        srcs/libft/ft_putnbr_fd.c
        srcs/libft/ft_putstr_fd.c
        srcs/libft/ft_split.c
        srcs/libft/ft_strchr.c
        srcs/libft/ft_strdup.c
        srcs/libft/ft_strjoin.c
        srcs/libft/ft_strlcat.c
        srcs/libft/ft_strlcpy.c
        srcs/libft/ft_strlen.c
        srcs/libft/ft_strmapi.c
        srcs/libft/ft_strncmp.c
        srcs/libft/ft_strnstr.c
        srcs/libft/ft_strrchr.c
        srcs/libft/ft_strtrim.c
        srcs/libft/ft_substr.c
        srcs/libft/ft_tolower.c
        srcs/libft/ft_toupper.c
        srcs/libft/get_next_line.c
        srcs/libft/heap_sort.c
        srcs/libft/libft.h
        srcs/list/ft_list.h
        mlx/mlx.h
        srcs/list/ft_create_elem.c
        srcs/list/ft_list_at.c
        srcs/list/ft_list_clear.c
        srcs/list/ft_list_find.c
        srcs/list/ft_list_foreach.c
        srcs/list/ft_list_foreach_if.c
        srcs/list/ft_list_last.c
        srcs/list/ft_list_merge.c
        srcs/list/ft_list_operation.c
        srcs/list/ft_list_size.c
        srcs/list/ft_list_reverse.c
        srcs/list/ft_list_remove_if.c
        srcs/list/ft_list_push_front.c
        srcs/list/ft_list_push_back.c
)
target_link_libraries(push_swap /Users/ptycho/Documents/42cursus/push_swap/mlx/libmlx.a)
target_link_libraries(push_swap "-framework OpenGL")
target_link_libraries(push_swap "-framework AppKit")
#target_compile_options(push_swap PRIVATE -Wall -Wextra -Werror)


