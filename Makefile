OBJS_DIR     = objs

UTIL_OBJS    = $(OBJS_DIR)/_log.o          \
			   $(OBJS_DIR)/_time.o         \
			   $(OBJS_DIR)/_string.o       \
			   $(OBJS_DIR)/_other.o        \
			   $(OBJS_DIR)/_queue.o        \
			   $(OBJS_DIR)/_mem_pool.o     \
			   $(OBJS_DIR)/_thread_pool.o  \
			   $(OBJS_DIR)/_memory.o       \
			   $(OBJS_DIR)/_process_lock.o \
			   $(OBJS_DIR)/_syslog.o       \
			   $(OBJS_DIR)/_property.o     \
			   $(OBJS_DIR)/_network.o      \
			   $(OBJS_DIR)/_shm.o          \
			   $(OBJS_DIR)/_buffer.o

HASHMAP_OBJS = $(OBJS_DIR)/hash_fcn.o      \
			   $(OBJS_DIR)/hashmap.o       \
			   $(OBJS_DIR)/prime_table.o

CONHASH_OBJS = $(OBJS_DIR)/conhash.o       \
			   $(OBJS_DIR)/conhash_inter.o \
			   $(OBJS_DIR)/conhash_util.o  \
			   $(OBJS_DIR)/crc32.o         \
			   $(OBJS_DIR)/util_rbtree.o

CRYPT_OBJS	 = $(OBJS_DIR)/3des.o \
			   $(OBJS_DIR)/md5.o	

#SERVER_CONHASH_OBJS = $(OBJS_DIR)/server_conhash.o

RBTREE_OBJS  = $(OBJS_DIR)/rbtree.o

IP_ZONE_OBJS = $(OBJS_DIR)/ip_zone.o

NETWORK_OBJS = $(OBJS_DIR)/udp.o          \
               $(OBJS_DIR)/network_util.o 

OBJS         = $(UTIL_OBJS)           \
	   		   $(HASHMAP_OBJS)        \
	  	       $(CONHASH_OBJS)        \
			   $(IP_ZONE_OBJS)        \
			   $(CRYPT_OBJS)          \
			   $(RBTREE_OBJS)         \
			   $(NETWORK_OBJS)

LIBS         = -lpthread -llua -ldl -lm

MAIN_LIBS    = $(LIBS) -llua -ldl -lm

CC           = gcc
CFLAGS       = -g -W -Wall -Werror -Wno-unused-parameter -Wunused-function \
			   -Wunused-variable -Wunused-value -fPIC \
			   -Ihashmap -Iconhash -Iutils -Irbtree

MAIN_EXE   = main
STATIC_LIB = libutils.a

lib:$(OBJS)
	ar rcs $(STATIC_LIB) $(OBJS)

main:main.o
	$(CC) -o $(MAIN_EXE) $(CFLAGS) main.o -lutils $(MAIN_LIBS)
	@echo $(MAIN_EXE) is generated!

$(OBJS_DIR)/_log.o:utils/_log.c
	$(CC) -c $(CFLAGS) -o $(OBJS_DIR)/_log.o utils/_log.c

$(OBJS_DIR)/_time.o:utils/_time.c
	$(CC) -c $(CFLAGS) -o $(OBJS_DIR)/_time.o utils/_time.c

$(OBJS_DIR)/_string.o:utils/_string.c
	$(CC) -c $(CFLAGS) -o $(OBJS_DIR)/_string.o utils/_string.c

$(OBJS_DIR)/_other.o:utils/_other.c
	$(CC) -c $(CFLAGS) -o $(OBJS_DIR)/_other.o utils/_other.c

$(OBJS_DIR)/_queue.o:utils/_queue.c
	$(CC) -c $(CFLAGS) -o $(OBJS_DIR)/_queue.o utils/_queue.c

$(OBJS_DIR)/_mem_pool.o:utils/_mem_pool.c
	$(CC) -c $(CFLAGS) -o $(OBJS_DIR)/_mem_pool.o utils/_mem_pool.c

$(OBJS_DIR)/_thread_pool.o:utils/_thread_pool.c
	$(CC) -c $(CFLAGS) -o $(OBJS_DIR)/_thread_pool.o utils/_thread_pool.c

$(OBJS_DIR)/_memory.o:utils/_memory.c
	$(CC) -c $(CFLAGS) -o $(OBJS_DIR)/_memory.o utils/_memory.c

$(OBJS_DIR)/_process_lock.o:utils/_process_lock.c
	$(CC) -c $(CFLAGS) -o $(OBJS_DIR)/_process_lock.o  utils/_process_lock.c

$(OBJS_DIR)/_syslog.o:utils/_syslog.c
	$(CC) -c $(CFLAGS) -o $(OBJS_DIR)/_syslog.o  utils/_syslog.c

$(OBJS_DIR)/_property.o:utils/_property.c
	$(CC) -c $(CFLAGS) -o $(OBJS_DIR)/_property.o  utils/_property.c

$(OBJS_DIR)/_network.o:utils/_network.c
	$(CC) -c $(CFLAGS) -o $(OBJS_DIR)/_network.o  utils/_network.c

