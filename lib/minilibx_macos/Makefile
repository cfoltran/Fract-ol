#
#
include include.mk

SRC= mlx_shaders.c mlx_new_window.m mlx_init_loop.m mlx_new_image.m mlx_xpm.c mlx_int_str_to_wordtab.c

OBJ1=$(SRC:.c=.o)

OBJ=$(OBJ1:.m=.o)

CFLAGS+=-O2

all:		$(LIBX)

$(LIBX):	$(OBJ)
	@ar -r $(LIBX) $(OBJ)
	@ranlib $(LIBX)

clean:
	@rm -f $(LIBX) $(OBJ) *~
	@rm -f mlx_app

re: clean all
