#include <stdio.h>

typedef struct Exam {
    int id; 
    char answers[9];
    double gradePercentage;

}Exam_t;


void read_n_chars(char arr[], int n) {
    for (int j = 0; j < n; j++) {
        scanf("%c", &arr[j]);
    }
}

void print_n_chars(char arr[], int n) {
    for (int j = 0; j < n; j++) {
        printf("%c ", arr[j]);
    }
    printf("\n");
}


double getGradeFromAnswers(const char correct[], const char answers[], int statistics[], const int numQuestions){
    double score = 0;
    for(int i = 0; i < numQuestions; i++){
        if(answers[i] == correct[i]) score++;
        else statistics[i]++;
    }
   // printf("Correct answers:|%s|\nGiven Answers: |%s|\n",correct,answers);
   // printf("Score: %lf\n\n",score);
    return ((score*100.0) / (double)numQuestions); 
}

int main(void) {

    int numAnswers;
    char temp;
    scanf("%d", &numAnswers);    // read num answers
    scanf("%c", &temp); // read the space
    
    char answers[numAnswers];
    read_n_chars(answers,numAnswers); /// read the correct answers and put them into answers array

    Exam_t exams[9]; 

    int id = -1; 

    int answersRecorded = 0;

    int statistics[numAnswers];
    for(int i = 0; i<numAnswers; i++) statistics[i] = 0;
    //TODO: Fix error with incorrect grade and statistics values
    while(scanf("%d%c", &id, &temp) != EOF && answersRecorded < 9){
        exams[answersRecorded] = (Exam_t){id,{'\0', '\0', '\0', '\0', '\0','\0','\0','\0','\0'},0.0};
        read_n_chars(exams[answersRecorded].answers,numAnswers+1);
        exams[answersRecorded].gradePercentage = getGradeFromAnswers(answers,exams[answersRecorded].answers,statistics,numAnswers);
        answersRecorded++; 
    }

    printf("Question :");
    for(int i = 1; i <= numAnswers; i++) printf(" %d",i);
    printf("\n");

    printf("Answer   :");
    for(int i = 0; i < numAnswers; i++) printf(" %c",answers[i]);
    printf("\n");
    
    printf("ID   Grade(%%)");

    for(int i = 0; i < answersRecorded; i++){
        printf("\n%-5d%5.2lf",exams[i].id, exams[i].gradePercentage);
    }
    printf("\nQuestion :");
    
    for(int i = 1; i <= numAnswers; i++) printf(" %d",i);

    printf("\nMissed by:");
    
    for(int i = 0; i < numAnswers; i++) printf(" %d", statistics[i]);
    printf("\n");
    return(0);
}
