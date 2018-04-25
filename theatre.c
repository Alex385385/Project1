/*
 * theatre.c
 *
 *  Created on: Apr 19, 2018
 *      Author: Alejandro Millan
 */
#include <stdio.h>

int showMenu();
void showChart();

const int rows = 15;
const int columns = 30;
char seatingChart[rows][columns];
const char emptySeat = '#';
const char fullSeat = '*';
double total = 0;
int seatsLeft = 450;
int seatsTaken = 0;
int quit = 1;


int main()
{
	double seatCost[rows];
	int choice;
	int rowChoice, columnChoice, answer;
	double cost;

	for(int i = 0; i < rows; i++)
	{
		printf("Please Enter seat cost for row %d: ", (i + 1));
		scanf("%lf", &seatCost[i]);
	}

	for(int i = 0; i < rows; i++)
	{
		for(int j = 0; j < columns; j++)
		{
			seatingChart[i][j] = emptySeat;
		}
	}

	do
	{
		choice = showMenu();
		switch(choice)
		{
			case 1:
				printf("Seat Prices\n\n");

				for(int i = 0; i < rows; i++)
				{
					printf("The price for row %d ", (i+1));
					printf("%.2lf\n", seatCost[i]);
				}
				break;
			case 2:
				do
				{
					printf("Please select your row: ");
					scanf("%d", &rowChoice);
					printf("Please select seat: ");
					scanf("%d", &columnChoice);
					if(seatingChart[rowChoice][columnChoice] == '*')
					{
						printf("Seat is sold out, select new one\n");
					}
					else
					{
						cost = seatCost[rowChoice] + 0;
						total = total + cost;
						printf("The ticket costs: %.2lf\n", cost);
						printf("Confirm Purchase? Enter (0  = Yes, 1 = No): ");
						scanf("%d", &answer);
						seatsLeft = seatsLeft - answer;
						seatsTaken = seatsTaken + answer;

						if(answer == 1)
						{
							printf("Your purchase has been confirmed\n");
							seatingChart[rowChoice][columnChoice] = fullSeat;
						}
						else if(answer == 2)
						{
							printf("Would you like another seat? Enter(1 = Yes, 2 = No): ");
							scanf("%d", &quit);
						}
						printf("Would you like purchase another seat? Enter(1 = Yes, 2 = No): ");
						scanf("%d", &quit);
					}
				} while(quit == 1);
				break;
			case 3:
				printf("Available Seats\n\n");
				showChart();
				break;
			case 4:
				printf("Total Ticket Sales: %lf\n", total);
				break;
			case 5:
				printf("Quit\n");
				break;
		}
	} while(choice != 5);

	return 0;
}

int showMenu()
{
	int menuChoice;

	printf("Main Menu\n");
	printf("1. View Seat Prices\n");
	printf("2. Purchase a Ticket\n");
	printf("3. View Available Seats\n");
	printf("4. View Ticket Sales\n");
	printf("5. Quit the program\n");
	printf("Enter a choice: ");
	scanf("%d", &menuChoice);
	printf("\n");

	return menuChoice;
}

void showChart()
{
	printf("\tSeats\n");
	printf("        123456789012345678901234567890\n");
	for(int i = 0; i < rows; i++)
	{
		printf("Row %d   ", (i+1));
		for(int j = 0; j < columns; j++)
		{
			printf("%c", seatingChart[i][j]);
		}
		printf("\n");
	}
}
