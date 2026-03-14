#include "manager.h"

char kname[2][10] = {"A+~F", "P/F"};

int loadData(struct st_class* c[]){
    int count=0;
    FILE* file;
    file=fopen("classes.txt", "r");
    if(file == NULL) return 0;

    while(!feof(file)){
        c[count] = (struct st_class*)malloc(sizeof(struct st_class));
        int r = fscanf(file, "%d %s %d %d", &(c[count]->code), c[count]->name, &(c[count]->unit), &(c[count]->grading));
        if(r < 4) break;
        count++;
    }
    fclose(file);
    return count;
}

void printAllClasses(struct st_class* c[], int csize){
    for(int i=0; i<csize; i++){
        printf("[%d] %s [credit %d - %s]\n", c[i]->code, c[i]->name, c[i]->unit, kname[c[i]->grading-1]);
    }
}

void findClasses(char* name, struct st_class* c[], int csize){
    int count = 0;
    printf("Searching (keyword : %s)\n", name);
    for(int i=0; i<csize; i++){
        if(strstr(c[i]->name, name)){
            printf("[%d] %s [credit %d - %s]\n", c[i]->code, c[i]->name, c[i]->unit, kname[c[i]->grading-1]);
            count++;
        }
    }
    printf("%d classes found.\n", count);
}

void saveAllClasses(struct st_class* c[], int csize){
    FILE* file;
    file = fopen("classes.txt", "w");
    for(int i=0; i<csize; i++){
        fprintf(file, "%d %s %d %d\n", c[i]->code, c[i]->name, c[i]->unit, c[i]->grading);
    }
    fclose(file);	
}

int addNewClass(struct st_class* c[], int csize){
    int code;
    int is_duplicate;

    while(1) {
        is_duplicate = 0;
        printf(">> code number > ");
        scanf("%d", &code);

        for(int i = 0; i < csize; i++) {
            if(c[i]->code == code) {
                printf(">> Code duplicated! Retry.\n");
                is_duplicate = 1;
                break;
            }
        }

        if(is_duplicate == 0) break;
    }

    struct st_class* p = (struct st_class*)malloc(sizeof(struct st_class));
    p->code = code;
    
    printf(">> class name > ");
    scanf("%s", p->name);
    printf(">> credits > ");
    scanf("%d", &(p->unit));
    printf(">> grading (1: A+~F, 2: P/F) > ");
    scanf("%d", &(p->grading));

    c[csize] = p;
    return csize + 1;
}

void editClass(struct st_class* c[], int csize){
    int code;
    struct st_class* p = NULL;
    printf(">> Enter a code of class > ");
    scanf("%d", &code);
    
    for(int i=0; i<csize; i++){
        if(c[i]->code == code){
            p = c[i];
            break;
        }
    }

    if(p == NULL){
        printf("> No such class.\n");
        return;
    }
    
    printf("> Current: [%d] %s [credits %d - %s]\n", p->code, p->name, p->unit, kname[p->grading-1]);
    printf("> Enter new class name > ");
    scanf("%s", p->name);
    printf("> Enter new credits > ");
    scanf("%d", &(p->unit));
    printf("> Enter new grading(1:Grade, 2: P/F) > ");
    scanf("%d", &(p->grading));

    printf("> Modified.\n");
}

int applyMyClasses(int my[], int msize, struct st_class* c[], int csize){
    return msize;
}

void printMyClasses(int my[], int msize, struct st_class* c[], int csize){
}

void saveMyClass(int my[], int msize, struct st_class* c[], int csize){
}