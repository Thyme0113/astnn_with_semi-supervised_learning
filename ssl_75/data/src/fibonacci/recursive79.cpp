int fib[1000000];

int solve(int a){
    if(fib[a])return fib[a];
    if(!fib[a-2])fib[a-2] = solve(a-2);
    if(!fib[a-1])fib[a-1] = solve(a-1);
    return fib[a-1]+fib[a-2];
}

int main(int argc, const char * argv[]) {
    
    fill(fib, fib+1000000, 0);
    fib[0] = 1;
    fib[1] = 1;
    int num; cin >> num;
    cout << solve(num) << endl;
    
    return 0;
}

