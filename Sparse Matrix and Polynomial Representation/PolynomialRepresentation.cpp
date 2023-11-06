#include <iostream>

using namespace std;

#include <cmath>

struct Term {
    int coeff;
    int exp;
};

struct Poly {
    int n;
    struct Term *t;
};

int polySum(struct Poly P, int x) {
    int i;
    int sum = 0;

    for(i = 0; i < P.n; i++) {
        sum += P.t[i].coeff * pow(x, P.t[i].exp);
    }

    return sum;
}

Poly *additionPoly(struct Poly p1, struct Poly p2) {
    int i = 0, j = 0, k = 0;

    struct Poly *p3;
    p3 = new Poly;
    p3 -> t = new Term[p1.n + p2.n];

    while(i < p1.n && j < p2.n) {
        if(p1.t[i].exp == p2.t[j].exp) {
            p3 -> t[k].exp = p1.t[i].exp;
            p3 -> t[k++].coeff = p1.t[i++].coeff + p2.t[j++].coeff;
        } else if(p1.t[i].exp > p2.t[j].exp) {
            p3 -> t[k++] = p1.t[i++];
        } else if(p1.t[i].exp < p2.t[j].exp) {
            p3 -> t[k++] = p2.t[j++];
        }
    }

    for(; i < p1.n; i++) {
        p3 -> t[k++] = p1.t[i];
    }

    for(; j < p2.n; j++) {
        p3 -> t[k++] = p2.t[j];
    }

    p3 -> n = k;

    return p3;

}

void printPoly(struct Poly p) {
    for(int i = 0; i < p.n; i++) {
        cout << p.t[i].coeff << "x^" << p.t[i].exp << " + ";
    }

    cout << endl;
}

int main() {
    struct Poly P1;
    printf("Enter number of non-zero terms: ");
    scanf("%d", &P1.n);

    P1.t = new Term[P1.n];

    for(int i = 0; i < P1.n; i++) {
        printf("Write term number %d: ", i + 1);
        scanf("%d %d", &P1.t[i].coeff, &P1.t[i].exp);
    }

    printPoly(P1);

    //cout << polySum(P, 4);

    struct Poly P2;
    printf("Enter number of non-zero terms: ");
    scanf("%d", &P2.n);

    P2.t = new Term[P2.n];

    for(int i = 0; i < P2.n; i++) {
        printf("Write term number %d: ", i + 1);
        scanf("%d %d", &P2.t[i].coeff, &P2.t[i].exp);
    }

    printPoly(P2);

    struct Poly *P3;
    P3 = additionPoly(P1, P2);

    printPoly(*P3);

    return 0;
}
