#include <stdio.h>
#include <string.h>

struct Job
{
    char title[50];
    char description[200];
    char qualifications[200];
    char experience[100];
    float salary;
    char location[100];
};

struct Candidate
{
    char name[50];
    char email[50];
    int phone_number;
    char education[200];
    char location[100];
};

struct apply
{
    char name[50];
    char email[50];
    int phone_number;
    char title[50];
    char qualification[200];
    float salary;
    char education[100];
    char experience[100];
};

void register_job()
{
    struct Job job;
    printf("Enter job Title: ");
    scanf("%s[^\n]", job.title);
    fflush(stdin);
    printf("Enter job Description: ");
    scanf("%s[^\n]", job.description);
    fflush(stdin);
    printf("Enter job Qualifications: ");
    scanf("%s[^\n]", job.qualifications);
    fflush(stdin);
    printf("Enter job Experience: ");
    scanf("%s[^\n] ", job.experience);
    fflush(stdin);
    printf("Enter job Salary: ");
    scanf("%f", &job.salary);
    fflush(stdin);
    printf("Enter job Location: ");
    scanf("%s[^\n] ", job.location);
    fflush(stdin);

    FILE *fptr;
    fptr = fopen("jobs.txt", "a");
    fprintf(fptr, "%s %s %s %s %f %s\n", job.title, job.description, job.qualifications, job.experience, job.salary, job.location);
    fclose(fptr);
    puts("Job Registered!");
}

void register_candidate()
{
    struct Candidate candidate;
    printf("Enter candidate Name: ");
    scanf("%s[^\n]", candidate.name);
    fflush(stdin);
    printf("Enter candidate Email: ");
    scanf("%s[^\n]", candidate.email);
    fflush(stdin);
    printf("Enter candidate Education: ");
    scanf("%s[^\n]", candidate.education);
    fflush(stdin);
    puts("Enter candidate Phone Number: ");
    scanf("%d", &candidate.phone_number);
    fflush(stdin);
    puts("Enter a Address: ");
    scanf("%s[^\n]", candidate.location);
    fflush(stdin);

    FILE *fptr;
    fptr = fopen("candidates.txt", "a");
    fprintf(fptr, "%s %s %s %d %s\n", candidate.name, candidate.email, candidate.education, candidate.phone_number, candidate.location);
    fclose(fptr);
    puts("Candidate Register!");
}

void search_job()
{
    char search_title[50];
    printf("Enter job title to Search: ");
    scanf("%s[^\n]", search_title);

    FILE *fptr;
    fptr = fopen("jobs.txt", "r");

    char title[50], description[200], qualifications[200];
    int found = 0;

    while (fscanf(fptr, "%s %s %s\n", title, description, qualifications) != EOF)
    {
        if (strcmp(title, search_title) == 0)
        {
            printf("Job title: %s\n", title);
            printf("Job description: %s\n", description);
            printf("Job qualifications: %s\n", qualifications);
            found = 1;
            break;
        }
    }

    if (!found)
    {
        printf("Job not found\n");
    }

    fclose(fptr);
}

void apply_job()
{
    FILE *fptr;
    fptr = fopen("jobs.txt", "r");
        char ch;
    ch = fgetc(fptr);
    while (ch != EOF)
    {
        printf("%c", ch);
        ch = fgetc(fptr);
    }
    printf("\n");
    fclose(fptr);

    struct apply apply_job;
    puts("Enter Name of Candidate: ");
    scanf("%s[^\n]", apply_job.name);
    fflush(stdin);
    puts("Enter Candidate Email ID: ");
    scanf("%s[^\n]", apply_job.email);
    fflush(stdin);
    puts("Enter Candidate Phone Number: ");
    scanf("%d", &apply_job.phone_number);
    fflush(stdin);
    puts("Enter Job Title: ");
    scanf("%s[^\n]", apply_job.title);
    fflush(stdin);
    puts("Enter Candidate Education: ");
    scanf("%s[^\n]", apply_job.education);
    fflush(stdin);
    puts("Enter Candidate Qualification: ");
    scanf("%s[^\n]", apply_job.qualification);
    fflush(stdin);
    puts("Enter Candidate Experience: ");
    scanf("%s[^\n]", apply_job.experience);
    fflush(stdin);
    puts("Enter Candidate Expected Salary: ");
    scanf("%f", &apply_job.salary);
    fflush(stdin);
   
    FILE *fptr3;
    fptr3 = fopen("job_application.txt", "a");
    fprintf(fptr, "%s %s %s %d %s %s %f %s \n", apply_job.name, apply_job.email, apply_job.education, apply_job.phone_number, apply_job.experience, apply_job.title, apply_job.salary, apply_job.qualification);
    fclose(fptr);
    printf("Applied Successful!");
}

