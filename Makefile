##
## EPITECH PROJECT, 2023
## Makefile
## File description:
## display
##

NAME	= 110borwein

RM    = rm -f

EXCLUDE_CRITERION = ./src/my_main.c

FILES = ./src/display.c	\
		./src/run_program.c

TEST_FILES = tests/unit_tests.c

UNIT = unit_tests

OBJ    = $(SRC:.c=.o)

all: $(NAME)
$(NAME):
	gcc $(FILES) $(EXCLUDE_CRITERION) -o $(NAME) -lm

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME) $(UNIT)
	$(RM) *.gcda
	$(RM) *.gcno
	$(RM) *.log

re: fclean all

tests_run : unit_tests
	gcc -o $(UNIT) $(FILES) $(TEST_FILES) --coverage -lcriterion -lm
	./$(UNIT)

