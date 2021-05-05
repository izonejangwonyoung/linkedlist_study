//#include <stdio.h>
//#include <string.h>
//
//struct employee {
//    char name[10];
//    int year;
//    int pay;
//};//구조체 선언
//
//void main() {//구조체 변수 선언
//    struct employee Lee;
//    struct employee *Sptr = &Lee; //포인터 선언(포인터Sptr은 Lee의 주소를 저장한다. Lee과 같은 자료형으로 선언.)
//    strcpy(Sptr->name, "손현아");//데이터 항목 지정, Sptr->name = (*Sptr).name
//    Sptr->year = 2015; //Sptr->year = (*Sptr).year
//    Sptr->pay = 5990; //Sptr->pay = (*Sptr).pay
//
//    printf("\n이름 : %s", Sptr->name);
//    printf("\n입사 : %d", Sptr->year);
//    printf("\n연봉 : %d", Sptr->pay);
//
//    getchar();
//}
/* Call by value - function to swap */

