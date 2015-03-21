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
	char *text_mode = "r";
	char *text_name = "websites.txt";
	char *shell_command = "open";
		/* SW_SHOWNORMAL = 1 */
	int shell_mode = SW_SHOWNORMAL;

	fp = fopen(text_name, text_mode);
	if (fp == NULL) {
		printf("Failed to open file");
		exit(1);
	}
	while(fgets(buf, 1000, fp)!= NULL) {
		ShellExecute(NULL, shell_command, buf, NULL, NULL, shell_mode);
	}
	fclose(fp);
	return 0;
}