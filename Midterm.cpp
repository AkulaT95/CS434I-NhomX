#include<iostream>
using namespace std;
 int n,x,v,A[100];
void nhapmang(int X[],int &n){
	cout<<"Nhap so phan tu cua mang:";
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cout<<"Nhap phan tu X["<<i<<"]:";
		cin>>X[i];
	}
}
void Inmang(int X[],int n){
	cout<<"Mang chua cac phan tu: ";
	for(int i=0;i<n;i++){
		cout<<X[i]<<" ";
	}
}
void Them(int X[],int &n){
	cout<<"Nhap x va v (x la phan tu can them, v la vi tri muon them trong mang, vi tri dau tien la 0):\n";
	cin>>x>>v;
	if(v>=0&&v<=n){
		n++;
		for(int i=n-1;i>v;i--)
			X[i]=X[i-1];
		X[v]=x;
		cout<<"Them thanh cong.";
	}
	else
		cout<<"Them that bai.";
}
int main()
{
	
   	int x;
    cout<<"1.Nhap mang 1 chieu\n2.Hien mang.\n3.Chen phan tu.\n";
    begin:
    cout<<"\nNhap lua chon: ";
    cin>>x;
    switch(x){
    			case 1:
    		nhapmang(A,n);
    		goto begin;
    		break;
    case 2:
    		Inmang(A,n);
    		goto begin;
    		break;
		    	case 3:
		    		Them(A,n);
		    		goto begin;
		    		break;
    default:
    			cout<<"Nhap sai, moi nhap lai.";
    		goto begin;
    		break;
	}
}
