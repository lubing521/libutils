#ifndef _PROPERTY_H_
#define _PROPERTY_H_
#include "_common.h"

/** 
 *        Name: property_read 
 * Description: read property file
 *   Parameter: file_name -> property file name.
 *              item_process_cb -> every item process callback.
 *              userp -> user data.
 *      Return: 1.  
 */
int property_read(char *file_name, int (*item_process_cb)(char *key, char *value, void *userp), 
                  void *userp);

/** 
 *        Name: property_set_comment_char
 * Description: 设置注释字符，默认#，如果c=0, 表示不处理注释行
 *   Parameter: c -> 注释字符.
 *
 *      Return: 
 */
void property_set_comment_char(char c);

#endif
