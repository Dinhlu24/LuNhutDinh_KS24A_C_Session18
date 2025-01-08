#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define max 50

struct sinhVien{
	int id;
	char name[20];
	int age;
	char phoneNum[20];
};

typedef struct sinhVien sinhVien;
void showSVList(sinhVien arr[],int sizeSVList);
int findDeleteList(sinhVien arr[],int *sizeSVList);


int main(){
	system("color 3");
	int sizeSVList=5;
	sinhVien arr[max] = {
		{1,"Tran Van Dan", 18,"09010101010"},
		{2,"Le Van Lien",20,"0901234567"},
		{3,"Nguyen Van A",8,"0901224461"},
		{4,"Hang Nhut B",70,"0801994347"},
		{5,"Lebron James",40,"9090909090"},
	};
	
	printf("Day la danh sach sinh vien cua ban truoc khi xoa:\n");
	showSVList(arr,sizeSVList);
	
	if(findDeleteList(arr,&sizeSVList)){
		printf("Sinh vien ban can xoa co trong danh sach, day la danh sach sau khi xoa\n");
		showSVList(arr,sizeSVList);
	}
	else{
		printf("Ten sinh vien ban can tim kiem khong ton tai trong danh sach");
	}
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

int findDeleteList(sinhVien arr[],int *sizeSVList){
	char deleteName[20];
	printf("Moi ban nhap vao ten sinh vien can xoa: ");	gets(deleteName);
	int i=0,j=0;
	for(i;i<*sizeSVList;i++){
		if(strcmp(arr[i].name,deleteName)){
			arr[j] = arr[i];
			j++;
		}
	}
	(*sizeSVList)--;
	return !(i==j);
}
