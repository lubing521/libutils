/*
 * =====================================================================================
 *
 *       Filename:  unix_socket_udp_server.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  01/07/2013 11:44:59 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  聂汉子 (niehanzi), niehanzi@qiyi.com
 *        Company:  奇艺世纪
 *
 * =====================================================================================
 */
#include <utils/udp.h>

#define UNIX_DOMAIN_PATH "/tmp/unix_domain_path_server.sock"

int main(void) 
{
    int sock_fd = -1;
    char buffer[1024];
    int bytes_recv = -1;
    
    log_set_level(LOG_LEVEL_DEBUG);

    sock_fd = udp_unix_socket_create(UNIX_DOMAIN_PATH);
    if (sock_fd < 0) {
        log_error("udp_unix_socket_create failed.");
        return 0;
    }

    set_non_blocking(sock_fd); 
    while(1) {
        bzero(buffer, sizeof(buffer));
        bytes_recv = udp_unix_socket_recv(sock_fd, buffer, sizeof(buffer) - 1);
        if (bytes_recv > 0) {
            log_debug("%d %s", bytes_recv, buffer);
        }
        else {
            log_info("no data received.");
        }
    }

    udp_unix_socket_close(sock_fd); 

    return 1;
}
