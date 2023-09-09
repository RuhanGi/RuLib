INC_DIR = inc
SRC_DIR = srcs
OBJ_DIR = objs

SRCS = convert.c ft_printf.c ft_split.c get_next_line.c isX.c \
		mem.c misc.c put_fd.c put.c str.c strfunc.c strrare.c 

OBJS = $(addprefix $(OBJ_DIR)/, $(SRCS:.c=.o))

SRCBONUS = ft_list.c list_actions.c

OBJBONUS = $(addprefix $(OBJ_DIR)/, $(SRCBONUS:.c=.o))

NAME = libft.a

all: ${NAME}

$(OBJ_DIR)/%.o : $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	@gcc -Wall -Werror -Wextra -c $< -o $@

${NAME}: ${OBJS}
	@ar -rcs ${NAME} ${OBJS}
	@printf "\x1B[32m$(NAME) ready\\x1B[32m\n";

clean:
	@rm -rf ${OBJ_DIR}

fclean: clean
	@rm -rf ${NAME}

bonus: ${OBJS} ${OBJBONUS}
	@ar -rcs ${NAME} ${OBJBONUS}
	@ranlib ${NAME}

gpush:
	git add .
	git commit -m sub
	git push

re: fclean all
