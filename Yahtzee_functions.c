#include "PA5_Yahtzee.h"

int display_menu(void)
{
	int menu_response = 0;
	printf("===============================================================================  \n");
	printf("  +---------+  __  __  ______  __  __ ______ ____  _____  _____   +---------+  \n");
	printf("  |         |  ||__||  ||  ||  ||  ||   ||     //  ||     ||      |  O   O  |  \n");
	printf("  |    O    |  |____|  ||==||  ||==||   ||    //   |====  |====   |  O   O  |  \n");
	printf("  |         |    ||    ||  ||  ||  ||   ||   //    ||     ||      |  O   O  |  \n");
	printf("  +---------+    ||    ||  ||  ||  ||   ||  //___  ||___  ||___   +---------+  \n\n");
	printf("===============================================================================  \n");
	printf("   1]  Rules of Yahtzee\n");
	printf("   2]  Play!\n");
	printf("   3]  Exit\n");
	printf("    |  ");
	scanf("%d", &menu_response);
	printf("===============================================================================\n"); 
	if ((menu_response > 3) || (menu_response < 1))
	{
		system("cls");
		display_menu();
	}
	else
	{
		return menu_response;
	}

}
void display_rules(void)
{
	int response = 0;
	system("cls");
	printf("_________  ___  ___ ___    _______  ________  \n");
	printf("| |    | | | |  | | | |    |  ____| | |       \n");
	printf("| |____|_| | |  | | | |    | |____  |_|_____  \n");
	printf("| |   | |  | |__| | | |___ | |____        | | \n");
	printf("|_|   |_|  |______| |_____||______|  _____|_| \n");
	printf("================================================================================\n "    );
	printf("   The scorecard used for Yahtzee is composed of two sections. A upper section\n"       );
	printf("and a lower section. A total of thirteen boxes or thirteen scoring combinations\n"      );
	printf("are divided amongst the sections. The upper section consists of boxes that are\n"       );
	printf("scored by summing the value of the dice matching the faces of the box. If a\n"          );
	printf("player rolls four 3's, then the score placed in the 3's box is the sum of the\n"        );
	printf("dice which is 12.\n   Once a player has chosen to score a box, it may not be changed\n" );
	printf("and the combination is no longer in play for future rounds. If the sum of the\n"        );
	printf("scores in the upper section is greater than or equal to 63, then 35 more points\n"      );
	printf("are added to the players overall score as a bonus. The lower section contains a\n"      );
	printf("number of poker like combinations.\n\n"      );
	printf("================================================================================\n"     );
	printf("               Would you like to see a chart of combinations?\n                          [1] yes [2] no : ");
	scanf(" %d", &response);
	if (response == 1)
	{
		system("cls");
		display_chart();
	}
	else if (response != 2)
	{
		system("cls");
		display_rules();
	}
}
void display_chart(void)
{
	printf("+------------+--------------------------+--------------------------------------+\n");
	printf("|___Name_____|_______Combination________|________________Score_________________|\n");
	printf("|3-of-a-kind |   3 dice with same face  | Sum of all face values on the 5 dice |\n");
	printf("|4-of-a-kind |   4 dice with same face  | Sum of all face values on the 5 dice |\n");
	printf("|Full house  |  One pair & 3-of-a-kind  |                  25                  |\n");
    printf("|Sml straight|   A sequence of 4 dice   |                  30                  |\n");
	printf("|Lrg straight|   A sequence of 5 dice   |                  40                  |\n");
	printf("|Yahtzee     |5 dice with the same face |                  50                  |\n");
	printf("|Chance      |   Any sequence of dice   | Sum of all face values on the 5 dice |\n");
	printf("+------------+--------------------------+--------------------------------------+\n");
}
void exit_game(void)
{
	printf("=============================================================================  \n");
	printf("\n                            Thanks for playing!                                 \n\n");
	printf("=============================================================================\n");
	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
	exit(1);
}
int roll_die(void)
{
	int die_value = 0;
	die_value = (rand() % 6) + 1;
	return die_value;
}
void display_roll(int die1, int die2, int die3, int die4, int die5)
{
	printf("                 Die 1    Die 2    Die 3    Die 4    Die 5 \n\n");
	Sleep(200);
	printf("                 [ %d ]", die1);
	Sleep(200);
	printf("	  [ %d ]",die2);
	Sleep(200);
	printf("    [ %d ]",die3);
	Sleep(200);
	printf("    [ %d ]",die4);
	Sleep(200);
	printf("    [ %d ]\n\n", die5);
	printf("--------------------------------------------------------------------------------");
}
int get_combination(void)
{
	int combination = 0;
	printf("_________________________________Combinations___________________________________\n");
	printf("          [1]Ones                [2]Twos                [3]Threes   \n          [4]Fours               [5]Fives               [6]Sixes\n"
		"          [7] 3-of-a-kind        [8] 4-of-a-kind        [9]Full house   \n          [10]Sml straight       [11]Lrg straight       [12]Yahtzee\n                                 [13]Chance\n");
	printf("================================================================================\n");
	printf("Combination: ");
	scanf(" %d", &combination);
	--combination;
	return combination;
}
int check_combination(int combination_selection, int combinations_list)
{
	int check = 0;
	if ((combination_selection < 0) || (combination_selection > 12))
	{
		return -1;
	}
	else 
	{
		if (combinations_list < 1)
		{
			return 1;
		}
		else 
			return -1;
	}
}
void sequential_search(int list[13], int size, int target, int *found_ptr, int *index_ptr)
{
	int index = 0;

	*found_ptr = 0;
	*index_ptr = -1;

	while ((index < size) && ((*found_ptr) != 1))
	{
		if (target == list[index])
		{
			*found_ptr = 1;
			*index_ptr = index;
		}
		else
		{
			index++;
		}
	}

}
int use_roll(int *use_roll_combination, int count)
{
	int combination = 0;
	char yes_no;

	if (count < 3)
	{
		printf("Use roll for a combinatination? (Y/N) ");
		scanf(" %c", &yes_no);

		if ((yes_no == 'y') || (yes_no == 'Y'))
		{
			combination = 1;
			*use_roll_combination = combination;
			return 1;
		}
		else if ((yes_no == 'n') ||(yes_no == 'N'))
		{

			combination = 0;
			*use_roll_combination = combination;
			return 0;
		}
		else
		{
			return -1;
		}
	}
	else
	{
		return 1;
	}
}
void pause_clear(void)
{
	system("pause");
	system("cls");
}
void determine_player(int count, int *player)
{
	if (((count + 1) % 2) == 0)
	{
		// Player 2's turn
		*player = PLAYER1;
	}
	else if (((count + 1) % 2) == 1)
	{
		// Player 1's turn
		*player = PLAYER2;
	}
}
int roll_again(int roll[5], int face_values[7], int length_roll, int length_face_values)
{
	int number_held = 0, temp_1 = 0,index = 0, face_count_copy[7] = {0};

	for (index = 0; index < length_roll; index++)
	{
		printf("Roll die %d again (Y/N)?  ", index + 1);
		scanf(" %c", &temp_1);
		printf("\n");
		if ((temp_1 == 'y') || (temp_1 == 'Y'))
		{
			roll[index] = roll_die();
		}
		face_values[roll[index]]++;
	}
	
	
}
void print_array(int list[13], int stop_value)
{
	int index = 0;
	for (index = 0; index < stop_value; index++)
	{
		printf("List[%d]: %d\n", index, list[index]);
	}
}
int sum_integers(int number_to_sum, int face_value_array[7] )
{
	int index = 0, sum = 0;
	for (index = 0; index < face_value_array[number_to_sum]; index++)
	{
		sum += number_to_sum;
		printf("SUM: %d\n", sum);
	}
	return sum;
}
void sort_list_ascending(int list[], int length)
{
	int index = 0, temp = 0, passes = 0;
	while (length > passes)
	{
		for (index = 0; index < (length - 1); index++)
		{
			if (list[index] > list[index + 1])
			{
				temp = list[index];
				list[index] = list[index + 1];
				list[index + 1] = temp;
			}
		}
		passes++;
	}
}
void sort_list_descending(int list[], int length)
{
	int index = 0, temp = 0, passes = 0;
	while (length > passes)
	{
		for (index = 0; index < (length - 1); index++)
		{
			if (list[index] < list[index + 1])
			{
				temp = list[index + 1];
				list[index + 1] = list[index];
				list[index] = temp;
			}
		}
		passes++;
	}
}
int determine_upper_section_points(int combination_selection ,int upper_point_values[4], int face_count[7], int length, int score_from_player)
{
	int points = 0, index = 0, face_count_sorted[7] = {0}, accumulator = 0;

	for (index = 0; index < length; index++)
	{
		face_count_sorted[index] = face_count[index];
	}

	sort_list_descending(face_count_sorted, length);
	/////////////////////////////////////////////////////////////////////////////////////////////////////////////
	//THIS IS A FOUR OF A KIND
	if ((face_count_sorted[0] >= FOUR_OF_A_KIND) && ((combination_selection == 7)))
	{
		for (index = 0; index < length; index++)
		{
			score_from_player += (face_count[index] * index);
		}
		return score_from_player;
	}
	/////////////////////////////////////////////////////////////////////////////////////////////////////////////
	//THIS IS A THREE OF A KIND
	else if ((face_count_sorted[0] >= THREE_OF_A_KIND) && ((combination_selection == 7)|| (combination_selection == 6)))
	{
		for (index = 0; index < length; index++)
		{
			score_from_player += (face_count[index] * index);
		}
		return score_from_player;
	}
	/////////////////////////////////////////////////////////////////////////////////////////////////////////////
	//THIS IS A YAHTZEE
	else if ((face_count_sorted[0] == 5) && (combination_selection == 11))
	{
		score_from_player += YAHTZEE_POINTS;
		return score_from_player;
	}
	/////////////////////////////////////////////////////////////////////////////////////////////////////////////
	//THIS IS A CHANCE
	else if (combination_selection == 12)
	{
		for (index = 0; index < length; index++)
		{
			score_from_player += (face_count[index] * index);
		}
		return score_from_player;
	}
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////
	//THIS IS A FULL HOUSE
	else if (((face_count_sorted[0] > 2) && (face_count_sorted[1] > 1)) && (combination_selection == 8))
	{
		score_from_player += FULL_HOUSE_POINTS;
		return score_from_player;
	}
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////
	//THIS IS A LARGE STRAIGHT
	else if (combination_selection == 10)
	{
		accumulator = 0;
		for (index = 0; index < length; index++)
		{
			if (face_count[index] == 1)
			{
				accumulator += 1;
			}
		}
		if (accumulator == 5)
		{
			score_from_player += LRG_STRAIGHT_POINTS;
			return score_from_player;
		}

	}
	/////////////////////////////////////////////////////////////////////////////////////////////////////////
	//THIS IS A SMALL STRAIGHT
	else if ((combination_selection == 9) || (combination_selection == 10))
	{
		accumulator = 0;
		for (index = 0; index < length; index++)
		{
			if (face_count[index] == 1)
			{
				accumulator += 1;
			}
		}
		for (index = 0; index < length; index++)
		{
			if (face_count[index] == 2)
			{
				accumulator += 1;
				break;
			}
		}
		if (accumulator == 4)
		{
			score_from_player += SML_STRAIGHT_POINTS;
			return score_from_player;
		}

	}
	
	else 
		return score_from_player;
}
void print_winner(int total_player1_score, int total_player2_score)
{
	printf("================================================================================\n");
	printf("                 Player 1 score: %d     Player 2 score: %d\n\n", total_player1_score, total_player2_score);
	printf("================================================================================\n");
	if (total_player1_score > total_player2_score)
	{
		printf("                               PLAYER 1 WINS!\n\n");
		printf("================================================================================\n");
	}
	else if (total_player1_score == total_player2_score)
	{
		printf("                     Well this is awkward...you tied...\n\n");
	}
	else if (total_player2_score > total_player1_score)
	{
		printf("                               PLAYER 2 WINS!\n\n");
		printf("================================================================================\n");
	}

}
void reset_face_count(int list[7], int length)
{
	int index = 0;
	for (index = 0; index < (length); index++)
	{
		list[index] = 0;
	}
}
