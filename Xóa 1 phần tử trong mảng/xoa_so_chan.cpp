// Yêu cầu:
// 1. xóa số chẵn trong mảng

// bản chất của thuật toán xóa phần tử
// là ghi đè phần tử đằng sau vào phần tử đằng trước

#include <iostream>
#define SIZE 50
using namespace std;

// hàm xóa 1 phần tử ở vị trí bất kỳ trong mảng
// input: mảng, độ_dài, vị_trí
// output: mảng đã xóa thành công, đội dài bị giảm 1
void XoaPhanTu_ViTriBatKy(int mang[SIZE], int &do_dai, int vi_tri){
    for(; vi_tri < do_dai;){
        mang[vi_tri] = mang[vi_tri + 1];
        
        vi_tri = vi_tri + 1;
    }
    
    do_dai = do_dai - 1;
}

// hàm xóa số chẵn trong mảng
// tức là gặp điều kiện "mang[i] % 2 = 0" thì gọi hàm xóa
// input: mảng, độ_dài
// output: mảng đã xóa thành công, độ_dài thì bị giảm
void Xoa_So_Chan(int mang[SIZE], int &do_dai){
    int index = 0;
    
    for(; index < do_dai;){
        if(mang[index] % 2 == 0){
            // nếu chia hết cho 2 thì gọi hàm xóa phần tử
            // xóa ở vị trí index luôn
            XoaPhanTu_ViTriBatKy(mang, do_dai, index);

            // xóa xong rồi thì nó lại kiểm tra xem 
            // index bằng 0 mới có chia hết cho 2 không
        }
        else if(mang[index] % 2 != 0){
            // nếu không chia hết cho 2
            // thì mới tăng index lên để làm việc với phần tử đằng sau
            index = index + 1;
        }
    }
}

int main(){
    // fake nhập n
    int n = 5;

    // tạo mảng
    int arr[SIZE] = {1, 2, 3, 4, 5};

    //hiển thị mảng ban đầu
    cout << "mang ban dau:\n";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << "  ";
    }
    cout << "\n";
    
    Xoa_So_Chan(arr, n);
    // hiển thị mảng sau khi xóa tất cả số chẵn
    cout << "\nmang sau khi xoa so chan la:\n";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << "  ";
    }

    cout << "\ndo dai: " << n;

    cout << "\n\n";

    return 0;
}