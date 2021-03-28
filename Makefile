LIB_SRCS = ft_substr.c \
		ft_strlen.c \
		ft_bzero.c \
		ft_strjoin.c \
		ft_strlcpy.c \
		ft_strlcat.c \
		ft_strtrim.c \
		ft_strchr.c \
		ft_split.c \
		ft_strrchr.c \
		ft_itoa.c \
		ft_putchar_fd.c \
		ft_putnbr_fd.c \
		ft_strmapi.c \
		ft_putstr_fd.c \
		ft_putendl_fd.c \
		ft_memset.c \
		ft_memcpy.c \
		ft_memccpy.c \
		ft_memmove.c \
		ft_memchr.c \
		ft_memcmp.c \
		ft_strncmp.c \
		ft_strnstr.c \
		ft_atoi.c \
		ft_toupper.c \
		ft_tolower.c \
		ft_isalpha.c \
		ft_isdigit.c \
		ft_isascii.c \
		ft_isprint.c \
		ft_isalnum.c \
		ft_calloc.c \
		ft_strdup.c \
		get_next_line.c \
		get_next_line_utils.c \
		ft_lstadd_back.c ft_lstadd_front.c ft_lstclear.c \
		ft_lstdelone.c ft_lstiter.c ft_lstlast.c \
		ft_lstmap.c ft_lstnew.c

LIST_SRCS = ft_create_elem.c \
            ft_list_at.c \
            ft_list_clear.c \
            ft_list_find.c \
            ft_list_foreach.c \
            ft_list_foreach_if.c \
            ft_list_last.c \
            ft_list_merge.c \
            ft_list_push_back.c \
            ft_list_push_front.c \
            ft_list_remove_if.c \
            ft_list_reverse.c \
            ft_list_size.c \
        	ft_list_operation.c

LIB_OBJ = $(addprefix $(LIBFT_HEADER)/,$(LIB_SRCS:.c=.o))
LIST_OBJ = $(addprefix $(LIBLIST_HEADER)/,$(LIST_SRCS:.c=.o))

NAME_PS = push_swap
NAME_PS_B = push_swap_bonus
NAME_CH = checker
NAME_CH_B = checker_bonus
NAME_VS = visualizer

CC = gcc
FLAGS = -Wall -Werror -Wextra
LIBRARIES = $(LIBLIST) $(LIBFT) -lmlx -L$(MLX_DIR) -framework OpenGL -framework AppKit
INCLUDES = -I$(HEADER_DIR) -I$(LIBFT_DIR) -I$(LIBLIST_DIR) -I$(MLX_DIR)

LIBFT_DIR = ./srcs/libft/
LIBLIST_DIR = ./srcs/list/
MLX_DIR = ./mlx/

LIBFT = $(LIBFT_DIR)libft.a
LIBLIST = $(LIBLIST_DIR)ft_list.a
LIBMLX = $(MLX_DIR)libmlx.a

LIBFT_HEADER = $(LIBFT_DIR)libft.h
LIBLIST_HEADER = $(LIBLIST_DIR)ft_list.h
MLX_HEADER = $(MLX_DIR)mlx.h

HEADER_DIR = ./includes/
HEADER_LIST = push_swap.h
HEADERS = $(addprefix $(HEADER_DIR), $(HEADER_LIST))

SRCS_DIR = ./srcs/
SRCS_LIST =		algo_core.c \
				algo_core_utils.c \
				three_elem_cases.c \
				count_command_for_every_elem.c \
				rr_rra_ra_rrr_rb_rrb.c \
				parser.c \
				utils.c \
				exec_command.c \
               	exec_command_bonus.c \
               	draw_bonus.c \
               	options_bonus.c

OBJ_DIR = ./objects/
SRCS_LIST_PS = push_swap.c
SRCS_LIST_CH = checker.c
SRCS_LIST_CH_B = checker_bonus.c
SRCS_LIST_VS = visualizer.c
SRCS = $(addprefix $(SRCS_DIR), $(SRCS_LIST))
SRCS_PS = $(addprefix $(SRCS_DIR) $(SRCS_LIST_PS))
SRCS_CH = $(addprefix $(SRCS_DIR) $(SRCS_LIST_CH))
SRCS_CH_B = $(addprefix $(SRCS_DIR) $(SRCS_LIST_CH_B))
SRCS_VS = $(addprefix $(SRCS_DIR) $(SRCS_LIST_VS))

