#include <stdio.h>
#include <string.h>
#define size 50

struct sinhVien{
	int id;
	char name[100];
	int age;
	char phoneNum[100];
};

typedef struct sinhVien sinhVien;

int main(){
	sinhVien arr[size];
	for(int i=0;i<5;i++){
		arr[i].id=i+1;
		printf("Moi nhap vao ten sinh vien thu %d: ",i+1);
		fgets(arr[i].name,100,stdin);
		arr[i].name[strcspn(arr[i].name,"\n")]='\0';
		
		printf("Moi nhap vao tuoi sinh vien thu %d: ",i+1);
		scanf("%d",&arr[i].age);
		while(getchar() != '\n');
		
		printf("Moi nhap vao sdt sinh vien thu %d: ",i+1);
		fgets(arr[i].phoneNum,100,stdin);
		arr[i].phoneNum[strcspn(arr[i].phoneNum,"\n")]='\0';
	}

	printf("%-3s %-15s %-5s %-12s\n","ID","Name","Age","Phone Number");
	for (int i = 0; i < 5; i++) {
        printf("%-3d %-15s %-5d %-12s\n", arr[i].id, arr[i].name, arr[i].age, arr[i].phoneNum);
    }
}
