# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: emcnab <emcnab@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/06 14:08:48 by emcnab            #+#    #+#              #
#    Updated: 2023/04/26 14:15:42 by emcnab           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# **************************************************************************** #
#                               COMPILATIONS TASKS                             #
# **************************************************************************** #

all: debug

# **************************************************************************** #
#                                   DEBUG TASK                                 #
# **************************************************************************** #

debug:
	@echo "$(BOLD)$(RED)[ Building in Debug Mode ]$(RESET)"
	@make --silent --file=./build/build_debug.mf

clean_debug:
	@echo "$(BOLD)$(RED)[ Removing all Debug objects ]$(RESET)"
	@make clean --silent --file=./build/build_debug.mf

fclean_debug:
	@echo "$(BOLD)$(RED)[ Removing all Debug files ]$(RESET)"
	@make fclean --silent --file=./build/build_debug.mf

re_debug:
	@echo "$(BOLD)$(RED)[ Rebuilding Debug binary ]$(RESET)"
	@make fclean --silent --file=./build/build_debug.mf
	@make --silent --file=./build/build_debug.mf

# **************************************************************************** #
#                                    TEST TASK                                 #
# **************************************************************************** #

test: debug
	@echo "$(BOLD)$(YELLOW)[ Building in Test Mode ]$(RESET)"
	@make --silent --file=./build/build_test.mf
	@echo "$(BOLD)$(YELLOW)[ Runnig tests... ]$(RESET)"
	@./bin/lib42_test

clean_test:
	@echo "$(BOLD)$(YELLOW)[ Removing all Test objects ]$(RESET)"
	@make clean --silent --file=./build/build_test.mf

fclean_test:
	@echo "$(BOLD)$(YELLOW)[ Removing all Test files ]$(RESET)"
	@make fclean --silent --file=./build/build_test.mf

re_test:
	@echo "$(BOLD)$(YELLOW)[ Rebuilding Test binary ]$(RESET)"
	@make fclean --silent --file=./build/build_test.mf
	@make --silent --file=./build/build_test.mf
	@echo "$(BOLD)$(YELLOW)[ Runnig tests... ]$(RESET)"
	@./bin/lib42_test

# **************************************************************************** #
#                                   FINAL TASK                                 #
# **************************************************************************** #

final:
	@echo "$(BOLD)$(BLUE)[ Building in Final Mode ]$(RESET)"
	@make --silent --file=./build/build_final.mf

clean_final:
	@echo "$(BOLD)$(BLUE)[ Removing all Final objects ]$(RESET)"
	@make clean --silent --file=./build/build_final.mf

fclean_final:
	@echo "$(BOLD)$(BLUE)[ Removing all Final files ]$(RESET)"
	@make fclean --silent --file=./build/build_final.mf

re_final:
	@echo "$(BOLD)$(BLUE)[ Rebuilding Final binary ]$(RESET)"
	@make fclean --silent --file=./build/build_final.mf
	@make --silent --file=./build/build_final.mf

-include ./build/colors.mf



.PHONY: all debug test clean fclean re final final_clean final_fclean final_re
