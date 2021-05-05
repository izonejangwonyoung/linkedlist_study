//#include <stdio.h>
//#include <stdlib.h>
//
//struct NODE {
//    int data;
//    struct NODE *ptr;
//};
//
//void addto(struct NODE *target, int data) {
//    struct NODE *new = malloc(sizeof(struct NODE));
//    new->ptr = target->ptr;
//    new->data = data;
//    target->ptr = new;
//}
//
//int main() {
//    struct NODE *head = malloc(sizeof(struct NODE));
//    head->ptr = NULL;
//
//
//    struct NODE *node1 = malloc(sizeof(struct NODE));
//    head->ptr = node1;
//    node1->data = 40;
//
//    struct NODE *node2 = malloc(sizeof(struct NODE));
//    node1->ptr = node2;
//    node2->data = 50;
//
//    addto(head, 30);
//    addto(head, 20);
//    addto(head, 10);
//
//
//    struct NODE *curr = head->ptr;
//    while (curr != NULL) {
//        printf("%d\n", curr->data);
//        curr = curr->ptr;
//    }
//
//    return 0;
//}