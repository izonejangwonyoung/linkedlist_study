//#define  _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//
//
//
//int point = 0, times = 1;
//
//int Gencode[4] = { 1,0,0,1 };
//
//int get = 0;
//
//int code[14];
//
//int arr1[14];
//
//int tmp[5] = { 9,9,9,9,9 };
//
//
//
//int main()
//
//
//{
//    printf("Please, type 4 - bit generation code : ");
//
//
//    // for (int i = 0; i < 4; i++) {
//    //      scanf("%1d", &Gencode[i]);
//    // }
//
//
//    //파일에서 코드 가져오기
//
//    FILE* f = fopen("data.txt", "r");
//
//    fscanf(f, "%d", &get);
//
//    for (int i = 9; i >= 0; i--)
//
//    {
//
//        code[i] = get % 10;
//
//        get /= 10;
//
//    }
//
//    fclose(f);
//
//
//
//    printf("code[] = ");
//
//    for (int i = 0; i < 14; i++) {
//
//        printf("%d", code[i]);
//
//    }
//
//
//
//    //1번째 계산
//
//
//
//    printf("\n%d번째 계산 : ", times);
//
//    for (int i = 0; i < 4; i++) {
//
//        printf("%d", Gencode[i] ^ code[i]);
//
//        arr1[i] = (Gencode[i] ^ code[i]);
//
//    }
//
//
//
//    printf("\n\n계산한 arr1[] = ");
//
//    for (int i = 0; i < 4; i++)
//
//        printf("%d", arr1[i]);
//
//
//
//
//
//    for (int i = 0; i < 4; i++) {
//
//        if (arr1[i] == 1) { point = i; break; }
//
//    }
//
//
//
//    printf("\n최종 arr1[] = ");
//
//    for (int i = point; i < point + 4; i++) {
//
//        if (arr1[i] == 9) arr1[i] = code[i];
//
//        printf("%d", arr1[i]);
//
//    }
//
//
//
//    printf("\npoint = %d\n", point);
//
//
//
//    //n번째 계산
//
//    while (point < 11) {
//
//        times++;
//
//        int a = 0;
//
//        printf("\n%d번째 계산 : ", times);
//
//        for (int i = point; i < point + 4; i++) {
//
//            arr1[i] = (Gencode[a] ^ arr1[i]);
//
//            a++;
//
//        }
//
//
//
//        int b = 0;
//
//        printf("\n\n계산한 arr1[] = ");
//
//        for (int i = point; i < point + 4; i++) {
//
//            printf("%d", arr1[i]);
//
//            tmp[b] = arr1[i];
//
//            b++;
//
//        }
//
//
//
//        for (int i = point; i < point + 4; i++) {
//
//            if (arr1[i] == 1) { point = i; break; }
//
//        }
//
//
//
//
//
//        printf("\npoint = %d\n", point);
//
//
//
//        printf("최종 arr1[] = ");
//
//        for (int i = point; i < point + 4; i++) {
//
//            if (arr1[i] == 9) arr1[i] = code[i];
//
//            printf("%d", arr1[i]);
//
//        }
//
//        printf("\n\n\n\n");
//
//    }
//
//
//
//    //파일로 출력
//
//    FILE* out;
//
//    out = fopen("CRC code.txt", "w");
//
//
//
//    printf("\n\n\nThe data with CRC is ");
//
//    fprintf(out, "\n\n\nThe data with CRC is ");
//
//    for (int i = 0; i < 10; i++) {
//
//        printf("%d", code[i]);
//
//        fprintf(out, "%d", code[i]);
//
//    }
//
//
//
//    for (int i = 0; i < 4; i++) {
//
//        printf("%d", tmp[i]);
//
//        fprintf(out, "%d", tmp[i]);
//
//    }
//
//    printf("\n\n\n");
//
//
//
//    return 0;
//
//}
