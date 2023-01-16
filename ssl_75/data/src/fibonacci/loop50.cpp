int N;

int fib() {
    int arr[N+1];
    arr[0] = 0; arr[1] = 1;

    for (int i = 2; i <= N+1; i++) {
        arr[i] = arr[i-1] + arr[i-2];
    }
    return arr[N+1];
}


int main() {

    scanf("%d", &N);
    printf("%d\n", fib());

}

