#include<iostream>
#include<string>
#include<iomanip>
using namespace std;
struct Date
{
	int ngay;
	int thang;
	int nam;
};
										//Class NhanVien
class NhanVien
{
public:
	NhanVien();
	unsigned int GetLuong();
	void NhapThongTin();
	void XuatThongTin();
	void TinhPhuCap();
	int GetTuoi();
	string GetMaSo();
	friend int TimViTriCoMaTrung(string ma_xet,NhanVien a[],int n);
	string GetName();
protected:
	int tuoi;
	string ho_ten;
	string ma_so;
	string dia_chi;
	int so_ngay_nghi;
	Date nam_vao_lam;
	int so_nam_lam;
	unsigned int phu_cap;
	unsigned int luong;
};

NhanVien::NhanVien()
		:tuoi(0),ho_ten(),ma_so(),dia_chi(),so_ngay_nghi(0),nam_vao_lam(),luong(0),so_nam_lam(),phu_cap(){
}
unsigned int NhanVien::GetLuong() {
	return luong;
}
int NhanVien::GetTuoi() {
	return tuoi;
}
string NhanVien::GetMaSo() {
	return ma_so;
}
void NhanVien::NhapThongTin() {
	while (getchar() != '\n');
	cout << "\nNhap ho ten: ";
	getline(cin, ho_ten);
	cout << "\nNhap tuoi: ";
	cin >> tuoi;
	while (getchar() != '\n');
	cout << "\nNhap ma so: ";
	getline(cin, ma_so);
	cout << "\nNhap dia chi: ";
	getline(cin, dia_chi);
	cout << "\nNhap so ngay nghi: ";
	cin >> so_ngay_nghi;
	while (getchar() != '\n');
	cout << "\nNhap so nam lam: ";
	cin >> so_nam_lam;
	cout << "\nNhap nam vao lam: ";
	cin >> nam_vao_lam.ngay >> nam_vao_lam.thang >> nam_vao_lam.nam;
	while(getchar() != '\n');
}
void NhanVien::TinhPhuCap() {
	phu_cap = 100000 + (so_nam_lam * 20000);
}
string NhanVien::GetName() {
	return ho_ten;
}
void NhanVien::XuatThongTin() {
	cout << "\nTen nhan vien: " << ho_ten;
	cout << "\nMa nhan vien: " << ma_so;
	cout << "\nDia chi nhan vien: " << dia_chi;
	cout << "\nSo ngay nghi nhan vien: " << so_ngay_nghi;
	cout << "\nNam vao lam nhan vien: " << nam_vao_lam.ngay << "/" << nam_vao_lam.thang << "/" << nam_vao_lam.nam;;
}
  int TimViTriCoMaTrung(string ma_xet,NhanVien a[],int n) {
	for (size_t i = 1; i <=n ; i++)
	{
		if (a[i].ma_so==ma_xet)
		{
			return i;
		}
	}
}
								//Class NhanVienSanXuat
class NhanVienSanXuat : public NhanVien
{
public:
	NhanVienSanXuat();
	void NhapThongTin();
	void XuatThongTin();
	void TinhLuongNhanVienSanXuat();
	void XoaNhanVienSanXuatTrongDanhSach(NhanVienSanXuat a[],int &n,int vi_tri);
	
private:
	
	int so_san_pham_ban;
};

NhanVienSanXuat::NhanVienSanXuat(): NhanVien()
{
	so_san_pham_ban = 0;
	
}
void NhanVienSanXuat::NhapThongTin() {
	NhanVien::NhapThongTin();
	cout << "\nNhap so san pham ban: ";
	cin >> so_san_pham_ban;
}
void NhanVienSanXuat::TinhLuongNhanVienSanXuat() {
	TinhPhuCap();
	luong = (	so_san_pham_ban * 10000	) +phu_cap;
}
void NhanVienSanXuat::XuatThongTin() {
	NhanVien::XuatThongTin();
	cout << "\nSo san pham ban duoc: " << so_san_pham_ban;
	TinhLuongNhanVienSanXuat();
	cout << "\n Luong nhan vien: " <<luong;
	
}
void NhanVienSanXuat::XoaNhanVienSanXuatTrongDanhSach(NhanVienSanXuat a[], int &n, int vi_tri) {
	for (size_t i = vi_tri; i <=n; i++)
	{
		a[i] = a[i + 1];
	}
	n--;
}
									//Class NhanVienVanPhong
