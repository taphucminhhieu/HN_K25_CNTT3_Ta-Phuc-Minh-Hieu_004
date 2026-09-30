#include <stdio.h>
#define MAX_SIZE 50


int main(void) {
    int stock[MAX_SIZE] = {120 , 250 , 180 , 95 , 310};
    int n = 5;
    int choice, value, pos, target, found;
	
	while(1){
		printf("\n======================================================\n");
		printf("        CHUONG TRINH QUAN LY DIEN NANG SAO MAI          \n");
		printf("1.Them chi so dien tieu thu. \n");
		printf("2.Sua chi so dien tieu thu.\n");
		printf("3.Xoa chi so dien tieu thu.\n");
		printf("4.Tim kiem chi so dien tieu thu.\n");
		printf("0.Thoat chuong trinh.\n");
		printf("\n==========================================================\n");
        printf("Nhap lua chon: ");
        scanf("%d", &choice);
	

    	switch(choice) {
            case 1:
                if (n == MAX_SIZE) {
					printf("Mang da day,khong the them\n"); 
					break; 
					}
                printf("Nhap gia tri va vi tri : ", n + 1);
                scanf("%d %d", &value, &pos);
                if (pos < 1 || pos > n + 1) {
					printf("Vi tri chen khong hop le!\n"); 	
					break; 
					}
                
                for (int i = n; i >= pos; i--) stock[i] = stock[i - 1];
                stock[pos - 1] = value;
                n++;
                break;
    		
            case 2:
                printf("Nhap vi tri va gia tri moi: ", n);
                scanf("%d %d", &pos, &value);
                if (pos <= 1 || pos >= n) { 
					printf("Vi tri khong hop le!\n"); 
					break;
				}
				if (value < 0 ){
					printf("Chi so khong hop le! \n");
				}
                stock[pos - 1] = value;
                break;
			
			case 3: 
                if (n == 0) { 
					printf("Mang rong khong the xoa\n"); 
					break; 
				}
				
                printf("Nhap vi tri can xoa (1 - %d): ", n);
                scanf("%d", &pos);
                if (pos < 1 || pos > n) { 
					printf("Vi tri khong hop le!\n"); 
					break; 
					}
                
                for (int i = pos - 1; i < n - 1; i++) stock[i] = stock[i + 1];
                n--;
                break;
                
            case 4:
                printf("Nhap gia tri can tim: ");
                scanf("%d", &target);
                found = 0;
                printf("Vi tri: ");
                for (int i = 0; i < n; i++) {
                    if (stock[i] == target) { printf("%d ", i + 1); found++; }
                }
                if (found > 0) printf("\nSo lan xuat hien: %d\n", found);
                else printf("Khong tim thay!\n");
                continue; 

            default:
                printf("Lua chon khong hop le!\n");
                continue;
            }
        
        printf("Mang hien tai: [");
        for (int i = 0; i < n; i++) {
            printf("%d%s", stock[i], (i == n - 1) ? "" : ", ");
        }
        printf("]\n");
    }
    return 0;
}



