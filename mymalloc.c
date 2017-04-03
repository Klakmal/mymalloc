#include "mymalloc.h"

char ram[sz] = {'\0'};

void *MyMalloc(size_t size)
{
	if(ram[0] == '\0'){
	//	printf("start\n");
		ram[0]='i';
		ram[1]='f';
		*(int*)(&ram[2]) = 24994;
	//	printf("Initialized\n");
	}
	
	int i=1;
	while(1){
		if(i<=25000){
		
			if ((ram[i] == 'f') && (*(int*)(&ram[i + 1]) >= (size))){
	            ram[i] = 'a';
				
			
				int curSize = *(int*)(&ram[i+1]);
		    	int leftSize = curSize - (size + 5);
		    	
		    	
		    	if (leftSize > 5) {
		            *(int*)(&ram[i+1]) = size;
		 		//	printf("allocated :%d",size);
		 			
		 			
		            int next = i + 5 + size;
		          //  printf("\nnext:%d\n", next);
		 
		            ram[next] = 'f';
		            *(int*)(&ram[next + 1]) = leftSize;
		            
		        }else if(leftSize >0){
		        	*(int*)(&ram[i+1]) = size+leftSize;
		        //	printf("\nno next. given size is %d",size+leftSize); //ithuru gaana + nam ekath allocate ekata ekathu karala daanawa
				}
				else{
				//	printf("full\n");
				}
				
		      //  printf("\nEnd of MyMalloc1\n");
		        return (void*)(&ram[i+5]);
	        }
			else{
				i += *(int*)(&ram[i + 1]) + 5;
			}
		
		}else{
		//	printf("Memmory is not enough!\n");
            return 0;
		}
	}
}


void MyFree(void* find){
//	printf("start of MyFree\n");
	int i = 1;
    int pre = 0;
    
    while(1){
    	if (i > 25000) {
       //     printf("no space\n");
            break;
        }
    	
    	if ((void*)(&ram[i+5]) == find){
       //     printf("found\n");
            ram[i] = 'f';
            int post = i + 5 + *(int*)(&ram[i + 1]); //check whether next aloocations is f or a
            
           
            if (ram[post] == 'f') {
                
                *(int*)(&ram[i + 1]) = *(int*)(&ram[i + 1]) + 5 + *(int*)(&ram[post + 1]);
                
            }
            if (ram[pre] == 'f') {
               
                *(int*)(&ram[pre + 1]) = *(int*)(&ram[pre + 1]) + 5 + *(int*)(&ram[i + 1]);
                
            }
            
    	
          //  printf("free space - %d",*(int*)(&ram[i + 1]));
            break;
    	
    	
		}else {
            pre = i;
            i += *(int*)(&ram[i + 1]) + 5;
        }
	}
}
