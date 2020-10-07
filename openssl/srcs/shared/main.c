#include "md5.h"
#include "sha256.h"

int main(int argc, char **argv) 
{ 
    t_block       block;
    t_sha         sha;
    int           fd;

    //init_md5(&block);
    //md5(argv[1], &block);

    init_sha256(&sha);
    sha256(argv[1], &sha);
    return 0; 
}  