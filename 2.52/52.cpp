//25125080
//PHAM QUOC BAO
//25A02
#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

int main() {
    ifstream fin;
    int numQuestions = 0;
    int numStudentAnswers = 0;

    fin.open("CorrectAnswers.txt");
    if (!fin.is_open()) {
        cout << "Error: Cannot open CorrectAnswers.txt" << endl;
        return 1;
    }

    fin >> numQuestions; 

    char* correctAns = new char[numQuestions];
    for (int i = 0; i < numQuestions; i++) {
        fin >> correctAns[i];
    }
    fin.close();

    fin.open("StudentAnswers.txt");
    if (!fin.is_open()) {
        cout << "Error: Cannot open StudentAnswers.txt" << endl;
        delete[] correctAns;
        return 1;
    }
    fin >> numStudentAnswers;

    if (numQuestions != numStudentAnswers) {
        cout << "Error: Number of questions does not match between files!" << endl;
        cout << "Correct file has " << numQuestions << ", Student file has " << numStudentAnswers << endl;
        delete[] correctAns;
        fin.close();
        return 1;
    }

    char* studentAns = new char[numStudentAnswers];
    for (int i = 0; i < numStudentAnswers; i++) {
        fin >> studentAns[i];
    }
    fin.close();

    int missedCount = 0;

    cout << "--- MISSED QUESTIONS REPORT ---" << endl;
    
    for (int i = 0; i < numQuestions; i++) {
        if (studentAns[i] != correctAns[i]) {
            cout << "Question " << (i + 1) << ":" << endl;
            cout << "  Correct Answer: " << correctAns[i] << endl;
            cout << "  Student Answer: " << studentAns[i] << endl;
            missedCount++;
        }
    }

    if (missedCount == 0) {
        cout << "(None. Perfect score!)" << endl;
    }

    cout << "-------------------------------" << endl;

    cout << "Total questions missed: " << missedCount << endl;

    int correctCount = numQuestions - missedCount;
    double percentage = ((double)correctCount / numQuestions) * 100.0;

    cout << fixed << setprecision(1);
    cout << "Percentage: " << percentage << "%" << endl;

    if (percentage >= 70.0) {
        cout << "Result: The student PASSED the exam." << endl;
    } else {
        cout << "Result: The student FAILED the exam." << endl;
    }

    delete[] correctAns;
    correctAns = nullptr;
    
    delete[] studentAns;
    studentAns = nullptr;

    return 0;
}