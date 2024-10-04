#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 1000

// 선택 정렬 함수
void selectionSort(int list[], int n) {
    int i, j, minIndex, temp;

    for (i = 0; i < n - 1; i++) {
        minIndex = i;  // 현재 위치를 최소값 인덱스로 설정
        for (j = i + 1; j < n; j++) {
            if (list[j] < list[minIndex]) {
                minIndex = j;  // 최소값 인덱스 업데이트
            }
        }
        // 최소값과 현재 위치의 원소 교환
        temp = list[minIndex];
        list[minIndex] = list[i];
        list[i] = temp;
    }
}

int main() {
    int list[MAX_SIZE];
    int n = MAX_SIZE;
    int s_num = 201916871;  // 본인의 학번
    int seed = s_num % 1000;  // 학번의 마지막 3자리 사용
    srand(seed);  // seed 설정

    // 배열 데이터 생성
    for (int i = 0; i < n; i++) {
        list[i] = rand() % 100000;  // 0부터 99999 사이의 랜덤 값 생성
    }

    long repetitions;
    double duration;
    clock_t start;

    // i) list[0] ~ list[9] 소팅 시간 출력
    printf("i) list[0] ~ list[9] 소팅 시간:\n");
    for (int index = 0; index < 10; index++) {
        int tempList[10];

        repetitions = 0;
        start = clock(); // 시간 측정 시작
        do {
            repetitions++;
            // 최악의 경우 데이터를 초기화
            for (int j = 0; j < 10; j++) {
                tempList[j] = 10 - j;  // 10부터 1까지의 값으로 초기화
            }

            selectionSort(tempList, index);  // 선택 정렬 수행
        } while ((clock() - start) < 1000);  // 시간 확보를 위한 반복

        duration = ((double)(clock() - start)) / CLOCKS_PER_SEC;
        duration /= repetitions;  // 반복 횟수에 따른 평균 시간 계산

        printf("list[%d] = %.9f 초\n", index, duration);  // 줄 바꿈 추가
    }
    printf("\n");

    // ii) list[500] ~ list[509] 소팅 시간 출력
    printf("ii) list[500] ~ list[509] 소팅 시간:\n");
    for (int index = 500; index < 510; index++) {
        int tempList[10];

        repetitions = 0;
        start = clock(); // 시간 측정 시작
        do {
            repetitions++;
            // 최악의 경우 데이터를 초기화
            for (int j = 0; j < 10; j++) {
                tempList[j] = 510 - j;  // 510부터 501까지의 값으로 초기화
            }

            selectionSort(tempList, index);  // 선택 정렬 수행
        } while ((clock() - start) < 1000);  // 시간 확보를 위한 반복

        duration = ((double)(clock() - start)) / CLOCKS_PER_SEC;
        duration /= repetitions;  // 반복 횟수에 따른 평균 시간 계산

        printf("list[%d] = %.9f 초\n", index, duration);  // 줄 바꿈 추가
    }
    printf("\n");

    // iii) list[990] ~ list[999] 소팅 시간 출력
    printf("iii) list[990] ~ list[999] 소팅 시간:\n");
    for (int index = 990; index < 1000; index++) {
        int tempList[10];

        repetitions = 0;
        start = clock(); // 시간 측정 시작
        do {
            repetitions++;
            // 최악의 경우 데이터를 초기화
            for (int j = 0; j < 10; j++) {
                tempList[j] = 1000 - j;  // 1000부터 991까지의 값으로 초기화
            }

            selectionSort(tempList, index);  // 선택 정렬 수행
        } while ((clock() - start) < 1000);  // 시간 확보를 위한 반복

        duration = ((double)(clock() - start)) / CLOCKS_PER_SEC;
        duration /= repetitions;  // 반복 횟수에 따른 평균 시간 계산

        printf("list[%d] = %.9f 초\n", index, duration);  // 줄 바꿈 추가
    }

    return 0;
}
