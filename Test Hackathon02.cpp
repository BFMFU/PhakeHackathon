#include <stdio.h>
int main() {
    int arr[100][100];
    int rows, cols;
    int choice, i, j, product, key, found;
    do {
        printf("\nMENU\n");
        printf("1. Nhap kich co va gia tri cac phan tu cua mang\n");
        printf("2. In gia tri cac phan tu cua mang theo ma tran\n");
        printf("3. In ra cac phan tu nam tren duong bien va tinh tich\n");
        printf("4. In ra cac phan tu nam tren duong cheo chinh\n");
        printf("5. In ra cac phan tu nam tren duong cheo phu\n");
        printf("6. Sap xep duong cheo chinh theo thu tu tang dan\n");
        printf("7. Tim kiem mot phan tu va in ra vi tri cua phan tu do trong mang\n");
        printf("8. Thoat\n");
        printf("Lua chon cua ban: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:{ //nhap kich co va gia tri
                printf("Nhap so hang: ");
                scanf("%d", &rows);
                printf("Nhap so cot: ");
                scanf("%d", &cols);
                printf("Nhap cac phan tu cua ma tran:\n");
                for (i = 0; i < rows; i++) {
                    for (j = 0; j < cols; j++) {
                        printf("Gia tri: ");
                        scanf("%d", &arr[i][j]);
                    }
                }
                break;
				}
            case 2:{ //in gia tri cua mang thanh ma tran
                printf("Ma tran:\n");
                for (i = 0; i < rows; i++) {
                    for (j = 0; j < cols; j++) {
                        printf("%d ", arr[i][j]);
                    }
                    printf("\n");
                }
                break;
				}
            case 3: { //in ra cac phan tu nam tren duong bien va tinh tich
                printf("Cac phan tu tren duong bien:\n");
                product = 1;
                for (i = 0; i < rows; i++) {
                    for (j = 0; j < cols; j++) {
                        if (i == 0 || i == rows - 1 || j == 0 || j == cols - 1) {
                            printf("%d ", arr[i][j]);
                            product *= arr[i][j];
                        }
                    }
                }
                printf("\nTich cac phan tu tren duong bien: %d\n", product);
                break;
            	}
            case 4:{//in ra cac phan tu nam tren duong cheo chinh
            	if(cols!=rows){
            		printf("Mang khong co duong cheo chinh.");
            		break;
					} else{
                printf("Cac phan tu tren duong cheo chinh:\n");
                for (i = 0; i < rows && i < cols; i++) {
                    printf("%d ", arr[i][i]);
                }
                printf("\n");
                break;
            	}
            	}
            case 5:{//in ra cac phan tu tren duong cheo phu
            	if(cols!=rows){
            		printf("Mang khong co duong cheo phu.");
            		break;
					} else{
                printf("Cac phan tu tren duong cheo phu:\n");
                for (i = 0; i < rows && i < cols; i++) {
                    printf("%d ", arr[i][cols - i - 1]);
                }
                printf("\n");
                break;
            	}
				}
            case 6:{//sap xep duong cheo chinh theo gia tri tang dan
                for (i = 0; i < rows - 1 && i < cols - 1; i++) {
                    for (j = i + 1; j < rows && j < cols; j++) {
                        if (arr[i][i] > arr[j][j]) {
                            int temp = arr[i][i];
                            arr[i][i] = arr[j][j];
                            arr[j][j] = temp;
                        }
                    }
                }
                printf("Duong cheo chinh sau khi sap xep tang dan:\n");
                for (i = 0; i < rows && i < cols; i++) {
                    printf("%d ", arr[i][i]);
                }
                printf("\n");
                break;
            	}
            case 7:{//tim kiem mot phan tu va in ra vi tri cua phan tu do trong mang
                printf("Nhap phan tu can tim: ");
                scanf("%d", &key);
                found = 0;
                for (i = 0; i < rows; i++) {
                    for (j = 0; j < cols; j++) {
                        if (arr[i][j] == key) {
                            printf("Phan tu %d tim thay tai vi tri (%d, %d)\n", key, i, j);
                            found = 1;
                        }
                    }
                }
                if (!found) {
                    printf("Khong tim thay phan tu %d trong ma tran.\n", key);
                }
                break;
            	}
            case 8:{// thoat chuong trinh.
                printf("Thoat chuong trinh.\n");
                break;
				}
            default:
                printf("Lua chon khong hop le. Vui long chon lai.\n");
        }
    } while (choice != 8);
    return 0;
}

