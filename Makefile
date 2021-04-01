compile = gcc -Wall -Werror -Wextra *.c -ltermcap
Name = readline

all : $(Name)

$(Name) :
	@$(compile) -o $(Name)
fclean:
	@rm -rf $(Name)
re : fclean all