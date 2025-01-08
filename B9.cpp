#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define max 100

struct dishMenu{
	int id;
	char name[25];
	double price;
};

typedef struct dishMenu dishMenu;
void showMenu(dishMenu arr[],int currentSize);
void addMenu(dishMenu menu[],int *currentSize);
void fixMenu(dishMenu menu[],int currentSize);
void deleteMenu(dishMenu menu[],int *currentSize);
void sortMenu(dishMenu menu[],int currentSize,char c);
void linearSearch(dishMenu menu[],int currentSize);
void nameSort(dishMenu menu[],int currentSize);
void binarySearch(dishMenu menu[],int currentSize);

int main(){
	system("color 6");
	int choice,currentSize=5;
	dishMenu menu[max]={
		{1,"Pho bo",25.000},
		{2,"Banh canh cua",25.000},
		{3,"Bun thit nuong",20.000},
		{4,"Bun ca",30.000},
		{5,"Bun cha Ha Noi",35.000},
	};
	
	do{
		printf("1. In ra menu mon an\n");
		printf("2. Them mot phan tu vao vi tri duoc chi dinh\n");
		printf("3. Sua mot phan tu o vi tri duoc chi dinh\n");
		printf("4. Xoa mot phan tu o vi tri duoc chi dinh\n");
		printf("5. Menu sap xep cac phan tu\n");
		printf("6. Menu tim kiem\n");
		printf("7. Thoat\n");
		printf("Lua chon cua ban: ");	scanf("%d",&choice);
		fflush(stdin);
		switch(choice){
			case 1:// In menu do an
				{
					showMenu(menu,currentSize);
				}
				break;
			case 2://Them mot phan tu vao vi tri duoc chi dinh
				{
					addMenu(menu,&currentSize);
				}
				break;
			case 3://Sua mot phan tu o vi tri duoc chi dinh
				{
					fixMenu(menu,currentSize);
				}
				break;
			case 4://Xoa mot phan tu o vi tri duoc chi dinh
				{
					deleteMenu(menu,&currentSize);
				}
				break;
			case 5:// Menu sap xep cac phan tu
				{
					char c;
					printf("a. Giam dan theo gia tien\n");
					printf("b. Tang dan theo gia tien\n");
					printf("Lua chon cua ban: ");	c=getchar();
					switch(c){
						case 'a':	case 'b':
							sortMenu(menu,currentSize,c);
							break;
						default:
							printf("Lua chon cua ban khong hop le !!!");
					}
				}
				break;
			case 6:// Menu tim kiem
				{
					char c;
					printf("a.Tim kiem tuyen tinh (tim kiem theo ten)\n");
					printf("b.Tim kiem nhi phan (tim kiem theo ten)\n");
					printf("Lua chon cua ban: "); c=getchar();
					fflush(stdin);
					switch(c){
						case 'a':
							linearSearch(menu,currentSize);
							break;
						case'b':
							nameSort(menu,currentSize);
							binarySearch(menu,currentSize);
							break;
					}
				}
				break;
			case 7:// Thoat
				{
					printf("Chuong trinh ket thuc !!!");
				}
				break;
			default:
				printf("Lua chon cua ban khong hop le !!!");
		}
		printf("\n\n");
	}while(choice != 7);
}

void showMenu(dishMenu menu[],int currentSize){
	printf("Day la menu cua ban:\n\n");
	printf("[%-5s%-25s:%-8s]\n","STT","Mon an","Gia");
	printf("------+------+------+------+------+------\n");
	for(int i=0;i<currentSize;i++){
		printf("|%-5d%-25s:%-8.3lf|\n",menu[i].id,menu[i].name,menu[i].price);
		if(i != currentSize-1){
			printf("-----------------------------------------\n");
		}
	}
	printf("[-----+------+------+------+------+-----]\n");
}

