/* `#include <bits/stdc++.h>` is a header file that includes all the standard library headers. It is
not a standard header file and is not guaranteed to be available on all systems. */
#include <bits/stdc++.h>
#include <string>

using namespace std;

const int MAX = 100;

/**
 * The above code defines a struct named "KhachHang" with two data members (Name and Age) and two
 * member functions (NhapThongTin and XuatThongTin) to input and output customer information.
 * @property {string} Name - A string variable that stores the name of a customer.
 * @property {int} Age - Age is an integer variable that stores the age of a customer in the KhachHang
 * struct.
 */
struct KhachHang{
    string Name;
    int Age;
    
    void NhapThongTin(){
        cin.ignore();
        cout<<"\n\n\t\t\tNHAP THONG TIN KH";
        cout<<"\nTen KH: "; getline(cin, Name);
        cout<<"Tuoi: "; cin>>Age;
    }

    void XuatThongTin(){
        cout<<"\n\n\t\t\tTHONG TIN KH";
        cout<<"\nTen KH: "<<Name;
        cout<<"\nTuoi: "<<Age;
    }
};
/**
 * The above code defines a C++ struct named "PhuongTien" that contains information about a vehicle,
 * including its name, engine displacement, and cost, and includes functions to input and output this
 * information.
 * @property {string} Name - A string variable that stores the name of a vehicle.
 * @property {int} phankhoi - It is a variable of type integer that represents the engine displacement
 * (in cubic centimeters) of a vehicle.
 * @property {double} cost - The cost of the vehicle in dollars.
 */
struct PhuongTien{
    string Name;
    int phankhoi;
    double cost;

    void NhapThongTin(){
        cin.ignore();
        cout<<"\n\n\t\t\tNHAP THONG TIN XE";
        cout<<"\nTen xe: "; getline(cin, Name);
        cout<<"Phan khoi: "; cin>>phankhoi;
        cout<<"Gia:  $"; cin>>cost;
    }

    void XuatThongTin(){
        string HangXe;
        HangXe = Name.substr(0, 2);
        cout<<"\n\n\t\t\t THONG TIN XE";
        cout<<"\nTen xe: "<<Name;
        cout<<"\nHang: "<<HangXe;
        cout<<"\nPhan khoi: "<<phankhoi<<"cc";
        cout<<"\nGia:  $"<<fixed<<setprecision(2)<<cost;
    }
};

void NhapThongTin(KhachHang *&KH, PhuongTien *&PT , int numberouskh, int numberouspt);
void XuatThongTin(KhachHang *&KH, PhuongTien *&PT , int numberouskh, int numberouspt);
void DieuChinhSoLuong(KhachHang *&KH, PhuongTien *&PT , int &numberouskh, int &numberouspt);
void ThemThongTin(KhachHang *&KH, PhuongTien *&PT , int &numberouskh, int &numberouspt);
void XoaThongTin(KhachHang *&KH, PhuongTien *&PT , int &numberouskh, int &numberouspt);


/**
 * The function creates arrays of customers and vehicles, prompts the user for the number of each,
 * inputs information for each, adjusts the quantity of each, and then deletes the arrays.
 */
int main(){
    system("cls");
    KhachHang* KH = new KhachHang[MAX];
    PhuongTien* PT = new PhuongTien[MAX];

    int numberous, numberourss;
    cout<<"So luong KH muon co: "; 
    cin>>numberous;
    cout<<"So luong PT muon co: ";
    cin>>numberourss;

    NhapThongTin(KH, PT, numberous, numberourss);
    // XuatThongTin(KH, PT, numberous, numberourss);
    DieuChinhSoLuong(KH, PT, numberous, numberourss);

    delete[] KH;
    delete[] PT;
}



/**
 * The function allows for adjusting the number of customers and vehicles by adding or deleting
 * information and then displays the updated information.
 * 
 * @param KH a pointer to an array of objects of type KhachHang (customer)
 * @param PT a pointer to an array of PhuongTien objects
 * @param numberouskh The number of customers (KhachHang) in the system.
 * @param numberouspt It is a variable that stores the number of PhuongTien (vehicles) in the system.
 */
void DieuChinhSoLuong(KhachHang *&KH, PhuongTien *&PT , int &numberouskh, int &numberouspt){
    cout<<"\n\n\n1. Them";
    cout<<"\n2. Xoa";
    cout<<"\n3. Thoat";
    cout<<"\nLua chon: ";
    
    int choice; cin>>choice;

    switch (choice){
        case 1: 
            ThemThongTin(KH, PT, numberouskh, numberouspt);
        break;
        case 2:
            XoaThongTin(KH, PT, numberouskh, numberouspt);
        break;
    }
    XuatThongTin(KH, PT, numberouskh, numberouspt);
}
/**
 * The function allows the user to input information for either a customer or a vehicle, based on their
 * choice.
 * 
 * @param KH a pointer to an array of KhachHang objects
 * @param PT an array of objects of type PhuongTien (which could be a class representing vehicles)
 * @param numberouskh The number of KhachHang objects to be created or the size of the array of
 * KhachHang objects.
 * @param numberouspt The variable "numberouspt" is likely the number of PhuongTien (vehicles) that the
 * user wants to input information for.
 */
