/* turns out have to make .exe, so going to make it in c */
/* when run, need to run test.exe !! */

# include <windows.h>
# include <stdio.h>

int main() {

	/* made an in finite while loop and accept different inputs for different moods:
		example: 0 - default stuff - mail and piazza
				 1 - for leisure
		only two inputs so far!
	*/

	/* file pointer intialization */
	FILE *fp_default, *fp_leisure, *fp_chosen;
	FILE *pointers[2]; /* to hold our file pointers */

	/* modes and int intialization */
	char buf[1000];
	char *text_mode = "r";
	char *shell_command = "open";
	int shell_mode = SW_SHOWNORMAL; 
	/* SW_SHOWNORMAL = 1 */
	int user_input;
	int intialization = 1;

	/* our own website text files */
	char *text_default = "default.txt";
	char *text_leisure = "leisure.txt";

	/* open file  and error check */
	fp_default = fopen(text_default, text_mode);
	if (fp_default == NULL) {
		printf("Failed to open default file");
		exit(1);
	}
	fp_leisure = fopen(text_leisure, text_mode);
	if (fp_leisure == NULL) {
		printf("Failed to open leisure file");
		exit(1);
	}

	/* fill our array of file pointers */
	pointers[0] = fp_default;
	pointers[1] = fp_leisure;

	/* infinite while loop */
	while(1) {
		
		/* probably a better way to do this, but wait until user input is 0 or 1 */
		if (intialization) {
			printf("Opened initial websites.\n");
			intialization = 0; 
			fp_chosen = pointers[0];
		} else {
			rewind(fp_chosen);
			printf("Awaiting next choice\n");
			printf("Press 0 for default, 1 for leisure websites.\n");
			while(1) {
				scanf("%d", &user_input);
				if (user_input == 0 || user_input == 1) {
					fp_chosen = pointers[user_input];
					break;
				}
			}
		}	

		/* open up all the default websites */
		while(fgets(buf, 1000, fp_chosen)!= NULL) {
			ShellExecute(NULL, shell_command, buf, NULL, NULL, shell_mode);
		}
		
	}

	fclose(fp_default);
	fclose(fp_leisure);

	return 0;
}