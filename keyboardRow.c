char** findWords(char** words, int wordsSize, int* returnSize) {
    char** ans = malloc(wordsSize * sizeof(char*));
    int count = 0;

    char row1[] = "qwertyuiop";
    char row2[] = "asdfghjkl";
    char row3[] = "zxcvbnm";

    for (int i = 0; i < wordsSize; i++) {
        int r = 0, valid = 1;

        char c = tolower(words[i][0]);

        if (strchr(row1, c)) r = 1;
        else if (strchr(row2, c)) r = 2;
        else r = 3;

        for (int j = 1; words[i][j] != '\0'; j++) {
            c = tolower(words[i][j]);

            if ((r == 1 && !strchr(row1, c)) ||
                (r == 2 && !strchr(row2, c)) ||
                (r == 3 && !strchr(row3, c))) {
                valid = 0;
                break;
            }
        }

        if (valid) {
            ans[count++] = words[i];
        }
    }

    *returnSize = count;
    return ans;
}
