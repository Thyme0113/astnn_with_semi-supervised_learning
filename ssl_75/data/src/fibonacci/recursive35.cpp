int memo[100];
int fibonacci( int a )
{
    if( a == 0 || a == 1 )
        return memo[0] = memo[1] = 1;
    else
    {
        if( memo[a] != 0 )
            return memo[a];
        else
            return memo[a] = fibonacci( a - 1 ) + fibonacci( a - 2 );
    }
}

int main()
{
    int n;
    
    cin >> n;

    cout << fibonacci(n) << endl;

    return 0;
}