void addMenu(dishMenu menu[],int *currentSize){
	int addIndex;
	dishMenu newDish;
	printf("Moi ban nhap vao vi tri ban muon them vao: ");	scanf("%d",&addIndex);	fflush(stdin);
	
	printf("Moi ban nhap mon an: ");	gets(newDish.name);
	printf("Moi ban nhap vao gia tien: ");	scanf("%lf",&newDish.price);	fflush(stdin);
	
	if(addIndex >= *currentSize){
		addIndex = *currentSize;
	}
	else if(addIndex < 0){
		addIndex = 1;
	}
	
	(*currentSize)++;
	for(int i=*currentSize-2;i>=addIndex-1;i--){
		menu[i+1] = menu[i];
		menu[i+1].id = i+2;
	}
	
	menu[addIndex-1] = newDish;
	menu[addIndex-1].id = menu[addIndex].id-1;
	printf("Da them mon an moi vao thanh cong !!!\n");
}

void fixMenu(dishMenu menu[],int currentSize){
	int fixIndex;
	printf("Lua chon vi tri ban muon sua doi: ");	scanf("%d",&fixIndex);	fflush(stdin);
	if(fixIndex < 1 || fixIndex >= currentSize){
		printf("Vi tri sua doi cua ban nhap vao khong hop le");
	}
	else{
		dishMenu fixIF = menu[fixIndex-1];
		printf("Moi ban nhap mon an: ");	gets(fixIF.name);
		printf("Moi ban nhap vao gia tien moi: ");	scanf("%lf",&fixIF.price);	fflush(stdin);
		menu[fixIndex-1] = fixIF;
		printf("Sua thong tin thanh cong !!!");
	}
}

void deleteMenu(dishMenu menu[],int *currentSize){
	int deleteIndex;
	printf("Lua chon vi tri ban muon xoa: ");	scanf("%d",&deleteIndex);	fflush(stdin);
	if(deleteIndex < 1 || deleteIndex > *currentSize){
		printf("Vi tri ban can xoa khong ton tai");
	}
	else{
		int j=deleteIndex-1;
		for(int i=deleteIndex-1;i<*currentSize;i++){
			if(menu[i].id != deleteIndex){
				menu[j] = menu[i];
				menu[j].id = j+1;
				j++;
			}
		}
		(*currentSize)--;
		printf("Da xoa thanh cong !!!");
	}
}

void sortMenu(dishMenu menu[],int currentSize,char c){
	for(int i=0;i<currentSize-1;i++){
		for(int j=0;j<currentSize-i-1;j++){
			if((c == 'a')?menu[j].price < menu[j+1].price:menu[j].price > menu[j+1].price){
				dishMenu tmp = menu[j];
				menu[j] = menu[j+1];
 				menu[j+1] = tmp;
 				menu[j+1].id = menu[j].id;
 				menu[j].id = tmp.id;
			}
		}
	}
	printf("Da sap xep xong");
}

void linearSearch(dishMenu menu[],int currentSize){
	char s[20];
	printf("Moi ban nhap ten mon an can tim kiem: ");	gets(s);
	
	for(int i=0;i<currentSize;i++){
		if(strcmp(s,menu[i].name)==0){
			printf("Mon an ban tim kiem co trong menu !!!");
			return;
		}
	}
	printf("Mon an ban tim kiem khong co trong menu !!!");
	return;
}

void nameSort(dishMenu menu[],int currentSize){
	for(int i=0;i<currentSize-1;i++){
		for(int j=0;j<currentSize-i-1;j++){
			if(strcmp(menu[i].name,menu[i+1].name) > 0){
				dishMenu tmp = menu[j];
				menu[j] = menu[j+1];
 				menu[j+1] = tmp;
 				menu[j+1].id = menu[j].id;
 				menu[j].id = tmp.id;
			}
		}
	}
	printf("Da sap xep ten lai theo thu tu tang dan\n");
	printf("Bat dau thuc hien thao tac tim kiem nhi phan\n");
}

void binarySearch(dishMenu menu[],int currentSize){
	char s[20];
	printf("Moi ban nhap vao ten mon an can tim kiem: ");	gets(s);
	
	int start=0,end=currentSize-1,mid;
	while(start <= end){
		mid = start + (end - start)/2;
		if(strcmp(s,menu[mid].name)==0){
			printf("Ten mon an can kiem co trong menu !!!");
			return;
		}
		else if(strcmp(s,menu[mid].name) < 0){
			end = mid - 1;
		}
		else{
			start = mid + 1;
		}
	}
	printf("Mon an ban can tim khong co trong menu !!!");
	return;
}
