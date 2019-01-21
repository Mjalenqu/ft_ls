# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: mjalenqu <marvin@le-101.fr>                +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2019/01/05 11:44:27 by mjalenqu     #+#   ##    ##    #+#        #
#    Updated: 2019/01/05 11:44:31 by mjalenqu    ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

NAME=ft_ls
CC=@gcc
SRC=src/opening.c src/check_flags.c src/ft_get_l.c src/ft_init_struct.c\
		src/ft_join_path.c src/get_stat.c src/main.c src/sort_list.c src/display.c\
		src/display_option.c src/sort_argv.c

CFLAGS += -Wall -Wextra -Werror -g

OBJ = $(SRC:.c=.o)

LIB_PATH=libft/libft.a

BLUE=\033[0;38;5;123m

LIGHT_PINK = \033[0;38;5;200m

PINK = \033[0;38;5;198m

DARK_BLUE = \033[0;38;5;110m

GREEN = \033[0;38;5;111m

LIGHT_GREEN = \033[1;38;5;121m

FLASH_GREEN = \033[33;32m

all: $(NAME)


$(NAME): $(OBJ)
	@echo "$(LIGHT_GREEN)Compilation de la libft : "
	@make -C libft
	$(CC) $(CFLAGS) -o $@ $^ $(LIB_PATH) -Iincludes
	@echo "$(FLASH_GREEN)$(NAME) compilé et prêt à l'usage !\n"

%.o: %.c ft_ls.h
	$(CC) $(CFLAGS) -o $@ -c $< -Iincludes
	@echo "$(DARK_BLUE.\c)"

clean:
	@make -C libft/ clean
	@rm -rf $(OBJ)
	@echo "$(LIGHT_PINK)Suppression des .o de "$(NAME)"\n"

fclean: clean
	@make -C libft/ fclean
	@rm -rf $(NAME)
	@echo "$(PINK)Suppression de" $(NAME)"\n"

re : fclean all
