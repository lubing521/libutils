#include <utils/ip_zone.h>
#include <utils/utils.h>


int main(int argc, char **argv) 
{
    ip_zones_t *ip_zones = NULL;    

    if (argc != 2) {
        printf("please input ip lib file\n");
        return 1;
    }
    ip_zones = ip_zones_load(argv[1]);

    ip_zones_destroy(&ip_zones);
    return 0;
}