class NhanVienVanPhong : public NhanVien
{
public:
	NhanVienVanPhong();
	void NhapThongTin();
	void XuatThongTin();
	void TinhLuongNhanVienVanPhong();

private:
	   int muc_luong ;
};

NhanVienVanPhong::NhanVienVanPhong()
		:muc_luong(150000){
}
void NhanVienVanPhong::NhapThongTin() {
	NhanVien::NhapThongTin();
}
void NhanVienVanPhong::TinhLuongNhanVienVanPhong() {
	TinhPhuCap();
	luong = (	muc_luong -(so_ngay_nghi * 10000)	)+phu_cap;
}
void NhanVienVanPhong::XuatThongTin() {
	NhanVien::XuatThongTin();
	TinhLuongNhanVienVanPhong();
	cout << "\n Luong nhan vien: " << luong;
}

													//Class NhanVienCongNhat
class NhanVienCongNhat: public NhanVien
{
public:
	NhanVienCongNhat();
	void NhapThongTin();
	void XuatThongTin();
	void TinhLuongNhanVienCongNhat();
	int GetSoNgayCong(NhanVienCongNhat *a);
	 friend int GetSoNgayDiLam(NhanVienCongNhat nv1);
	 friend int GetSoNgayNghi(NhanVienCongNhat nv1);
	
private:

	 int luong_cung = 2000000;
	int so_ngay_di_lam;
	int so_ngay_cong;
};

NhanVienCongNhat::NhanVienCongNhat()
{
	
	NhanVien::NhanVien();
	so_ngay_di_lam = 0;
	so_ngay_cong = 0;
}
int NhanVienCongNhat::GetSoNgayCong(NhanVienCongNhat *a) {
	 so_ngay_cong = GetSoNgayDiLam(*a) - GetSoNgayNghi(*a);
	 return so_ngay_cong;
}
void NhanVienCongNhat::NhapThongTin() {
	NhanVien::NhapThongTin();
	cout << "\nNhap so ngay di lam: ";
	cin>>so_ngay_di_lam;
}
int GetSoNgayNghi(NhanVienCongNhat nv1) {
	return nv1.so_ngay_nghi;
}
int GetSoNgayDiLam(NhanVienCongNhat nv1) {
	return nv1.so_ngay_di_lam;
}

void NhanVienCongNhat::TinhLuongNhanVienCongNhat(){
	TinhPhuCap();
	luong =( (	(so_ngay_di_lam - so_ngay_nghi)	 * 100000) + luong_cung	)+phu_cap;
}
void NhanVienCongNhat::XuatThongTin() {
	NhanVien::XuatThongTin();
	cout << "\nSo ngay di lam nhan vien: " << so_ngay_di_lam;
	TinhLuongNhanVienCongNhat();
	cout << "\nLuong nhan vien: " << luong;
}

																		//Class QuanLyNhanVien
class QLNV
{
public:
	QLNV();
	~QLNV();
	friend void Menu(QLNV& ql1);
	friend void TinhTongTienMoiThang(QLNV ql1);
	void NhapDanhSachNhanVienSanXuat(NhanVienSanXuat *&a,int n);
	void NhapDanhSachNhanVienVanPhong(NhanVienVanPhong*& a, int n);
	void NhapDanhSachNhanVienCongNhat(NhanVienCongNhat*& a, int n);
	void XuatDanhSachNhanVienSanXuat(NhanVienSanXuat* a, int n);
	void XuatDanhSachNhanVienVanPhong(NhanVienVanPhong* a, int n);
	void XuatDanhSachNhanVienCongNhat(NhanVienCongNhat* a, int n);
	void XuatDanhSachNhanVienCongNhatVoiSoNgayCongTuongUng(NhanVienCongNhat* a, int n);
	void InDanhSachNhanVienLonHon_50_Tuoi(QLNV ql1);
	void XoaNhanVienCoMa_X(QLNV &ql,string ma_xet);
	void XoaDanhSachNhanVienSanXuat(NhanVienSanXuat a[],int &n,int vi_tri);
	void XoaDanhSachNhanVienVanPhong(NhanVienVanPhong a[], int &n, int vi_tri);
	void XoaDanhSachNhanVienCongNhat(NhanVienCongNhat a[], int &n, int vi_tri);
	void TimTenTheoKiTuNhap(QLNV ql1,string chuoi_xet);

private:
	NhanVienVanPhong* ds_vp; 
	NhanVienCongNhat* ds_cn;  
	NhanVienSanXuat* ds_sx;  
	int ds_vp_count;
	int ds_cn_count;
	int ds_sx_count;
};