void delete_job()
{
    char search_title[50];
    printf("Enter job title to delete: ");
    scanf("%s", search_title);

    FILE *fptr1, *fptr2;
    fptr1 = fopen("jobs.txt", "r");
    fptr2 = fopen("temp.txt", "w");

    char title[50], description[200], qualifications[200];
    int found = 0;

    while (fscanf(fptr1, "%s %s %s\n", title, description, qualifications) != EOF)
    {
        if (strcmp(title, search_title) != 0)
        {
            fprintf(fptr2, "%s %s %s\n", title, description, qualifications);
        }
        else
        {
            found = 1;
        }
    }

    if (!found)
    {
        printf("Job not found\n");
    }
    else
    {
        printf("Job deleted successfully\n");
    }

    fclose(fptr1);
    fclose(fptr2);

    remove("jobs.txt");
    rename("temp.txt", "jobs.txt");
}

void update_candidate()
{
    char search_name[50];
    printf("Enter candidate name to update: ");
    scanf("%s[^\n]", search_name);

    struct Candidate candidate;

    printf("Enter updated candidate name: ");
    scanf("%s[^\n]", candidate.name);

    printf("Enter updated candidate email: ");
    scanf("%s[^\n]", candidate.email);

    printf("Enter updated candidate education: ");
    scanf("%s[^\n]", candidate.education);

    FILE *fptr1, *fptr2;
    fptr1 = fopen("candidates.txt", "r");
    fptr2 = fopen("temp.txt", "w");

    char name[50], email[50], education[200];
    int found = 0;

    while (fscanf(fptr1, "%s %s %s\n", name, email, education) != EOF)
    {
        if (strcmp(name, search_name) != 0)
        {
            fprintf(fptr2, "%s %s %s\n", name, email, education);
        }
        else
        {
            fprintf(fptr2, "%s %s %s\n", candidate.name, candidate.email, candidate.education);
            found = 1;
        }
    }

    if (!found)
    {
        printf("Candidate not found\n");
    }
    else
    {
        printf("Candidate updated successfully\n");
    }

    fclose(fptr1);
    fclose(fptr2);

    remove("candidates.txt");
    rename("temp.txt", "candidates.txt");
}

int main()
{
    int choice;
    while (1)
    {
        printf("Menu:\n");
        printf("1. Register a job\n");
        printf("2. Register a candidate\n");
        printf("3. Search for a job\n");
        printf("4. Apply for a job\n");
        printf("5. Update/delete a job\n");
        printf("6. Update candidate details\n");
        printf("7. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            register_job();
            break;
        case 2:
            register_candidate();
            break;
        case 3:
            search_job();
            break;
        case 4:
            apply_job();
            break;
        case 5:
            printf("1. Update a job\n");
            printf("2. Delete a job\n");
            printf("Enter your choice: ");
            scanf("%d", &choice);

            if (choice == 1)
            {
                // update_job();
            }
            else if (choice == 2)
            {
                delete_job();
            }
            else
            {
                printf("Invalid choice\n");
            }
            break;
        case 6:
            update_candidate();
            break;
        case 7:
            printf("Exiting...\n");
            return 0;
        default:
            printf("Invalid choice\n");
            break;
        }
    }

    return 0;
}