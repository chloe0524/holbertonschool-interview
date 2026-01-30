#include <limits.h>
#include <stdlib.h>
#include <string.h>


#include "substring.h"

static int match_word(char const *segment, size_t word_len,
                      char const **unique, int unique_count)
{
    for (int i = 0; i < unique_count; i++)
    {
        if (strncmp(segment, unique[i], word_len) == 0 &&
            unique[i][word_len] == '\0')
            return i;
    }
    return -1;
}

int *find_substring(char const *s, char const **words, int nb_words, int *n)
{
    int *results = NULL;
    char const **unique = NULL;
    int *freq = NULL;
    int *window = NULL;
    int *word_ids = NULL;
    int found = 0;
    int capacity = 0;
    int unique_count = 0;
    int error = 0;
    size_t len_s;
    size_t word_len;
    size_t total_len;

    if (!n)
        return NULL;
    *n = 0;

    if (!s || !words || nb_words <= 0 || !words[0])
        return NULL;

    word_len = strlen(words[0]);
    if (word_len == 0)
        return NULL;

    len_s = strlen(s);
    total_len = word_len * (size_t)nb_words;
    if (len_s < total_len)
        return NULL;

    unique = malloc((size_t)nb_words * sizeof(*unique));
    freq = malloc((size_t)nb_words * sizeof(*freq));
    if (!unique || !freq)
    {
        error = 1;
        goto cleanup;
    }

    for (int i = 0; i < nb_words; i++)
    {
        size_t len;

        if (!words[i])
        {
            error = 1;
            goto cleanup;
        }

        len = strlen(words[i]);
        if (len != word_len)
        {
            error = 1;
            goto cleanup;
        }

        int j;
        for (j = 0; j < unique_count; j++)
        {
            if (strcmp(words[i], unique[j]) == 0)
            {
                freq[j]++;
                break;
            }
        }
        if (j == unique_count)
        {
            unique[unique_count] = words[i];
            freq[unique_count] = 1;
            unique_count++;
        }
    }

    word_ids = malloc(len_s * sizeof(*word_ids));
    if (!word_ids)
    {
        error = 1;
        goto cleanup;
    }

    size_t idx;
    for (idx = 0; idx + word_len <= len_s; idx++)
        word_ids[idx] = match_word(s + idx, word_len, unique, unique_count);
    for (; idx < len_s; idx++)
        word_ids[idx] = -1;

    window = malloc((size_t)unique_count * sizeof(*window));
    if (!window)
    {
        error = 1;
        goto cleanup;
    }

    for (size_t offset = 0; offset < word_len; offset++)
    {
        size_t left = offset;
        size_t right = offset;
        int used = 0;

        memset(window, 0, (size_t)unique_count * sizeof(*window));

        while (right + word_len <= len_s)
        {
            int current = word_ids[right];
            right += word_len;

            if (current == -1)
            {
                memset(window, 0, (size_t)unique_count * sizeof(*window));
                used = 0;
                left = right;
                continue;
            }

            window[current]++;
            used++;

            while (window[current] > freq[current])
            {
                int left_idx = word_ids[left];
                if (left_idx < 0)
                {
                    error = 1;
                    goto cleanup;
                }
                window[left_idx]--;
                used--;
                left += word_len;
            }

            if (used == nb_words)
            {
                if (found == capacity)
                {
                    int new_cap = capacity ? capacity * 2 : 8;
                    int *tmp = realloc(results, (size_t)new_cap * sizeof(*results));
                    if (!tmp)
                    {
                        error = 1;
                        goto cleanup;
                    }
                    results = tmp;
                    capacity = new_cap;
                }

                if (left > (size_t)INT_MAX)
                {
                    error = 1;
                    goto cleanup;
                }

                results[found++] = (int)left;

                int left_idx = word_ids[left];
                if (left_idx < 0)
                {
                    error = 1;
                    goto cleanup;
                }
                window[left_idx]--;
                used--;
                left += word_len;
            }
        }
    }

cleanup:
    free(unique);
    free(freq);
    free(window);
    free(word_ids);

    if (error || found == 0)
    {
        free(results);
        results = NULL;
        found = 0;
    }

    *n = found;
    return results;
}
