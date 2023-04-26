# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: emcnab <emcnab@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/06 14:08:48 by emcnab            #+#    #+#              #
#    Updated: 2023/04/26 13:27:42 by emcnab           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# **************************************************************************** #
#                               COMPILATIONS TASKS                             #
# **************************************************************************** #

all: debug

debug:
	@echo "$(BOLD)$(RED)[ Building in Debug Mode ]$(RESET)"
	@make --silent --file=./build/build_debug.mf

final:
	@echo "$(BOLD)$(BLUE)[ Building in Final Mode ]$(RESET)"
	@make --silent --file=./build/build_final.mf

clean:
	@make clean --silent --file=./build/build_debug.mf

fclean:
	@make fclean --silent --file=./build/build_debug.mf

re:
	@make re --silent --file=./build/build_debug.mf



-include ./build/colors.mf



.PHONY: all debug final clean fclean re
