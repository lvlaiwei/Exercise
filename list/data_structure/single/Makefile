CC := gcc
CFLAG +=  -fPIC
NAME_MODEL = single_list_data

all: $(NAME_MODEL)_bin $(NAME_MODEL)_lib

%.o:%.c
	$(CC) $(CFLAG) -c $< -o $@

$(NAME_MODEL)_bin: $(NAME_MODEL).o
	$(CC) $^ -o $@
	
$(NAME_MODEL)_lib: $(NAME_MODEL).o
	$(AR) crv lib$(NAME_MODEL).a $^
	$(CC) $^ -shared -o lib$(NAME_MODEL).so

clean:
	rm -rf *.o *.so *.a $(NAME_MODEL)

.PHONY:$(NAME_MODEL)_bin $(NAME_MODEL)_lib clean