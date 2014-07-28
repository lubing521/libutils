/*
 * =====================================================================================
 *
 *       Filename:  unix_socket_udp_client.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  01/07/2013 11:44:52 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  聂汉子 (niehanzi), niehanzi@qiyi.com
 *        Company:  奇艺世纪
 *
 * =====================================================================================
 */
#include <utils/udp.h>

#define UNIX_DOMAIN_PATH "/tmp/unix_domain_path_client.sock"
#define UNIX_DOMAIN_SERVER_PATH "/tmp/unix_domain_path_server.sock"

int main(void) 
{
    int sock_fd = -1;
    
    log_set_level(LOG_LEVEL_DEBUG);
    sock_fd = udp_unix_socket_create(UNIX_DOMAIN_PATH);
    if (sock_fd == -1) {
        printf("udp_unix_socket_create failed.");
        return 0;
    }

    set_non_blocking(sock_fd); 
    while(1) {
        int bytes_sent = -1;
        bytes_sent = udp_unix_socket_send(sock_fd, UNIX_DOMAIN_SERVER_PATH, "hello", sizeof("hello") - 1);

        log_debug("bytes_sent: %d", bytes_sent);
    }

    udp_unix_socket_close(sock_fd); 

    return 1;
}