QLNV::QLNV()
{
	ds_vp= new NhanVienVanPhong[100];
	ds_cn= new NhanVienCongNhat[100];
	ds_sx= new NhanVienSanXuat[100];
	ds_vp_count = 0;
	ds_cn_count = 0;
	ds_sx_count = 0;
}

QLNV::~QLNV()
{
	delete[] ds_vp;
	delete[] ds_cn;
	delete[] ds_sx;

}

																	//Các hàm bổ trợ cho menu
void QLNV::NhapDanhSachNhanVienVanPhong(NhanVienVanPhong *&a, int n) {
	for (size_t i = 1; i <= n; i++)
	{	
		cout << "\nNhap nhan vien thu " << i << endl;
		a[i].NhapThongTin();
	}
}
void QLNV::NhapDanhSachNhanVienSanXuat(NhanVienSanXuat*& a, int n) {
	for (size_t i = 1; i <= n; i++)
	{
		cout << "\nNhap nhan vien thu " << i << endl;
		a[i].NhapThongTin();
	}
}
void QLNV::NhapDanhSachNhanVienCongNhat(NhanVienCongNhat*& a, int n) {
	for (size_t i = 1; i <= n; i++)
	{
		cout << "\nNhap nhan vien thu " << i << endl;
		a[i].NhapThongTin();
	}
}

void QLNV::XuatDanhSachNhanVienVanPhong(NhanVienVanPhong* a, int n) {
	for (size_t i = 1; i <= n; i++)
	{
		cout << "\nXuat nhan vien thu " << i << endl;
		a[i].XuatThongTin();
	}
}
void QLNV::XuatDanhSachNhanVienSanXuat(NhanVienSanXuat* a, int n) {
	for (size_t i = 1; i <= n; i++)
	{
		cout << "\nXuat nhan vien thu " << i << endl;
		a[i].XuatThongTin();
	}
}
void QLNV::XuatDanhSachNhanVienCongNhat(NhanVienCongNhat* a, int n) {
	for (size_t i = 1; i <= n; i++)
	{
		cout << "\nXuat nhan vien thu " << i << endl;
		a[i].XuatThongTin();
	}
}
void TinhTongTienMoiThang(QLNV ql1) {
	long int sum_cty{};
	for (size_t i = 1; i <= ql1.ds_sx_count; i++)
	{
		sum_cty += ql1.ds_sx[i].GetLuong();
	}
	for (size_t i = 1; i <= ql1.ds_vp_count; i++)
	{
		sum_cty += ql1.ds_vp[i].GetLuong();
	}
	for (size_t i = 1; i <= ql1.ds_cn_count; i++)
	{
		sum_cty += ql1.ds_cn[i].GetLuong();
	}
	cout << "\nTong luong ma cty nay phai tra la: " << sum_cty;
}

