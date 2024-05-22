#include <stdio.h>
#include <math.h>

// 원본 다항식 f(x) = ax^4 + bx^3 + cx^2 + dx + e
double f(double x, double a, double b, double c, double d, double e) {
    return a * pow(x, 4) + b * pow(x, 3) + c * pow(x, 2) + d * x + e;
}

// f(x)의 첫 번째 미분 f'(x)
double df(double x, double a, double b, double c, double d) {
    return 4 * a * pow(x, 3) + 3 * b * pow(x, 2) + 2 * c * x + d;
}

// f'(x)의 미분 f''(x)
double ddf(double x, double a, double b, double c) {
    return 12 * a * pow(x, 2) + 6 * b * x + 2 * c;
}

double dddf(double x, double a, double b) {
    return 24 * a * x + 6 * b;
}

// Newton's Method로 f'(x) = 0을 만족하는 x 찾기
double newtonsMethod(double start, double a, double b, double c, double d, double e) {
    double x = start, x_next, post_x;
    do {
        double fx = df(x, a, b, c, d);
        double dfx = ddf(x, a, b, c);
        printf("\ndf %lf and ddf %lf", fx, dfx);
  /*      if (fabs(dfx) < 1e-6) break;*/
        x_next = x - fx / dfx;
        printf("\nnew x is %lf", x);
        post_x = x;
        x = x_next;
    } while (x_next - post_x > 0.000001);

    //double x = start;
    //for (int i = 0; i < 100; ++i) {
    //    double fx = df(x, a, b, c, d);
    //    double dfx = ddf(x, a, b, c);
    //    printf("\ndf %lf and ddf %lf", fx, dfx);
    //    if (fabs(dfx) < 1e-6) break; // 0으로 나누기 방지
    //    double x_next = x - fx / dfx;
    //    if (fabs(x_next - x) < 1e-6) break; // 수렴 조건
    //    printf("\nnew x is %lf", x_next);
    //    x = x_next;
    //}
    return x;
}

//double findmin(double a, double b, double c, double d, double e) {
//    double x[3] = { 0 };
//    double mp = -6 * b / (24 * a);
//    printf("mp : %lf\n", mp);
//    double p1 = newtonsMethod(mp - 10, 12 * a, 6 * b, 2 * c, 0, 0);
//    double p2 = newtonsMethod(mp + 10, 12 * a, 6 * b, 2 * c, 0, 0);
//    printf("1p : %lf   2p : %lf\n", p1, p2);
//    x[0] = newtonsMethod(p1 - 10, 4 * a, 3 * b, 2 * c, d, 0);
//    x[1] = newtonsMethod((p1+p2)/2, 4 * a, 3 * b, 2 * c, d, 0);
//    x[2] = newtonsMethod(p2 + 10, 4 * a, 3 * b, 2 * c, d, 0);
//    double minx = x[0];
//    for (int i = 1; i < 3; i++) {
//        if (f(x[i], a, b, c, d, e) < f(minx, a, b, c, d, e))
//            minx = x[i];
//    }
//
//    return minx;
//}

int main() {
    double a, b, c, d, e;
    printf("Enter coefficients a, b, c, d, e for the polynomial ax^4 + bx^3 + cx^2 + dx + e: ");
    scanf_s("%lf %lf %lf %lf %lf", &a, &b, &c, &d, &e);

    //double x_min = findmin(a, b, c, d, e);
    double x_min = newtonsMethod(0,a, b, c, d, e);
    printf("Minimum (or maximum) at min = %lf, f(x) = %lf\n", x_min, f(x_min, a, b, c, d, e));
    return 0;
}