#ifndef MANAGER_H
#define MANAGER_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct st_class {
    int code;
    char name[30];
    int unit;
    int grading;
};

extern char kname[2][10];

int loadData(struct st_class* c[]);
void printAllClasses(struct st_class* c[], int csize);
void findClasses(char* name, struct st_class* c[], int csize);
void saveAllClasses(struct st_class* c[], int csize);

int addNewClass(struct st_class* c[], int csize);
void editClass(struct st_class* c[], int csize);

int applyMyClasses(int my[], int msize, struct st_class* c[], int csize);
void printMyClasses(int my[], int msize, struct st_class* c[], int csize);
void saveMyClass(int my[], int msize, struct st_class* c[], int csize);

#endif