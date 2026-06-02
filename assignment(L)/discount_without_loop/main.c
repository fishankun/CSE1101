#include <stdio.h>

float discount(float x){
	if(x >= 500){
		if(x >= 2000 && x <= 4000 && x != 2027)
			return x * 0.05;
		else if(x > 2026.99 && x < 2027.01)
			return 270;
		else if(x >= 5000){
			if(x * 0.1 >= 2000){
				return 2000;
			}
			else{
				return x * 0.1;
				}
			}
		else{
			return 50;
		}
	}	
	
	else{
		return 0;
	}
}

int main(){
	float cart_value, cp, cp_to_tk;
	float total_dis, payable, new_cp;
	float remaining_cp, earned_cp, dis;
	
	printf("Enter the cart value: ");
	scanf("%f", &cart_value);
	printf("Enter customer point: ");
	scanf("%f", &cp);

	cp_to_tk = cp / 40;
	dis = discount(cart_value);
	if(cart_value - dis >= cp_to_tk){
		total_dis = cp_to_tk + dis;
		payable = cart_value - total_dis;
		new_cp = cart_value * 0.4;
	}
	else{
		payable = 0;
		total_dis = cart_value;
		remaining_cp = (cp_to_tk - (cart_value - dis)) * 40;
		earned_cp = cart_value * 0.4;
		new_cp = remaining_cp + earned_cp;
	}

	printf("Total discount: %.2f\nPayable: %.2f\nUpdated CP: %.2f\n", total_dis, payable, new_cp);

	return 0;	
}
