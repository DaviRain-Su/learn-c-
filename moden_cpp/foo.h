// foo.h
#ifdef __cplusplus
extern "C" {
#endif

int add(int x, int y);

#ifdef __cplusplus
}
#endif 

//foo.c
int add(int x, int y){
    return x + y;
}
