#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void bubblesort(char names[100][100], int n){
    for(int i = 0; i < n - 1; i++){
        for(int j = 0; j < n - i - 1; j++){
            if(strcmp(names[j], names[j + 1]) > 0){
                char temp[100];
                strcpy(temp, names[j]);
                strcpy(names[j], names[j + 1]);
                strcpy(names[j + 1], temp);
            }
        }
    }
}

int binarysearch(char names[100][100], int n, char *x){
    int l = -1, r = n;
    while(r - l > 1){
        int m = l + (r - l)/2;
        if(strcmp(names[m], x) <= 0) l = m;
        else r = m;
    }
    return (l >= 0 && strcmp(names[l], x) == 0)? l: -1;
}

int main(){
    char names[100][100];
    FILE *fp = fopen("studentname.txt", "r");
    if(!fp){
        printf("error\n");
        return 0;
    }

    int num = 0;
    while(fscanf(fp, "%s", names[num]) == 1){
        num++;
    }
     
    fclose(fp);
    bubblesort(names, num);

    printf("Sorted names: \n");
    for(int i = 0; i < num; i++){
        printf("%s\n", names[i]);
    }

    char searchname[100];
    printf("enter name to search: ");
    scanf("%s", searchname);
    int result = binarysearch(names, num, searchname); 

    if(result != -1){
        printf("found at position %d\n", result);
    }
    else{
        printf("not found\n");
    }

    return 0;
}
