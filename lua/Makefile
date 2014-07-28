CC      = gcc
LIB		= -lutils -luuid
CFLAGS  = -g -W -Wall -Wno-unused-parameter -Wunused-function \
		  -Wunused-variable -Wunused-value -Werror -fPIC
OBJS    = utils_lua.o 

lua:$(OBJS)
	$(CC) -shared -o utils_lua.so utils_lua.o $(LIB)

utils_lua.o:utils_lua.c
	$(CC) -c $(CFLAGS) -o utils_lua.o utils_lua.c

install:
	 install -m644 utils_lua.so  /opt/soft/base_env/openresty/lualib

clean:
	rm -f utils_lua.so 
	rm -f utils_lua.o
