#include<iostream>
using namespace std;
struct Node
	{
		int data;
		Node*truoc;
		Node*sau;
	};
struct List
{
	Node *pHead;
	Node *pTail;
};
void initList(List &ds){
	ds.pHead=NULL;
	ds.pTail=NULL;
}
Node *TaoNode(int x){
	Node *p;
	p= new Node;
	p->data=x;
	p->truoc=NULL;
	p->sau=NULL;
	return p;
}
void ThemNodeCuoi(List &ds,int x){
	Node *p=TaoNode(x);
	if(ds.pHead==NULL){
		ds.pHead=p;
		ds.pTail=p;
	}
	else{
		ds.pTail->sau=p;
		p->truoc=ds.pTail;
		ds.pTail=p;
	}
}
void NhapNode(List &ds){
	int x,n,i=0;
	cout<<"Nhap so so nguyen can nhap(n): ";
	cin>>n;
	while(i<n){
		cout<<"Nhap so nguyen:\n";
		cin>>x;	
		ThemNodeCuoi(ds,x);
		i++;
	}
}
void InNode(List ds){
	cout<<"\nDanh sach chua cac so nguyen: ";
	for(Node *p=ds.pHead;p!=NULL;p=p->sau){
			cout<<p->data<<" ";
	}
}
bool ktSNT(int x){
	if(x<=1)
		return false;
	else{
		for(int i=2;i<=x/2;i++)
			if(x%i==0)
				return false;
	}
	return true;
}
void xoa(List &ds,Node *p){
	if(p==ds.pHead){
		p->sau->truoc=NULL;
		ds.pHead=p->sau;
	}
	else if(p==ds.pTail){
		p->truoc->sau=NULL;
		ds.pTail=p->truoc;
	}
	else{
		p->sau->truoc=p->truoc;
		p->truoc->sau=p->sau;
	}
	delete p;
}
void xoaSNTDauTien(List &ds){
	for(Node *p=ds.pHead;p!=NULL;p=p->sau){
		if(ktSNT(p->data)){
			xoa(ds,p);
			break;
		}
		else if(p->sau==NULL)
				cout<<" DS khong ton tai SNT.";
	}
}
int main()
{
	//cout<<1/2;
	//cout<<ktSNT(6);
	List(DS);
	initList(DS);
	NhapNode(DS);
	InNode(DS);
	cout<<"\nKet qua sau khi xoa SNT dau tien:";
	xoaSNTDauTien(DS);
	InNode(DS);
}