OBJ_LIST = $(patsubst %.c, %.o, $(SRCS_LIST))
OBJ_LIST_PS = $(patsubst %.c, %.o, $(SRCS_LIST_PS))
OBJ_LIST_CH = $(patsubst %.c, %.o, $(SRCS_LIST_CH))
OBJ_LIST_CH_B = $(patsubst %.c, %.o, $(SRCS_LIST_CH_B))
OBJ_LIST_VS = $(patsubst %.c, %.o, $(SRCS_LIST_VS))
OBJ = $(addprefix $(OBJ_DIR), $(OBJ_LIST))
OBJ_PS = $(addprefix $(OBJ_DIR), $(OBJ_LIST_PS))
OBJ_CH = $(addprefix $(OBJ_DIR), $(OBJ_LIST_CH))
OBJ_CH_B = $(addprefix $(OBJ_DIR), $(OBJ_LIST_CH_B))
OBJ_VS = $(addprefix $(OBJ_DIR), $(OBJ_LIST_VS))

PUSH_OBJ = $(PUSH_SRCS:.c=.o)
CHECKER_OBJ = $(CHECKER_SRCS:.c=.o)

.PHONY: all clean fclean re bonus

all: $(NAME_PS) $(NAME_CH)

$(NAME_PS): $(LIBFT) $(LIBLIST) $(OBJ_DIR) $(OBJ) $(OBJ_PS) $(HEADERS)
	$(CC) $(FLAGS) $(OBJ) $(OBJ_PS) $(INCLUDES) $(LIBRARIES) -o $(NAME_PS)

$(NAME_CH): $(LIBFT) $(LIBLIST) $(OBJ_DIR) $(OBJ) $(OBJ_CH) $(HEADERS)
	$(CC) $(FLAGS) $(OBJ) $(OBJ_CH) $(LIBRARIES) $(INCLUDES) -o $(NAME_CH)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(OBJ_DIR)%.o : $(SRCS_DIR)%.c $(HEADERS)
	$(CC) $(FLAGS) -c $(INCLUDES) $< -o $@

$(LIBFT):
	@$(MAKE) -C $(LIBFT_DIR)

$(LIBLIST):
	@$(MAKE) -C $(LIBLIST_DIR)

bonus: $(NAME_PS_B) $(NAME_CH_B) $(NAME_VS)
$(NAME_PS_B): $(LIBFT) $(LIBLIST) $(OBJ_DIR) $(OBJ) $(OBJ_PS) $(HEADERS)
	$(CC) $(FLAGS) $(OBJ) $(OBJ_PS) $(INCLUDES) $(LIBRARIES) -o $(NAME_PS_B)

$(NAME_CH_B): $(LIBFTT) $(LIBLISTT) $(LIBFT) $(LIBLIST) $(OBJ_DIR) $(OBJ_DIRR) $(OBJ) $(OBJ_CH_B)
	$(CC) $(FLAGS) $(OBJ) $(OBJ_CH_B) $(LIBRARIES) $(INCLUDES) -o $(NAME_CH_B)

$(NAME_VS): $(LIBFTT) $(LIBLISTT) $(LIBFT) $(LIBLIST) $(OBJ_DIR) $(OBJ_DIRR) $(OBJ) $(OBJ_VS)
	$(CC) $(FLAGS) $(OBJ) $(OBJ_VS) $(LIBRARIES) $(INCLUDES) -o $(NAME_VS)

OBJ_DIRR:
	mkdir -p $(OBJ_DIR)

$(OBJ_DIR)%.o : $(SRCS_DIR)%.c $(HEADERS)
	$(CC) $(FLAGS) -c $(INCLUDES) $< -o $@

LIBFTT:
	@$(MAKE) -C $(LIBFT_DIR)

LIBLISTT:
	@$(MAKE) -C $(LIBLIST_DIR)

clean:
	@$(MAKE) -C ./srcs/libft clean
	@$(MAKE) -C ./srcs/list clean
	@/bin/rm -rf $(OBJ_DIR)

fclean: clean
	@/bin/rm -f $(LIBFT)
	@/bin/rm -f $(LIBLIST)
	@/bin/rm -f	$(LIBMLX)
	@/bin/rm -f	$(NAME_PS)
	@/bin/rm -f	$(NAME_CH)
	@/bin/rm -f	$(NAME_PS_B)
	@/bin/rm -f	$(NAME_CH_B)
	@/bin/rm -f	$(NAME_VS)

re: fclean all

.PHONY: all clean fclean re
