#include <cstdio>
#include <cmath>

int main() {
    int t;
    double u, v, w, U, V, W;
    double a, b, c, d, X, Y, Z, x, y, z;

    scanf("%d", &t);
    while (t--) {
        scanf("%lf%lf%lf%lf%lf%lf", &U, &W, &v, &V, &w, &u);
        X = (w-U+v)*(U+v+w);
        x = (U-v+w)*(v-w+U);
        Y = (u-V+w)*(V+w+u);
        y = (V-w+u)*(w-u+V);
        Z = (v-W+u)*(W+u+v);
        z = (W-u+v)*(u-v+W);
        a = sqrt(x*Y*Z);
        b = sqrt(y*Z*X);
        c = sqrt(z*X*Y);
        d = sqrt(x*y*z);
        double result = sqrt((-a+b+c+d)*(a-b+c+d)*(a+b-c+d)*(a+b+c-d))/(192*u*v*w);

        printf("%.4lf\n", result);
    }
    return 0;
}
