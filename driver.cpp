#include "linlib.cpp"

int main(){
    mat testmat = random_mat(3,3,5);
    print_mat(testmat);
    vl test = {1,2,3};
    print_mat(test);
    print_mat(mat_times_vector(testmat,test));
    return 0;
}

