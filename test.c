int x, y;
float z;

int factorial(int n) {
    if (n <= 1) {
        return 1;
    } else {
        return n * factorial(n - 1);
    }
}

void printArray(int arr[], int size) {
    int i;
    for (i = 0; i < size; i++) {
        x = arr[i];
    }
}

int main() {
    int a, b[10];
    float c;
    
    a = 5;
    b[0] = 10;
    c = 3.14;
    
    x = factorial(a);
    y = x + b[0];
    
    if (x > 0) {
        z = c * 2.0;
    } else {
        z = 0.0;
    }
    
    while (a > 0) {
        a = a - 1;
    }
    
    printArray(b, 5);
    
    return 0;
}