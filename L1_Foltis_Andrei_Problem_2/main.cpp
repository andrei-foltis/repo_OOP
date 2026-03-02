#include <iostream>

bool isprime(int x) {
    if (x<2) {
        return false;
    }
    for (int i=2; i<=x/2; i++) {
        if (x%i==0) {
            return false;
        }
    }
    return true;
}

void generate_prime(int n) {
    int i=2;
    while (n>0) {
        while (true){
            if (isprime(i)) {
                std::cout<<i<<" ";
                i++;
                break;
            }
            else {
                i++;
            }
        }
        n--;
    }
}



bool relativ_prime(int a, int b) {
    for (int i=2; i<=a && i<=b; i++) {
        if (a%i==0 && b%i==0) {
            return false;
        }
    }
    return true;
}
void print_array(int v[], int n) {
    for (int i=0; i<n; i++) {
        std::cout<<v[i]<<" ";
    }
    std::cout<<"\n";
}

void teilfolge(int v[], int n){
    int current_len=1;
    int current_st_pos=0;
    int st_pos=-1;
    int max_len=0;
    for (int i=0; i<n-1; i++) {
        if (relativ_prime(v[i+1],v[i])) {
            current_len++;
        }
        else {
            if (current_len>max_len) {
                st_pos=current_st_pos;
                max_len=current_len;
            }
            current_len=1;
            current_st_pos=i+1;
        }
    }
    if (current_len>max_len) {
        st_pos=current_st_pos;
        max_len=current_len;
    }
    int* myarray = new int [n];
    for (int i=0; i<max_len; i++) {
        myarray[i]=v[st_pos+i];
    }
    print_array(myarray, max_len);
    delete[] myarray;
}

void point_a() {
    int n;
    std::cout<<"enter number n\n";
    std::cin>>n;
    generate_prime(n);
}

void point_b() {
    int len;
    std::cout<<"enter array length\n";
    std::cin>>len;
    int* vec = new int[len];
    for (int i=0; i<len; i++) {
        std::cin>>vec[i];
    }
    teilfolge(vec, len);
    delete[] vec;
}

int main(){
    point_a();
    point_b();
}