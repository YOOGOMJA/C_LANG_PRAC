#include <stdio.h>
#include <stdlib.h>

int main(){

    // 문자열 
    // 문자열은 문자로 이루어진 배열
    // 1. 문자열의 선언 
    char str_1[5] = { 'h' , 'e' , 'l', 'l' ,'o' };
    char str_2[5] = "hello";
    char str_3[] = "hello";
    
    // 2. 출력
    printf("length : %lu , content : [" , (sizeof(str_1) / sizeof(char)));
    for(int i = 0 ; i < 5; i++){
        printf("%c" , str_1[i]);
        if(i == 4) printf("]\n"); 
    }

    printf("length : %lu , content : [%s]\n" ,(sizeof(str_2) / sizeof(char)), str_2);

    printf("length : %lu , content : [%s]\n" ,(sizeof(str_3) / sizeof(char)) , str_3);
    // 3. 문자열을 입력받기 

    
    // 4. string.h의 사용



    return 0;
}