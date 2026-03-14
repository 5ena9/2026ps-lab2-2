#include <time.h>
#include "manager.h"

int main(void) {
    int no; 
    struct st_class* classes[50]; 
    int myclass[10]; 
    int mycount = 0; 

    srand(time(0));
    int count = loadData(classes);
    printf("> Load %d classes.\n", count);

    while(1){
        printf("\n> Menu 1.List 2.Add 3.Modify 4.Search 5.Apply 6.My classes 7.Save 0.Quit\n");
        printf(">> Menu? > ");
        if(scanf("%d", &no) <= 0) break;

        if(no == 1) { 
            printf("> 1.Class list (%d classes)\n", count);
            printAllClasses(classes, count);
        }
        else if(no == 2) { 
            printf("> 2.Add a Class\n");
            count = addNewClass(classes, count);
        }
        else if(no == 3) { 
            printf("> 3.Modify a Class\n");
            editClass(classes, count);
        }
        else if(no == 4) {
            printf("> 4.Search a Class\n");
            printf(">> Enter class name > ");
            char name[30];
            scanf("%s", name);
            findClasses(name, classes, count);
        }
        else if(no == 5) {
            printf("> 5.Apply a class\n");
            mycount = applyMyClasses(myclass, mycount, classes, count);
            printf("%d classes has been applied.\n", mycount);
        }
        else if(no == 6) {
            printf("> 6.My classes\n");
            printMyClasses(myclass, mycount, classes, count);
        }
        else if(no == 7) {
            printf("> 7.Save\n");
            saveMyClass(myclass, mycount, classes, count);
            saveAllClasses(classes, count);
            printf("\n> All files were saved.\n");
        }
        else break;
    }
    return 0;
}