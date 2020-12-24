#include "linlib.cpp"

int main(){
    mat testmat = random_mat(3,3,5);
    print_mat(testmat);
    cout << endl;
    mat testmat2 = random_mat(3,3,5);
    print_mat(testmat2);
    cout << endl;
    print_mat(mat_times_mat(testmat,testmat2));
    return 0;
}

