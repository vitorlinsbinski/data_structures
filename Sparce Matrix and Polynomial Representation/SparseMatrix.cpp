#include <iostream>

using namespace std;

struct Element {
    int i;
    int j;
    int x;
};

struct Sparse {
    int m;
    int n;
    int num;
    struct Element *e;
};

void create(struct Sparse *s) {
    printf("Enter dimensions: ");
    scanf("%d %d", &s -> m, &s -> n);

    printf("Enter number of non-zero elements: ");
    scanf("%d", &s -> num);

    s -> e = new Element[s -> num];

    printf("Enter all elements: \n");

    for(int i = 0; i < s -> num; i++) {
        scanf("%d %d %d", &s -> e[i].i, &s -> e[i].j, &s -> e[i].x);
    }
}

void display(struct Sparse s) {
    int i, j, k = 0;

    for(i = 0; i < s.m; i++) {
        for(j = 0; j < s.n; j++) {
            // Check if the coordinates from original matrix is equal to the currently matrix of non-zero elements
            if(i == s.e[k].i && j == s.e[k].j) {
                printf("%d ", s.e[k++].x);
            } else {
                printf("0 ");
            }
        }
        printf("\n");
    }
}

struct Sparse* add(struct Sparse *s1, struct Sparse *s2) {
    if(s1 -> m != s2 -> m || s1 -> n != s2 -> n) {
        return 0;
    }

    struct Sparse *sum;

    sum = new struct Sparse;

    sum -> m = s1 -> m;
    sum -> n = s1 -> n;
    sum -> e = new Element[s1 -> num + s2 -> num];

    int i = 0, j = 0, k = 0;

    while(i < s1 -> num && j < s2 -> num) {
        // Comparing row number elements
        if(s1 -> e[i].i < s2 -> e[j].i) {
            sum -> e[k++] = s1 -> e[i++];
        } else if(s1 -> e[i].i > s2 -> e[j].i) {
            sum -> e[k++] = s2 -> e[j++];
        } else { // The row number elements are equal in both
            // Comparing column number elements
            if(s1 -> e[i].j < s2 -> e[j].j) {
                sum -> e[k++] = s1 -> e[i++];
            } else if(s1 -> e[i].j > s2 -> e[j].j) {
                sum -> e[k++] = s2 -> e[j++];
            } else {
                sum -> e[k] = s1 -> e[i++];
                sum -> e[k++].x += s2 -> e[j++].x;
            }
        }
    }

    for(; i < s1 -> num; i++) {
        sum -> e[k++] = s1 -> e[i];
    }

    for(; j < s2 -> num; j++) {
        sum -> e[k++] = s2 -> e[j];
    }

    sum -> num = k;

    return sum;
};

int main() {
    struct Sparse s1;
    create(&s1);
    display(s1);

    struct Sparse s2;
    create(&s2);
    display(s2);

    struct Sparse *sum = add(&s1, &s2);
    cout << endl;
    display(*sum);


    return 0;
}
