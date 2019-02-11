#include <stdio.h>

int main()
{
	FILE *input, *output;
	char ch;
	int index;
	int previous = 'x';
	int counter = 1;
	int i = 0;

	input = fopen("testinput.txt", "r");
	output = fopen("testoutput.txt", "w");
	
	previous = fgetc(input);
	while ((ch = fgetc(input)) != EOF)		//loops through whole file one character
	{						//at a time
		if (previous == ch)
		{
			counter++;		//keeps track of repeating chars
		}
		else
		{
			if (counter >= 16)
			{
				if (previous == '0')		//compresses zeros
				{
					fputc('-', output);		//write char to file
					fprintf(output, "%d", counter);	//write integer to file
					fputc('-', output);		
					counter = 1;			
				}
				else			//compresses ones
				{
					fputc('+', output);
					fprintf(output, "%d", counter);
					fputc('+', output);
					counter = 1;
				}

			}
			else
			{
				for (i; i<counter; i++)
				{
					fputc(previous, output);
				}

				i = 0;
				counter = 1;
			}
		}
		previous = ch;
	}
	fcloseall();
	return 0;
}


////////////////////IGNORE BELOW////////////////////

/*
int main()
{
		

	//execl("/bin/ls", "ls", "-l", 0);	//how to execute terminal commands thru program
	//printf("Can only get here on error\n");	
	return 0;
}
*/
