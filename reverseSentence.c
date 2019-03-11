#include <stdio.h>

void reverseSentence(char s[]);
void reverse(char s[], int start, int end);

int main()
{
	char s[100];
	printf("Enter a sentence: ");
	scanf(" %[^\n]", s);
	printf("Original Sentence: %s\n", s);
	reverseSentence(s);
	printf("Reversed Sentence: %s\n", s);
	return 0;
}

void reverseSentence(char *s)
{
	int i, l, start = 0;

	for(l = 0; s[l] != '\0'; l++)
		;

	reverse(s, 0, l-1);

	for(i = 0; i <= l; i++) {
		if(s[i] == ' ' || s[i] == '\t' || s[i] == '\0') {
			reverse(s, start, i-1);
			start = i+1;
		}
	}
}

void reverse(char *s, int start, int end)
{
	int i, j;
	char temp; 
	for(i = start, j = end; i < j; i++, j--) {
		temp = s[i];
		s[i] = s[j];
		s[j] = temp;
	}
}
