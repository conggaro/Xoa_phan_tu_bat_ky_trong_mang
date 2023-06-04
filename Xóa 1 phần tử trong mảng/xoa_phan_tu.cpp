// Yêu cầu:
// 1. xóa phần tử ở vị trí bất kỳ

#include <iostream>
#define SIZE 50
using namespace std;

// hàm xóa phần tử ở vị trí bất kỳ trong mảng
// input: mảng, độ_dài, vị_trí
// output: xóa phần tử trong mảng thành công, và làm cho độ_dài giảm đi 1

// bản chất của thuật toán là lấy phần tử đằng sau ghi đè lên phần tử đằng trước
// ghi đè xong hết rồi thì "độ_dài = độ_dài - 1"

void XoaPhanTu(int mang[SIZE], int &do_dai, int vi_tri){
    for (; vi_tri < do_dai;)
    {
        mang[vi_tri] = mang[vi_tri + 1];
        
        vi_tri = vi_tri + 1;
    }
    
    do_dai = do_dai - 1;
}

int main(){
    // fake nhập vào n
    int n = 5;

    // cho mảng 
    int arr[SIZE] = {1, 2, 3, 4, 5};

    // fake nhập vào vị trí
    int index = 2;

    // hiển thị mảng ban đầu
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << "  ";
    }
    cout << "\n\n";

    XoaPhanTu(arr, n, index);

    // hiển thị mảng sau khi xóa
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << "  ";
    }
    cout << "\n\n";

    return 0;
}