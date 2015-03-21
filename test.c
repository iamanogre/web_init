/* turns out have to make .exe, so going to make it in c */

# include <windows.h>
# include <stdio.h>

int main() {
	
	/* when run, need to run test.exe !! */

	/* after add to startup folder, works!! */
	/* next going to make a infinite while loop and accept different inputs for different moods:
		example: default stuff - mail and piazza
					1 - for leisure
					2 - for other stuffs
	*/

	FILE *fp;
	char buf[1000];
	char user_web_choices[10];
	char *text_mode = "r";
	char *text_default = "default.txt";
	char *shell_command = "open";
		/* SW_SHOWNORMAL = 1 */
	int shell_mode = SW_SHOWNORMAL;
	int user_input;

	/* open file  and error check */
	fp = fopen(text_default, text_mode);
	if (fp == NULL) {
		printf("Failed to open file");
		exit(1);
	}

	/* infinite while loop */
	while(1) {
		rewind(fp);

		printf("Defaulting...Press 0 to continue\n");
		
		/* probably a better way to do this, but wait until user input is 0 */
		while(1) {
			scanf("%d", &user_input);
			if (user_input == 0) {
				memcpy(user_web_choices, text_default, sizeof(text_default));
				break;
			}
		}	

		/* open up all the default websites */
		while(fgets(buf, 1000, fp)!= NULL) {
			ShellExecute(NULL, shell_command, buf, NULL, NULL, shell_mode);
		}
		
	}

	fclose(fp);

	return 0;
}