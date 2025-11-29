#include<bits/stdc++.h>
using namespace std;

class sanpham{
	protected:
		string maSP;
		string tenSP;
		double giaNhap;
		int soLuong;
	public:
		sanpham(){
			maSP= "";
			tenSP="";
			giaNhap=0;
			soLuong=0;
		}
		sanpham(string maSP, string tenSP, double giaNhap, int soLuong){
			this->maSP =maSP;
			this->tenSP=tenSP;
			this->giaNhap=giaNhap;
			this->soLuong=soLuong;
		}
		
		virtual void nhap(){
			cout <<"Nhap ma SP: ";
			getline(cin,maSP);
			cout <<"Nhap ten SP: ";
			getline(cin,tenSP);
			cout <<"Nhap gia nhap: ";
			cin>>giaNhap;
			cout <<"Nhap so luong SP: ";
			cin>>soLuong;
			cin.ignore();
		}
		
		virtual double tinhGiaBan() = 0;
		
		virtual void xuat(){
			cout << "Ma SP: "<<maSP<<"\nTen SP: "<<tenSP<<"\nGia Nhap: "<<giaNhap<<"\nSo Luong: "<<soLuong;
		}
		
		double operator + (sanpham &a){
			return ( giaNhap * soLuong ) + (a.giaNhap * a.soLuong);
		}
		double getgiaNhap(){
			return giaNhap;
		}
		int getsoLuong(){
			return soLuong;
		}
};

class DienThoai : public sanpham{
	int dungLuongPin;
	public:
		DienThoai() : sanpham() {
        	this->dungLuongPin = 0;
    	}
    	DienThoai(string maSP, string tenSP, double giaNhap, int soLuong, int dungLuongPin) {
        	this->maSP = maSP;
    	   	this->tenSP = tenSP;
    	    this->giaNhap = giaNhap;
    	    this->soLuong = soLuong;
    	    this->dungLuongPin = dungLuongPin;
		}
		double tinhGiaBan(){
			return giaNhap * 1.3;
		}
		void nhap(){
			sanpham::nhap();
			cout <<"Nhap dung luong Pin: ";
			cin>>dungLuongPin;
			cin.ignore();		
		}
		void xuat() override {
			sanpham::xuat();
			cout<<"\nDung Luong Pin: "<<dungLuongPin<<" mAh"<<"\nGia Ban: "<<tinhGiaBan();
		}
};

class LapTop : public sanpham{
	string card;
	public:
		LapTop():sanpham(){
			this->card = "";
		}
		LapTop(string maSP, string tenSP, double giaNhap, int soLuong,string card){
			this->maSP=maSP;
			this->tenSP=tenSP;
			this->giaNhap=giaNhap;
			this->soLuong=soLuong;
			this->card=card;
		}
		double tinhGiaBan(){
			return giaNhap * 1.5;
		}
		void nhap(){
			sanpham::nhap();
			cout <<"Nhap Card do hoa: ";
			getline(cin,card);
		}
		void xuat(){
			sanpham::xuat();
			cout <<"\nCard do hoa: "<<card<<"\nGia ban: "<<tinhGiaBan();
		}
};

int main(){
	int n;
	cout <<"Nhap so luong san pham: ";
	cin>>n;
	cin.ignore();
	
	sanpham* b[100];
	for (int i=0;i<n;i++){
		int loai;
		cout <<"Nhap loai san pham: ";
		cin >> loai;
		cin.ignore();
		if (loai == 2){
			b[i]=new LapTop;
		}else{
			b[i]=new DienThoai;
		}
		b[i]->nhap();	
	}
	cout <<"Danh sach san pham: \n";
	
	for (int i=0;i<n;i++){
		b[i]->xuat();
		cout <<endl;
	}
	
	double tong = 0;
	for (int i=0;i<n-1;i++){
		tong += *b[i] + *b[i+1];
	}
	cout <<"Tong ton kho: \n"<<fixed<<setprecision(0)<<tong;
}
