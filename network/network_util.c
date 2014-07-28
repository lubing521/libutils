/*
 * =====================================================================================
 *
 *       Filename:  network_util.c
 *
 *    Description:  网络编程工具代码
 *
 *        Version:  1.0
 *        Created:  01/07/2013 03:50:45 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  聂汉子 (niehanzi), niehanzi@qiyi.com
 *        Company:  奇艺世纪
 *
 * =====================================================================================
 */
#include "network_util.h"

int set_non_blocking(int sock_fd){
    int opts;
    opts = fcntl(sock_fd,F_GETFL);
    if(opts < 0){
        log_error("fcntl(sock_fd,GETFL), %s", strerror(errno));
        return 0;
    } 

    opts = opts | O_NONBLOCK;
    if(fcntl(sock_fd,F_SETFL,opts)<0){
        log_error("fcntl(sock_fd,SETFL,opts), %s", strerror(errno));
        return 0;
    } 

    return 1;
}

int set_reuse_addr(int sock_fd){
    int opt_val       = 1;
    socklen_t opt_len = sizeof(int);
    int ret;
    
    ret = setsockopt(sock_fd, SOL_SOCKET, SO_REUSEADDR, &opt_val, opt_len);
    return ret < 0 ? 0 : 1;
}

int nic_get_ip(char *name, char *ip, int ip_size)
{
    int fd = -1; 
    struct ifreq ifr;

    bzero(ip, ip_size);

    fd = socket(AF_INET, SOCK_DGRAM, 0);
    if (fd < 0) {
        log_error("nic_get_addr: create socket failed.");
        return 0;
    }

    ifr.ifr_addr.sa_family = AF_INET;
    strcpy(ifr.ifr_name , name);

    ioctl(fd, SIOCGIFADDR, &ifr);
    strncpy(ip, inet_ntoa(((struct sockaddr_in *)&ifr.ifr_addr)->sin_addr), ip_size - 1);   

    return 1;
}
