#include <stdbool.h>
#include <stdio.h>

int main() {
    // Variable Declarations for calculating grades and control flow of program
    int studentIncrement = 1;
    char userYesOrNo;
    float labMark1, labMark2, labMark3, labMark4, labMark5, labGradeAverage;
    float assignMark1, assignMark2, assignMark3, assignmentGradeAverage;
    int moss1, moss2, moss3;
    float quizMark1, quizMark2, quizMark3, quizMark4, quizGradeAverage;
    float labExamMark, labExamMarkCalc;
    char transferLabExam;
    float finalExamMark, finalExamMark40, finalExamMark30, finalExamMark40Two;
    float quizPlusExam;
    float overallFinalMark;
    float classTotalGrade;
    float classAverage;
    bool hasFailedMOSS = false;

    printf("Welcome to ALT1300 admin page\n\n");

    do {
        // Declared to false to reset for next student
        hasFailedMOSS = false;

        printf("Student #%d \n\n", studentIncrement);

        // Scanner for the 5 lab marks
        printf("Enter 5 lab marks, each separated by a space: ");
        scanf("%f %f %f %f %f", &labMark1, &labMark2, &labMark3, &labMark4, &labMark5);

        // Calculation out of 20 for the 5 lab marks
        labGradeAverage = ((labMark1 + labMark2 + labMark3 + labMark4 + labMark5) / 25.0);
        printf("Overall lab grade (20) = %1.2f / 20 \n\n", labGradeAverage);

        // Scanner for the 3 assignment marks
        printf("Enter 3 assignment marks, each separated by a space: ");
        scanf("%f %f %f", &assignMark1, &assignMark2, &assignMark3);

        // MOSS input 1
        printf("Enter MOSS result for A1: ");
        scanf("%d", &moss1);

        // MOSS input 2
        printf("Enter MOSS result for A2: ");
        scanf("%d", &moss2);

        // MOSS input 3
        printf("Enter MOSS result for A3: ");
        scanf("%d", &moss3);

        // MOSS decision
        if (moss1 == 0 && moss2 == 0 && moss3 == 0) {
            // If student gets detected on all, failed
            assignMark1 = 0;
            assignMark2 = 0;
            assignMark3 = 0;
            hasFailedMOSS = true;
        }
        if (moss1 == 0) {  // If student gets detection on assignment 1
            assignMark1 = 0;
        }
        if (moss2 == 0) {  // If student gets detection on assignment 2
            assignMark2 = 0;
        }
        if (moss3 == 0) {  // If student gets detection on assignment 3
            assignMark3 = 0;
        }

        // Calculation out of 20 for the 3 assignment marks after MOSS
        assignmentGradeAverage = ((assignMark1 + assignMark2 + assignMark3) / 15.0);
        printf("Overall assignment grade (20) = %1.2f /20 \n\n", assignmentGradeAverage);

        // Scanner for the 4 quiz marks
        printf("Enter 4 quiz marks, each separated by a space: ");
        scanf("%f %f %f %f", &quizMark1, &quizMark2, &quizMark3, &quizMark4);

        // Calculation out of 20 for the 4 quiz marks
        quizGradeAverage = ((quizMark1 + quizMark2 + quizMark3 + quizMark4) / 20.0);
        printf("Overall quiz grade (20) = %1.2f / 20 \n\n", quizGradeAverage);

        // Scanner for the lab exam mark
        printf("Enter lab exam mark: ");
        scanf("%f", &labExamMark);

        // Scanner for the transfer of mark to the exam
        printf("Enter the survey response ('y' or 'n'): ");
        scanf(" %c", &transferLabExam);

        // If statement for "yes" if they want to transfer the mark
        if (transferLabExam == 'y') {
            printf("Your lab exam is worth 0, and final exam is worth 40 \n\n");

            // Scanner for the final exam mark
            printf("Enter final exam mark: ");
            scanf("%f", &finalExamMark);

            // Calculation out of 40 for the final exam mark
            finalExamMark40 = ((finalExamMark / 100.0) * 40.0);
            printf("Overall final exam grade (40) = %1.2f / 40 \n\n", finalExamMark40);

            // Calculation out of 30 for the final exam mark
            finalExamMark40Two = ((finalExamMark / 100.0) * 30.0);

            // Calculation for the quiz grade and the final exam mark added
            quizPlusExam = (quizGradeAverage + finalExamMark40Two);

            // Display of all marks
            printf("Quizzes + Final Exam = %1.2f + %1.2f = %1.2f \n\n", quizGradeAverage, finalExamMark40Two,
                   quizPlusExam);
            printf("Overall course marks (%%) \n");
            printf("************************* \n");
            printf("Labs = %1.2f \n", labGradeAverage);
            printf("Assignments = %1.2f \n", assignmentGradeAverage);
            printf("Quizzes = %1.2f \n", quizGradeAverage);
            printf("Final Exam = %1.2f \n", finalExamMark40);
            printf("************************* \n\n");

            // If student fails due to MOSS
            if (hasFailedMOSS == true) {
                overallFinalMark = 0;
            } else {
                overallFinalMark = (labGradeAverage + assignmentGradeAverage + quizGradeAverage + finalExamMark40);
            }
        } else if (transferLabExam == 'n') {
            printf("Your lab exam is worth 10, and final exam is worth 30 \n\n");

            // Scanner for the final exam mark
            printf("Enter final exam mark: ");
            scanf("%f", &finalExamMark);

            // Calculation out of 10 for the lab exam mark
            labExamMarkCalc = ((labExamMark / 100.0) * 10.0);

            // Calculation out of 30 for the final exam mark
            finalExamMark30 = (((finalExamMark) / 100.0) * 30.0);
            printf("Overall final exam grade (30) = %1.2f / 30 \n\n", finalExamMark30);

            // Calculation for the quiz grade and the final exam mark added
            quizPlusExam = (quizGradeAverage + finalExamMark30);

            // Display of all marks
            printf("Quizzes + Final Exam = %1.2f + %1.2f = %1.2f \n\n", quizGradeAverage, finalExamMark30,
                   quizPlusExam);
            printf("Overall course marks (%%) \n");
            printf("************************* \n");
            printf("Labs = %1.2f \n", labGradeAverage);
            printf("Assignments = %1.2f \n", assignmentGradeAverage);
            printf("Quizzes = %1.2f \n", quizGradeAverage);
            printf("Lab Exam = %1.2f \n", labExamMarkCalc);
            printf("Final Exam = %1.2f \n", finalExamMark30);
            printf("************************* \n\n");

            // If student fails due to MOSS
            if (hasFailedMOSS == true) {
                overallFinalMark = 0;
                printf("Overall grade = F \n\n");
            } else {
                overallFinalMark =
                    (labGradeAverage + assignmentGradeAverage + quizGradeAverage + labExamMarkCalc + finalExamMark30);
            }
        }

        if (quizPlusExam < 25) {
            printf("Your overall course marks = %1.2f%% \n", overallFinalMark);
            printf("Overall grade = F \n\n");
        } else {
            // Displays the final grade
            printf("Your overall course marks = %1.2f%% \n", overallFinalMark);

            // Displays the latter grade
            if (overallFinalMark >= 80 && overallFinalMark <= 100) {
                printf("Overall grade = A \n\n");
            } else if (overallFinalMark >= 70 && overallFinalMark < 79) {
                printf("Overall grade = B \n\n");
            } else if (overallFinalMark >= 60 && overallFinalMark < 69) {
                printf("Overall grade = C \n\n");
            } else if (overallFinalMark >= 50 && overallFinalMark < 59) {
                printf("Overall grade = D \n\n");
            } else {
                printf("Overall grade = F \n\n");
            }
        }

        // To add the grade of the student just marked to the previous one
        classTotalGrade += overallFinalMark;

        // Next student command
        printf("Would you like to continue - enter y for yes, n for no: ");
        scanf(" %c", &userYesOrNo);

        // To increment student number and division for class average
        studentIncrement++;
    } while (userYesOrNo == 'y');

    // To get rid of the extra increment that i made when exiting the loop
    studentIncrement = (studentIncrement - 1);
    printf("\n");

    // Calculates class average
    classAverage = (classTotalGrade / studentIncrement);
    printf("Average course mark out of %d students = %1.2f\n", studentIncrement, classAverage);

    return 0;
}