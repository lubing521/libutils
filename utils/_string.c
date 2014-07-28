/*
 * =====================================================================================
 *
 *       Filename:  _string.c
 *
 *    Description:  字符串工具处理函数
 *
 *        Version:  1.0
 *        Created:  07/13/2012 11:13:44 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  聂汉子 (niehanzi), niehanzi@qiyi.com
 *        Company:  奇艺世纪
 *
 * =====================================================================================
 */
#include "_string.h"

int is_comment(char *str, char comment_char){
    if(NULL == str){
        return 0;
    }   

    while(*str != '\0'){
        if(*str == '\t' || *str == ' '){
            str++;
            continue;
        }   
        if(*str == comment_char){
            return 1;
        }   
        else{
            return 0;
        }   
    }
    return 0;
}

int is_blank(char *str){
    if(NULL == str){
        return 1;
    }

    while('\0' != *str){
        if(' ' != *str && '\t' != *str && '\r' != *str && '\n' != *str){
            return 0;
        }
        str++;
    }

    return 1;
}

char* trim_str(char *str){
    int str_len = 0;
    char *res = str;

    if(NULL == str){
        return NULL;
    }

    str_len = strlen(res);
    while(*res == ' ' || *res == '\t'){
        res++;
    }

    str += str_len  - 1;
    while(*str == '\t' || *str == '\r' || *str == '\n' || *str == ' '){
        *str = '\0';
        str--;
    }

    return res;
}

void delete_comment(char *str, char comment_char){
    if(NULL == str){
        return ;
    }

    while(*str != '\0'){
        if(*str == comment_char)
            *str = '\0';
        str++;
    }
}

int char_at(char *str, char c){
    int i = 0;

    if(NULL == str){
        return -1;
    }

    while(str[i] != '\0'){
        if(str[i] == c){
            return i;
        }
        i++;
    }

    return -1;
}

void split_url(char *url, char *path, int path_size, char *name, int name_size){
    int   str_len = 0;
    char *ptr     = NULL;
    char *end     = NULL;
    int   copy_len = 0;

    bzero(path, path_size);
    bzero(name, name_size);
    if(NULL == url){
        return;
    }

    if(path_size <= 0 || name_size <= 0){
        return;
    }
    
    str_len = strlen(url); 
    if(0 == str_len){
        return;
    }

    ptr = url + str_len - 1;
    end = url + str_len;
    if('/' == *ptr){
        strncpy(path, url, path_size - 1);
        return;
    }

    while(url <= ptr){
        if('/' == *ptr){
            copy_len = ptr - url + 1;
            if(copy_len > path_size -1){
                copy_len = path_size - 1;
            }
            memcpy(path, url, copy_len);

            copy_len = end - (ptr + 1);
            if(copy_len > name_size - 1){
                copy_len = name_size - 1;
            }
            memcpy(name, ptr + 1, copy_len);
            return;
        }

        ptr--;
    }

    strncpy(name, url, name_size - 1);
    return;
}

int str_cmp(char *str1, int size1, char *str2, int size2)
{
    int cmp_size = size1 < size2 ? size1:size2;
    int result = memcmp(str1, str2, cmp_size); 
    if(result != 0){
        if(result < 0){
            return -1;
        }
        else{
            return 1;
        }
    }
    else{
        if(size1 == size2){
            return 0;
        }
        if(size1 > size2){
            return 1; 
        }
        else{
            return -1;
        }
    }
}

