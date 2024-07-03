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

// Newton's Method로 f'(x) = 0을 만족하는 x 찾기
double newtonsMethod(double a, double b, double c, double d, double e) {
    double x = 0; // 초기 추정값
    for (int i = 0; i < 100; ++i) {
        double fx = df(x, a, b, c, d);
        double dfx = ddf(x, a, b, c);
        if (fabs(dfx) < 1e-6) break; // 0으로 나누기 방지
        double x_next = x - fx / dfx;
        printf("current x_next = %lf\n", x_next);
        if (fabs(x_next - x) < 1e-6) break; // 수렴 조건
        x = x_next;
    }
    return x;
}

int main() {
    double a, b, c, d, e;
    printf("Enter coefficients a, b, c, d, e for the polynomial ax^4 + bx^3 + cx^2 + dx + e: ");
    scanf_s("%lf %lf %lf %lf %lf", &a, &b, &c, &d, &e);

    double x_min = newtonsMethod(a, b, c, d, e);
    printf("Minimum (or maximum) at x = %lf, f(x) = %lf\n", x_min, f(x_min, a, b, c, d, e));
    return 0;
}