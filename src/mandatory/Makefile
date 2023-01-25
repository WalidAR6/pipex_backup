NAME = pipex 

FLAGS = -Wall -Wextra -Werror

SRC = main\
	check_args\
	get_file_name\
	join_cmds\
	execution\
	execve

OBJ_DIR = ../../bin/mandatory/

OBJ = ${SRC:=.o}

OBJCTS = ${addprefix $(OBJ_DIR),$(OBJ)}

EXE = ../libft_global/libft.a

all: ${NAME}

${NAME} : ${OBJCTS} 
	${CC} ${FLAGS} $(EXE) $^ -o $@

$(OBJ_DIR)%.o : %.c ../../inc/pipex.h ../../inc/libft.h $(EXE)
	@mkdir -p $(OBJ_DIR)
	${CC} ${FLAGS} -c $< -o $@ -g

clean: 
	@${RM} $(OBJCTS)

fclean : clean
	@${RM} -rf ${NAME} $(OBJ_DIR)

re: fclean all