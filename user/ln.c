#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

int main(int argc, char *argv[])
{
  if (argc == 4 && strcmp(argv[2], "-s"))
  {
    if (symlink(argv[2], argv[3]) < 0){
      fprintf(2, "symbol link %s %s: failed\n", argv[2], argv[3]);
    } else
      exit(0);
  }
  if (argc == 3)
  { 
    if(link(argv[1], argv[2])<0){
      fprintf(2, "link %s %s: failed\n", argv[1], argv[2]);
    }else
    exit(0);
  }
    fprintf(2, "For hard like: in old new\n For symbol link: ln -s old new");
    exit(1);
}