void NhapThongTin(KhachHang *&KH, PhuongTien *&PT , int numberouskh, int numberouspt){
    cout<<"\n1. NhapThongTin KH";
    cout<<"\n2. NhapThongTin Phuongtien";
    cout<<"\n3. Thoat";
    cout<<"\nLua chon: ";

    int choice;

    cin>>choice;

    switch (choice){
    case 1:
        for (int i=0; i<numberouskh; ++i)
            KH[i].NhapThongTin();
        break;
    case 2:
        for (int i=0; i<numberouspt; ++i)
            PT[i].NhapThongTin();
        break;
    case 3:
        break;
    }
}
/**
 * The function allows the user to choose between displaying information about customers or vehicles,
 * and then displays the chosen information.
 * 
 * @param KH a pointer to an array of objects of type KhachHang (customer)
 * @param PT An array of objects of the class PhuongTien, which represents vehicles.
 * @param numberouskh The number of KhachHang objects in the array KH.
 * @param numberouspt The variable "numberouspt" is likely the number of "PhuongTien" objects in the
 * program. It is used in the function "XuatThongTin" to loop through and display information about
 * each "PhuongTien" object.
 */
void XuatThongTin(KhachHang *&KH, PhuongTien *&PT , int numberouskh, int numberouspt){
    system("cls");
    cout<<"\n1. XuatThongTin KH";
    cout<<"\n2. XuatThongTin Phuongtien";
    cout<<"\n3. Thoat";
    cout<<"\nLua chon: ";

    int choice;

    cin>>choice;

    switch (choice){
    case 1:
        for (int i=0; i<numberouskh; ++i)
            KH[i].XuatThongTin();
        break;
    case 2:
        for (int i=0; i<numberouspt; ++i)
            PT[i].XuatThongTin();
        break;
    case 3:
        break;
    }
}
/**
 * The function allows the user to add information about a customer or a vehicle to the respective
 * arrays.
 * 
 * @param KH a pointer to an array of KhachHang objects
 * @param PT an array of objects of type PhuongTien (transportation vehicles)
 * @param numberouskh The number of existing KhachHang objects in an array before adding a new one. It
 * is passed by reference so that it can be updated after adding a new KhachHang object.
 * @param numberouspt The variable "numberouspt" is an integer that stores the current number of
 * "PhuongTien" objects in the program. It is passed as a reference to the function "ThemThongTin" so
 * that the function can update its value as new "PhuongTien" objects
 */
void ThemThongTin(KhachHang *&KH, PhuongTien *&PT , int &numberouskh, int &numberouspt){
    cout<<"\n\n\n1. Them KH";
    cout<<"\n2. Them PT";
    cout<<"\n3. Thoat";
    cout<<"\nLua chon: ";
    
    int choice; cin>>choice;

    switch (choice){
        case 1:
            KH[numberouskh++].NhapThongTin();
            numberouskh++;
        break;
        case 2:
            PT[numberouspt++].NhapThongTin();
            numberouspt++;
        break;
    }
}
/**
 * The function allows the user to delete information of a customer or a vehicle from the system.
 * 
 * @param KH a pointer to an array of KhachHang objects (customers)
 * @param PT A pointer to an array of PhuongTien objects.
 * @param numberouskh The number of existing KhachHang (customers) in the system.
 * @param numberouspt The variable "numberouspt" is likely used to store the number of "PhuongTien"
 * objects currently in the system.
 */
void XoaThongTin(KhachHang *&KH, PhuongTien *&PT , int &numberouskh, int &numberouspt){
    cout<<"\n\n\n1. Xoa KH";
    cout<<"\n2. Xoa PT";
    cout<<"\n3. Thoat";
    cout<<"\nLua chon: ";
    
    int choice; cin>>choice;
    string name;

    switch (choice){
        case 1:
            cout<<"Ten KH muon xoa: "; cin.ignore(); getline(cin, name);
            for (int i=0; i<numberouskh; ++i)
                if (KH[numberouskh].Name == name){
                    KH[numberouskh] = KH[numberouskh+1];
                    numberouskh--;
                } else cout<<"Khong ton tai";
        break;
        case 2:
            cout<<"Ten PT muon xoa: "; cin.ignore(); getline(cin, name);
            for (int i=0; i<numberouspt; ++i)
                if (PT[numberouspt].Name == name){
                    KH[numberouspt] = KH[numberouspt+1];
                    numberouspt--;
                } else cout<<"Khong ton tai";
        break;
        case 3:
            break;
    }
}