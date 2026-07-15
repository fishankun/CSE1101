#include <stdio.h>
#include <string.h>

int menu();

int main(){
    int option, i, ID, room, flag, total_revenue = 0;
    char idate[11];
    int res_id[10] = {
    1001, 1002, 1003, 1004, 1005,
    1006, 1007, 1008, 1009, 1010
};

    char guest_name[10][100] = {
    "Muhtasim Nasif Shafin",
    "Arik Hossain",
    "Vacant",
    "Nomaan Shahriar",
    "Vacant",
    "Azmira Tashnim",
    "Naznin Nisha",
    "Vacant",
    "Numan Anjum",
    "Vacant"
};

    int room_no[10] = {
    101, 102, 201, 202, 301,
    302, 401, 402, 501, 502
};

    char room_type[10][20] = {
    "Single",
    "Double",
    "Suite",
    "Single",
    "Double",
    "Suite",
    "Single",
    "Double",
    "Suite",
    "Single"
};

    char date[10][11] = {   // 11 to include '\0'
    "15/07/2026",
    "16/07/2026",
    " ",
    "18/07/2026",
    " ",
    "20/07/2026",
    "21/07/2026",
    " ",
    "23/07/2026",
    " "
};

    int rent[10] = {
    2500,
    4000,
    7000,
    2500,
    4000,
    7000,
    2500,
    4000,
    7000,
    2500
};

    int occupancy[10] = {
    1, // Occupied
    1,
    0, // Vacant
    1,
    0,
    1,
    1,
    0,
    1,
    0
};
    
    do{
        flag = 0;
        option = menu();
        switch (option){
            case 1:
                while(!flag){
                    flag = 1;
                    printf("Enter the room number you want to reserve: ");
                    scanf("%d", &room);
                    for(i = 0; i < 10; i++){
                        if(room_no[i] == room) break;
                    }
                    if(i == 10){
                        printf("Invalid room number. Please try again.\n");
                        flag = 0;
                        continue;
                    }
                    else if(i < 10 && occupancy[i] == 1){
                        printf("This room is already reserved, Sir. Please look for a vacant room.\n");
                        flag = 0;
                        continue;
                    }
                }
                printf("Room type: %s\nRent: %d\n", room_type[i], rent[i]);
                printf("Enter your Name, Sir.\n");
                scanf(" %99[^\n]", guest_name[i]);
                printf("Enter the date: (DD\\MM\\YYYY)\n");
                scanf("%10s", date[i]);

                occupancy[i] = 1;
                printf("Reservation successful.\n");
                printf("Reservation ID: %d\n", res_id[i]);
                printf("Room No.: %d\n", room_no[i]);
                printf("Room Type: %s\n", room_type[i]);
                printf("Guest Name: %s\n", guest_name[i]);
                printf("Date: %s\n", date[i]);
                printf("Rent: %d\n", rent[i]);
                break;
            case 2:
                do{
                    flag = 0;
                    printf("Enter the Reservation ID you want to search: ");
                    scanf("%d", &ID);
                    for(i = 0; i < 10; i++){
                        if(occupancy[i] == 1 && res_id[i] == ID){
                            flag = 1;
                            break;
                        }
                    }
                    if(!flag) printf("Reservation ID not found. Please try again.\n");
                }while(!flag);

                printf("Reservation ID: %d\n", res_id[i]);
                printf("Room No.: %d\n", room_no[i]);
                printf("Room Type: %s\n", room_type[i]);
                printf("Guest Name: %s\n", guest_name[i]);
                printf("Reservation Date: %s\n", date[i]);
                printf("Rent: %d\n", rent[i]);
                break;
            case 3:
                do{
                    flag = 0;
                    printf("Enter the Reservation Date: ");
                    scanf("%10s", idate);
                    printf("%-15s\t%-15s\t%-20s\t%-15s\n", "Reservation ID", "Room No.", "Guest Name", "Room Type");
                    for(i = 0; i < 10; i++){
                        if(strcmp(date[i], idate) == 0 && occupancy[i] == 1){
                            printf("%-15d\t%-15d\t%-20s\t%-15s\n", res_id[i], room_no[i], guest_name[i], room_type[i]);
                            flag = 1;
                        }
                    }
                    if(!flag) printf("Reservation Date not found. Please try again.\n");
                }while(!flag);
                break;
            case 4:
                flag = 0;
                printf("Vacant Rooms:\n");
                for(i = 0; i < 10; i++){
                    if(occupancy[i] == 0){
                        printf("Room No.: %d\n", room_no[i]);
                        flag = 1;
                    }
                }
                if(!flag) printf("No vacant rooms available.\n");
                break;
            case 5:
                total_revenue = 0;

                for(i = 0; i < 10; i++){
                    if(occupancy[i] == 1){
                        total_revenue += rent[i];
                    }
                }
                printf("Total Yearly Revenue: %d\n", 365 * total_revenue);
                break;
        }
        printf("Press 0 to exit or 1 to continue.");
        scanf("%d", &option);
        printf("\n");
    }while(option != 0);
    


    return 0;
}

int menu(){
    int option;
    printf("Welcome to the Hotel Management System\n");
    printf("Please select an option:\n");
    printf("1. Add New Reservation\n");
    printf("2. Search Reservation by Reservation ID\n");
    printf("3. Display All Reservations by Date\n");
    printf("4. Display Vacant Rooms\n");
    printf("5. Calculate Total Yearly Revenue\n");
    printf("Enter your choice: ");
    scanf("%d", &option);
    printf("\n");
    return option;
}