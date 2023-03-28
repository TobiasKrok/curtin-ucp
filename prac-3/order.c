void ascending2(int *x, int *y) {

    if(*x > *y) {
        int temp;
        temp = *x;

        *x = *y;
        *y = temp;
    }
}

void ascending3(int *x, int *y, int *z) {

    ascending2(x, y);

    if(*y > *z) {
        ascending2(y, z);
    }
}

void descending3(int *x, int *y, int *z) {

    int temp1;
    int temp2;

    ascending3(x, y, z);

    temp1 = *x;
    temp2 = *y;
    
    *z = temp1;
    *y = temp2;
    *x = *z;
}
