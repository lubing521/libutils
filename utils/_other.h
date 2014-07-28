/*
 * =====================================================================================
 *
 *       Filename:  _util.h
 *
 *    Description:  没有归类的工具函数都放到在这儿了。
 *
 *        Version:  1.0
 *        Created:  2012年02月24日 11时23分01秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  聂汉子 (niehanzi), niehanzi@qiyi.com
 *        Company:  奇艺世纪
 *
 * =====================================================================================
 */
#ifndef _UTILS_H_
#define _UTILS_H_
#include "_common.h"

/** 
 *        Name: file_suffix
 * Description: get file name's suffix.
 *              for example: xxxxxx.mpg
 *              return .mpg.
 *   Parameter: file_name -> file name.
 *      Return: file name's suffix.
 */
char *file_suffix(char *file_name);

/** 
 *        Name: file_get_length
 * Description: get file's length.
 *   Parameter: file_name -> file name.
 *      Return: file length.
 */
off_t file_get_length(const char *file_name);

/** 
 *        Name: create_random
 * Description: generate a random number between 0 ~ max.
 *   Parameter: max -> random number <= max.
 *              
 *      Return: return a random number between 0 ~ max.
 */
int create_random(int max);

/** 
 *        Name: list_dir 
 * Description: list first level sub directory.
 *   Parameter: path -> directory path.
 *              callback -> every file in the directory, call callback. 
 *      Return: 1 -> list successflly.
 *              0 -> list failedly.
 */
int list_dir(char *path, void (*callback)(char *file_name)); 

/** 
 *        Name: create_dir 
 * Description: create directory, if directory exists, return.
 *   Parameter: path_name -> directory name.
 *              
 *      Return: 1 -> create successfully or directory exist.
 *              0 -> create failedly
 */
int create_dir(char *path_name);

/** 
 *        Name: file_exist
 * Description: 判断文件是否存在.
 *   Parameter: file_name -> file path
 *              
 *      Return: 1 -> 文件是否存在。 
 *              0 -> 文件不存在。
 */
int file_exist(char *file_name);

/** 
 *        Name: create_file
 * Description: 创建文件.
 *   Parameter: file_name -> file path
 *              size -> 文件大小
 *              
 *      Return: 1 -> 创建文件成功。 
 *              0 -> 创建文件失败。
 */
int create_file(char *file_name, size_t size);

/** 
 *        Name: create_file_if_not_existed
 * Description: 如果文件不存在,创建该文件.
 *   Parameter: file_name -> 文件名.
 *              
 *      Return: 1 -> 创建成功.
 *              0 -> 创建失败. 
 */
int create_file_if_not_existed(char *file_name);

/** 
 *        Name: remove_file
 * Description: 如果文件存在，删除它.
 *   Parameter: file_name -> 文件名.
 *              
 *      Return: 1 -> 删除成功.
 *              0 -> 删除失败. 
 */
int remove_file(char *file_name);

#endif
