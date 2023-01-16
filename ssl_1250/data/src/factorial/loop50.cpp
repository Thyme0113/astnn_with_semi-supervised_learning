int f(int n) {
    int r = 1;
    for (int i = 0; i < (int)(n); i++) {
        r *= i+1;
    }
    
    return r;
}

int main() {
    int n;
    scanf("%d", &n);
    cout << f(n) << endl;
    return 0;
}