$(OBJS_DIR)/hashmap.o:hashmap/hashmap.c
	$(CC) -c $(CFLAGS) -o $(OBJS_DIR)/hashmap.o  hashmap/hashmap.c

$(OBJS_DIR)/hash_fcn.o:hashmap/hash_fcn.c
	$(CC) -c $(CFLAGS) -o $(OBJS_DIR)/hash_fcn.o  hashmap/hash_fcn.c

$(OBJS_DIR)/prime_table.o:hashmap/prime_table.c
	$(CC) -c $(CFLAGS) -o $(OBJS_DIR)/prime_table.o  hashmap/prime_table.c

$(OBJS_DIR)/conhash.o:conhash/conhash.c
	$(CC) -c $(CFLAGS) -o $(OBJS_DIR)/conhash.o  conhash/conhash.c

$(OBJS_DIR)/conhash_inter.o:conhash/conhash_inter.c
	$(CC) -c $(CFLAGS) -o $(OBJS_DIR)/conhash_inter.o  conhash/conhash_inter.c

$(OBJS_DIR)/conhash_util.o:conhash/conhash_util.c
	$(CC) -c $(CFLAGS) -o $(OBJS_DIR)/conhash_util.o  conhash/conhash_util.c

$(OBJS_DIR)/crc32.o:conhash/crc32.c
	$(CC) -c $(CFLAGS) -o $(OBJS_DIR)/crc32.o  conhash/crc32.c

$(OBJS_DIR)/util_rbtree.o:conhash/util_rbtree.c
	$(CC) -c $(CFLAGS) -o $(OBJS_DIR)/util_rbtree.o  conhash/util_rbtree.c

$(OBJS_DIR)/md5.o:crypt/md5.c
	$(CC) -c $(CFLAGS) -o $(OBJS_DIR)/md5.o  crypt/md5.c

$(OBJS_DIR)/3des.o:crypt/3des.c
	$(CC) -c $(CFLAGS) -o $(OBJS_DIR)/3des.o  crypt/3des.c

$(OBJS_DIR)/main.o:main.c
	$(CC) -c $(CFLAGS) -o $(OBJS_DIR)/main.o main.c 

$(OBJS_DIR)/ip_zone.o:ip_zone/ip_zone.c
	$(CC) -c $(CFLAGS) -o $(OBJS_DIR)/ip_zone.o ip_zone/ip_zone.c

$(OBJS_DIR)/_shm.o:utils/_shm.c
	$(CC) -c $(CFLAGS) -o $(OBJS_DIR)/_shm.o utils/_shm.c

$(OBJS_DIR)/_buffer.o:utils/_buffer.c
	$(CC) -c $(CFLAGS) -o $(OBJS_DIR)/_buffer.o utils/_buffer.c

$(OBJS_DIR)/server_conhash.o:server_conhash/server_conhash.c
	$(CC) -c $(CFLAGS) -o $(OBJS_DIR)/server_conhash.o server_conhash/server_conhash.c

$(OBJS_DIR)/rbtree.o:rbtree/rbtree.c
	$(CC) -c $(CFLAGS) -o $(OBJS_DIR)/rbtree.o rbtree/rbtree.c

$(OBJS_DIR)/udp.o:network/udp.c
	$(CC) -c $(CFLAGS) -o $(OBJS_DIR)/udp.o network/udp.c

$(OBJS_DIR)/network_util.o:network/network_util.c
	$(CC) -c $(CFLAGS) -o $(OBJS_DIR)/network_util.o network/network_util.c

$(OBJS_DIR)/tcp_server.o:network/tcp_server.c
	$(CC) -c $(CFLAGS) -o $(OBJS_DIR)/tcp_server.o network/tcp_server.c

$(OBJS_DIR)/tcp_client.o:network/tcp_client.c
	$(CC) -c $(CFLAGS) -o $(OBJS_DIR)/tcp_client.o network/tcp_client.c

clean:
	rm -f $(MAIN_EXE)
	rm -f $(OBJS) main.o libutils.a

install:
	mkdir -p /usr/local/include/utils
	install -m644 libutils.a         /usr/local/lib	
	install -m644 utils/*.h          /usr/local/include/utils
	install -m644 hashmap/hashmap.h  /usr/local/include/utils
	install -m644 hashmap/hash_fcn.h /usr/local/include/utils
	install -m644 conhash/conhash.h  /usr/local/include/utils
	install -m644 conhash/configure.h  /usr/local/include/utils
	install -m644 ip_zone/ip_zone.h  /usr/local/include/utils
	install -m644 server_conhash/server_conhash.h  /usr/local/include/utils
	install -m644 crypt/md5.h  /usr/local/include/utils
	install -m644 crypt/3des.h  /usr/local/include/utils
	install -m644 rbtree/rbtree.h  /usr/local/include/utils
	install -m644 network/udp.h  /usr/local/include/utils
	install -m644 network/network_util.h  /usr/local/include/utils
	install -m644 network/tcp_server.h  /usr/local/include/utils

uninstall:
	rm -f  /usr/local/lib/libutils.a
	rm -rf /usr/local/include/utils
