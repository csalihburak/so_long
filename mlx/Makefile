NAME=libmlx.a
SRC= mlx_shaders.c mlx_new_window.m mlx_init_loop.m mlx_new_image.m mlx_xpm.c mlx_int_str_to_wordtab.c
SRC+= mlx_png.c mlx_mouse.m
OBJ1=$(SRC:.c=.o)
OBJ=$(OBJ1:.m=.o)
CFLAGS+=-O2

# colors for printing
Y = "\033[33m"
R = "\033[31m"
G = "\033[32m"
B = "\033[34m"
X = "\033[0m"
UP = "\033[A"
CUT = "\033[K"

# changed the following 8 lines to silence all the warnings created
%.o : %.c
	@echo $(B)Compiling [$<]...$(X)
	@cc -O2 -w -DSTRINGPUTX11   -c -o $@ $<
%.o : %.m
	@echo $(B)Compiling [$<]...$(X)
	@cc -O2 -w -DSTRINGPUTX11   -c -o $@ $<

# add to match string put with X11 in size and position
CFLAGS+= -DSTRINGPUTX11

all: $(NAME)

$(NAME): $(OBJ)
	@echo $(B)Compiling [$(NAME)]...
	@ar -r $(NAME) $(OBJ)
	@ranlib $(NAME)

clean:
	@rm -f $(OBJ)
	@echo $(R)Removed [$(OBJ)]

fclean: clean
	@rm -f $(NAME) *~
	@rm -f mlx_app
	@echo $(R)Removed [$(NAME)]

re: clean all
