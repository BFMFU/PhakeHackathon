#include<stdio.h>
#include<math.h>
int main(){
	int choice,n ;
	int arr[100] ;
	while(choice<9){
	printf("\n MENU\n");
	printf("1. Nhap so cac phan tu can nhap va gia tri cac phan tu.\n");
	printf("2. In ra cac phan tu dang qua ly.\n");
	printf("3. In ra gia tri lon nhat cua mang.\n");
	printf("4. In ra cac phan tu la so nguyen to trong mang.\n");
	printf("5. Them 1 phan tu vao trong mang.\n");
	printf("6. Xoa 1 phan tu trong mang.\n");
	printf("7. Sap xep mang theo gia tri tang dan.\n");
	printf("8. Tim kiem phan tu (nguoi dung nhap) va in ra index cua phan tu do.\n");
	printf("9. Thoat.\n");
	printf("Lua chon cua ban la: ");
	scanf("%d",&choice);
	if(choice<0&&choice>9){
		printf("Lua chon khong hop le.");
		break;
	}
	switch(choice){
		case 1: { //Nhap so luong phan tu va gia tri phan tu
			do{
				printf("Nhap so luong phan tu cho mang: ");
				scanf("%d",&n);
			} while(n<0);
			for(int i=0;i<n;i++){
				printf("Nhap gia tri cho phan tu thu %d: ",i);
				scanf("%d",&arr[i]);
			}
			break;
		}
		case 2: { //in ra mang 
			printf("Mang hien tai la: ");
			for(int i=0;i<n;i++){
				printf("%d ",arr[i]);
			}
			break;
		}
		case 3:{ // in ra gia tri lon nhat
			int max=arr[0];
			for(int i=0;i<n;i++){
				if(arr[i]>max){
					max=arr[i];
				}
			}
			printf("Gia tri lon nhat la: %d",max);
			break;
		}
		case 4:{ // in ra cac so nguyen to
			printf("Cac so nguyen to gom co: ");
			for (int i = 0; i < n; i++) {
        		int num = arr[i];
       			if (n < 2) {
            		continue;
        		}
        		int element = 1;
        		for (int j = 2; j <= sqrt(num); j++) {
            	if (num % j == 0) {
                element = 0;
                break;
            	}
        	}
        		if (element==1) {
            	printf("%d ", num);
        		}
    		}
			
			break;
		}
		case 5:{ //them 1 phan tu vao mang
			int pos, value;
			do{
				printf("Nhap vi tri  muon them: ");
				scanf("%d",&pos);
			} while(pos<0&&pos>n);
			printf("Nhap gia tri ma ban muon them: ");
			scanf("%d",&value);
			for(int i=n;i>=pos;i--){
			arr[i]=arr[i-1];
			}	
			arr[pos-1]=value;
			++n;
			break;
		}
		case 6:{ // xoa 1 phan tu trong mang.
			int pos;
			do{
			printf("Nhap vao vi tri phan tu ban muon xoa: ");
			scanf("%d",&pos);
			} while (pos>=n&&pos<0);
			for(int i=pos-1;i<n;i++){
			arr[i]=arr[i+1];
			}
			--n;
			break;
		}
		case 7:{ // sap xem thu tu mang tang dan
			for(int i=1;i<n;i++){
			int key =arr[i];
			for(int j=i-1;j>=0&&arr[j]>key;j--){
				arr[j+1]=arr[j];
				arr[j]=key;
			}
		}
			break;
		}
		case 8:{//tim kiem phan tu
			int value,findIndex,count=0;
			printf("Nhap phan tu ban muon tim: ");
			scanf("%d",&value);
			for(int i=0;i<n;i++){
				if(arr[i]==value){
					count+=1;
					findIndex=i;
				}
			}
			if(count==1){
				printf("Vi tri cua phan tu trong mang la: %d",findIndex);
			} else{
				printf("Khong tim thay phant tu trong mang.");
			}
			break;
		}
		default :{
			printf("Lua chon khong hop le. Moi ban nhap lai.");
			break;
		}
	}
	}	
	printf("Thoat chuong trinh. ");
	return 0 ;
}
