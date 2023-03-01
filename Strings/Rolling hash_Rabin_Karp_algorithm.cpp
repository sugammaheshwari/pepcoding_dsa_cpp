
/*

 Rolling hash | Rabin karp algorithm | Pattern searching
 Video Link : https://www.youtube.com/watch?v=BQ9E-2umSWc

 Its modified sliding window technique for matching of a pattern with a given text
 but before matching hash is computed and string is matched iff hash value of pattern and substr matches
 *substring is selected using sliding windows technique !!!

 Time complexity O(m+n) , m: length of text , n: length of pattern

 To Reduce the collision and thus improve the time complexity of the algorithm , a strong hash function is selected !!!

*/


#include<iostream>
using namespace std;

// d=26 for 26 small alphabets ,can be modified as per the use case !
#define d 26

void search(char pat[], char txt[], int q)
{
    int M = int(strlen(pat));
    int N = int(strlen(txt));
    int i, j;
    int p = 0; // hash value for pattern
    int t = 0; // hash value for txt
    int h = 1;

    // The value of h would be "pow(d, M-1)%q"
    for (i = 0; i < M - 1; i++)
        h = (h * d) % q;

    // Calculate the hash value of pattern and first
    // window of text
    for (i = 0; i < M; i++)
    {
        p = (d * p + pat[i]) % q;
        t = (d * t + txt[i]) % q;
    }

    // Slide the pattern over text one by one
    for (i = 0; i <= N - M; i++)
    {

        // Check the hash values of current window of text
        // and pattern. If the hash values match then only
        // check for characters on by one
        if ( p == t )
        {
            /* Check for characters one by one */
            for (j = 0; j < M; j++)
            {
                if (txt[i+j] != pat[j])
                    break;
            }

            // if p == t and pat[0...M-1] = txt[i, i+1, ...i+M-1]
            if (j == M)
                cout<<"Pattern found at index "<< i<<endl;
        }

        // Calculate hash value for next window of text: Remove
        // leading digit, add trailing digit
        if ( i < N-M )
        {
            t = (d*(t - txt[i]*h) + txt[i+M])%q;
            if (t < 0)                              // to fix the -ve after modulo operation !!
            t = (t + q);
        }
    }
}

int main()
{
    char txt[] = "acdbhgvfacsfabcassabce";
    char pat[] = "abce";
    int q = 101;
    search(pat, txt, q);
    return 0;
}

