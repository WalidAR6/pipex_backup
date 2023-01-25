LIBFT_DIR = src/libft_global

MANDA_DIR = src/mandatory

BONUS_DIR = src/bonus

OBJ_DIR = bin/

all: 
	@${MAKE} -C ${LIBFT_DIR}
	@echo "\033[92mlibft compiled ✔\033[0m"
	@${MAKE} -C ${MANDA_DIR}
	@echo "\033[92mmandatory compiled ✔\033[0m"

bonus:
	@${MAKE} -C ${LIBFT_DIR}
	@echo "\033[92mlibft compiled ✔\033[0m"
	@${MAKE} -C ${BONUS_DIR}
	@echo "\033[92mbonus compiled ✔\033[0m"

clean:
	@${MAKE} -C ${MANDA_DIR} clean
	@${MAKE} -C ${LIBFT_DIR} clean
	@${MAKE} -C ${BONUS_DIR} clean

fclean:
	@${MAKE} -C ${LIBFT_DIR} fclean
	@${MAKE} -C ${MANDA_DIR} fclean
	@${MAKE} -C ${BONUS_DIR} fclean
	@$(RM) -rf $(OBJ_DIR)

re: fclean all
