#------------------------------------------------------------------------------#
#                                  GENERICS                                    #
#------------------------------------------------------------------------------#

# Special variables
DEFAULT_GOAL: all
.DELETE_ON_ERROR: $(NAME)
.PHONY: all bonus clean fclean re
HIDE =



#------------------------------------------------------------------------------#
#                                VARIABLES                                     #
#------------------------------------------------------------------------------#

# Compiler and flags
CC		=	gcc $(DEBUG)
CFLAGS	=	-Wall -Werror -Wextra -I. -I./$(INCDIR)
RM		=	rm -f
DEBUG 	=	-g3 -fsanitize=address

# Output file name
NAME	=	rush_01

# Sources are all .c files
SRCDIR	=	./
SRCS	=	$(wildcard $(SRCDIR)*.c) # Wildcard for sources is forbidden by norminette

# Objects are all .o files
OBJDIR	=	bin/
OBJS	=	$(patsubst $(SRCDIR)%.c,$(OBJDIR)%.o,$(SRCS))

# Includes are all .h files
INCDIR	=	./
INC		=	$(wildcard $(INCDIR)*.h)


#------------------------------------------------------------------------------#
#                                 TARGETS                                      #
#------------------------------------------------------------------------------#

all: $(NAME)

# Generates output file
$(NAME): $(OBJS)
	$(HIDE)$(CC) $(CFLAGS) -o $@ $^

# Compiles sources into objects
$(OBJS): $(OBJDIR)%.o : $(SRCDIR)%.c $(INC) | $(OBJDIR)
	$(HIDE)$(CC) $(CFLAGS) -c $< -o $@

# Creates directory for binaries
$(OBJDIR):
	$(HIDE)mkdir -p $@

# Removes objects
clean:
	$(HIDE)$(RM) $(OBJS)

# Removes objects and executables
fclean: clean
	$(HIDE)$(RM) $(NAME)

# Removes objects and executables and remakes
re: fclean all
