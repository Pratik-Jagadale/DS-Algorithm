#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define success 1

typedef int ret_t;

struct vector_int{
	int* p_arr;
	int size;
};

struct vector_int* create_vector_int(); //returns malloced array
void show_vector(struct vector_int* p_vec);
ret_t destroy_vec(struct vector_int* p_vec);
ret_t push_back(struct vector_int* p_vec, int);

int main(){

	int ret ;
	struct vector_int* vec = NULL;
	 vec = create_vector_int();
	
	for(int i = 0; i < 5 ; i++)
		push_back(vec, i*10 );
	
	show_vector(vec);
	ret = destroy_vec(vec);
	if(ret != success )
		printf("vector does not destroyed succesfully\n");
	return (EXIT_SUCCESS);
}

struct vector_int* create_vector_int(){
	struct vector_int* p_vec = NULL;
 	p_vec = (struct vector_int*)malloc(sizeof(struct vector_int));
 	assert(p_vec != NULL);
 	p_vec->p_arr = NULL;
 	p_vec->size = 0;	
 	return (p_vec);
}

void show_vector(struct vector_int* p_vec){
	if(p_vec->size == 0 ){
		printf("Array is empty...\n");
		return ;
	}

	for(int i = 0 ; i < p_vec->size ; i++)
		printf("%d :[%d]\n",i ,p_vec->p_arr[i] );
}

ret_t destroy_vec(struct vector_int* p_vec){

	if(p_vec->size == 0){
		free(p_vec);
		p_vec = NULL;
		return success;
	}
	free(p_vec->p_arr);
	p_vec->p_arr = NULL;
	free(p_vec);
	p_vec= NULL;
	return success;
}

ret_t push_back(struct vector_int* p_vec, int num){

	p_vec->size = p_vec->size + 1; 
	p_vec->p_arr = realloc(p_vec->p_arr ,p_vec->size * sizeof(int));
	assert(p_vec->p_arr != NULL);

	p_vec->p_arr[p_vec->size - 1] = num;

	return success;
}

