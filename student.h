#ifndef STUDENT_H
#define STUDENT_H

struct students {
    int id;
    char name[30];
    char department[30];
    int flag;
};

void add();
void view();
void update();
void delete();
void display();

#endif // STUDENT_H
