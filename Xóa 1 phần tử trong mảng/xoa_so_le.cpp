// Yêu cầu:
// 1. xóa số lẻ trong mảng

#include <iostream>
#define SIZE 50
using namespace std;

// hàm xóa 1 phần tử ở vị trí bất kỳ trong mảng
// input: 
// 1. mảng
// 2. độ_dài (tham chiếu)
// 3. vị_trí

// output:
// 1. mảng đã xóa thành công
// 2. độ_dài bị giảm đi 1
void XoaPhanTu_O_ViTriBatKy(int mang[SIZE], int &do_dai, int vi_tri){
    while(vi_tri < do_dai){
        mang[vi_tri] = mang[vi_tri + 1];

        vi_tri = vi_tri + 1;
    }

    do_dai = do_dai - 1;
}

// hàm xóa tất cả các số lẻ trong mảng
// input:
// 1. mảng
// 2. độ_dài

// output:
// 1. mảng đã xóa thành công tất cả số lẻ
// 2. độ dài thì bị giảm đi
void Ham_Xoa_So_Le(int mang[SIZE], int &do_dai){
    int index = 0;

    while(index < do_dai){
        if(mang[index] % 2 != 0){
            // nếu không chia hết cho 2 thì gọi hàm xóa phần tử
            XoaPhanTu_O_ViTriBatKy(mang, do_dai, index);
        }
        else if(mang[index] % 2 == 0){
            // nếu cái vị trí đấy không chia hết cho 2
            // thì mới tăng index để làm việc với phần tử tiếp theo
            index = index + 1;
        }
    }
}

int main(){
    // fake nhập n
    int n = 5;

    // tạo mảng
    int arr[SIZE] = {1, 2, 3, 4, 5};

    // hiển thị mảng ban đầu
    cout << "mang ban dau:\n";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << "  ";
    }

    // gọi hàm xóa hết số lẻ trong mảng
    Ham_Xoa_So_Le(arr, n);

    // hiển thị mảng sau khi xóa
    cout << "\n\nmang sau khi xoa la:\n";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << "  ";
    }

    cout << "\ndo dai: " << n;

    cout << "\n\n";

    return 0;
}