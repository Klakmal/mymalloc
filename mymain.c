#include "mymalloc.c"

 
int main(int argc, char const *argv[])
{
    
 
    char* x = (char*)MyMalloc(24983);
    MyFree((void*)x );
    //char* y = (char*)MyMalloc(112);
    //char* z = (char*)MyMalloc(25);
    
   // MyFree((void*)z );
    //MyFree((void*)y );
   

    return 0;
}
