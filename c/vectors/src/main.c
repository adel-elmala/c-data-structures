#include "vector.h"
#include <limits.h>




void prettyPrint(void* vec);

int main(int argc, char** argv)
{

    void* vecA = createVector(5);

    prettyPrint(vecA);

    printf("size is: %lu\n",size(vecA));
    printf("capacity is: %lu\n",capacity(vecA));
    printf("Empty?: %d\n",is_empty(vecA));



    int a = 111;
    push(vecA,&a);
    prettyPrint(vecA);

    printf("size is: %lu\n",size(vecA));
    printf("capacity is: %lu\n",capacity(vecA));
    printf("Empty?: %d\n",is_empty(vecA));

 
    int b = 222;
    push(vecA,&b);
    prettyPrint(vecA);

    printf("size is: %lu\n",size(vecA));
    printf("capacity is: %lu\n",capacity(vecA));
    printf("Empty?: %d\n",is_empty(vecA));

    
    int c = 333;
    push(vecA,&c);
    prettyPrint(vecA);

    printf("size is: %lu\n",size(vecA));
    printf("capacity is: %lu\n",capacity(vecA));
    printf("Empty?: %d\n",is_empty(vecA));

    
    int d = 444;
    push(vecA,&d);
    prettyPrint(vecA);

    printf("size is: %lu\n",size(vecA));
    printf("capacity is: %lu\n",capacity(vecA));
    printf("Empty?: %d\n",is_empty(vecA));
    
    
    int e = 555;
    push(vecA,&e);
    prettyPrint(vecA);

    printf("size is: %lu\n",size(vecA));
    printf("capacity is: %lu\n",capacity(vecA));
    printf("Empty?: %d\n",is_empty(vecA));
    
    int f = 666;
    push(vecA,&f);
    prettyPrint(vecA);

    printf("size is: %lu\n",size(vecA));
    printf("capacity is: %lu\n",capacity(vecA));
    printf("Empty?: %d\n",is_empty(vecA));
    
    int l = 777;
    insert(vecA,6,&l);
    
    prettyPrint(vecA);

    printf("size is: %lu\n",size(vecA));
    printf("capacity is: %lu\n",capacity(vecA));
    printf("Empty?: %d\n",is_empty(vecA));
    
    int g = 888;
    prepend(vecA,&g);
    
    prettyPrint(vecA);

    printf("size is: %lu\n",size(vecA));
    printf("capacity is: %lu\n",capacity(vecA));
    printf("Empty?: %d\n",is_empty(vecA));
    
    size_t last = size(vecA) ;
    // test pop
    printf("pop!\n");
    for(size_t i = 0;i != last;++i){
        fprintf(stdout,"%d\t",pop(vecA));
    } 
    fprintf(stdout,"\n");

    prettyPrint(vecA);

    printf("size is: %lu\n",size(vecA));
    printf("capacity is: %lu\n",capacity(vecA));
    printf("Empty?: %d\n",is_empty(vecA));



    int r = 111;
    push(vecA,&r);
    prettyPrint(vecA);

    printf("size is: %lu\n",size(vecA));
    printf("capacity is: %lu\n",capacity(vecA));
    printf("Empty?: %d\n",is_empty(vecA));

    delete(vecA,0);
    prettyPrint(vecA);

    printf("size is: %lu\n",size(vecA));
    printf("capacity is: %lu\n",capacity(vecA));
    printf("Empty?: %d\n",is_empty(vecA));
    
    pop(vecA);
    prettyPrint(vecA);

    printf("size is: %lu\n",size(vecA));
    printf("capacity is: %lu\n",capacity(vecA));
    printf("Empty?: %d\n",is_empty(vecA));
    
    

    destroyVector(vecA);

}



void prettyPrint(void* vec){

    fprintf(stdout,"\n[");
    for(size_t i = 0; i < capacity(vec); ++i){
        if(i%5 == 0 && i != 0)
            fprintf(stdout,"\n");
        
        // replace this with the appropriate printing function for complex data-structres
        fprintf(stdout,"%d\t",at_all(vec,i));
    }
    
    fprintf(stdout,"]\n");

}
