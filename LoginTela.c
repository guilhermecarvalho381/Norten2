#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXC 256    //Se precisar de uma constante
#define TENTATIVA  3 //Numero de tentativas
#define CREDFILE "dat/credfile.txt"

int login(void);
int create(void);

int TelaLogi(void)
{
    //variavel
    char ans[MAXC];

    printf("Bem vindo a Norten\n\n");
    printf("Type yes to login or no to create a new account: ");

    if (!fgets (ans, MAXC, stdin)) {
        fputs ("(user canceled input)\n", stderr);
        return 1;
    }
    ans[strcspn(ans, "\n")] = 0;                /* trim trialing '\n' */

    if (strcmp(ans, "yes") == 0) {          /* handle login */
        int tries = TENTATIVA, success = 0;     /* 3-tries and success flag */
        while (tries--)                     /* loop at most 3 times */
            if ((success = login()))        /* on success break loop */
                break;
        if (!success) { /* if login was not a success, handle error */
            fprintf (stderr, "error: %d login tries exhausted.\n", TENTATIVA);
            return 1;
        }
    }
    else {  /* otherwise create() */
        int tries = TENTATIVA, success = 0;     /* same 3-tries */
        while (tries--)                     /* loop at most 3-times */
            if ((success = create()))       /* on success break loop */
                break;
        if (!success) { /* if create was not a success, handle error */
            fprintf (stderr, "error: %d create tries exhausted.\n", TENTATIVA);
            return 1;
        }
        login();    /* now you can have user login to verify account */
    }

    return 0;
}

/* returns 1 on success, 0 otherwise */
int login2 (void)
{
    FILE *fp;
    char name[MAXC], fname[MAXC], buf[MAXC];    /* buf - read all with fgets */
    int pin, fpin;

    printf("~Login~\n");

    printf ("Name: ");
    if (!fgets (name, MAXC, stdin)) {       /* using fgets() */
        fputs ("(user canceled input)\n", stderr);
        return 0;
    }
    name[strcspn (name, "\n")] = 0;         /* so trim trailing '\n' */

    printf ("Password: ");
    if (!fgets (buf, MAXC, stdin)) {        /* read pin with fgets()!!! */
        fputs ("(user canceled input)\n", stderr);
        return 0;
    }
    if (sscanf (buf, "%d", &pin) != 1) {    /* now use sscanf to parse int */
        fputs ("error: invalid integer input.\n", stderr);
        return 0;
    }

    if (!(fp = fopen (CREDFILE, "r"))) {    /* open/validate file open */
        perror ("fopen-file");
        exit (EXIT_FAILURE);
    }

    if (fscanf (fp, " %255s%d", fname, &fpin) != 2) {   /* read fname/fpin */
        fputs ("error: read of fname/fpin failed.\n", stderr);
        exit (EXIT_FAILURE);
    }
    fclose (fp);

    if ((strcmp(name, fname) == 0) && (pin == fpin)) {  /* validate login */
        printf ("You have successfully logged in!\n");
        return 1;   /* return success */
    }

    printf ("The information you gave is incorrect. Try again... \n");

    return 0;       /* return failure */
}

/* returns 1 on success, 0 otherwise */
int create (void)
{
    FILE *fp;
    char name[MAXC], buf[MAXC];
    int pin;

    printf ("\nEnter your name: ");
    if (!fgets (name, MAXC, stdin)) {       /* using fgets() */
        fputs ("(user canceled input.}\n", stderr);
        return 0;
    }
    name[strcspn (name, "\n")] = 0;         /* so trim trailing '\n' */

    printf ("Enter a numerical password: ");
    if (!fgets (buf, MAXC, stdin)) {        /* read pin with fgets()!!! */
        fputs ("(user canceled input)\n", stderr);
        return 0;
    }
    if (sscanf (buf, "%d", &pin) != 1) {    /* now use sscanf to parse int */
        fputs ("error: invalid integer input.\n", stderr);
        return 0;
    }

    if (!(fp = fopen(CREDFILE, "w"))) {    /* open/validate file open */
        perror ("fopen-failed");
        exit (EXIT_FAILURE);
    }

    fprintf (fp, "%s\n%d\n", name, pin);    /* write creditials to file */
    fclose(fp);

    printf("\nYour new account has been created!\n"
            "You may now login to the system!\n");

    return 1;       /* return success */
}