void QLNV::XuatDanhSachNhanVienCongNhatVoiSoNgayCongTuongUng(NhanVienCongNhat *a,int n) {
	for (size_t i = 1; i <=n; i++)
	{
		a[i].XuatThongTin();
		cout << "\nSo ngay cong: " << a[i].GetSoNgayCong(&a[i]);
	}
}
void QLNV::InDanhSachNhanVienLonHon_50_Tuoi(QLNV ql) {
	for (size_t i = 1; i <=ql.ds_sx_count ; i++)
	{
		if (	ql.ds_sx[i].GetTuoi()	>	50)
		{
			ql.ds_sx[i].XuatThongTin();
		}
	}
	for (size_t i = 1; i <= ql.ds_vp_count; i++)
	{
		if (ql.ds_vp[i].GetTuoi() > 50)
		{
			ql.ds_vp[i].XuatThongTin();
		}
	}
	for (size_t i = 1; i <= ql.ds_cn_count; i++)
	{
		if (ql.ds_cn[i].GetTuoi() > 50)
		{
			ql.ds_cn[i].XuatThongTin();
		}
	}
}
void QLNV::XoaNhanVienCoMa_X(QLNV &ql,string ma_xet) {
	for (size_t i = 1; i <= ql.ds_sx_count; i++)
	{
		if (ql.ds_sx[i].GetMaSo()==ma_xet)
		{
			ql.XoaDanhSachNhanVienSanXuat(ql.ds_sx, ql.ds_sx_count, TimViTriCoMaTrung(ma_xet, ql.ds_sx, ql.ds_sx_count));
		}
	}
	for (size_t i = 1; i <= ql.ds_vp_count; i++)
	{
		if (ql.ds_vp[i].GetMaSo()==ma_xet)
		{
			ql.XoaDanhSachNhanVienVanPhong(ql.ds_vp, ql.ds_vp_count, TimViTriCoMaTrung(ma_xet, ql.ds_vp, ql.ds_vp_count));
		}
		
	}
	for (size_t i = 1; i <= ql.ds_cn_count; i++)
	{
		if (ql.ds_cn[i].GetMaSo()==ma_xet)
		{
			ql.XoaDanhSachNhanVienCongNhat(ql.ds_cn, ql.ds_cn_count, TimViTriCoMaTrung(ma_xet, ql.ds_cn, ql.ds_cn_count));
		}
	}
}
void QLNV::XoaDanhSachNhanVienSanXuat(NhanVienSanXuat a[], int &n, int vi_tri) {
	for (size_t i = 1; i <=n; i++)
	{
		a[i] = a[i + 1];
	}
	n--;
}
void QLNV::XoaDanhSachNhanVienVanPhong(NhanVienVanPhong a[], int &n, int vi_tri) {
	for (size_t i = 1; i <= n; i++)
	{
		a[i] = a[i + 1];
	}
	n--;
}
void QLNV::XoaDanhSachNhanVienCongNhat(NhanVienCongNhat a[], int &n, int vi_tri) {
	for (size_t i = 1; i <= n; i++)
	{
		a[i] = a[i + 1];
	}
	n--;
}
bool DuyetChuoiXetTheoHoTen(string ho_ten, string chuoi_xet) {
	int so_luong_ki_tu_chuoi_xet = chuoi_xet.length();
	int so_luong_ki_tu_trong_chuoi_se_lay{};
	for (size_t i =0; i <ho_ten.length() ; i++)
	{
		for (size_t j = 0;  j< so_luong_ki_tu_chuoi_xet; j++)
		{
			cout << "\nDang xet ki tu thu " << j << "trong chuoi ten" << endl;
			if (chuoi_xet[j]== ho_ten[i])
			{
				so_luong_ki_tu_trong_chuoi_se_lay++;
			}
			
		}
		if (so_luong_ki_tu_trong_chuoi_se_lay == so_luong_ki_tu_chuoi_xet)
			
		{
			return true;
		}
	}
	
		cout << "\nstr lay:" << so_luong_ki_tu_trong_chuoi_se_lay;
		cout << "\nstr xet:" << so_luong_ki_tu_chuoi_xet;

		return false;
}
void QLNV::TimTenTheoKiTuNhap(QLNV ql1, string chuoi_xet) {
	for (size_t i = 1; i <=ql1.ds_sx_count; i++)
	{
		if (	DuyetChuoiXetTheoHoTen(ql1.ds_sx[i].GetName(),chuoi_xet) == true)
		{
			ql1.ds_sx[i].XuatThongTin();
			
		}
	}
	for (size_t i = 1; i <= ql1.ds_vp_count; i++)
	{
		if (DuyetChuoiXetTheoHoTen(ql1.ds_vp[i].GetName(), chuoi_xet) == true)
		{
			ql1.ds_vp[i].XuatThongTin();
			
		}
	}
	for (size_t i = 1; i <= ql1.ds_cn_count; i++)
	{
		if (DuyetChuoiXetTheoHoTen(ql1.ds_cn[i].GetName(), chuoi_xet) == true)
		{
			ql1.ds_cn[i].XuatThongTin();
		
		}
	}
	
}
void Menu(QLNV &ql1) {
	int main_menu_selection{};
	do
	{
		cout << setw(30) << "Cong ty san xuat Ba Con Sau";
		cout << setw(30) << "\n1/Nhap danh sach nhan vien cong ty";
		cout << setw(30) << "\n2/Xuat thong tin tung loai nhan vien";
		cout << setw(30) << "\n3/Tinh tong so tien cong ty phai tra cho nhan vien moi thang";
		cout << setw(30) << "\n4/Xuat danh sach nhan vien cong nhat voi so ngayn nghi tuong ung";
		cout << setw(30) << "\n5/In danh sach cac nhan vien lon hon 50 tuoi";
		cout << setw(30) << "\n6/Xoa nhan vien co ma X";
		cout << setw(30) << "\n7/Nhap xau x tim ten nhan vien";
		cout << setw(30) << "\n0/Thoat";
		cout << "\nMoi ban nhap lua chon: ";
		cin >> main_menu_selection;
		switch (main_menu_selection)
		{
			case 1: {
				int nhap_nhan_vien_selection{};
				do
				{
					system("cls");

					cout << setw(30) << "\nChung toi hien tai co 3 loai nhan vien: ";
					cout << setw(30) << "\n1/Nhan vien san xuat";
					cout << setw(30) << "\n2/Nhan vien van phong";
					cout << setw(30) << "\n3/Nhan vien cong nhat";
					cout << "\n0/Thoat";
					cout << setw(30) << "\nMoi ban nhap loai nhan vien muon them: ";
					cin >> nhap_nhan_vien_selection;
					switch (nhap_nhan_vien_selection)		//Switch cua menu_muc_1
					{
					case 1: {
						cout << setw(30) << "\nNhap so luong nhan vien san xuat: ";
						cin >> ql1.ds_sx_count;
						ql1.NhapDanhSachNhanVienSanXuat(ql1.ds_sx, ql1.ds_sx_count);
						break;
					}
					case 2: {
						cout << setw(30) << "\nNhap so luong nhan vien van phong: ";
						cin >> ql1.ds_vp_count;
						ql1.NhapDanhSachNhanVienVanPhong(ql1.ds_vp, ql1.ds_vp_count);
						break;
					}
					case 3: {
						cout << setw(30) << "\nNhap so luong nhan vien cong nhat: ";
						cin >> ql1.ds_cn_count;
						ql1.NhapDanhSachNhanVienCongNhat(ql1.ds_cn, ql1.ds_cn_count);
						break;
					}
					case 0: {
						break;
					}
					}
				} while (nhap_nhan_vien_selection<4 && nhap_nhan_vien_selection >0);
				system("cls");
					break;
			}
			case 2: {
				int xuat_nhan_vien_selection{};
				do
				{
					system("cls");

					cout << setw(30) << "\nChung toi hien tai co 3 loai nhan vien: ";
					cout << setw(30) << "\n1/Nhan vien san xuat";
					cout << setw(30) << "\n2/Nhan vien van phong";
					cout << setw(30) << "\n3/Nhan vien cong nhat";
					cout << "\n0/Thoat";
					cout << setw(30) << "\nMoi ban nhap loai nhan vien muon xuat: ";
					cin >> xuat_nhan_vien_selection;
					switch (xuat_nhan_vien_selection)		//Switch cua menu_muc_1
					{
					case 1: {
						cout << setw(30) << "\nXuat so luong nhan vien san xuat: ";			
						ql1.XuatDanhSachNhanVienSanXuat(ql1.ds_sx, ql1.ds_sx_count);
						system("pause");
						system("cls");
						break;
					}
					case 2: {
						cout << setw(30) << "\nXuat so luong nhan vien van phong: ";					
						ql1.XuatDanhSachNhanVienVanPhong(ql1.ds_vp, ql1.ds_vp_count);
						system("pause");
						system("cls");
						break;
					}
					case 3: {
						cout << setw(30) << "\nXuat so luong nhan vien cong nhat: ";
						ql1.XuatDanhSachNhanVienCongNhat(ql1.ds_cn, ql1.ds_cn_count);
						system("pause");
						system("cls");
						break;
					}
					
					case 0: {
						break;
					}
					}
				} while (xuat_nhan_vien_selection < 4 && xuat_nhan_vien_selection >0);
				system("cls");
				break;
			}
			case 3: {
				TinhTongTienMoiThang(ql1);
				system("pause");
				system("cls");
				break;
			}
			case 4: {
				ql1.XuatDanhSachNhanVienCongNhatVoiSoNgayCongTuongUng(ql1.ds_cn, ql1.ds_cn_count);									//bo Cong Nhat vao day
				system("pause");
				system("cls");
				break;
			}
			case 5: {
				cout << "\n Cac nhan vien thuoc chinh sach nghi huu la: "<<endl;
				ql1.InDanhSachNhanVienLonHon_50_Tuoi(ql1);
				system("pause");
				system("cls");
				break;
			}
			case 6: {
				while (getchar() != '\n');
				string ma_xet = "";
				cout << "\nMoi ban nhap ma muon xoa: ";
				getline(cin, ma_xet);
				ql1.XoaNhanVienCoMa_X(ql1, ma_xet);
				system("cls");
				break;
			}
			case 7: {												//Cau 7
				while (getchar() != '\n');
				string x = " ";
				cout << "\nMoi ban nhap xau ky tu de tim ten: ";
				getline(cin, x);
				bool kq = false;
				ql1.TimTenTheoKiTuNhap(ql1, x);
				break;
			}
		}
	} while (main_menu_selection < 8 && main_menu_selection >0);
}
int main() {
	QLNV ql1;
	Menu(ql1);
	return 0;
}