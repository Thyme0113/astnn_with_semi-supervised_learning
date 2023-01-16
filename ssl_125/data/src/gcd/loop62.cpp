int main(void) {
    int x,y;
    cin >> x >> y;
    if (x<=y)
        swap(x,y);
    while (x%y!=0){
        x %= y;
        swap(x,y);
    }

    cout << y << endl;

    return 0;
}
