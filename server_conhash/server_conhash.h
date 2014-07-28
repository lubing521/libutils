/*
 * =====================================================================================
 *
 *       Filename:  server_conhash.h
 *
 *    Description:  存储所有IDC机房的一致性哈希实例 
 *
 *        Version:  1.0
 *        Created:  10/16/2012 03:24:03 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  聂汉子 (niehanzi), niehanzi@qiyi.com
 *        Company:  奇艺世纪
 *
 * =====================================================================================
 */
#ifndef _SERVER_CONHASH_H_
#define _SERVER_CONHASH_H_
#include "utils.h"
#include "conhash.h"
#include "hashmap.h"

typedef struct _server_conhash_t {
    hashmap_t *conhashs; /* IDC一致性哈希实例哈希表 */
    hashmap_t *ips;  /* 存储haship到ip的映射 */
}server_conhash_t;

/** 
 *        Name: server_conhash_create
 * Description: 创建server_conhash_t实例.
 *   Parameter: lua_file lua文件
 *      Return: 返回server_conhash_t实例
 *              NULL -> 创建失败.
 */
server_conhash_t *server_conhash_create(char *lua_file);

/** 
 *        Name: server_conhash_destroy
 * Description: 销毁实例.
 *   Parameter: server_hash.
 *      Return: 
 */
void server_conhash_destroy(server_conhash_t **server_conhash);

/** 
 *        Name: server_conhash_find
 * Description: 根据IDC ID和url得到相应的Server的IP.
 *   Parameter: group -> IDC ID.
 *              url -> 视频URL.
 *      Return: 
 */
char *server_conhash_find(server_conhash_t *server_conhash, int group_id, char *url);

#endif
