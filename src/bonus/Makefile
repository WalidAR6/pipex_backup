NAME = pipex 

FLAGS = -Wall -Wextra -Werror

SRC = main_bonus\
		here_doc_bonus\
		get_file_name_bonus\
		execve_bonus\
		check_arg_bonus\
		join_cmds_bonus\
		multiple_files_bonus\
		first_last\
		multi_pipe_exe\
		here_loop

OBJ_DIR = ../../bin/bonus/

OBJ = ${SRC:=.o}

OBJCTS = ${addprefix $(OBJ_DIR),$(OBJ)}

EXE = ../libft_global/libft.a

all: ${NAME}

${NAME} : ${OBJCTS} 
	${CC} ${FLAGS} $(EXE) $^ -o $@

$(OBJ_DIR)%.o : %.c ../../inc/pipex_bonus.h ../../inc/libft.h $(EXE)
	@mkdir -p $(OBJ_DIR)
	${CC} ${FLAGS} -c $< -o $@

clean: 
	@${RM} $(OBJCTS)

fclean : clean
	@${RM} -rf ${NAME} $(OBJ_DIR)

re: fclean all