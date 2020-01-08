#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void print(char ch,int state[],int miss);
int main(void)

{
	FILE *fp;
	char ch = '\0';
	errno_t err;
	int outcome, missnumber = 0, miss;
	int state[2] = { '\0' };

	if ((err = fopen_s(&fp, "test.txt", "r")) != 0)
	{
		printf("open file error!!\n");
		system("PAUSE");
		exit(0);
	}

	while ((ch = getc(fp)) != EOF) 
	{

		outcome = -1;
		miss = 0;

		if (ch == 'T')
		{
	
			outcome = 1;
			if (state[0] != outcome)
			{
				miss++;
				missnumber ++;
				print(ch,state, miss);
				state[1] ++;				
				if (state[1] == 2)
				{
					state[1] = 0;
					state[0]++;
				}//進位

			}
			else
			{
				print(ch,state, miss);
				if(state[1]== 0)
					state[1]++;
				if (state[1] == 2)
				{
					state[1] = 0;
					state[0]= 1;
				}//進位
			

			}
				
		}
		else if (ch == 'N')
		{
			
			outcome = 0;
			if (state[0] != outcome)
			{
				miss++;
				missnumber++;
				print(ch,state, miss);
				state[1]--;	
				if (state[1] < 0)
				{
					state[1] = 1;
					state[0] = 0;
				}///位數調整

			}
			else
			{
				print(ch,state,miss);
				state[1] = 0;
				
			}
		

		}

	}
	fclose(fp);

	printf(" miss number: %d\n", missnumber);

	system("pause");
	return 0;

}

void print(char ch ,int state[], int miss)
{
	char pred ;
	if (state[0] == 0)
		pred = 'N';
	else
		pred = 'T';
	printf("pred:%c outcome:%c	%d%d  miss: %d\n",pred,ch, state[0], state[1], miss);
}