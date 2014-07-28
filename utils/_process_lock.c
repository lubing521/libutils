/*
 * =====================================================================================
 *
 *       Filename:  semaphore.c
 *
 *    Description:  封装进程间同步的信号灯操作。 
 *
 *        Version:  1.0
 *        Created:  06/11/2012 02:01:48 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  聂汉子 (niehanzi), niehanzi@qiyi.com
 *        Company:  奇艺世纪
 *
 * =====================================================================================
 */
#include "_process_lock.h"

union semun {
    int val;                    /*  value for SETVAL */
    struct semid_ds *buf;       /*  buffer for IPC_STAT & IPC_SET */
    unsigned short *array;      /*  array for GETALL & SETALL */
    struct seminfo *__buf;      /*  buffer for IPC_INFO */   //test!!
    void *__pad;
};

process_lock_t *process_lock_create(char *file, int sub_id){
    process_lock_t *pm = NULL; 

    /* 为进程锁分配空间 */
    pm = (process_lock_t *)malloc(sizeof(process_lock_t));
    if(NULL == pm){
        printf("malloc for processt_t instance failed.\n");
        goto error;
    }

    /* 为进程锁创建key */
    pm->key = ftok(file, sub_id);
    if(-1 == pm->key){
        perror("ftok for process mutex failed");
        goto error;
    }

    /* 创建进程锁 */
    pm->id = semget(pm->key, 1, IPC_CREAT);
    if(-1 == pm->id){
        perror("semget failed");
        goto error;
    }

    return pm;

error:
    if(pm){
        free(pm);
    }
    return NULL;
}

/* 初始化进程锁 */
int process_lock_init(process_lock_t *pm){
    union semun sem_val;

    sem_val.val = 1; 
    if(-1 == semctl(pm->id, 0, SETVAL, sem_val)){
        perror("semctl failed");
        return 0;
    }

    return 1;
}

int process_try_lock(process_lock_t *pm){
    struct sembuf p = {0, -1, IPC_NOWAIT | SEM_UNDO};
    int result = 0;

    result = semop(pm->id, &p, 1);
    if(result == -1){
        if(errno == EAGAIN){
            return 0;
        }
        else{
            perror("semop try lock failed.");
            return -1;
        }
    }

    return 1;
}

int process_lock(process_lock_t *pm){
    struct sembuf p = {0, -1, SEM_UNDO};

    if(semop(pm->id, &p, 1) == -1){
        //perror("semop for lock failed");
        return 0;
    }

    return 1;
}

int process_unlock(process_lock_t *pm){
    struct sembuf v = {0, 1, SEM_UNDO};

    if(semop(pm->id, &v, 1) == -1){
        //perror("semop for unlock failed");
        return 0;
    }

    return 1;
}

int process_lock_release(process_lock_t **pm){
    if(NULL == pm || NULL == *pm){
        return 1;
    }
    
    free(*pm);
    *pm = NULL;
    return 1;
}

int process_lock_delete(process_lock_t *pm){
    if(-1 == semctl(pm->id, 1, IPC_RMID)){
        perror("delete global sem failed");
        return 0;
    }

    return 1;
}

#ifdef PROCESS_LOCK_TEST
int main(void)
{
    process_lock_t *lock = NULL;

    lock = process_acquire("/var/va_server/test.lck", 0);
    if(NULL == lock){
        return 0;
    }

    process_lock_init(lock);
    process_try_lock(lock);
    process_try_lock(lock);
    process_lock(lock);
    process_try_lock(lock);
    process_unlock(lock);
    process_try_lock(lock);

    process_lock_release(&lock);
    return 1;
}
#endif
