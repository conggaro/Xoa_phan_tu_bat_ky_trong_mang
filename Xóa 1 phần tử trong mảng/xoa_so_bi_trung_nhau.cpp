// Yêu cầu:
// 1. xóa số bị trùng nhau trong mảng

// Chú ý: 
// thuật toán xóa số trùng nhau chỉ áp dụng cho mảng đã được
// sắp xếp theo chiều tăng dần (từ bé đến lớn)

#include <iostream>
#define SIZE 50
using namespace std;

// hàm xóa 1 phần tử ở vị trí bất kỳ
// input:
// 1. mảng
// 2. độ_dài (tham chiếu)
// 3. vị_trí

// output:
// 1. mảng đã xóa thành công
// 2. độ_dài bị giảm đi 1
void XoaPhanTu_O_ViTriBatKy(int mang[SIZE], int &do_dai, int vi_tri){
    // việc bây giờ là lấy phần tử đằng sau
    // ghi đè lên phần tử đăng trước
    while(vi_tri < do_dai){
        mang[vi_tri] = mang[vi_tri + 1];

        vi_tri = vi_tri + 1;
    }

    do_dai = do_dai - 1;
}

// hàm xóa phần tử trùng nhau
// input:
// 1. mảng
// 2. độ_dài (tham chiếu)

// output:
// 1. mảng đã xóa số bị trùng nhau
// 2. độ dài đã bị giảm đi
void Xoa_So_Bi_Trung_Nhau(int mang[SIZE], int &do_dai){
    int index = 0;
    
    while(index < do_dai){
        if(mang[index] == mang[index + 1]){
            // nếu phần tử đằng trước bằng phần tử đằng sau
            // thì gọi hàm xóa phần tử ở vị trí bất kỳ
            XoaPhanTu_O_ViTriBatKy(mang, do_dai, index);
        }
        else if(mang[index] != mang[index + 1]){
            // nếu số đằng trước khác số đằng sau
            // thì tăng index để làm việc với số đằng sau
            index = index + 1;
        }
    }
}

int main(){
    // fake nhập n
    int n = 8;

    // tạo mảng
    // fake mảng đã được sắp xếp
    int arr[SIZE] = {1, 2, 3, 3, 3, 3, 4, 5};

    // hiển thị mảng ban đàu
    cout << "mang ban dau:\n";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << "  ";
    }
    cout << "\ndo dai: " << n;
    
    // gọi hàm xóa số trùng nhau
    Xoa_So_Bi_Trung_Nhau(arr, n);

    // hiển thị mảng sau khi xóa số trùng nhau
    cout << "\n\nmang sau khi xoa so bi trung nhau la:\n";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << "  ";
    }
    cout << "\ndo dai: " << n;

    cout << "\n\n";

    return 0;
}