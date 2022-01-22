#include<string.h>
#include <iostream>
using namespace std;
//Mã sinh viên, họ tên, lớp, năm sinh và điểm chuyên đề.
class SINH_VIEN
  {
      string *ma_sinh_vien,*lop, *ho_ten;
      int nam_sinh;
      float diem_cd;
      public:
       SINH_VIEN();
       SINH_VIEN(string *ma_sinh_vien1, string *lop1, string *ho_ten1, int nam_sinh1, float diem_cd1);
       ~SINH_VIEN();
       void nhap_SINH_VIEN();
       void xuat_SINH_VIEN();
       int lay_nam_sinh() {return nam_sinh;};
    // Các hàm và phương thức khác

  };
SINH_VIEN::SINH_VIEN()
 {ma_sinh_vien= new string;lop= new string; ho_ten = new string;
  nam_sinh=2004;
  diem_cd=0.0;
 }

SINH_VIEN::SINH_VIEN(string *ma_sinh_vien1, string *lop1, string *ho_ten1, int nam_sinh1, float diem_cd1)
 {
  ma_sinh_vien= new string;
  *ma_sinh_vien=*ma_sinh_vien1;
  lop= new string;
  *lop =*lop1;
  ho_ten = new string;
  *ho_ten=*ho_ten1;
  nam_sinh=nam_sinh1;
  diem_cd=diem_cd1;
 };

SINH_VIEN::~SINH_VIEN()
{ delete ma_sinh_vien;delete lop; delete ho_ten;
  nam_sinh=0;
  diem_cd=0.0;
};
void SINH_VIEN::nhap_SINH_VIEN()
 { fflush(stdin);
   cout<<"\n HO SO SINH VIEN !"<<endl;
   cout<<"\nMa sinh vien: ";getline(cin,*ma_sinh_vien);                                 ;
   cout<<"Ten sinh vien: " ; fflush(stdin);getline(cin,*ho_ten);
   cout<<"Lop: ";fflush(stdin);getline(cin,*lop);
   cout<<" Nam sinh: "; cin>>nam_sinh;
   cout<<" Diem chuyen de: ";cin>>diem_cd;
 };
void SINH_VIEN::xuat_SINH_VIEN()
{ cout<<"\n HO SO SINH VIEN !"<<endl;
   cout<<"\nMa sinh vien: "<<*ma_sinh_vien<<endl;
   cout<<"Ten sinh vien: "<<*ho_ten<<endl;
   cout<<"Lop: "<<*lop<<endl;
   cout<<" Nam sinh: "<<nam_sinh<<endl;
   cout<<" Diem chuyen de: "<<diem_cd<<endl;

};
// Xây dựng xong lớp SINH_VIEN
void nhap_SINH_VIEN(SINH_VIEN[], int);
int nam_sinh_min(SINH_VIEN [], int );
void in_sinh_vien_lon_tuoi_nhat(SINH_VIEN sinh_vien[], int );

void nhap_SINH_VIEN(SINH_VIEN sinh_vien[], int k)
    {   cout<<"\n NHAP DANH SACH SINH VIEN..."<<endl;

        for(int i=0; i<k;i++)
        {  fflush(stdin);
            cout<<" Sinh vien thu "<<i+1<< "? "<<endl;
            sinh_vien[i].nhap_SINH_VIEN();
        }
    };
 int nam_sinh_min(SINH_VIEN sinh_vien[], int k)
    {
        int min1= sinh_vien[0].lay_nam_sinh();
        for(int i=1;i<k; i++)
            if(min1> sinh_vien[i].lay_nam_sinh()) min1=sinh_vien[i].lay_nam_sinh();
        return min1;

    };
void in_sinh_vien_lon_tuoi_nhat(SINH_VIEN sinh_vien[], int k )
    {
        cout<<"\n SINH VIEN LON TUOI NHAT..."<<endl;
        int min1=nam_sinh_min(sinh_vien,k);
        for(int i=0;i<k; i++)
            if(sinh_vien[i].lay_nam_sinh()== min1)
            {
                sinh_vien[i].xuat_SINH_VIEN(); exit(0);
            }
    }

int main()
  { 
    SINH_VIEN sm[2];
    SINH_VIEN sv1;// Gọi hàm tạo không đối
    sv1.nhap_SINH_VIEN();
    sv1.xuat_SINH_VIEN();
    string *ma2,*lop2,*ten2;
    ma2= new string;
    lop2=new string;
    ten2=new string;
    *ma2="K1";
    *lop2=" HTTT";
    *ten2="Kieu Quen";
     SINH_VIEN sv2(ma2,lop2,ten2,1968,10);// gọi hàm tạo có đối
    sv2.xuat_SINH_VIEN();
    system("pause");
    system("cls");
    
    SINH_VIEN sinh_vien[40];
    int n;
    cout<<"\n So sinh vien: ";cin>>n;
    nhap_SINH_VIEN(sinh_vien,n);
    system("cls");
   in_sinh_vien_lon_tuoi_nhat(sinh_vien,n);
       system("pause");
    return 0;
};
