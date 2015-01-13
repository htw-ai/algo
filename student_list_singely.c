/** @file student_list_singely.h
 *  @brief implements linked list sinely structure
 *
 *  @author Frederik Dudzik (doodzik)
 *  @bug No know bugs.
 */

#include "student_list.h"
#ifndef DOUBLE_LINKED_LIST

#include <stdlib.h>
#include <string.h>
#include "student.h"
#include "student_list_singely.h"


StudentList* initStudentList ()
{
    StudentList* head = (StudentList*) malloc(sizeof(StudentList));
    StudentList* tail = (StudentList*) malloc(sizeof(StudentList));
    //if (head == 0L) return EXIT_FAILURE;
    tail->next = 0L;
    head->next = tail;
    head->sentientEnd = tail;
    return head;
}

void push (StudentList* sl, Student* s)
{
    StudentList* nNew = (StudentList*) malloc(sizeof(StudentList));
    StudentList* node = sl;
    nNew->student = s;
    nNew->next = sl->sentientEnd;
    while (node->next->next != 0L ) {
        node = node->next;
    }
    node->next = nNew;
}

void unshift (StudentList* sl, Student* s)
{
  StudentList* slNew = (StudentList*) malloc(sizeof(StudentList));
  slNew->student = s;
  slNew->next = sl->next;
  sl->next = slNew;
}

int destroy (StudentList* sl, int stundent_id)
{
    StudentList* node = sl;
    StudentList* lastNode = node;
    while (node->next->next != 0L)
    {
        node = node->next;
        if (node->student->id == stundent_id) {
            lastNode->next = node->next;
            free(node->student);
            free(lastNode);
            return 0;
        }
        lastNode = node;
    }
    return 0;
}

void destroyList (StudentList** sl)
{
    StudentList* node = (*sl)->next;
    StudentList* nOld = 0L;
    while (node->next->next != NULL)
    {
        nOld = node;
        node = node->next;
        free(nOld->student);
        free(nOld);
    }
    (*sl)->next = (*sl)->sentientEnd;
}

#endif /* DOUBLE_LINKED_LIST */
