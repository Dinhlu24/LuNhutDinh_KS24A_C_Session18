#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define max 50

//struct sinhVien{
//	int id;
//	char name[20];
//	int age;
//	char phoneNum[20];
//};
//
//typedef struct sinhVien sinhVien;

typedef struct{
	int id;
	char name[20];
	int age;
	char phoneNum[20];
}sinhVien;

void showSVList(sinhVien arr[],int sizeSVList);
void addSVList(sinhVien arr[],int *sizeSVList);

int main(){
	system("color 3");
	int sizeSVList=10;
	sinhVien arr[max] = {
		{1,"Beyonce", 18,"09010101010"},
		{2,"JayZ",20,"0901234567"},
		{3,"Justin Bieber",8,"0901224461"},
		{4,"Sean Combs",70,"0801994347"},
		{5,"Lebron James",40,"9090909090"},
		{6,"Chi Phien",30,"123456789"},
		{7,"Tra Vinh Scoot",29,"0987765512"},
		{8,"Meo meo",50,"5000000"},
		{9,"Hong Quang Minh",48,"911112312"},
		{10,"Le Tung Van",80,"6663629"},
	};
	
	printf("Day la danh sach sinh vien cua ban truoc khi them:\n");
	showSVList(arr,sizeSVList);
	
	addSVList(arr,&sizeSVList);
	
	printf("Danh sach sinh vien sau khi them moi vao:\n");
	showSVList(arr,sizeSVList);
}

void showSVList(sinhVien arr[],int sizeSVList){
	printf("-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-\n");
	printf("|%-5s%-20s%-5s%-15s|\n","ID","Name","Age","Phone Number");
	printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
	for(int i=0;i<sizeSVList;i++){
		printf("|%-5d%-20s%-5d%-15s|\n",arr[i].id=i+1,arr[i].name,arr[i].age,arr[i].phoneNum);
		printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
	}
}

void addSVList(sinhVien arr[],int *sizeSVList){
	int addIndex;
	sinhVien newStudent;
	
	printf("Moi nhap vao vi tri sinh vien ban can them: ");	scanf("%d",&addIndex);
	fflush(stdin);
	printf("Moi ban nhap vao cac thong tin sinh vien can them vao sau day:\n");
	printf("Name: ");	gets(newStudent.name);
	printf("Age: ");	scanf("%d",&newStudent.age);	fflush(stdin);
	printf("Phone Number: ");	gets(newStudent.phoneNum);
	
	if(addIndex >= *sizeSVList){
		addIndex = *sizeSVList+1;
	}
	else if(addIndex < 1){
		addIndex=1;
	}
	(*sizeSVList)++;
	
	for(int i=*sizeSVList-2;i >= addIndex-1;i--){
		arr[i+1] = arr[i];
	}
	arr[addIndex-1] = newStudent;
}
